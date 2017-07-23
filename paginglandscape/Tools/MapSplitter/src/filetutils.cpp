/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as        *
*   published by the Free Software Foundation; either version 2 of the    *
*   License, or (at your option) any later version.                       *
*                                                                         *
***************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>

#ifdef _WIN32
#   include <windows.h>
#   include <direct.h>
#   include <io.h>

#   define S_ISDIR(mode) (mode&S_IFDIR)
#   define STRUCT_STAT  struct _stat
#   define CHDIR        _chdir
#   define GETCWD       _getcwd
#   define MKDIR(A)     _mkdir(A)
#   define STAT(A,S)    _stat(A,S)

#if _MSC_VER >= 1400
#	define STRNCPY(A, ASIZE, O, I) strncpy_s(A, ASIZE, O, I)
#else
#	define STRNCPY(A, ASIZE, O, I) strncpy(A, O, I)
#endif

#else //_LINUX _APPLE

#ifdef _APPLE
#   include <malloc/malloc.h>
#else 
#   include <malloc.h>	
#endif

#   include <unistd.h>
#   include <sys/param.h>

#   define MAX_PATH MAXPATHLEN
#   define STRUCT_STAT  struct stat
#   define CHDIR        chdir
#   define GETCWD       getcwd
#   define MKDIR(A)     mkdir(A, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)// set mode of directory to drwxr-xr-x.
#   define STAT(A,S)    stat(A,S)

#	define STRNCPY(A, ASIZE, O, I) strncpy(A, O, I)

#endif  //_LINUX _APPLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutils.h"

//-----------------------------------------------------------------------
static void error_directory(char *Dirname)
{
	printf( "OutDirectory cannot be created");
	exit(1);
}
//-----------------------------------------------------------------------
static char* GetCurrDir()
{
    // GETCWD MALLOCS A BUFFER. REMEMBER TO FREE IT.
    return GETCWD(0,0);;
}
//-----------------------------------------------------------------------
static void RecurseMakeDir (const char *outputdir)
{
	// make output directory
	const size_t len = strlen (outputdir);
	char *Dirname = new char [len + 1]; 
	size_t index = 0;
#ifdef _WIN32
    // handle Different windows disk name (c: d: e: , etc...)
    if (len > 2 && outputdir[1] == ':')
    {
        index += 2;
    }
#endif //_WIN32
    while (index++ < len)
	{
		if (index > 0 && 
			((outputdir[index] == '/') || (outputdir[index] == '\\')))
		{
			STRNCPY (Dirname, len + 1, outputdir, index);
			Dirname[index] = 0;
			if (!DirExists(Dirname))
			{
				const int status = MKDIR (Dirname); // build each subdirectory recursively if needed
				if (status != 0) 
					error_directory(Dirname);
			}
		} 
	}
	index = len - 1;
	if (!((outputdir[index] == '/') || (outputdir[index] == '\\')))
	{
		if (!DirExists(outputdir))
		{
			const int status = MKDIR (outputdir); // final directory may not have the final slash
			if (status != 0) 
				error_directory(Dirname);
		}
	}
	delete [] Dirname;
}
//-----------------------------------------------------------------------
bool DirExists(const char *Dirname)
{
    STRUCT_STAT st;

    if (STAT(Dirname, &st))
    {
        // doesn't exist; must create it
        return false;
    }
    if (S_ISDIR(st.st_mode) == 0) 
    {
        // it's not a dir, must create a dir        
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------
char * ChangeToDir (const char *Dirname)
{
   if (!DirExists(Dirname))
		RecurseMakeDir (Dirname);
		
    char *oldDirname = GetCurrDir ();
    CHDIR(Dirname);
    return oldDirname;
}
//-----------------------------------------------------------------------
void RetablishDir(char *oldDirname)
{
    if (oldDirname != NULL) 
     {
        ChangeToDir (oldDirname);
        // FREE MALLOC'ED GETCWD BUFFER.
        free (oldDirname);
    }
}
