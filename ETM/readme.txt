EDITABLE TERRAIN MANAGER
==========================

created 2007 by Holger Frydrych
Find it at: http://www.oddbeat.de

The Editable Terrain Manager is an addon library for OGRE which manages and displays terrain based on heightmap data. It can be used as a replacement for the Terrain Scene Manager, but its main advantage is the edit possibility for the terrain: You can deform and set the terrain heights in real time, as you would need to if you are developing an editor application. In addition, the library also has means to support editable splatting, probably the current standard for detailed terrain texturing.

All of the parts have been designed to be as flexible as possible and do not even depend upon each other. That means you don’t need to use splatting if you don’t want to - or you can use that part with a different terrain renderer. Unlike OGRE’s TSM, it’s not a scene manager, either, so you could (in theory) choose whatever scene manager you like. All its headers are light-weight, using the PIMPL idiom to hide costly implementation details.


LICENSE: 
See license.txt

DOCUMENTATION: 
See doc/html/index.html. There's also a demo application in Sample that you should check out.

INSTALLATION:
Open the Visual C++ project file or the CodeBlocks workspace (for GCC/mingw). Under Linux, you can also simply type "make" to create the library.
