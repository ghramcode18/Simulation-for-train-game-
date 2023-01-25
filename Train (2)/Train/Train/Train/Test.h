#pragma once
#include "Point.h"
class Test
{
public:
	static void DrawLine(Point startPoint, Point endPoint);
	static void DrawFace(Point leftDownPoint, Point rightUpPoint);
	static void DrawCube(Point startPoint, Point endPoint);
};

