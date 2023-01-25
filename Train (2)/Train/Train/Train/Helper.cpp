#include "Helper.h"

#include <windows.h>
#include <gl\gl.h>
#include <cmath>

void Helper::DrawGrid()
{

	glBegin(GL_LINES);
		glColor3ub(255,0,0);
		glVertex3f(-30,0,0);
		glVertex3f(30,0,0);
		glColor3ub(0,255,0);
		glVertex3f(0,-30,0);
		glVertex3f(0,30,0);
		glColor3ub(0,0,255);
		glVertex3f(0,0,-30);
		glVertex3f(0,0,30);
	glEnd();

	for(int i=0;i<=30;i++){
			glBegin(GL_LINES);
			glColor3ub(255,255,255);
			glVertex3f(0,0,i);
			glVertex3f(30,0,i);
			glEnd();
	}
}

