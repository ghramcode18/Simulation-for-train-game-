#include "Shapes.h"



void Shapes::DrowSquareXY(Point startPoint, float distanceX, float distanceY)
{
	glBegin(GL_POLYGON);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z);
		glVertex3f(startPoint.x + distanceX,startPoint.y,startPoint.z);
		glVertex3f(startPoint.x + distanceX,startPoint.y + distanceY,startPoint.z);
		glVertex3f(startPoint.x,startPoint.y + distanceY,startPoint.z);
	glEnd();

}

void Shapes::DrowSquareZY(Point startPoint, float distanceZ, float distanceY)
{
	glBegin(GL_POLYGON);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z + distanceZ);
		glVertex3f(startPoint.x,startPoint.y + distanceY,startPoint.z + distanceZ);
		glVertex3f(startPoint.x,startPoint.y + distanceY,startPoint.z);
	glEnd();

}

void Shapes::DrowSquareXZ(Point startPoint, float distanceX, float distanceZ)
{
	glBegin(GL_POLYGON);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z);
		glVertex3f(startPoint.x + distanceX,startPoint.y,startPoint.z);
		glVertex3f(startPoint.x + distanceX,startPoint.y,startPoint.z + distanceZ);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z + distanceZ);
	glEnd();

}

void Shapes::DrowSquareWithTextureXY(Point startPoint, float distanceX, float distanceY, int image, int RepeatX, int RepeatY)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z);
		glTexCoord2d(RepeatX, 0);
		glVertex3f(startPoint.x + distanceX,startPoint.y,startPoint.z);
		glTexCoord2d(RepeatX, RepeatY);
		glVertex3f(startPoint.x + distanceX,startPoint.y + distanceY,startPoint.z);
		glTexCoord2d(0, RepeatY);
		glVertex3f(startPoint.x,startPoint.y + distanceY,startPoint.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Shapes::DrowSquareWithTextureZY(Point startPoint, float distanceZ, float distanceY, int image, int RepeatZ, int RepeatY)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z);
		glTexCoord2d(RepeatZ, 0);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z + distanceZ);
		glTexCoord2d(RepeatZ, RepeatY);
		glVertex3f(startPoint.x,startPoint.y + distanceY,startPoint.z + distanceZ);
		glTexCoord2d(0, RepeatY);
		glVertex3f(startPoint.x,startPoint.y + distanceY,startPoint.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Shapes::DrowSquareWithTextureXZ(Point startPoint, float distanceX, float distanceZ, int image, int RepeatX, int RepeatZ)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z);
		glTexCoord2d(RepeatZ, 0);
		glVertex3f(startPoint.x,startPoint.y,startPoint.z + distanceZ);
		glTexCoord2d(RepeatZ, RepeatX);
		glVertex3f(startPoint.x + distanceX,startPoint.y,startPoint.z + distanceZ);
		glTexCoord2d(0, RepeatX);
		glVertex3f(startPoint.x + distanceX,startPoint.y,startPoint.z);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void Shapes::DrowBox(Point startPoint, float distanceX, float distanceY, float distanceZ)
{
	//glNormal3f(-1.0f, 0.0f, 0.0f);
	Shapes::DrowSquareXY(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceY);
	//glNormal3f(1.0f, 0.0f, 0.0f);
	Shapes::DrowSquareXY(Point(startPoint.x,startPoint.y,startPoint.z + distanceZ),distanceX,distanceY);
	//glNormal3f(0.0f, 0.0f, 1.0f);
	Shapes::DrowSquareZY(Point(startPoint.x,startPoint.y,startPoint.z),distanceZ,distanceY);
	//glNormal3f(0.0f, 0.0f, -1.0f);
	Shapes::DrowSquareZY(Point(startPoint.x + distanceX,startPoint.y,startPoint.z),distanceZ,distanceY);
	//glNormal3f(0.0f, -1.0f, 0.0f);
	Shapes::DrowSquareXZ(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceZ);
	//glNormal3f(0.0f, 1.0f, 0.0f);
	Shapes::DrowSquareXZ(Point(startPoint.x,startPoint.y + distanceY,startPoint.z),distanceX,distanceZ);
}

void Shapes::DrowBoxWithTexture(Point startPoint, float distanceX,
		float distanceY, float distanceZ, int startImageXY,
		int endImageXY, int startImageZY, int endImageZY, int startImageXZ, int endImageXZ, int RepeatX, int RepeatY)
{
	
	glEnable(GL_TEXTURE_2D);
	
	Shapes::DrowSquareWithTextureXY(Point(startPoint.x,startPoint.y,startPoint.z), distanceX, distanceY, startImageXY, RepeatX, RepeatY);
	//glNormal3f(0.0f, 0.0f, 0.0f);
	Shapes::DrowSquareWithTextureXY(Point(startPoint.x,startPoint.y,startPoint.z  + distanceZ), distanceX, distanceY, endImageXY, RepeatX, RepeatY);
	//glNormal3f(0.0f, 0.0f, 0.0f);
	Shapes::DrowSquareWithTextureZY(Point(startPoint.x,startPoint.y,startPoint.z),distanceZ,distanceY, startImageZY, RepeatX, RepeatY);
	//glNormal3f(0.0f, 0.0f, 0.0f);
	Shapes::DrowSquareWithTextureZY(Point(startPoint.x + distanceX,startPoint.y,startPoint.z),distanceZ,distanceY, endImageZY, RepeatX, RepeatY);
	//glNormal3f(0.0f, 0.0f, 0.0f);
	Shapes::DrowSquareWithTextureXZ(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceZ, startImageXZ, RepeatX, RepeatY);
	//glNormal3f(0.0f, 0.0f, 0.0f);
	Shapes::DrowSquareWithTextureXZ(Point(startPoint.x,startPoint.y + distanceY,startPoint.z),distanceX,distanceZ, endImageXZ, RepeatX, RepeatY);
	glDisable(GL_TEXTURE_2D);
}

void Shapes::DrowBoxWithTexture(Point startPoint, float distanceX,
		float distanceY, float distanceZ, int Image, int RepeatX, int RepeatY)
{
	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);
	Shapes::DrowSquareWithTextureXY(Point(startPoint.x,startPoint.y,startPoint.z), distanceX, distanceY, Image, RepeatX, RepeatY);
	Shapes::DrowSquareWithTextureXY(Point(startPoint.x,startPoint.y,startPoint.z  + distanceZ), distanceX, distanceY, Image, RepeatX, RepeatY);

	Shapes::DrowSquareWithTextureZY(Point(startPoint.x,startPoint.y,startPoint.z),distanceZ,distanceY, Image, RepeatX, RepeatY);
	Shapes::DrowSquareWithTextureZY(Point(startPoint.x + distanceX,startPoint.y,startPoint.z),distanceZ,distanceY, Image, RepeatX, RepeatY);

	Shapes::DrowSquareWithTextureXZ(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceZ, Image, RepeatX, RepeatY);
	Shapes::DrowSquareWithTextureXZ(Point(startPoint.x,startPoint.y + distanceY,startPoint.z),distanceX,distanceZ, Image, RepeatX, RepeatY);
	glDisable(GL_TEXTURE_2D);
}

void Shapes::DrowColorfulCircle(Point center, float radius)
{
	int steps = 360;
	float theta = 0;
	float depth = center.z;
	glBegin(GL_TRIANGLES);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + radius * cos(theta);
		float y = center.y + radius * sin(theta);
		glVertex3f(x, y, depth);
		theta = theta + .5;
		x = center.x + radius * cos(theta);
		y = center.y + radius * sin(theta);
		glVertex3f(x, y, depth);
		glVertex3f(center.x, center.y, depth);
		theta = theta + .5;
	}
	glEnd();
}

void Shapes::DrawCircle(Point center, float radius)
{
	int steps = 360;
	float theta = 0;
	glBegin(GL_POINTS);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + radius * cos(theta);
		float y = center.y + radius * sin(theta);
		glVertex3f(x, y, center.z);
		theta = theta + .5;
		x = center.x + radius * cos(theta);
		y = center.y + radius * sin(theta);
		glVertex3f(x, y, center.z);
		theta = theta + .5;
	}
	glEnd();
}

void Shapes::DrawArc(Point center, float radius, float startAngle, float endAngle)
{
	if (startAngle > endAngle)
	{
		float temp = startAngle;
		startAngle = endAngle;
		endAngle = temp;
	}
	float theta = startAngle;
	glBegin(GL_POINTS);
	for (; theta <= endAngle; theta = theta + .5)
	{
		float x = center.x + radius * cos(theta * 3.14 / 180);
		float y = center.y + radius * sin(theta * 3.14 / 180);
		glVertex3f(x, y, center.z);
	}
	glEnd();
}