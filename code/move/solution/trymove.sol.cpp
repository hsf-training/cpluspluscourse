#include <memory>
#include <random>
#include <vector>

/**
 * An attempt to make a movable class. It allocates memory on construction, and has
 * array semantics. (Prefer std::array or std::vector instead of hand-crafted solutions, though.)
 * We made it copyable by providing copy constructor and assignment operator, but note that we
 * are violating the rule of 5, so it's not moveable yet.
*/
class CustomArray {
    static constexpr std::size_t size = 10000;

public:
    CustomArray() = default;
    CustomArray(CustomArray const & other)
    {
        // Delegate copying to the assignment operator
        *this = other;
    }
    CustomArray & operator=(const CustomArray & other)
    {
        // We don't do anything when asked to self assign
        if (this == &other) return *this;

        std::copy(other.m_storage.get(), other.m_storage.get() + size, m_storage.get());
        return *this;
    }

    // *******
    // Task 1: Provide move constructor and move assignment operator.
    // Remember from the lectures that you can use the copy and swap
    // idiom.
    // *******

    // Step 1: declare a swap function as hidden friend
    friend void swap(CustomArray & a, CustomArray & b) noexcept
    {
        auto tempStorage{ std::move(a.m_storage) };
        a.m_storage = std::move(b.m_storage);
        b.m_storage = std::move(tempStorage);
    }

    // Step 2: implement move constructor and move assignment using swap
    CustomArray(CustomArray && other) noexcept :
        m_storage{ nullptr } // This avoids the initial allocation
    {
        swap(*this, other);
    }
    CustomArray & operator=(CustomArray && other) noexcept
    {
        // Protect against self assignment
        if (this == &other) return *this;

        swap(*this, other);
        return *this;
    }

    int & operator[](std::size_t index) { return m_storage[index]; }

private:
    std::unique_ptr<int[]> m_storage { std::make_unique<int[]>(size) };
};

/**
 * A function to randomly swap entries.
 * Unfortunately, it needs three copies to execute each swap.
*/
void randomiseOrder(std::vector<CustomArray> & v) {
    // we randomise by applying 10*len random swaps
    const auto len = v.size();
    std::default_random_engine e;
    std::uniform_int_distribution<std::size_t> randomIntDistr{0, len-1};

    auto swapEntries = [&v](std::size_t i, std::size_t j)
    {
        // *******
        // Task 2: Use move instead of copy to speed up the swap.
        // Test that you are moving by measuring the speed of the program.
        // *******

        // Option 1:
        // We use the move constructor for temp, and move assign into v[i], v[j]:
        // CustomArray temp{ std::move(v[i]) };
        // v[i] = std::move(v[j]);
        // v[j] = std::move(temp);

        // Option 2: swap!
        swap(v[i], v[j]);
    };

    for (std::size_t i = 0; i < 10*len; i++) {
        const std::size_t m = randomIntDistr(e);
        const std::size_t n = randomIntDistr(e);
        swapEntries(m, n);
    }
}

int main() {
    // Create a lot of movables
    std::vector<CustomArray> vec(10000);
    randomiseOrder(vec);

    return 0;
}
