#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

public:
    explicit MyClass(QObject *parent = nullptr);
    ~MyClass() {};

    double addition(double a, double b);

signals:

};

#endif // MYCLASS_HPP
