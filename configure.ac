AC_INIT([abduction], [0.0.1], [bugs@skedars.com], [dev], [https://github.com/Bigorneau/abduction/])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_PROG_CC
AC_CONFIG_HEADER([config.h])

AC_DEFINE_UNQUOTED([CHANGESET], ["`git rev-parse --verify HEAD`"], [git revision])

PKG_CHECK_MODULES([SDL2], [sdl2])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
