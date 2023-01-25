#include "Parts.h"


void Parts::DrowWindowXY (Point startPoint, float distanceX, float distanceY)
{
	glColor4f(0.9f,0.9f,0.9f,0.2f);
	Shapes::DrowSquareXY(startPoint,distanceX,2*distanceY/3);
	glColor4f(0.3f,0.3f,0.3f,1.0f);
	Shapes::DrowSquareXY(Point(startPoint.x,startPoint.y + 2*distanceY/3 ,startPoint.z),distanceX,distanceY/20);
	glColor4f(0.9f,0.9f,0.9f,0.2f);
	Shapes::DrowSquareXY(Point(startPoint.x,startPoint.y + 2*distanceY/3 ,startPoint.z),distanceX,distanceY/3);
}

void Parts::DrowWindowZY (Point startPoint, float distanceZ, float distanceY)
{

	glColor4f(0.9f,0.9f,0.9f,0.2f);
	Shapes::DrowSquareZY(startPoint,distanceZ,2*distanceY/3);
	glColor4f(0.3f,0.3f,0.3f,1.0f);
	Shapes::DrowSquareZY(Point(startPoint.x,startPoint.y + 2*distanceY/3 ,startPoint.z),distanceZ,distanceY/20);
	glColor4f(0.9f,0.9f,0.9f,0.2f);
	Shapes::DrowSquareZY(Point(startPoint.x,startPoint.y + 2*distanceY/3 ,startPoint.z),distanceZ,distanceY/3);

}

void Parts::DrowCarriageWallWithWindowsZY (Point startPoint, float distanceX, float distanceY, float distanceZ , int windowsNum, float shutdownLevel, int image,int CurtainImage)
{
	

	Shapes::DrowBoxWithTexture(startPoint,distanceX,distanceY/3,distanceZ,image,10,1);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y + distanceY/3 ,startPoint.z),distanceX,distanceY/3,distanceZ/(windowsNum*2+1),image,1,1);
	for(int i =1 ; i<(windowsNum*2+1) ;i++){
		Parts::DrowWindowZY(Point(startPoint.x,startPoint.y + distanceY/3 ,startPoint.z + (i*distanceZ/(windowsNum*2+1))),distanceZ/(windowsNum*2+1),distanceY/3);
		Parts::CurtainsZY ( Point(startPoint.x ,startPoint.y + distanceY/3 ,startPoint.z + (i*distanceZ/(windowsNum*2+1))), distanceZ/(windowsNum*2+1),  distanceY/3,CurtainImage,shutdownLevel);
		i++;
		
		Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y + distanceY/3 ,startPoint.z + (i*distanceZ/(windowsNum*2+1))),distanceX,distanceY/3,distanceZ/(windowsNum*2+1),image,1,1);
	}
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y +(2* distanceY/3) ,startPoint.z),distanceX,distanceY/3,distanceZ,image,10,1);
	
}

void Parts::DrowCarriageWallWithDoorZY (Point startPoint, float distanceZ, float distanceY)
{
	glColor3ub(128,128,128);
	Shapes::DrowBox(startPoint,0.5,distanceY,distanceZ/4);
	Shapes::DrowBox(Point(startPoint.x,startPoint.y,startPoint.z + distanceZ/4),0.5,2*distanceY/3,distanceZ/2);
	glColor3ub(28,28,28);
	Shapes::DrowBox(Point(startPoint.x,startPoint.y,startPoint.z + 3*distanceZ/4),0.5,distanceY/3,distanceZ/4);
	
}

void Parts::DrowCarriageWallWithDoorXY (Point startPoint, float distanceX, float distanceY,int image)
{

	Shapes::DrowBoxWithTexture(startPoint,distanceX/3,distanceY,0.5f,image,1,5);
	Shapes::DrowBoxWithTexture(Point(startPoint.x + distanceX/3,startPoint.y + 2*distanceY/3 ,startPoint.z),2*distanceX/3,distanceY/3,0.5f,image,1,1);
	Shapes::DrowBoxWithTexture(Point(startPoint.x + 2*distanceX/3,startPoint.y,startPoint.z),distanceX/3,distanceY,0.5f,image,1,5);
}


void Parts::CurtainsZY (Point startPoint, float distanceZ, float distanceY ,int image, float shutdownLevel){
		glLineWidth(5);
		glColor3ub(150,0,0);
		glBegin(GL_LINES);
				glVertex3f(startPoint.x,startPoint.y +distanceY,startPoint.z);
				glVertex3f(startPoint.x,startPoint.y +distanceY,startPoint.z + distanceZ);
		glEnd();
		glLineWidth(1);glColor3ub(255,255,255);
		Shapes::DrowSquareWithTextureZY(Point(startPoint.x,startPoint.y +distanceY ,startPoint.z),distanceZ,-distanceY+shutdownLevel,image,1,1);
}
void Parts::DrowCarriage (Point startPoint, float distanceX, float distanceY, float distanceZ , int windowsNum , float shutdownLevel,float clossdoor1,float clossdoor2,int firstImage,int secondImage,int thirdImage)
{
	Parts::DrowCarriageWallWithWindowsZY(startPoint,0.5f,distanceY,distanceZ,windowsNum,shutdownLevel,firstImage,thirdImage);
	
	Parts::DrowCarriageWallWithWindowsZY(Point(startPoint.x + distanceX,startPoint.y,startPoint.z),0.5f,distanceY,distanceZ,windowsNum,shutdownLevel,firstImage,thirdImage);

	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,1.0,distanceZ,secondImage,3,15);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y + distanceY,startPoint.z),distanceX,0.5f,distanceZ,secondImage,3,15);

	Parts::DrowCarriageWallWithDoorXY(startPoint,distanceX,distanceY,secondImage);
	Parts::DrowCarriageWallWithDoorXY(Point(startPoint.x,startPoint.y,startPoint.z + distanceZ ),distanceX,distanceY,secondImage);
	
	Parts::door (Point(startPoint.x+distanceX/3,startPoint.y,startPoint.z),distanceX/2.9,2*distanceY/3 , 1 , clossdoor1);
	Parts::door (Point(startPoint.x+distanceX/3,startPoint.y,startPoint.z+distanceZ),distanceX/2.9,2*distanceY/3 , 1 , clossdoor2);
}

void Parts::projectionPanel (Point startPoint, float distanceX, float distanceY , float shutdownLevel,int display,int statusLight){
	glColor3ub(255,255,255);
	//Shapes::DrowSquareXY(Point(startPoint.x,startPoint.y +distanceY ,startPoint.z),distanceX,-distanceY+shutdownLevel*1.7);
	if(statusLight>0){glEnable(GL_LIGHT2);}
	Shapes::DrowSquareWithTextureXY(Point(startPoint.x,startPoint.y +distanceY ,startPoint.z),distanceX,-distanceY+shutdownLevel*1.7,display,1,1);
	glDisable(GL_LIGHT2);	
	glLineWidth(3);
		glColor3ub(0,0,0);
		glBegin(GL_LINES);
				glVertex3f(startPoint.x,startPoint.y +distanceY,startPoint.z);
				glVertex3f(startPoint.x+ distanceX,startPoint.y +distanceY,startPoint.z );
		glEnd();
		glBegin(GL_LINES);
				glVertex3f(startPoint.x -5,startPoint.y +distanceY,startPoint.z);
				glVertex3f(startPoint.x -5,startPoint.y + 10 +distanceY,startPoint.z);
		glEnd();
		glBegin(GL_LINES);
				glVertex3f(startPoint.x+distanceX +5,startPoint.y +distanceY,startPoint.z);
				glVertex3f(startPoint.x+distanceX +5,startPoint.y + 10 +distanceY,startPoint.z);
		glEnd();
}

void Parts::door (Point startPoint, float distanceX,float distanceY , float distanceZ , float clossDoor ){
	glColor3ub(10,20,20);
	Shapes::DrowBox(Point(startPoint.x,startPoint.y,startPoint.z),distanceX-clossDoor,distanceY,distanceZ/10);
	

}
void Parts::chair (Point startPoint, float distanceX,float distanceY , float distanceZ,int firstImage,int secondImage ){
	
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y+distanceY/3,startPoint.z),distanceX,2*distanceY/3,distanceZ/10,firstImage,1,10);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y+distanceY/3,startPoint.z),distanceX,distanceY/10,-distanceZ,firstImage,1,1);
	
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y ,startPoint.z -(7* distanceZ/8)),distanceX,distanceY/3,-distanceZ/8,secondImage,1,1);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceY/3,distanceZ/10,secondImage,1,1);
}


void Parts::chairsDistribution (int firstImage,int secondImage){

	for(int i=0; i<10;i++){
		for(int j=0; j<=2;j++){
			Parts::chair (Point(1+(j*10),0,-40-(i*16)), 9,25 ,10,firstImage,secondImage);
			Parts::chair (Point(40+(j*10),0,-40-(i*16)), 9,25 ,10,firstImage,secondImage);
		}
	}

}

void Parts::controlPanel(Point startPoint, float distanceX,float distanceY , float distanceZ){

	glColor3ub(40,140,140);
	Shapes::DrowBox(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceY,distanceZ);

	glColor3ub(255,0,0);

	for (int j=0;j<=3;j++){
		for (int i=0;i<3;i++){
		
		Shapes::DrowBox(Point(startPoint.x+distanceX+0.2,startPoint.y+j*distanceY/8+j+1,startPoint.z+(i*distanceZ/5-(1*(i+1)))),distanceX/3,distanceY/8,distanceZ/5);
		}
	}
}



void Parts::table(Point startPoint, float distanceX,float distanceY , float distanceZ,float img_wood){

	glColor3ub(255,255,255);
	Shapes::DrowBoxWithTexture(Point((2*startPoint.x+distanceX)/2,startPoint.y,startPoint.z),2,1,distanceZ,img_wood,5,10);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y,(2*startPoint.z+distanceZ)/2),distanceZ,1,2,img_wood,5,10);
	Shapes::DrowBoxWithTexture(Point((2*startPoint.x+distanceX)/2,startPoint.y,(2*startPoint.z+distanceZ)/2),2,distanceY,2,img_wood,5,10);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y+distanceY,startPoint.z),distanceX,1,distanceZ,img_wood,5,10);
	

	
}

void Parts::labtop(Point startPoint, float distanceX,float distanceY , float distanceZ, float levelOpen,float img_keyboard,float img_hp,float img_black,float display,float statusLight){

	glColor3ub(255,255,255);

	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,distanceY,distanceZ,img_black,img_black,img_black,img_black,img_black,img_keyboard,1,1);
	glColor3ub(40,40,40);
	glPushMatrix();
	
	glTranslated(startPoint.x,startPoint.y+distanceY,startPoint.z);
	glRotated(-levelOpen,0,0,1);
	Shapes::DrowBoxWithTexture(Point(0,0,0),distanceX,distanceY-0.02,distanceZ,img_black,img_black,img_black,img_black,img_black,img_hp,1,1);
	
	if(statusLight>0){glEnable(GL_LIGHT2);}
	Shapes::DrowSquareWithTextureXZ(Point(-0.4,-0.01,distanceZ+0.3),distanceX+0.8,-distanceZ-0.6, display, 1, 1);
	glDisable(GL_LIGHT2);
	glPopMatrix();
	//Shapes::DrowBox(Point(startPoint.x,startPoint.y+distanceY,startPoint.z),distanceX,distanceY-0.02,distanceZ);

	
}




void Parts::DrowCarriageWithoutDoors(Point startPoint, float distanceX, float distanceY, float distanceZ, int windowsNum , int firstImage,int secondImage,int thirdImage){

	Parts::DrowCarriageWallWithWindowsZY(startPoint,0.5f,distanceY,distanceZ,windowsNum,0,firstImage,thirdImage);
	
	Parts::DrowCarriageWallWithWindowsZY(Point(startPoint.x + distanceX,startPoint.y,startPoint.z),0.5f,distanceY,distanceZ,windowsNum,0,firstImage,thirdImage);

	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,1.0,distanceZ,secondImage,3,15);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y + distanceY,startPoint.z),distanceX,0.5f,distanceZ,secondImage,3,15);

}



