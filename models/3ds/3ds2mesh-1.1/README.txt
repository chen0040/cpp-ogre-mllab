3ds2mesh - converter from 3D Studio file to Ogre3D .mesh/.material

The purpose of 3ds2mesh is to get Ogre3D mesh from .3ds files

Ogre is an object oriented graphics rendering engine. See http://www.ogre3d.org/ for more information.

As a do not have enough .3ds files to fully test my converter, if you encounter any problem please contact
me.

The sources can be obtained from ogre cvs add-ons repository.

To compile it under windows :

1) if you have the OgreSDK installed
- set the OGRE_HOME environment variable to the path of your OgreSDK (c:\OgreSDK)
- add %OGRE_HOME%\bin\release;%OGRE_HOME%\bin\debug to your PATH

2) if you want to use the OGRE sources to compile 3ds2mesh
- set the OGRE_SRC environment variable to the path of your source installation
- add (at the beginning) to your PATH : 
%OGRE_SRC%\samples\common\bin\debug;%OGRE_SRC%\samples\common\bin\release

Then you will just have to load 3ds2mesh.sln in VC++ 7.1 (.NET 2003) and generate solution. It will generate
bin\debug\3ds2mesh.exe
bin\release\3ds2mesh.exe

To compile it under linux :
1) set the OGRE_HOME environment variable to the path of your OgreSDK
setenv OGRE_HOME /usr/local/OGRE
export OGRE_HOME=/usr/local/OGRE

2) compile the sources
make
the executable will be produced in the src directory

Supported platform: at the current time, only tested with VC++ 7.1 (.NET 2003) and linux

--
David Geldreich <david.geldreich@free.fr>
