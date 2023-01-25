#include "Parts2.h"

#include "texture.h"


#define push glPushMatrix
#define pop glPopMatrix
#define PI 3.1416
#define gt(x,y,z) glTranslatef(x,y,z)
#define gs(x,y,z) glScalef(x,y,z)
#define gr(a,x,y,z) glRotatef(a,x,y,z)

int angle=0;
GLUquadric *quadricSL =  gluNewQuadric();



void Parts2::DrowCarriage(float shutdownLevel, int firstImage,int secondImage,int thirdImage,int game_machine,int game_machine_screan,int game_place,int ImageSofa,int image,int monitor,int case_left,int case_front,int case_top){
	glPushMatrix();
	Parts2::DrowCarriageWithoutDoors(Point(0,0,250.0f),70.0f,70.0f,-250.0f,5,shutdownLevel,firstImage,secondImage,thirdImage);
	Shapes::DrowBoxWithTexture(Point(55,0,100),15,15,5,case_left,case_left,case_front,case_front,case_left,case_left,1,1);

	Shapes::DrowBoxWithTexture(Point(55,0,130),15,15,5,case_left,case_left,case_front,case_front,case_left,case_left,1,1);
	Shapes::DrowBoxWithTexture(Point(55,0,160),15,15,5,case_left,case_left,case_front,case_front,case_left,case_left,1,1);

	//game_machine
	glPushMatrix();
		glTranslated(0,0,60);
		
		glScaled(12,12,12);
		glPushMatrix();
		glRotated(90,0,1,0);
		Parts2::draw_game_machine(game_machine,game_machine_screan,game_place);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,110);
		
		glScaled(12,12,12);
		glPushMatrix();
		glRotated(90,0,1,0);
		Parts2::draw_game_machine(game_machine,game_machine_screan,game_place);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,150);
		
		glScaled(12,12,12);
		glPushMatrix();
		glRotated(90,0,1,0);
		Parts2::draw_game_machine(game_machine,game_machine_screan,game_place);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,200);
		
		glScaled(12,12,12);
		glPushMatrix();
		glRotated(90,0,1,0);
		Parts2::draw_game_machine(game_machine,game_machine_screan,game_place);
		glPopMatrix();
	glPopMatrix();


	//table

		glPushMatrix();
		glTranslated(60,20,120);
		glScaled(0.8,1,1);
		Parts2::table(image);
		glPopMatrix();
	
		glPushMatrix();
			glTranslated(60,33,110);
			glScaled(0.7,0.7,0.7);
			glPushMatrix();
			glRotated(-90,0,1,0);
			Parts2:: draw_advanced_monitor(monitor);
			glPopMatrix();
		glPopMatrix();

				glPushMatrix();
			glTranslated(60,33,140);
			glScaled(0.7,0.7,0.7);
			glPushMatrix();
			glRotated(-90,0,1,0);
			Parts2:: draw_advanced_monitor(monitor);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
			glTranslated(60,33,170);
			glScaled(0.7,0.7,0.7);
			glPushMatrix();
			glRotated(-90,0,1,0);
			Parts2:: draw_advanced_monitor(monitor);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}


void Parts2::DrowCarriageWithoutDoors(Point startPoint, float distanceX, float distanceY, float distanceZ, int windowsNum , float shutdownLevel , int firstImage,int secondImage,int thirdImage){

	Parts::DrowCarriageWallWithWindowsZY(startPoint,0.5f,distanceY,distanceZ,windowsNum,shutdownLevel,firstImage,thirdImage);
	
	Parts::DrowCarriageWallWithWindowsZY(Point(startPoint.x + distanceX,startPoint.y,startPoint.z),0.5f,distanceY,distanceZ,windowsNum,shutdownLevel,firstImage,thirdImage);

	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y,startPoint.z),distanceX,1.0,distanceZ,secondImage,3,15);
	Shapes::DrowBoxWithTexture(Point(startPoint.x,startPoint.y + distanceY,startPoint.z),distanceX,0.5f,distanceZ,secondImage,3,15);

}



	


void draw_solid_cube(){
	
glBegin(GL_QUADS);     //quad1
glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,-0.5);
    glTexCoord2f(1,0);
		glVertex3f(0.5,-0.5,-0.5);
		 glTexCoord2f(1,1);
		glVertex3f(0.5,-0.5,0.5);
		 glTexCoord2f(0,1);
		glVertex3f(-0.5,-0.5,0.5);
	glEnd();


	glBegin(GL_QUADS);       //quad2
	glTexCoord2f(0,0);
		glVertex3f(-0.5,0.5,0.5);

    glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);

		 glTexCoord2f(1,1);
		glVertex3f(0.5,0.5,-0.5);

		 glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,-0.5);
	glEnd();


	glBegin(GL_QUADS);           //quad3
	glTexCoord2f(0,0);
		glVertex3f(-0.5,0.5,-0.5);
    glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,-0.5);
		 glTexCoord2f(1,1);
		glVertex3f(0.5,-0.5,-0.5);
		 glTexCoord2f(0,1);
		glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	
	glBegin(GL_QUADS);              //quad4
	glTexCoord2f(0,0);
		glVertex3f(0.5,0.5,0.5);

		

    glTexCoord2f(1,0);
		glVertex3f(-0.5,0.5,0.5);
		 glTexCoord2f(1,1);
		glVertex3f(-0.5,-0.5,0.5);
		 glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_QUADS);//quad5
	glTexCoord2f(0,0);
		glVertex3f(0.5,0.5,-0.5);
    glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);
		 glTexCoord2f(1,1);
		glVertex3f(0.5,-0.5,0.5);
		 glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,-0.5);
	glEnd();

	glBegin(GL_QUADS);          //quad6
	glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,-0.5);
    glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,0.5);

		 glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,0.5);
		 glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,-0.5);
	glEnd();

}

void draw_sofa_cube(){
glScaled(0.1,0.1,0.1);
draw_solid_cube();
};

void Parts2::draw_sofa(int ImageSofa, int ImageSofa2)
{
	//1
   
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa);
	glTranslatef(-0.32, 0.065, -0.3);
	glScalef(4, 0.65, 1.7);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//base under
	glPushMatrix(); 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa2);
	glTranslatef(-0.32, 0.015, -0.3);
	glScalef(4.1, 0.15, 1.71);
	draw_sofa_cube();    
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//back
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa);
	glTranslatef(-0.32, 0.1, -0.36);
	glScalef(4.1, 1.3, 0.61);
	draw_sofa_cube();    
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//seat
	
	/*glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa);
	glTranslatef(-0.41, 0.092, -0.25);
	glScalef(1.7, 0.15, 1.0);
	draw_sofa_cube();    
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/

	
	/*glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa);
	glTranslatef(-0.22, 0.092, -0.25);
	glScalef(1.7, 0.15, 1.0);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/

		//1

	//side rest
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa2);
	glTranslatef(-0.55, 0.065, -0.3);
	glScalef(0.7, 1.4, 0.7);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

		//1

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ImageSofa2);
	glTranslatef(-0.09, 0.065, -0.3);
	glScalef(0.7, 1.4, 0.7);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void drawCircle(float cx, float cy, float r1, float r2, int number_vertices) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < number_vertices; i++)
	{
		float theta = 2.0 * 3.1415926 * i / number_vertices;               //get the current angle 
		float x = r1 * cos(theta);                                         //calculate the x component 
		float y = r2 * sin(theta);                                         //calculate the y component 
		glVertex2f(x + cx, y + cy);                                        //output vertex 
	}
	glEnd();
}

void drawPolygon(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{ 
	// with 4 vertexes
	
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawTriangleFun(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{ 
	// with 4 vertexes
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void drawTriangleFun(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6)
{ 
	// with 6 vertexes
	
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glEnd();
}

void drawCube(float x, float y, float z)
{
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f);



        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);   
        

        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);  
        

        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);
        

        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f+y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+y, 0.0f-z);


        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+x, 0.0f, 0.0f-z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-z);
        


    glEnd();
}

void drawTriangle(float x, float y, float z){

        glBegin(GL_QUADS);

        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0,0,0);
        glVertex3f(x,0,0);
        glVertex3f(x,y,0);
        glVertex3f(0,y,0);

        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(x,0,0);
        glVertex3f(x,0,-z);
        glVertex3f(x,y,-z);
        glVertex3f(x,y,0);

        glNormal3f(0.0f, 1.0f, 1.0f);
        glVertex3f(x,0,-z);
        glVertex3f(0,0,0);
        glVertex3f(0,y,0);
        glVertex3f(x,y,-z);

        glEnd();

        glBegin(GL_TRIANGLES);

        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0,y,0);
        glVertex3f(x,y,0);
        glVertex3f(x,y,-z);

        glNormal3f(0.0f, -1.0f, 0.0f);

        glVertex3f(0,0,0);
        glVertex3f(x,0,0);
        glVertex3f(x,0,-z);

        glEnd();
    

}

void drawCircle(float x, float y, float z)
{
    glPushMatrix();
    for(int i = 0; i < 100; i++)
    {
        glRotatef(3.6,0,1,0);
        drawTriangle(x,y,z);
    }
    
    glPopMatrix();
}

void Parts2:: draw_advanced_monitor(int image)
{
		glPushMatrix();
		glTranslated(1,1,1);

		//mointor from back
		glColor3d(0.3,0.3,0.3);
		glBegin(GL_QUADS);
		glVertex3d(-10,5,-2.5);
		glVertex3d(-5,5, -2.5);
		glVertex3d(-5,-2,-2.5); 
		glVertex3d(-10,-2,-2.5);
		glEnd();
			
		glColor3d(0.8,0.8,0.8);
	    glBegin(GL_QUADS);
		glVertex3d(-25,15,-1);
	    glVertex3d(5,15,-1);
	    glVertex3d(-5,5,-2.5);
	    glVertex3d(-15,5,-2.5);
	    glEnd();
		
		glColor3d(0.4,0.4,0.4);
	    glBegin(GL_QUADS); 
		glVertex3d(-5,5,-2.5);
	    glVertex3d(5,15,-1);
	    glVertex3d(5,-12,-1);
	    glVertex3d(-5,-2,-2.5);
	    glEnd();
		
		glColor3d(0.4,0.4,0.4);
		glBegin(GL_QUADS);
		glVertex3d(-15,-2,-2.5);
	    glVertex3d(-5,-2,-2.5);
	    glVertex3d(5,-12,-1);
	    glVertex3d(-25,-12,-1);
	    glEnd();
		
		glColor3d(0.45,0.45,0.45);
		glBegin(GL_QUADS);
		glVertex3d(-25,15,-1);
	    glVertex3d(-15,5,-2.5);
	    glVertex3d(-15,-2,-2.5);
	    glVertex3d(-25,-12,-1);
	    glEnd();

	   //The end of monitor from behind
			int g=-1;   

	   glColor3d(0.3,0.3,0.3);
	   glBegin(GL_QUADS);
	   glVertex3d(-25,15,0);
	   glVertex3d(5,15,0);
	   glVertex3d(5,-12,0);
	   glVertex3d(-25,-12,0);
	   glEnd();

	   //blue monitor
	    glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-24,14,0.01);
		glTexCoord2d(1, 0);
		glVertex3d(4,14,0.01);
		glTexCoord2d(1,1);
		glVertex3d(4,-11,0.01);		
		glTexCoord2d(0,1);
		glVertex3d(-24,-11,0.01);
		glEnd();
		glDisable(GL_TEXTURE_2D);
        glPopMatrix();

		glColor3d(0,0,0);//blue monitor edges
		glBegin(GL_QUADS); 
		glVertex3d(-24,14,0);
		glVertex3d(-24,14,g);
		glVertex3d(-24,-11,g);
		glVertex3d(-24,-11,0);
		glEnd();

		//// monitor edges
		glColor3d(1,0.8,0.8);
		glBegin(GL_QUADS); 
		glVertex3d(-25,15,0);
		glVertex3d(5,15,0);
		glVertex3d(5,15,-1);
		glVertex3d(-25,15,-1);
		glEnd();

		glBegin(GL_QUADS); 
		glVertex3d(5,15,0);
		glVertex3d(5,15,-1);
		glVertex3d(5,-12,-1);
		glVertex3d(5,-12,0);
		glEnd();

		glBegin(GL_QUADS); 
		glVertex3d(5,-12,0);
		glVertex3d(5,-12,-1);
		glVertex3d(-25,-12,-1);
		glVertex3d(-25,-12,0);
		glEnd();

		glBegin(GL_QUADS); 
		glVertex3d(-25,15,0);
		glVertex3d(-25,15,-1);
		glVertex3d(-25,-12,-1);
		glVertex3d(-25,-12,0);
		glEnd();
		//the end of edges
	  
		//monitor leg
		glColor3d(0.3,0.3,0.3);
		glBegin(GL_QUADS);//the drawing on the monitor
		glVertex3d(-13,-4,-2);
		glVertex3d(-7,-4, -2);
		glVertex3d(-7,-6,-2); 
		glVertex3d(-13,-6,-2);
		glEnd();

		glColor3d(0.1,0.1,0.1);
		glBegin(GL_QUADS);
		glVertex3d(-11,-6,-2);
		glVertex3d(-9,-6, -2);
		glVertex3d(-9,-4,-2); 
		glVertex3d(-11,-4,-2);
		glEnd();

		glColor3d(0.2,0.2,0.2);//leg edges
		glBegin(GL_QUADS);
		glVertex3d(-11,-7,-4);
		glVertex3d(-9,-7, -4);
		glVertex3d(-9,-9,-5); 
		glVertex3d(-11,-9,-5);
		glEnd();

		glColor3d(0.15,0.15,0.15);
		glBegin(GL_QUADS);/// assa1
		glVertex3d(-11,-6,-2);
		glVertex3d(-11,-4, -2);
		glVertex3d(-11,-7,-4); 
		glVertex3d(-11,-9,-5);//
		glEnd();

		glColor3d(0.3,0.3,0.3);
		glBegin(GL_QUADS);
		glVertex3d(-11,-4,-2);
		glVertex3d(-9,-4, -2);
		glVertex3d(-9,-7,-4); 
		glVertex3d(-11,-7,-4);
		glEnd();

		glColor3d(0.15,0.15,0.15);
		glBegin(GL_QUADS);
		glVertex3d(-9,-6,-2);
		glVertex3d(-9,-4, -2);
		glVertex3d(-9,-7,-4); 
		glVertex3d(-9,-9,-5);
		glEnd();

		glColor3d(0.2,0.2,0.2);
		glBegin(GL_QUADS);//assa2
		glVertex3d(-11,-7,-4);
		glVertex3d(-9,-7, -4);
		glVertex3d(-9,-15,-4); 
		glVertex3d(-11,-15,-4);
		glEnd();
		
		glBegin(GL_QUADS);
		glVertex3d(-11,-7,-4);
		glVertex3d(-11,-9, -5);
		glVertex3d(-11,-15,-5); 
		glVertex3d(-11,-15,-4);
		glEnd();

		glColor3d(0.3,0.3,0.3);
		glBegin(GL_QUADS);
		glVertex3d(-11,-9,-5);
		glVertex3d(-9,-9, -5);
		glVertex3d(-9,-15,-5); 
		glVertex3d(-11,-15,-5);
		glEnd();

		glColor3d(0.15,0.15,0.15);
		glBegin(GL_QUADS);
		glVertex3d(-9,-9,-5);
		glVertex3d(-9,-7, -4);
		glVertex3d(-9,-15,-4); 
		glVertex3d(-9,-15,-5);
		glEnd();

		glColor3d(0.15,0.15,0.15);///the end on assa 2
		glBegin(GL_QUADS);
		glVertex3d(-11,-15,-5);//leg ground
		glVertex3d(-9,-15, -5);
		glVertex3d(-7,-17,-9); 
		glVertex3d(-13,-17,-9);
		glEnd();

		glColor3d(0.15,0.15,0.15);
		glBegin(GL_QUADS);
		glVertex3d(-11,-15,-4);
		glVertex3d(-9,-15, -4);
		glVertex3d(-7,-17,-4-4*-1); 
		glVertex3d(-13,-17,-4-4*-1);
		glEnd();

		glColor3d(0.35,0.3,0.3);
		glBegin(GL_QUADS);
		glVertex3d(-7,-17,-4+5*-1);
		glVertex3d(-9,-15,-4+-1);
		glVertex3d(-9,-15,-4); 
		glVertex3d(-7,-17,-4-4*-1);
		glEnd();

		glColor3d(0.35,0.3,0.3);
		glBegin(GL_QUADS);
		glVertex3d(-11,-15,-4+-1);
		glVertex3d(-11,-15,-4);
		glVertex3d(-13,-17,-4-4*-1); 
		glVertex3d(-13,-17,-4+5*-1);
		glEnd();
		glPopMatrix();
	   
}

void Parts2:: draw_office_drawer_desk()
{
	glPushMatrix();
	glTranslated(0.7,9,15);
	glColor3f(1, 1.32, 0.13);  //drawer handle
	drawPolygon(-40.0, -19.0, -36.0, -19.0, -36.0, -20.0, -40.0, -20.0);
	glPopMatrix();

	//drawer
	glPushMatrix();
	glColor3f(0.51, 0.11, 0);
	glTranslated(-37.4,-11,9);
	glScaled(115,40,110);
	glScaled(0.1,0.1,0.1);


	glBegin(GL_QUADS);     //quad1
	glTexCoord2f(0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,-0.5,0.5);
	glEnd();


	glBegin(GL_QUADS);       //quad2
	glTexCoord2f(0,0);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();


	glBegin(GL_QUADS);           //quad3
	glTexCoord2f(0,0);
	glVertex3f(-0.5,0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	glBegin(GL_QUADS);              //quad4
	glTexCoord2f(0,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,0);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_QUADS);//quad5
	glTexCoord2f(0,0);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(0.5,-0.5,-0.5);
	glEnd();

	glBegin(GL_QUADS);          //quad6
	glTexCoord2f(0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();
	glPopMatrix();
}

void Parts2:: draw_office_desk(){

	glPushMatrix();
	glTranslated(0,0,12);
	glPushMatrix();
	glTranslated(-22, -13.5, -23);
	glScaled(470, 271, 40);
	glColor3f(0.51, 0.30, 0);
	glScaled(0.1,0.1,0.1);
	glBegin(GL_QUADS);     //quad1
	glTexCoord2f(0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,-0.5,0.5);
	glEnd();


	glBegin(GL_QUADS);       //quad2
	glTexCoord2f(0,0);
	glVertex3f(-0.5,0.5,0.5);

	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,0.5);

	glTexCoord2f(1,1);
	glVertex3f(0.5,0.5,-0.5);

	glTexCoord2f(0,1);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();


	glBegin(GL_QUADS);           //quad3
	glTexCoord2f(0,0);
	glVertex3f(-0.5,0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	
	glBegin(GL_QUADS);              //quad4
	glTexCoord2f(0,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,0);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_QUADS);//quad5
	glTexCoord2f(0,0);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(0.5,-0.5,-0.5);
	glEnd();

	glBegin(GL_QUADS);          //quad6
	glTexCoord2f(0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();
	glPopMatrix();


	glColor3ub(197,130,60);
	glPushMatrix();
	glTranslated(0,0,12);
	glPushMatrix();
	glTranslated(0, -13.5, -11);
	glScaled(30, 271, 40);
	draw_sofa_cube();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-30, -13.5, 0);
	glScaled(30, 271, 40);
	draw_sofa_cube();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-45, -13.5, 0);
	glScaled(30, 271, 40);
	draw_sofa_cube();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,0,1);
	glTranslated(-7.3,38, 0);
	glScaled(30, 150, 40);
	draw_sofa_cube();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotated(90,0,0,1);
	glTranslated(-1,22.1, 0);
	glScaled(22, 480,300 );
	draw_sofa_cube();
	glPopMatrix();
}

void draw_offical_chair(){

	glBegin(GL_POLYGON);// chair back
	glColor3f(0.337 , 0.152 , 0.176);
	glVertex3f(16.5, 8.5,0.1); 
	glVertex3f(17.5, 10.5,0.1);
	glVertex3f(24.5, 10.5,0.1);
	glVertex3f(25.5, 8.5,0.1);
	glVertex3f(26.5, -4,0.1);
	glVertex3f(25.5, -6.5,0.1);
	glVertex3f(17.0, -6.5,0.1);
	glVertex3f(15.5, -4.5,0.1);
	glEnd();
	
	glColor3ub(115, 119, 123);
	glBegin(GL_POLYGON);
	glVertex3f(17.5, 10.5,0.1);
	glVertex3f(24.5, 10.5,0.1);
	glVertex3f(24.5, 10.5,2);
	glVertex3f(17.5, 10.5,2);
	glEnd();

	
	glBegin(GL_POLYGON);
	glVertex3f(17.5, 10.5,0.1);
	glVertex3f(17.5, 10.5,2);
	glVertex3f(16.5, 8.5,2); 
	glVertex3f(16.5, 8.5,0.1); 
	glEnd();

	
	glBegin(GL_POLYGON);
	glVertex3f(24.5, 10.5,0.1);
	glVertex3f(24.5, 10.5,2);
	glVertex3f(25.5, 8.5,2);
	glVertex3f(25.5, 8.5,0.1); 
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(25.5, 8.5,2);
	glVertex3f(25.5, 8.5,0.1); 
	glVertex3f(26.5, -4,0.1);
	glVertex3f(26.5, -4,2);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glVertex3f(16.5, 8.5,2); 
	glVertex3f(16.5, 8.5,0.1);
	glVertex3f(15.5, -4.5,0.1);
	glVertex3f(15.5, -4.5,2);
	glVertex3f(17.0, -6.5,0.1);
	glEnd();

		
	glBegin(GL_POLYGON);
	glVertex3f(15.5, -4.5,0.1);
	glVertex3f(15.5, -4.5,2);
	glVertex3f(17.0, -6.5,2);
	glVertex3f(17.0, -6.5,0.1);
	glEnd();

	
	glBegin(GL_POLYGON);
	glVertex3f(26.5, -4,0.1);
	glVertex3f(26.5, -4,2);
	glVertex3f(25.5, -6.5,2);
	glVertex3f(25.5, -6.5,0.1);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glVertex3f(25.5, -6.5,2);
	glVertex3f(25.5, -6.5,0.1);
	glVertex3f(17.0, -6.5,0.1);
	glVertex3f(17.0, -6.5,2);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.337 , 0.152 , 0.176);
	glVertex3f(16.5, 8.5,2); 
	glVertex3f(17.5, 10.5,2);
	glVertex3f(24.5, 10.5,2);
	glVertex3f(25.5, 8.5,2);
	glVertex3f(26.5, -4,2);
	glVertex3f(25.5, -6.5,2);
	glVertex3f(17.0, -6.5,2);
	glVertex3f(15.5, -4.5,2);
	glEnd();

	push(); //chair seat
	glColor3f(0.337 , 0.152 , 0.176);
	glTranslated(21,-9,4.5);
	glRotated(-2,1,0,0);
	glRotated(-3,0,1,0);
	glScaled(14,2,-10);
	glBegin(GL_QUADS);     //quad1
	glTexCoord2f(0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,-0.5,0.5);
	glEnd();


	glBegin(GL_QUADS);       //quad2
	glTexCoord2f(0,0);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();

	glColor3ub(115, 119, 123);
	glBegin(GL_QUADS);           //quad3
	glTexCoord2f(0,0);
	glVertex3f(-0.5,0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,-0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,-0.5,-0.5);
	glEnd();

	
	glBegin(GL_QUADS);              //quad4
	glTexCoord2f(0,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,0);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(0.5,-0.5,0.5);
	glEnd();

	glBegin(GL_QUADS);//quad5
	glTexCoord2f(0,0);
	glVertex3f(0.5,0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(0.5,0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(0.5,-0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(0.5,-0.5,-0.5);
	glEnd();

	glBegin(GL_QUADS);          //quad6
	glTexCoord2f(0,0);
	glVertex3f(-0.5,-0.5,-0.5);
	glTexCoord2f(1,0);
	glVertex3f(-0.5,-0.5,0.5);
	glTexCoord2f(1,1);
	glVertex3f(-0.5,0.5,0.5);
	glTexCoord2f(0,1);
	glVertex3f(-0.5,0.5,-0.5);
	glEnd();
	pop();
	
	push(); //right handler for arm of the chair
	glColor3d(0.1,0.1,0.1);
	glTranslated(27.5,-10.2,3);
	glScaled(50,3,10);
	draw_sofa_cube();
	pop();

	push(); //left handler for arm of the chair
	glColor3d(0.1,0.1,0.1);
	glTranslated(14.5,-10.2,3);
	glScaled(50,3,10);
	draw_sofa_cube();
	pop();

	
	push();//bottom of the chair
	glTranslated(21,-10,2);
	glRotated(-2,1,0,0);
	glRotated(-3,0,1,0);
	glColor3d(0.1,0.1,0.1);
	glScaled(140,6,-58);
	draw_sofa_cube();
	pop();
	
	push();//left arm of chair
	glColor3f(0.1,0.1,0.1);
	glTranslated(13,-6.8,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,0.6,0.6,3.3,100,100);
	pop();

	push();
	glColor3ub(115, 119, 123);
	glTranslated(13,-3.8,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,0.3,0.3,4.3,100,100);
	pop();

	push();
	glColor3f(0.1,0.1,0.1);
	glTranslated(13,-3.8,3);
	glScaled(20,6,-30);
	draw_sofa_cube();
	pop();


	push();//right arm of chair
	glColor3f(0.1,0.1,0.1);
	glTranslated(28.9,-6.8,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,0.6,0.6,3.3,100,100);
	pop();

	push();
	glColor3ub(115, 119, 123);
	glTranslated(28.9,-3.8,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,0.3,0.3,4.3,100,100);
	pop();

	push();
	glColor3f(0.1,0.1,0.1);
	glTranslated(28.9,-3.8,3);
	glScaled(20,6,-30);
	draw_sofa_cube();
	pop();


	push();//base of chair
	glColor3f(0.1,0.1,0.1);
	glTranslated(21,-12.8,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,1,1,4,100,100);
	pop();

	push();//base of chair
	glColor3f(0.1,0.1,0.1);
	glTranslated(21,-15.8,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,1.3,1.3,2.8,100,100);
	pop();

	push();
	glColor3ub(115, 119, 123);
	glTranslated(21,-10,3);
	glRotated(90,1,0,0);
	gluCylinder(quadricSL,0.7,0.7,2.8,100,100);
	pop();
	 
	
	push();
	glColor3f(0.1,0.1,0.1);
	glTranslated(21.2,-7.7,0);
	glScaled(20,48,20);
	draw_sofa_cube();
	pop();

	glTranslated(0,-0.9,0);
	push();//right chair leg
	glColor3ub(115, 119, 123);
	glTranslated(21.6,-18,3);
	glRotated(90,0,1,0);
	angle++;
	gluCylinder(quadricSL,0.5,0.5,4,100,100);
	pop();

	push();
	glColor3d(0.1,0.1,0.1);
	glTranslated(25.7,-18.5,4);
	angle++;
	gluSphere(quadricSL,0.7,100,100);
	pop();

	push();
	glColor3ub(115, 119, 123);//left chair leg
	glTranslated(20.3,-18,3);
	glRotated(-90,0,1,0);
	angle++;
	gluCylinder(quadricSL,0.5,0.5,4,100,100);
	pop();

	push();
	glColor3d(0.1,0.1,0.1);
	glTranslated(16.2,-18.5,3.8);
	angle++;
	gluSphere(quadricSL,0.7,100,100);
	pop();

	};

void Parts2:: draw_office_carriage(int monitor){
	push();
	glTranslated(55,32,-100);
	push();
	glTranslated(26,0,30);
	glScaled(1.6,1.6,1.6);
	glRotated(190,0,1,0);
	draw_offical_chair();
	pop();

	glTranslated(0,-3,0);
	push();
	glRotated(20,0,1,0);
	glTranslated(-27,11.6,1.8);
	glScaled(0.7,0.7,0.7);
	Parts2::draw_advanced_monitor(monitor);
	pop();

	push();
	Parts2::draw_office_drawer_desk();
	pop();

	push();
	glTranslated(0,-4,0);
	Parts2::draw_office_drawer_desk();
	pop();

	push();
	glTranslated(0,6.5,0);
	Parts2::draw_office_drawer_desk();
	pop();

	push();
	draw_office_desk();
	pop();
	push();
    
}

void Parts2::table(int image)
{
	//top
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glColor3f(0.80, 0.72, 0.62);
	glPushMatrix();
	glTranslated(0.375, -0.325, -0.375);
	glScaled(200, 50, 1300);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//legs
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glTranslated(-7, -10, -63);
	glScaled(50, 170, 0.5);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glTranslated(-7, -10, 56);
	glScaled(50, 170, 0.5);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glTranslated(8, -10, 56);
	glScaled(50, 170, 0.5);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image);
	glTranslated(8, -10, -63);
	glScaled(50, 170, 0.5);
	draw_sofa_cube();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Parts2::draw_game_machine(int game_machine,int game_machine_screan,int game_place){
	//back
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(2, 2);
	glVertex3d(1,2,0);
	glTexCoord2d(0, 2);
	glVertex3d(0,2,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//left
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(0,0,1);
	glTexCoord2d(2, 2);
	glVertex3d(0,2,1);
	glTexCoord2d(0, 2);
	glVertex3d(0,2,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//right
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(1,0,1);
	glTexCoord2d(2, 2);
	glVertex3d(1,2,1);
    glTexCoord2d(0, 2);
	glVertex3d(1,2,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//front
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,1);
	glTexCoord2d(2, 0);
	glVertex3d(1,0,1);
	glTexCoord2d(2, 2);
	glVertex3d(1,2,1);
	glTexCoord2d(0, 2);
	glVertex3d(0,2,1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);


	//floor
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(2, 2);
	glVertex3d(1,0,1);
	glTexCoord2d(0, 2);
	glVertex3d(0,0,1);
	glEnd();glDisable(GL_TEXTURE_2D);
	
	
	glTranslated(0,2,0);
	
	//backCenter
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
    glTexCoord2d(2, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(2, 2);
	glVertex3d(1,0.5,0);
	glTexCoord2d(0, 2);
	glVertex3d(0,0.5,0);
	glEnd();glDisable(GL_TEXTURE_2D);
	
	//leftCenter
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(0,0,1);
	glTexCoord2d(2, 2);
	glVertex3d(0,0.5,0.5);
	glTexCoord2d(0, 2);
	glVertex3d(0,0.5,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//rightCenter
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(1,0,1);
	glTexCoord2d(2, 2);
	glVertex3d(1,0.5,0.5);
	glTexCoord2d(0, 2);
	glVertex3d(1,0.5,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//frontCenter
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_place);	
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
	glVertex3d(0,0,1);
	glTexCoord2d(1, 0);
	glVertex3d(1,0,1);
	glTexCoord2d(1, 1);
	glVertex3d(1,0.5,0.5);
	glTexCoord2d(0, 1);
	glVertex3d(0,0.5,0.5);
	glEnd();glDisable(GL_TEXTURE_2D);

	glTranslated(0,0.5,0);
   //backup
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(2, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(2, 2);
	glVertex3d(1,1,0);
	glTexCoord2d(0, 2);
	glVertex3d(0,1,0);
	glEnd();glDisable(GL_TEXTURE_2D);

    //leftUp
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);	
	glTexCoord2d(2, 0);
	glVertex3d(0,0,0.5);
	glTexCoord2d(2, 2);
	glVertex3d(0,1,0.5);
	glTexCoord2d(0, 2);
	glVertex3d(0,1,0);
	glEnd();glDisable(GL_TEXTURE_2D);

    //rightUp
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
    glVertex3d(1,0,0);	
	glTexCoord2d(2, 0);
	glVertex3d(1,0,0.5);	
	glTexCoord2d(2, 2);
    glVertex3d(1,1,0.5);
	glTexCoord2d(0,2);
	glVertex3d(1,1,0);
	glEnd();glDisable(GL_TEXTURE_2D);

    //frontUp
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
    glVertex3d(0,0,0.5);	
	glTexCoord2d(2, 0);
    glVertex3d(1,0,0.5);	
	glTexCoord2d(2, 2);
    glVertex3d(1,1,0.5);	
	glTexCoord2d(0,2);
    glVertex3d(0,1,0.5);
	glEnd();glDisable(GL_TEXTURE_2D);

	//screen of the machine
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine_screan);	
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
	glVertex3d(0.1,0.1,0.5);	
	glTexCoord2d(1, 0);
	glVertex3d(0.9,0.1,0.5);	
	glTexCoord2d(1, 1);
	glVertex3d(0.9,0.9,0.5);	
	glTexCoord2d(0, 1);
	glVertex3d(0.1,0.9,0.5);
	glEnd();glDisable(GL_TEXTURE_2D);

	glTranslated(0,1,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);	//topFloor
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);	
	glTexCoord2d(2, 0);
    glVertex3d(1,0,0);	
	glTexCoord2d(2,2);
    glVertex3d(1,0,1);	
	glTexCoord2d(0,2);
	glVertex3d(0,0,1);
	glEnd();glDisable(GL_TEXTURE_2D);

	//topBack
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(1,0,0);
	glTexCoord2d(1,1);
	glVertex3d(1,0.25,0);
	glTexCoord2d(0,1);
	glVertex3d(0,0.25,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//topLeft
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
    glVertex3d(0,0,0);	
	glTexCoord2d(1, 0);
	glVertex3d(0,0,1);	
	glTexCoord2d(1, 1);
	glVertex3d(0,0.25,1);	
	glTexCoord2d(0, 1);
	glVertex3d(0,0.25,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//rightCenter
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
    glVertex3d(1,0,0);	
	glTexCoord2d(1, 0);
	glVertex3d(1,0,1);	
    glTexCoord2d(1, 1);
    glVertex3d(1,0.25,1);	
	glTexCoord2d(0, 1);
	glVertex3d(1,0.25,0);
	glEnd();glDisable(GL_TEXTURE_2D);

	//topFront
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
    glVertex3d(0,0,1);	
	glTexCoord2d(1, 0);
    glVertex3d(1,0,1);
	glTexCoord2d(1, 1);
	glVertex3d(1,0.25,1);	
	glTexCoord2d(0, 1);
	glVertex3d(0,0.25,1);
	glEnd();glDisable(GL_TEXTURE_2D);

	//topTop
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, game_machine);
	glBegin(GL_QUADS);	
	glTexCoord2d(0, 0);
    glVertex3d(0,0.25,0);	
    glTexCoord2d(1, 0);
    glVertex3d(1,0.25,0);	
    glTexCoord2d(1,1);
    glVertex3d(1,0.25,1);	
    glTexCoord2d(0, 1);
	glVertex3d(0,0.25,1);
	glEnd();glDisable(GL_TEXTURE_2D);

}

//Eating room
void Parts2::drawTriangleTexture(Point p,int img,int img2)
{          

      glBindTexture(GL_TEXTURE_2D,img2);  
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2d(0,0);
        glVertex3f(0,0,0);
		glTexCoord2d(1,0);
        glVertex3f(p.x,0,0);
		glTexCoord2d(1,1);
        glVertex3f(p.x,p.y,0);
		glTexCoord2d(0,1);
        glVertex3f(0,p.y,0);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2d(1,0);
        glVertex3f(p.x,0,0);
		glTexCoord2d(1,0);
        glVertex3f(p.x,0,-p.z);
		glTexCoord2d(1,1);
        glVertex3f(p.x,p.y,-p.z);
		glTexCoord2d(1,1);
        glVertex3f(p.x,p.y,0);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 1.0f);
		glTexCoord2d(1,0);
        glVertex3f(p.x,0,-p.z);
		glTexCoord2d(0,0);
        glVertex3f(0,0,0);
		glTexCoord2d(0,1);
        glVertex3f(0,p.y,0);
		glTexCoord2d(1,1);
        glVertex3f(p.x,p.y,-p.z);
        glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

        glBindTexture(GL_TEXTURE_2D,img);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2d(0,1);
        glVertex3f(0,p.y,0);
		glTexCoord2d(1,1);
        glVertex3f(p.x,p.y,0);
		glTexCoord2d(1,1);
        glVertex3f(p.x,p.y,-p.z);
	
		glTexCoord2d(0,0);
        glVertex3f(0,0,0);
		glTexCoord2d(1,0);
        glVertex3f(p.x,0,0);
		glTexCoord2d(1,0);
        glVertex3f(p.x,0,-p.z);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255); 

}

void Parts2::drawCircleTexture(Point p,int img,int img2)
{
   glPushMatrix();              
    for(int i = 0; i < 100; i++)
    {
    glRotatef(3.6,0,1,0);
	Parts2::drawTriangleTexture(Point(p.x,p.y,p.z),img,img2 );
	}
    glPopMatrix();    
}

void Parts2::drawRoundTableTexture(int img1,int img2)
{    
	glColor3ub(255,255,255);
	glTranslatef(6,2,6.5);    
	drawCircleTexture(Point(2.2,0.1,0.2),img1,img2);
	glTranslatef(-6,-2,-6.5);    
}

void Parts2::drawCubeTexture(Point p,int img,int img2)   ///for table
{ 
	glBindTexture(GL_TEXTURE_2D,img2);   
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);  
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);  
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);


		glBindTexture(GL_TEXTURE_2D,img2);
		glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);  
}

void Parts2::drawDinningTableTexture(int img1,int img2)
{

   drawRoundTableTexture(img1,img2);
    glTranslatef(4,0,6);
    Parts2::drawCubeTexture(Point(0.2,2,0.2),img1,img2);

    glTranslatef(-4,0,-6);
    glTranslatef(4.2,0,8);
    Parts2::drawCubeTexture(Point(0.2,2,0.2),img1,img2);

    glTranslatef(-4.2,0,-8);
    glTranslatef(7.7,0,6);
    Parts2::drawCubeTexture(Point(0.2,2,0.2),img1,img2);

    glTranslatef(-7.7,0,-6);
    glTranslatef(7.5,0,8);
    Parts2::drawCubeTexture(Point(0.2,2,0.2),img1,img2);
    glTranslatef(-7.5,0,-8);
}

void Parts2::drawCubeTexture_1(Point p,int img,int img2)   ///  for  back of chair
{
   glBindTexture(GL_TEXTURE_2D,img2); //back
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

        glBindTexture(GL_TEXTURE_2D,img); //frontOfback
	    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f); 
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2); 
	    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);  
        glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2); 
	    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
        glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2); 
	    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		glEnd();
	    glDisable(GL_TEXTURE_2D);
	    glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img2); 
	    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
}

void Parts2::draw_solid_cube1(int img1,int img4){      //front right vending machine
    glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glBegin(GL_QUADS);     //quad1
    glTexCoord2f(0,0);
    glVertex3f(-0.5,-0.5,-0.5);
    glTexCoord2f(1,0);
    glVertex3f(0.5,-0.5,-0.5);
    glTexCoord2f(1,1);
    glVertex3f(0.5,-0.5,0.5);
    glTexCoord2f(0,1);
    glVertex3f(-0.5,-0.5,0.5);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);       //quad2
		glTexCoord2f(1,0);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,0);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,-0.5);
		glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

	glBindTexture(GL_TEXTURE_2D,img4); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);           //quad3    front for right vending
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,-0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(0,0);
		glVertex3f(0.5,-0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,-0.5);
		glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
    glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);              //quad4           front for left vending
		glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(0,0);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(0.5,-0.5,0.5);
		glEnd();
   glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
    
	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);//quad5
		glTexCoord2f(0,0);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(0.5,-0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,-0.5);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);          //quad6
		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,-0.5);
		glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
}

void Parts2::draw_solid_cube2(int img1,int img5){      //back right vending machine
    glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glBegin(GL_QUADS);     //quad1
    glTexCoord2f(0,0);
    glVertex3f(-0.5,-0.5,-0.5);
    glTexCoord2f(1,0);
    glVertex3f(0.5,-0.5,-0.5);
    glTexCoord2f(1,1);
    glVertex3f(0.5,-0.5,0.5);
    glTexCoord2f(0,1);
    glVertex3f(-0.5,-0.5,0.5);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);       //quad2
		glTexCoord2f(1,0);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,0);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,-0.5);
		glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);           //quad3    front for right vending
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,-0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(0,0);
		glVertex3f(0.5,-0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,-0.5);
		glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
    glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);              //quad4           front for left vending
		glTexCoord2f(1,1);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(1,0);
		glVertex3f(0.5,-0.5,0.5);
		glEnd();
   glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
    
	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);//quad5
		glTexCoord2f(0,0);
		glVertex3f(0.5,0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(0.5,0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(0.5,-0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(0.5,-0.5,-0.5);
		glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
 
	glBindTexture(GL_TEXTURE_2D,img1); 
	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);          //quad6
		glTexCoord2f(0,0);
		glVertex3f(-0.5,-0.5,-0.5);
		glTexCoord2f(1,0);
		glVertex3f(-0.5,-0.5,0.5);
		glTexCoord2f(1,1);
		glVertex3f(-0.5,0.5,0.5);
		glTexCoord2f(0,1);
		glVertex3f(-0.5,0.5,-0.5);
		glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
  

}

void Parts2::drawChairTexture(int img1,int img2){ 
	glPushMatrix();        
		glTranslatef(1.5,1,7);
		drawCubeTexture_1(Point(0.1,2,2),img1,img2);
		glTranslatef(-1.5,-1,-7);
		glTranslatef(1.5,1,7);
		drawCubeTexture_1(Point(1.3,0.1,2),img1,img2);
		glTranslatef(-1.5,-1,-7);
		glTranslatef(1.9,0,6.2);
		drawCubeTexture_1(Point(0.2,1,0.2),img1,img1);
		glTranslatef(-1.9,0,-6.2);
		glTranslatef(2.0,0,6.1);
		drawCircleTexture(Point(0.4,0.1,0.2),img1,img2);
		glTranslatef(-2.0,0,-6.1);    
    glPopMatrix();   
}

void  Parts2::drawSetChairTexture(int img1,int img2)
{   
	glTranslatef(0.7,0,0.8);
	Parts2::drawChairTexture(img1,img2);
	glTranslatef(-0.7,0,-0.8);
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
	glRotatef(180,0,1,0);
	glTranslatef(-10,0,-12);
	Parts2::drawChairTexture(img1,img2);
	glRotatef(-180,0,1,0);
	glTranslatef(10,0,12);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
    
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-11,0,-1);
	Parts2::drawChairTexture(img1,img2);
	glRotatef(-90,0,1,0);
	glTranslatef(-11,0,-1);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glRotatef(-90,0,1,0);
	glTranslatef(2,0,-11);
	Parts2::drawChairTexture(img1,img2);
	glRotatef(90,0,1,0);
	glTranslatef(2,0,-11);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();  
}

void Parts2::drawEatingTableTexture(int img1,int img2)
{

    float x,y,z;
    x = -4.5;
    y = -4.5;
    z = -8;
    glPushMatrix();
    glTranslatef(x,y,z);
    glTranslatef(-1,0,0);
	Parts2::drawDinningTableTexture(img1,img2);
    glTranslatef(-1,0,0);
    glPopMatrix();

    glPushMatrix();      
    glTranslatef(x,y,z);    
    Parts2::drawSetChairTexture(img1,img2);
	glPopMatrix();
}
//img1 is a color for table and img2 is a color for leg of table and the eating machine from out 
//img4 and img5 are a faces for differnt eating machine 
void Parts2::draw_eating_carriageTexture(int img1,int img2,int img4,int img5){

	push();
		gs(8,8,8);
		push();
	
		gt(-90,-20,-130);
		Parts2::drawEatingTableTexture(img1,img2);
		pop();

		push();	
		Parts2::drawEatingTableTexture(img1,img2);
		pop(); 
		gs(1,1,1);

		push();
		//gs(8,8,8);
		gt(0,0,10);
		Parts2::drawEatingTableTexture(img1,img2);
		pop();
		//gs(8,8,8);
		//front right vending machine
		push();
		gr(90,0,1,0);
		gt(5,-1,12);
		gs(7,10,2);
		Parts2::draw_solid_cube1(img2,img4);
		pop();
		//back right vending machine
		push();
		gr(90,0,1,0);
		gt(20,-1,12);
		gs(7,10,2);
		Parts2::draw_solid_cube1(img2,img4);
		pop();

		//back left vending machine
		push();
		gr(90,0,1,0);
		gt(20,-1,-12);
		gs(7,10,2);
		Parts2::draw_solid_cube2(img2,img5);
		pop();

		//front left vending machine
		push();
		gr(90,0,1,0);
		gt(5,-1,-12);
		gs(7,10,2);
		Parts2::draw_solid_cube2(img2,img5);
		pop();
	pop();
}   

//Bed room

void Parts2::drawBed(int img)    ///new
{
   glColor3d(1,0,1);  ///pink
    push();
        gt(3,0,-13.5);
        drawCube(15,1.5,8);
    pop();

   glColor3d(1,1,0);  ///yellow
    push();
        gt(3,1.5,-13.5);
        drawCube(15,1.5,8);
    pop();
  
    glColor3d(0,1,1);  //light blue
    push();
        gt(2,0,-13.5);
        drawCube(1,6,8);
    pop();
  
   glColor3d(0,0,1);
    push();
        gt(5.5,4,-14.5);
        push();
        // push();
        gr(160,0,0,1);
        drawCube(2,1,4);
    // pop();
        pop();
    pop();
    pop();
    
  
	glColor3ub(255,255,255);
 
}

void Parts2::draw_sleeping_carriage(int img)
{
	glPushMatrix();
	glScaled(3.5,3.5,3.5);
	glTranslated(17,1.7,0);
	glColor3ub(255,0,0);
	drawBed(img);
	glPopMatrix();

}
///////////////////////////////////////////////// with texture
void Parts2::drawCubeTexture1(Point p,int img)   ///1   wood ground  and back
{

	glBindTexture(GL_TEXTURE_2D,img); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

	glBindTexture(GL_TEXTURE_2D,img); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);   
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
         glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);


    glEnd();
}
void Parts2::drawCubeTexture2(Point p,int img3)   ///2      bed ground      for bed1
{

	glBindTexture(GL_TEXTURE_2D,img3); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

	glBindTexture(GL_TEXTURE_2D,img3); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);   
		 glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
	glBindTexture(GL_TEXTURE_2D,img3); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
	glBindTexture(GL_TEXTURE_2D,img3); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
	glBindTexture(GL_TEXTURE_2D,img3); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

	glBindTexture(GL_TEXTURE_2D,img3); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
         glEnd();
    glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
    glEnd();
}
void Parts2::drawCubeTexture3(Point p,int img5)   ///3   pillow
{

	glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);       
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

	glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);   
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
        glTexCoord2f(1,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);
        
		glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f);
        glTexCoord2f(1,1); 
        glVertex3f(0.0f+p.x, 0.0f+p.y, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f+p.y, 0.0f-p.z);
		 glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);

		glBindTexture(GL_TEXTURE_2D,img5); 
	glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glNormal3f(0.0f, -1.0f, 0.0f);
        glTexCoord2f(0,0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glTexCoord2f(1,0);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f);
        glTexCoord2f(1,1);
        glVertex3f(0.0f+p.x, 0.0f, 0.0f-p.z);
        glTexCoord2f(0,1);
        glVertex3f(0.0f, 0.0f, 0.0f-p.z);
         glEnd();
  glDisable(GL_TEXTURE_2D);
	glColor3ub(255,255,255);


    glEnd();
}


void Parts2::drawBedTexture1(int img,int img2,int img3){       /////bed1
	
  // glColor3d(1,0,1);  ///pink
	glColor3ub(255,255,255);
    push();
        gt(3,0,-13.5);
        drawCubeTexture1(Point(15,1.5,8),img);    
    pop();

	
  // glColor3d(1,1,0);  ///yellow
    push();
        gt(3,1.5,-13.5);
        drawCubeTexture2(Point(15,1.5,8),img2);     
    pop();

  
   // glColor3d(0,1,1);  //light blue
    push();
        gt(2,0,-13.5);
        drawCubeTexture1(Point(1,6,8),img);   
    pop();
  

  // glColor3d(0,0,1);
    push();
        gt(5.5,4,-14.5);
        push();
        // push();
        gr(160,0,0,1);
        drawCubeTexture3(Point(2,1,4),img3);   
    // pop();
        pop();
    pop();
	pop();
}

void Parts2::draw_sleeping_carriageTexture(int img,int img2,int img3){


	glPushMatrix();
	glScaled(3.5,3.5,3.5);
	glTranslated(17,1.7,0);
	glColor3ub(255,0,0);
	drawBedTexture1(img,img2,img3);
	glPopMatrix();

}

