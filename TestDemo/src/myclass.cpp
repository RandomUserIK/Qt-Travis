#include "myclass.hpp"

MyClass::MyClass(QObject *parent) : QObject(parent)
{

}

double MyClass::addition(double a, double b)
{
    return a + b;
}
