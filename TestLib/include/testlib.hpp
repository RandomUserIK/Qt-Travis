#ifndef TESTLIB_HPP
#define TESTLIB_HPP

#include <iostream>

#include "arrayfire.h"
#include "opencv2/core.hpp"

class TestLib
{
public:
    TestLib() { };
    virtual ~TestLib() { };

    void test1();
    void test2();
    int addition(int a, int b);

private:
    af::array arrayFireArray;
    cv::Mat cvMat;
};

#endif // TESTLIB_HPP
