#include <iostream>
#include <cassert>

void runTests();

int main() {
    runTests();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

#define ASSERT_EQUAL(expected, actual) assert((expected) == (actual))
#define ASSERT_TRUE(condition) assert(condition)
#define ASSERT_FALSE(condition) assert(!(condition))
