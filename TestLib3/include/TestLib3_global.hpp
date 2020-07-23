#ifndef TESTLIB3_GLOBAL_H
#define TESTLIB3_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TESTLIB3_LIBRARY)
#  define TESTLIB3_EXPORT Q_DECL_EXPORT
#else
#  define TESTLIB3_EXPORT Q_DECL_IMPORT
#endif

#endif // TESTLIB3_GLOBAL_H
