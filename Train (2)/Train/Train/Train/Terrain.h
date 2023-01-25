#pragma once
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "Shapes.h"
class Terrain
{
public:
	static void drawMyTerrain(int terrainWidth,int terrainDepth,int terrainTexture,double texSStep,double texTStep,GLubyte* heightData);
};

