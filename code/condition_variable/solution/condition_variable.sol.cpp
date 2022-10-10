#include <condition_variable>
#include <chrono>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>
#include <vector>

/*
 * ------------------------------------------------------------
 *  Setup and helpers. You don't need to change any code here.
 * ------------------------------------------------------------
 */
using namespace std::chrono_literals; // We can write 1s

// Print contents of the stream to cout in a thread-safe manner.
// This class consumes stream inputs, buffers them, and writes them
// out when destructed respecting the cout_mutex.
class SafeCout {
  std::stringstream stream;
  inline static std::mutex cout_mutex; // We need this to synchronise printing

public:
  ~SafeCout() {
    std::scoped_lock<std::mutex> coutLock{cout_mutex};
    std::cout << stream.str();
  }

  template<typename T>
  SafeCout & operator<<(T&& arg) {
    stream << std::forward<T>(arg);
    return *this;
  }
};

// A mock data object
struct Data {
  bool isReady() const {
    return _isReady;
  }

  bool _isReady = false;
  bool _isConsistent = false;
};


// The function that processes the data. You don't need to touch it.
// It will check whether the data are in a consistent state, and
// idle a bit to simulate longer data processing.
// Note: It should run in parallel.
bool process(unsigned int threadIdx, Data const & data) {
  bool processingOK = true;

  SafeCout{} << '[' << threadIdx << "] I'm starting to process the data now\n";
  if (!data._isConsistent) {
    processingOK = false;
    SafeCout{} << '[' << threadIdx << "] ERROR data isn't fully ready! Race condition!\n";
  }

  // Burn some CPU cycles to simulate intensive data processing.
  const auto startTime = std::chrono::high_resolution_clock::now();
  unsigned dummyCounter = 0;
  while (std::chrono::high_resolution_clock::now() - startTime < 5s) {
    ++dummyCounter;
  }
  return processingOK;
}

/*
 * ------------------------------------------------------------
 *  Exercise code you need to work on.
 * ------------------------------------------------------------
 * This program tries to implement a producer/multi-consumer dependency between threads.
 * One producer provides some data, and multiple consumers wait for the data to become ready.
 *
 * The threads communicate via std::condition_variable, but the implementation is incomplete.
 *
 * Tasks:
 * 1. Run the program and understand why the consumer threads start running too early (on some
 *    platforms, at least ...).
 *    Run it multiple times if necessary.
 *    Why do they wake up although they should remain sleeping?
 * 2. Fix the race condition by protecting the data production phase with a lock.
 * 3. When you run the program now, the consumers should start running only after the data are ready.
 *    Why do they run one by one, though?
 *    Check the CPU consumption with a tool like top in a second shell.
 *    Ideally, we want 400% utilisation.
 * 4. Fix the consumer waiting phase like in the lecture to make the consumers run in parallel.
 *    Check the CPU consumption again.
 */


int main() {
  std::mutex mutex;
  std::condition_variable cond;
  Data data;

  // DATA-PROCESSING THREADS
  // Here we start the processing threads. They have to wait for the data to be ready,
  // and then they should process it in parallel.
  auto processData = [&](unsigned int threadIdx){
    SafeCout{} << '[' << threadIdx << "] I'm starting to wait\n";
    {
      std::unique_lock<std::mutex> lock{mutex};
      cond.wait(lock, [&](){ return data.isReady(); });
    }
    auto result = process(threadIdx, data);

    SafeCout{} << '[' << threadIdx << "] Data processing completed " << (result ? "OK" : "with failure!") << '\n';
  };

  std::vector<std::thread> consumers;
  for (unsigned int i=0; i < 4; ++i) {
    consumers.emplace_back(processData, i);
  }

  // DATA-PRODUCER THREAD
  // This thread produces the data. We simulate a complicated way of producing the data
  // by making the thread wait for a few seconds during the data production.
  std::thread producer([&](){
    SafeCout{} << "[p] Starting to produce data\n";
    {
      std::scoped_lock lock(mutex);
      data._isReady = true;
      // Sleep a bit to simulate a complicated set up phase
      std::this_thread::sleep_for(6s);
      data._isConsistent = true;
    }
    SafeCout{} << "[p] Data ready now\n";

    // Wake up all threads
    cond.notify_all();
  });

  // Join all threads, so we don't terminate prematurely
  producer.join();
  for (auto & t : consumers) {
    t.join();
  }

  return 0;
}
