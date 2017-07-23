noinst_PROGRAMS = PagingLandScape2

PagingLandScape2_CPPFLAGS = -I$(top_srcdir)/Samples/PagingLandScape2/include \
			    -I$(top_srcdir)/PlugIns/PagingLandScape2/include \
			    $(OGRE_CFLAGS) $(OIS_CFLAGS) \
			    -I$(top_srcdir)/Samples/Common/include
PagingLandScape2_LDFLAGS = $(OGRE_LIBS) $(OIS_LIBS) 

PagingLandScape2_SOURCES = PagingLandScape.cpp

install-exec-local:
	$(INSTALL_PROGRAM) PagingLandScape2 $(top_builddir)/Samples/Common/bin/PagingLandScape2

