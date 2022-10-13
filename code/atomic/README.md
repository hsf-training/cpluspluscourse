
## Instructions

You know this program already from "racing".
It tries to increment an integer 200 times in two threads.
Last time, we fixed the race condition using a lock, but now we'll try atomics.

Tasks:
- Replace the counter 'a' by an atomic.
  Run the program, and check for race conditions.
- Go back to 'racing', and check the execution time of the atomic vs the lock solution,
  e.g. using `time ./atomic`
  You might have to increase the number of tries if it completes too fast.
