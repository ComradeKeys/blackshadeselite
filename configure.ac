#AUTOCONF REQUIREMENTS
AC_INIT([blackshades], [0.9], [bkeys@bkeys.org], [blackshades], [http://www.bkeys.org])

#AUTOCONF MINIMUM VERSION NUMBER
AC_PREREQ(2.68)

#Require this file to exist
AC_CONFIG_SRCDIR([src/Main.cpp])

#PUT CONFIGURATION HERE IN A HEADER FILE THAT WILL BE #INCLUDED
AC_CONFIG_HEADERS([src/config.h])

#using an m4 directory
AC_CONFIG_MACRO_DIR([m4])

#checking for freeglut
AC_CHECK_LIB([GL], [glBegin])
AC_CHECK_LIB([glut], [glutInit])
AC_CHECK_LIB([GLU], [gluPerspective])
AC_CHECK_LIB([SDL], [SDL_Init])
AC_CHECK_LIB([openal], [alSourcei])
AC_CHECK_LIB([alut], [alutInit])
AC_CHECK_LIB([vorbisfile], [ov_open])


#put autoconf files in it's own directory
AC_CONFIG_AUX_DIR(build-aux)

#ENABLE AUTOMAKE TO SIMPLIFY MAKEFILES
AM_INIT_AUTOMAKE([1.11 subdir-objects -Wall -Werror])

AC_CONFIG_FILES(Makefile)

AC_PROG_CXX

#FINAL OUTPUT
AC_OUTPUT
