#pragma once
#include "Point.h"
class Collider
{
public:
	static int checkHitSphier(Point camera,Point P,int partNum);
	static int myPosition(Point position);
	static bool SquareInCollider(float minX,float minZ,float maxX,float maxZ,Point camera);
	static bool SquareOutCollider(float minX,float minZ,float maxX,float maxZ,Point camera);
	static bool chairsCollider(Point camera);
	static bool wallsCollider(Point camera);
	
};

