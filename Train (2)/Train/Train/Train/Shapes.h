#pragma once
#include "Point.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>
class Shapes
{
public:
	static void DrowSquareXY(Point startPoint, float distanceX, float distanceY);
	static void DrowSquareZY(Point startPoint, float distanceZ, float distanceY);
	static void DrowSquareXZ(Point startPoint, float distanceX, float distanceZ);

	static void DrowSquareWithTextureXY(Point startPoint, float distanceX, float distanceY, int image, int RepeatX, int RepeatY);
	static void DrowSquareWithTextureZY(Point startPoint, float distanceZ, float distanceY, int image, int RepeatZ, int RepeatY);
	static void DrowSquareWithTextureXZ(Point startPoint, float distanceX, float distanceZ, int image, int RepeatX, int RepeatZ);

	static void DrowBox(Point startPoint, float distanceX, float distanceY, float distanceZ);
	static void DrowBoxWithTexture(Point startPoint, float distanceX,
		float distanceY, float distanceZ, int startImageXY,
		int endImageXY, int startImageZY, int endImageZY, int startImageXZ, int endImageXZ, int RepeatX, int RepeatY);
	static void DrowBoxWithTexture(Point startPoint, float distanceX,float distanceY, float distanceZ, int Image, int RepeatX, int RepeatY);
	static void Shapes::DrowColorfulCircle(Point center, float radius);
	static void Shapes::DrawCircle(Point center, float radius);
	static void Shapes::DrawArc(Point center, float radius, float startAngle, float endAngle);
};

