#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([datacl], [0.8], [subramonian@gmail.com])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_CONFIG_SRCDIR([src/q.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_CPP

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcurl':
AC_CHECK_LIB([curl], [curl_easy_setopt])
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [dlopen])
# FIXME: Replace `main' with a function in `-lgomp':
AC_CHECK_LIB([gomp], [main])
# FIXME: Replace `main' with a function in `-lkyotocabinet':
AC_CHECK_LIB([kyotocabinet], [main])
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [sin])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [pthread_create])
# FIXME: Replace `main' with a function in `-lsqlite3':
AC_CHECK_LIB([sqlite3], [sqlite3_open])

# Checks for header files.
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h inttypes.h limits.h malloc.h memory.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/socket.h sys/statvfs.h sys/time.h unistd.h values.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([atexit fdatasync floor ftruncate getcwd getpagesize gettimeofday isascii localtime_r memmove memset mkdir munmap pow putenv regcomp rmdir socket sqrt strcasecmp strchr strdup strerror strncasecmp strndup strrchr strstr strtol strtoull])

AC_CONFIG_FILES([approxalgos/ApproxFrequent/Makefile
                 approxalgos/ApproxQuantile/Makefile
                 approxalgos/ApproxUnique/Makefile
                 approxalgos/GPU_Work_Final2/bussAnal/filter/Makefile
                 approxalgos/GPU_Work_Final2/bussAnal/filter/backup/Makefile
                 approxalgos/GPU_Work_Final2/bussAnal/tar/filter_gpu/Makefile
                 approxalgos/GPU_Work_Final2/bussAnal/tar/filter_gpu/backup/Makefile
                 approxalgos/GPU_Work_Final2/dataScience/QGPU/Makefile
                 approxalgos/GPU_Work_Final2/dataScience/QGPU/unit_tests/datagen/Makefile
                 q-base/gpu/Makefile
                 q-base/latex/Makefile
                 q-base/src/Makefile
                 q-base/Makefile
                 qtils/Makefile
                 qtils/src/Makefile
                 src/Makefile
		 Makefile])
AC_OUTPUT
