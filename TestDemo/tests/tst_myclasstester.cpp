#include <QtTest/QtTest>
#include "myclass.hpp"

// add necessary includes here

class MyClassTester : public QObject
{
    Q_OBJECT

public:
    MyClassTester();
    ~MyClassTester() {};

private slots:
    void test_case1();

private:
    MyClass myclass;

};

MyClassTester::MyClassTester()
{

}

void MyClassTester::test_case1()
{
    QVERIFY(5 + 5 == myclass.addition(5, 5));
}

QTEST_APPLESS_MAIN(MyClassTester)

#include "tst_myclasstester.moc"
