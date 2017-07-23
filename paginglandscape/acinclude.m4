AC_DEFUN([PLSM2_CHECK_OGRE],
[AC_ARG_WITH(ogre, 
             AC_HELP_STRING([--with-ogre=PATH],
                           [the path to OGRE.]),
             ac_cv_use_ogre=$withval,
             ac_cv_use_ogre=/usr/local)
 AC_CACHE_CHECK([the path to OGRE], ac_cv_use_ogre,
                ac_cv_use_ogre=/usr/local)
 if test x$ac_cv_use_ogre != xno; then
     OGRE_CFLAGS=`pkg-config --cflags OGRE`
     OGRE_LIBS=`pkg-config --libs OGRE`
     OGRE_PLUGINDIR=`pkg-config --variable plugindir OGRE`
 fi
 AC_SUBST(OGRE_CFLAGS)
 AC_SUBST(OGRE_LIBS)
 AC_SUBST(OGRE_PLUGINDIR)
])

AC_DEFUN([PLSM2_BUILD_DEMO], [
    AC_ARG_ENABLE(plsm2_demo,
        AC_HELP_STRING([--disable-demo], 
            [Do not build PLSM2 demo]),
            [build_plsm2_demo=$enableval], [build_plsm2_demo=yes])

    if test "x$build_plsm2_demo" = "xyes" ; then
        PKG_CHECK_MODULES(OIS, OIS >= 1.0.0, [ois_found=yes],[ois_found=no])
        AC_SUBST(OIS_CFLAGS)
        AC_SUBST(OIS_LIBS)

        if test "x$ois_found" = "xyes" ; then
           AC_MSG_NOTICE([*** PLSM2 Demo will be built ***])
        else
          build_plsm2_demo=no
          AC_MSG_NOTICE([
****************************************************************
* You do not have OIS installed.  This is required to build    *
* PLSM2 demo. You may find it at:                              *
* http://www.sourceforge.net/projects/wgois.                   *
* If you do not want to build the demos, you can safely ignore *
* this.                                                        *
****************************************************************])
        fi
    else
        build_plsm2_demo=no
        AC_MSG_NOTICE([*** Building of PLSM2 demo disabled ***])
    fi

    AM_CONDITIONAL([PLSM2_BUILDING_DEMO], [test x$build_plsm2_demo = xyes])
])

AC_DEFUN([OGRE_SETUP_FOR_TARGET],
[case $host in
*-*-cygwin* | *-*-mingw* | *-*-pw32*)
	AC_SUBST(SHARED_FLAGS, "-shared -no-undefined -Xlinker --export-all-symbols")
	AC_SUBST(PLUGIN_FLAGS, "-shared -no-undefined -avoid-version")
	AC_SUBST(GL_LIBS, "-lopengl32 -lglu32")	
	AC_CHECK_TOOL(RC, windres)
        nt=true
;;
*-*-darwin*)
        AC_SUBST(SHARED_FLAGS, "-shared")
        AC_SUBST(PLUGIN_FLAGS, "-shared -avoid-version")
        AC_SUBST(GL_LIBS, "-lGL -lGLU")
        osx=true
;;
 *) dnl default to standard linux
	AC_SUBST(SHARED_FLAGS, "-shared")
	AC_SUBST(PLUGIN_FLAGS, "-shared -avoid-version")
	AC_SUBST(GL_LIBS, "-lGL -lGLU")
        linux=true
;;
esac
dnl you must arrange for every AM_conditional to run every time configure runs
AM_CONDITIONAL(OGRE_NT, test x$nt = xtrue)
AM_CONDITIONAL(OGRE_LINUX, test x$linux = xtrue)
AM_CONDITIONAL(OGRE_OSX,test x$osx = xtrue )
])
