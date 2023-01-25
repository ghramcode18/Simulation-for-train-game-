#pragma once
#include "Point.h"
#include "Shapes.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>
class Parts
{
public:
	static void labtop(Point startPoint, float distanceX,float distanceY , float distanceZ, float levelOpen,float img_keyboard,float img_hp,float img_black,float display,float statusLight);
	static void table(Point startPoint, float distanceX,float distanceY , float distanceZ,float img_wood);
	static void chair (Point startPoint, float distanceX,float distanceY , float distanceZ ,int firstImage,int secondImage);
	static void door (Point startPoint, float distanceX,float distanceY , float distanceZ, float clossDoor );
	static void projectionPanel (Point startPoint, float distanceX, float distanceY , float shutdownLevel,int display,int statusLight);
	static void chairsDistribution (int firstImage,int secondImage);
	static void Parts::controlPanel(Point startPoint, float distanceX,float distanceY , float distanceZ);
	
	static void DrowWindowXY (Point startPoint, float distanceX, float distanceY);
	static void DrowWindowZY (Point startPoint, float distanceZ, float distanceY);
	
	static void CurtainsZY (Point startPoint, float distanceZ, float distanceY,int image, float shutdownLevel);
	static void DrowCarriageWithoutDoors (Point startPoint, float distanceX, float distanceY, float distanceZ, int windowsNum , int firstImage,int secondImage,int thirdImage);
	static void DrowCarriage (Point startPoint, float distanceX, float distanceY, float distanceZ, int windowsNum , float shutdownLevel,float clossdoor1,float clossdoor2,int firstImage,int secondImage,int thirdImage);
	static void DrowCarriageWallWithWindowsZY (Point startPoint, float distanceX, float distanceY, float distanceZ, int windowsNum, float shutdownLevel, int image,int CurtainImage);
	static void DrowCarriageWallWithDoorXY (Point startPoint, float distanceX, float distanceY,int image);
	static void DrowCarriageWallWithDoorZY (Point startPoint, float distanceZ, float distanceY);



};

