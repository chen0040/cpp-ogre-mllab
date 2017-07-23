noinst_PROGRAMS = MapEditor

MapEditor_CPPFLAGS = -I$(top_srcdir)/Samples/MapEditor/include $(OGRE_CFLAGS) \
		     -I$(top_srcdir)/Samples/Common/include
MapEditor_LDFLAGS = $(OGRE_LIBS)


MapEditor_SOURCES = MapEditor.cpp ActionBar.cpp FogEditor.cpp Line3D.cpp \
                    main.cpp MapEditor.cpp MapEditorListener.cpp \
		    MorphWindow.cpp ObjectWindow.cpp TabWindow.cpp \
		    TextureWindow.cpp

install-exec-local:
	$(INSTALL_PROGRAM) .libs/MapEditor $(top_builddir)/Samples/Common/bin/MapEditor
