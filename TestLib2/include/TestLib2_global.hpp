#ifndef TESTLIB2_GLOBAL_H
#define TESTLIB2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTLIB2_LIBRARY)
#  define TESTLIB2_EXPORT Q_DECL_EXPORT
#else
#  define TESTLIB2_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTLIB2_GLOBAL_H
