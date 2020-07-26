#ifndef TESTLIB_HPP
#define TESTLIB_HPP

#include "include/TestLib_global.hpp"

#include <iostream>

#include <QObject>
#include <QDebug>
#include <QVector>
#include <QMap>
#include <QElapsedTimer>
#include <QDir>
#include <QString>
#include <QFileInfo>
#include <QListIterator>
#include <QVectorIterator>
#include <QImage>
#include <QThread>

#include "af/array.h"
#include "arrayfire.h"
#include "opencv4/opencv2/core.hpp"

class TESTLIB_EXPORT TestLib
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
