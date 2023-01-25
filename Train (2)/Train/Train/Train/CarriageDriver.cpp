#include "CarriageDriver.h"
#define push glPushMatrix
#define pop glPopMatrix
GLUquadric *quadricD =  gluNewQuadric();


void CarriageDriver::DrowCarriage(int firstImage,int secondImage,int thirdImage)
{
	//Parts::DrowCarriageWithoutDoors(Point(0,0,-250.0f),70.0f,70.0f,-150.0f,0,firstImage,secondImage,thirdImage);
	//Shapes::DrowBoxWithTexture(Point(0,70,-400.0f),70.0f,1.0f,-20.0f,secondImage,1,1);
	
	//top
	Shapes::DrowBoxWithTexture(Point(0,70,-250.0f),70.0f,1.0f,-170.0f,secondImage,1,1);
	//buttom
	Shapes::DrowBoxWithTexture(Point(0,0,-250.0f),70.0f,1.0f,-170.0f,secondImage,1,1);
	//left
	Shapes::DrowBoxWithTexture(Point(0,0,-250.0f),1.0f,70.0f,-90.0f,secondImage,1,1);
	Shapes::DrowBoxWithTexture(Point(0,50,-340.0f),1.0f,20.0f,-35.0f,secondImage,1,1);
	Shapes::DrowBoxWithTexture(Point(0,0,-340.0f),1.0f,50.0f,-35.0f,firstImage,1,1);//door
	Shapes::DrowBoxWithTexture(Point(0,0,-365.0f),1.0f,70.0f,-35.0f,secondImage,1,1);
	//right
	Shapes::DrowBoxWithTexture(Point(70,0,-250.0f),1.0f,70.0f,-90.0f,secondImage,1,1);
	Shapes::DrowBoxWithTexture(Point(70,50,-340.0f),1.0f,20.0f,-35.0f,secondImage,1,1);
	Shapes::DrowBoxWithTexture(Point(70,0,-340.0f),1.0f,50.0f,-35.0f,firstImage,1,1);//door
	Shapes::DrowBoxWithTexture(Point(70,0,-365.0f),1.0f,70.0f,-35.0f,secondImage,1,1);

	glPushMatrix();
		glTranslated(0,0,-400);
		glRotated(30,0,1,0);
		Shapes::DrowBoxWithTexture(Point(0,0,0),25.0f,30.0f,1.0f,firstImage,1,1);
		//left
		Shapes::DrowBoxWithTexture(Point(0,0,0),5.0f,70.0f,1.0f,firstImage,1,1);
			glPushMatrix();
				glTranslated(5,30,0);
				Parts::DrowWindowXY(Point(0,0,0),20,40);
			glPopMatrix();
		glTranslated(20,0,0);
		Shapes::DrowBoxWithTexture(Point(0,0,0),5.0f,70.0f,1.0f,firstImage,1,1);

	glPopMatrix();

	glPushMatrix();
		glTranslated(70,0,-400);
		glRotated(150,0,1,0);
		Shapes::DrowBoxWithTexture(Point(0,0,0),25.0f,30.0f,1.0f,firstImage,1,1);
		//right 
		Shapes::DrowBoxWithTexture(Point(0,0,0),5.0f,70.0f,1.0f,firstImage,1,1);
			glPushMatrix();
				glTranslated(5,30,0);
				Parts::DrowWindowXY(Point(0,0,0),20,40);
			glPopMatrix();
		glTranslated(20,0,0);
		Shapes::DrowBoxWithTexture(Point(0,0,0),5.0f,70.0f,1.0f,firstImage,1,1);

	glPopMatrix();

	glPushMatrix();
		glTranslated(22,0,-412);
		//glRotated(90,0,1,0);
		Shapes::DrowBoxWithTexture(Point(0,0,0),27.0f,30.0f,1.0f,firstImage,1,1);
		glPushMatrix();
			glTranslated(0,30,0);
			Parts::DrowWindowXY(Point(0,0,0),27,40);
		glPopMatrix();
	glPopMatrix();

	push();
	glTranslated(20,10,-350.0f);
	glScaled(2,2,2);
	CarriageDriver::Chair();
	glTranslated(15,0,0);
	CarriageDriver::Chair();
	pop();

	push();
	glTranslated(0,20,-370.0f);
	CarriageDriver::BoardDriver();

	pop();
}


void CarriageDriver::Chair(){

	
	push();
		glColor3ub(20,20,20);
		glRotated(90,1,0,0);
		gluCylinder(quadricD, 2, 3, 4, 32, 70);
	pop();
	push();
		glColor3ub(30,30,30);
		Shapes::DrowBox(Point(-5,0,-5),10.0f,1.0f,10.0f);
		Shapes::DrowBox(Point(-5,0,5),10.0f,15.0f,1.0f);
		push();
			glTranslated(4,2,-5);
			glColor3ub(20,20,20);
			gluCylinder(quadricD, 1, 1, 10, 32, 70);
			gluDisk(quadricD, 0, 1, 32, 32);
			glTranslated(0,2,0);
			gluCylinder(quadricD, 1, 1, 10, 32, 70);
			gluDisk(quadricD, 0, 1, 32, 32);
		pop();
		push();
			glTranslated(-4,2,-5);
			glColor3ub(20,20,20);
			gluCylinder(quadricD, 1, 1, 10, 32, 70);
			gluDisk(quadricD, 0, 1, 32, 32);
			glTranslated(0,2,0);
			gluCylinder(quadricD, 1, 1, 10, 32, 70);
			gluDisk(quadricD, 0, 1, 32, 32);
		pop();
	pop();
	
}

void CarriageDriver::BoardDriver(){
	Shapes::DrowBox(Point(0,0,0),70.0f,2.0f,-30.0f);
	Shapes::DrowBox(Point(0,0,0),70.0f,-20.0f,-2.0f);
	for (int i = 0; i < 4; i++)
	{
		push();
			glTranslated(i*3+5,6,-5);
			//glRotated(10*i,1,0,0);
			push();
				glColor3ub(120,120,120);
				glRotated(90,1,0,0);
				gluCylinder(quadricD, 0.7, 0.7, 4, 32, 70);
				glColor3ub(120,0,0);
				gluSphere(quadricD, 1.2, 32, 32);
			pop();
		pop();
	}
	push();
		push();
			glTranslated(7,0,-10);
			glColor4f(0.9f,0.9f,0.9f,0.2f);
			push();
				glRotated(70,1,0,0);
				glTranslated(0,2,0);
				Shapes::DrowBox(Point(0,0,0),5.0f,2.0f,-5.0f);
			pop();
			glTranslated(3,3,-3);
			push();
				glRotated(90,1,0,0);
				glColor3ub(120,0,0);
				gluCylinder(quadricD, 2, 2, 3, 32, 70);
				gluDisk(quadricD, 0, 2, 32, 32);
			pop();
		pop();
		glTranslated(10,0,0);
		push();
			glTranslated(7,0,-10);
			glColor4f(0.9f,0.9f,0.9f,0.2f);
			push();
			glRotated(70,1,0,0);
			glTranslated(0,2,0);
			Shapes::DrowBox(Point(0,0,0),5.0f,2.0f,-5.0f);
			pop();
			glTranslated(3,3,-3);
			push();
				glRotated(90,1,0,0);
				glColor3ub(0,120,0);
				gluCylinder(quadricD, 2, 2, 3, 32, 70);
				gluDisk(quadricD, 0, 2, 32, 32);
			pop();
		pop();

		push();
			glTranslated(20,6,-2);
			push();
				glColor3ub(120,120,120);
				glRotated(90,1,0,0);
				gluCylinder(quadricD, 0.5, 0.5, 4, 32, 70);
			pop();
			push();
			glColor3ub(0,0,0);
			glRotated(90,0,1,0);
			gluCylinder(quadricD, 0.7, 0.7, 4, 32, 70);
			pop();

			push();
				glTranslated(4,0,0);
				glColor3ub(120,120,120);
				glRotated(90,1,0,0);
				gluCylinder(quadricD, 0.5, 0.5, 4, 32, 70);
			pop();
		pop();
		glTranslated(0,0,-10);
		push();
			glTranslated(20,6,-2);
			push();
				glColor3ub(120,120,120);
				glRotated(90,1,0,0);
				gluCylinder(quadricD, 0.5, 0.5, 4, 32, 70);
			pop();
			push();
			glColor3ub(0,0,0);
			glRotated(90,0,1,0);
			gluCylinder(quadricD, 0.7, 0.7, 4, 32, 70);
			pop();

			push();
				glTranslated(4,0,0);
				glColor3ub(120,120,120);
				glRotated(90,1,0,0);
				gluCylinder(quadricD, 0.5, 0.5, 4, 32, 70);
			pop();
		pop();
	pop();


}
