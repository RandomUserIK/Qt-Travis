include(../defaults.pri)

CONFIG += c++17
QMAKE_CFLAGS_ISYSTEM=


TARGET = myapp
TEMPLATE = lib

SOURCES += \
    myclass.cpp

HEADERS += \
    myclass.hpp

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

DISTFILES += \
    defaults.pri
