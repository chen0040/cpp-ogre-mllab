noinst_PROGRAMS = MapSplitter

MapSplitter_CPPFLAGS = -I$(top_srcdir)/Tools/MapSplitter/include \
		       -I$(top_srcdir)/PlugIns/PagingLandScape2/include \
		       $(OGRE_CFLAGS) -D_MAPSPLITTER
MapSplitter_LDFLAGS = $(OGRE_LIBS)



MapSplitter_SOURCES = filetutils.cpp MapBlender.cpp MapBlurrer.cpp MapHorizon2.cpp \
            MapHorizon.cpp MapInfinitizer.cpp MapLighter.cpp MapMergeModulater.cpp \
            MapNormaler.cpp MapSplatter.cpp MapSplitter.cpp MapTool.cpp MapUtil.cpp \
            MapVis.cpp MapHorizon3.cpp MapEqualizer.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeOptions.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_HeightField.cpp \
                ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_HeightFieldTC.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_HeightFieldRaw.cpp \
                ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_HeightFieldRawTC.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_HeightFieldN.cpp \
                ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_HeightFieldNTC.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2D_Spline.cpp \
            ../../../PlugIns/PagingLandScape2/src/OgrePagingLandScapeData2DManager.cpp \
            ../../../PlugIns/PagingLandScape2/src/DRGNURBSSurface.cpp

install-exec-local:
	$(INSTALL_PROGRAM) MapSplitter $(top_builddir)/Samples/Common/bin/MapSplitter

