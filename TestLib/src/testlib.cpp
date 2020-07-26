#include "include/testlib.hpp"

void TestLib::test1() {
    std::cout << this->arrayFireArray.isempty() << '\n';
}

int TestLib::addition(int a, int b) {
    return a + b;
}

void TestLib::test2() {
    std::cout << this->cvMat.dims << '\n';
}

