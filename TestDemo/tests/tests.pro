include(../defaults.pri)
TEMPLATE = app

QT += testlib

CONFIG += c++17
QMAKE_CFLAGS_ISYSTEM=

CONFIG   += console
CONFIG   -= app_bundle

SOURCES += tst_myclasstester.cpp

unix:!macx: LIBS += -L$$OUT_PWD/../src/ -lmyapp

INCLUDEPATH += $$PWD/../src
DEPENDPATH += $$PWD/../src

