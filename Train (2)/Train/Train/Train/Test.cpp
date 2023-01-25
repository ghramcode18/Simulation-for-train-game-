#include "Test.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>

void Test::DrawFace(Point leftDownPoint, Point rightUpPoint)
{
	glBegin(GL_QUADS);
	glVertex3f(leftDownPoint.x, leftDownPoint.y, leftDownPoint.z);
	glVertex3f(rightUpPoint.x, leftDownPoint.y, leftDownPoint.z);
	glVertex3f(rightUpPoint.x, rightUpPoint.y, rightUpPoint.z);
	glVertex3f(leftDownPoint.x, rightUpPoint.y, leftDownPoint.z);
	glEnd();
}
