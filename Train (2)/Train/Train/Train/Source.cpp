
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <camera.h>
#include"texture.h"
#include <heightMap.h>
#include "tgaLoader.h"
#include <3DTexture.h>
#include "Terrain.h"

#include "Helper.h"
#include "Test.h"
#include "Point.h"
#include "Shapes.h"
#include "Parts.h"
#include "Collider.h"
#include "CarriageDriver.h"
//#include "CarriageGame.h"
//#include "CarriageSleeping.h"
#include "Parts2.h"


using namespace std ;

#define FRAMES 500

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default


//Terrain Data
int terrainWidth = 512;
int terrainDepth = 512;
GLubyte* heightData;
int terrainTexture;
double texSStep = 1.0 / 512.0;
double texTStep = 1.0 / 512.0;
int TerrainSize = 512;

TGAImage grassTerrain;
GLUquadric* quadricS = gluNewQuadric();
//Kitchen
int texWood , texFridge , texFrontFridge , texOven , texFrontOven , texInWall ,texOutWall , texTopOven ,texCab,texFrontCab , texSkin , texFrontDoor , texSideDoor,woodtex;  

int mouseX=0,mouseY=0;
bool isClicked=0,isRClicked=0;
int backSky,frontSky,leftSky,rightSky,topSky,bottomSky;
int game_machine,game_machine_screan,game_place,ImageSofa,ImageSofa2,monitor;
int case_back,case_front,case_left,case_right,case_top,case_down,case_inner;
int marbleWhite,plates,marble,grass,wood,blackColor,carpet,diamondPlate,leather,blackMarble,planks,metalPlates2,concrete,fabric;
int google,mainp,vc,disctop,off,display,runp,keyboard,hp,displayPanel;

	
	  int image,img,img1,img2,img4,img5;
	  int bed1,bed2,bed3;
	  int speed=0;


LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
void initImages();
void initLight();
void initMaterial();


GLfloat LightDir[]  = {0.0f,-50.0f,0.0f,1.0f };
GLfloat LightPos[] = { -80.0f,200.0f,-20.0f,1.0f };
GLfloat LightAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat LightDiff[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat LightSpec[] = { 0.2f,0.2f,0.2f,1.0f };

GLfloat MatAmb[] = { 1.0f,1.0f,1.0f,1.0f };
GLfloat MatDif[] = { 0.6f,0.6f,0.6f,1.0f };
GLfloat MatSpec[] = { 0.2f,0.2f,0.2f,1.0f };
GLfloat MatShn[] = { 128.0f };

Camera MyCamera;

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,10000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
GLfloat color[4] = { 0.9, 0.9, 0.9, 1 };
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	initLight();
	initMaterial();
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	MyCamera = Camera();
	MyCamera.Position.x = 33;
	MyCamera.Position.y = 33;
	MyCamera.Position.z = -220;
	//MyCamera.RotateY(180.0);
	
	
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.1f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHT1);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	sndPlaySound("tre.wav",SND_ASYNC);
	initImages();
	return TRUE;										// Initialization Went OK
}

void drawTexQuad(int tex, float repX, float repY);
void drawTexWall();
void drawTexDoor();
void drawDoor();
void drawWalls();
void drawWood();
void drawFoot();
void drawChair();
void drawTable();
void drawSideCab();
void drawFrontCab();
void drawLeftSkin();
void drawG();
void drawOven();
void drawFrontFridge();
void drawSideFridge();
void drawFridge();
void drawCabent();
void drawFullCabs();
void tablewithchair();
void drawKitchen();


void DrowCarriageSleeping();

bool chickDrowCarriages=false;
float angle,x,z;
float mx =1,my =1,mz=1;
float xx =1,yy =1,zz=1;
float tx =0,ty =0,tz=0;
float shutdownLevel =23,levelOpen=0;
float clossdoor1 =0,clossdoor2 =0, clossdoor3 =0,clossdoor4 =0,clossdoor5,clossdoor6,clossdoor7,clossdoor8;
bool isOpenDoor1=false,isOpenDoor2=false;
bool isOpenLabtop=false;
Point oldPositionCamera(MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z);
bool inCollider =false;
bool outCollider =false;

float statusLight=0;
int myPositionStatus;



int hitPart =0;
void hitPoint(){
	if(keys['E']){
		for (int i=0;i<30;i++){
			MyCamera.MoveForward(1.5);
			//door 1
			hitPart=Collider::checkHitSphier(Point(MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z),Point (35,20,0),1);
			if (hitPart!=0)break;
			hitPart=Collider::checkHitSphier(Point(MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z),Point (35,20,-250),2);
			if (hitPart!=0)break;
			hitPart=Collider::checkHitSphier(Point(MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z),Point (62,20,-10),3);
			if (hitPart!=0)break;

			
				} 
		MyCamera.Position.x=oldPositionCamera.x;
		MyCamera.Position.y=oldPositionCamera.y;
		MyCamera.Position.z=oldPositionCamera.z;			 
		}
}
void collider(){
	if(inCollider||outCollider){
		MyCamera.Position.x=oldPositionCamera.x;
		MyCamera.Position.y=oldPositionCamera.y;
		MyCamera.Position.z=oldPositionCamera.z;
		inCollider=false;
		//outCollider=false;
	}else
	{
		oldPositionCamera.x=MyCamera.Position.x;
		oldPositionCamera.y=MyCamera.Position.y;
		oldPositionCamera.z=MyCamera.Position.z;
	}
}


void partsControl(){
	//Door
	if (hitPart==1&&isOpenDoor1==false&&clossdoor1<=24){clossdoor1+=1;if(clossdoor1>=24){ isOpenDoor1=true;hitPart=0;}}
	if (hitPart==1&&isOpenDoor1==true&&clossdoor1>=1){clossdoor1-=1; if(clossdoor1<=1){ isOpenDoor1=false;hitPart=0;}}
	
	if (hitPart==2&&isOpenDoor2==false&&clossdoor2<=24){clossdoor2+=1;if(clossdoor2>=24){ isOpenDoor2=true;hitPart=0;}}
	if (hitPart==2&&isOpenDoor2==true&&clossdoor2>=1){clossdoor2-=1; if(clossdoor2<=1){ isOpenDoor2=false;hitPart=0;}}
	
	//labtop
	if (hitPart==3&&isOpenLabtop==false&&levelOpen<=100){levelOpen+=2;if(levelOpen>=100){ isOpenLabtop=true;hitPart=0;}}
	if (hitPart==3&&isOpenLabtop==true&&levelOpen>=0){levelOpen-=2; if(levelOpen<=0){ isOpenLabtop=false;hitPart=0;}}

	
}
void keybord()
{
	
	if (keys[VK_LEFT])			MyCamera.RotateY(2);
	if (keys[VK_RIGHT])		    MyCamera.RotateY(-2);
	//if (keys[VK_DOWN])	    MyCamera.RotateX(-0.5);
	//if (keys[VK_UP])		    MyCamera.RotateX(0.5);
	if (keys['S'])      MyCamera.MoveForward(-2);
	if (keys['W'])      MyCamera.MoveForward(2);
	if (keys['A'])	    MyCamera.MoveRight(-2);
	if (keys['D'])		MyCamera.MoveRight(2);
	if (keys[VK_UP])    	MyCamera.MoveUpward(0.5);
	if (keys[VK_DOWN])		MyCamera.MoveUpward(-0.5);
	
	if(shutdownLevel<=1)displayPanel=display;
	if(shutdownLevel>1)displayPanel=marbleWhite;
		
	if (keys['T']&&shutdownLevel>0)
	{
		
		shutdownLevel-=1;

		if(xx>=-0.3&&yy>=-0.3&&zz>=-0.3){
			xx-=0.05;
			yy-=0.05;
			zz-=0.05;
		}
		if(shutdownLevel<=0){shutdownLevel=0;glDisable(GL_LIGHT1);}
	}
	if (keys['R']&&shutdownLevel<24) {
		
		shutdownLevel+=1;
		if(xx<=1&&yy<=1&&zz<=1){
			xx+=0.05;
			yy+=0.05;
			zz+=0.05;
			glEnable(GL_LIGHT1);
		
		}
		if(shutdownLevel>23)shutdownLevel=23;
	}
		

	if (keys['7'])  glEnable(GL_LIGHT2);
	if (keys['8'])  glDisable(GL_LIGHT2);
	if (keys['5']){statusLight++;display=mainp;}
	if (keys['4']){statusLight=0;display=off;}
	if(keys['G'])chickDrowCarriages=true;
	if(keys['H'])chickDrowCarriages=false;
}
void mouse (int mouseX, int mouseY, bool isClicked, bool isRClicked)
{

	//if (isClicked)
	//	MyCamera.RotateY(-0.1);
	//if (isRClicked)
	//	MyCamera.RotateY(0.1);


	
	
}


void lighting(){
	LightAmb[0]=xx;
	LightAmb[1]=yy;
	LightAmb[2]=zz;
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	//glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, xxx);
}
void circle(Point center, float radius){
	glPushMatrix();

		glBegin(GL_POINTS);
			for(angle = -3.14f; angle <= 3.14; angle += 0.001)
				{
					x = cos(angle)*radius;
					z = sin(angle)*radius;
					
					glVertex3f(x +center.x, center.y, z+center.z);
					}
		glEnd();
	
	glPopMatrix();
	
}


void DrowCarriageCinma(){
	hitPoint();
	myPositionStatus=Collider::myPosition(Point (MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z));
	partsControl();
	Parts::DrowCarriage(Point(0,0,0),70.0f,70.0f,-250.0f,5,shutdownLevel,clossdoor1,clossdoor2,metalPlates2,plates,fabric);
	Parts::projectionPanel (Point (60,10,-245), -50, 50 , shutdownLevel,displayPanel,statusLight);
	Parts::controlPanel(Point (70,25,-7),-2,15,-10);
	Parts::chairsDistribution (leather,concrete);
	Parts::table(Point (66,1,-1),-15,18,-15,wood);
	
	Parts::labtop(Point (62,20,-3),-6.3,0.1,-9,levelOpen,keyboard,hp,blackColor,display,statusLight);
	
	glPushMatrix();
		glTranslated(35,50,-35);
		glPushMatrix();
			glRotated(-10,1,0,0);
			Shapes::DrowBoxWithTexture(Point (0,0,0),12,4,10,case_front,case_back,case_left,case_left,case_left,case_left,1,1);
		glPopMatrix();
		glPushMatrix();
			glTranslated(5,20,5);
			glPushMatrix();
				glRotated(90,1,0,0);
				glColor3ub(40,40,40);
				gluCylinder(quadricS, 0.5, 0.5, 20, 32, 70);
			glPopMatrix();
		glPopMatrix();
		
	glPopMatrix();
}

float terrainZ=0;
int terrainZRep=0;
void terrain();

void terrainMove();

void cameraMouse();


void DrowCarriages(){
	
	Parts::DrowCarriageWithoutDoors (Point(0,0,1000),70.0f,70.0f,-250.0f,0,metalPlates2,plates,fabric);
	Parts::DrowCarriage (Point(0,0,1250),70.0f,70.0f,-250.0f,0,shutdownLevel,clossdoor1,clossdoor2,metalPlates2,plates,fabric);
	Parts::DrowCarriageWithoutDoors (Point(0,0,1500),70.0f,70.0f,-250.0f,0,metalPlates2,plates,fabric);
	glColor3ub(40,40,40);
	Shapes::DrowBox(Point(0,0,1500),70.0f,70.0f,-2.0f);

	glPushMatrix();
		glTranslated(0,0,1500);
		Parts::chairsDistribution (leather,concrete);
		glTranslated(0,0,-250);
		Parts::chairsDistribution (leather,concrete);
		glTranslated(0,0,-250);
		Parts::chairsDistribution (leather,concrete);
	glPopMatrix();
	
}
void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix
		
	MyCamera.Render();
	 cameraMouse();
	lighting();
	Shapes::DrowBoxWithTexture(Point(-2500,-2500,-2500),5000,5000,5000,leftSky,rightSky,frontSky,backSky,bottomSky,topSky,1,1);
	
	


	keybord();
	mouse (mouseX, mouseY,isClicked, isRClicked);
	//terrain();	
	//terrainMove();
	//inCollider=Collider::SquareInCollider(0,-250,70,0,Point (MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z));
	
	outCollider=Collider::chairsCollider(Point (MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z));
	if(outCollider==false)
	outCollider=Collider::wallsCollider(Point (MyCamera.Position.x,MyCamera.Position.y,MyCamera.Position.z));


	collider();
		 

	DrowCarriageCinma();
	Parts2::DrowCarriage(shutdownLevel,metalPlates2,plates,fabric,game_machine,game_machine_screan,game_place,ImageSofa,wood,monitor, case_left, case_front, case_top);
		
	  CarriageDriver::DrowCarriage(metalPlates2,plates,fabric);
	  DrowCarriageSleeping();
	  
	  DrowCarriages();

	

	Parts::DrowCarriage (Point(0,0,500),70.0f,70.0f,-250.0f,0,shutdownLevel,clossdoor1,clossdoor2,metalPlates2,plates,fabric);

	drawKitchen();
    glFlush();											// Done Drawing The Quad	
	
    //DO NOT REMOVE THIS
	SwapBuffers(hDC);			
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
		case WM_MOUSEMOVE:
		{
		mouseX = (int)LOWORD(lParam); mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
		}
		case WM_LBUTTONUP:
		isClicked = false; break;
		case WM_RBUTTONUP:
		isRClicked = false; break;
		case WM_LBUTTONDOWN:
		isClicked = true; break;
		case WM_RBUTTONDOWN:
		isRClicked = true; break;

	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Train",1350,690,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,0,50,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
	}

	return 0;

}




void initImages(){
	backSky = LoadTexture("images/skybox/Daylight Box_Back.bmp");
	frontSky = LoadTexture("images/skybox/Daylight Box_Front.bmp");
	leftSky = LoadTexture("images/skybox/Daylight Box_Left.bmp");
	rightSky = LoadTexture("images/skybox/Daylight Box_Right.bmp");
	topSky = LoadTexture("images/skybox/Daylight Box_Top.bmp");
	bottomSky = LoadTexture("images/skybox/Daylight Box_Bottom.bmp");

	keyboard = LoadTexture("images/keyboard.bmp");
	grass = LoadTexture("images/Grass.bmp");
	wood = LoadTexture("images/Wood.bmp");
	carpet = LoadTexture("images/Carpet.bmp");
	plates = LoadTexture("images/MetalPlates.bmp");
	diamondPlate = LoadTexture("images/DiamondPlate.bmp");
	marble = LoadTexture("images/Marble.bmp");
	planks = LoadTexture("images/Planks.bmp");
	leather = LoadTexture("images/Leather2.bmp");
	fabric = LoadTexture("images/Fabric.bmp");
	concrete = LoadTexture("images/Concrete.bmp");
	metalPlates2 = LoadTexture("images/MetalPlates2.bmp");
	marbleWhite = LoadTexture("images/MarbleWhite.bmp");
	blackColor = LoadTexture("images/black.bmp");
	blackMarble = LoadTexture("images/BlackMarble.bmp");
	hp = LoadTexture("images/hp_labtop.bmp");
	
	//display 
	off = LoadTexture("images/display/off.bmp");
	google = LoadTexture("images/display/google.bmp");
	mainp = LoadTexture("images/display/main.bmp");
	vc = LoadTexture("images/display/vc.bmp");
	disctop = LoadTexture("images/display/disctop.bmp");
	runp = LoadTexture("images/display/runp.bmp");
	display=off;
	displayPanel=marbleWhite;
	//Terrain
	heightData = new GLubyte[terrainWidth*terrainDepth];
	heightData = LoadHeightMap("images\\data\\Islands.bmp");
	//terrainTexture = LoadTexture("images\\data\\TerrainTex.bmp");
	//terrainTexture = LoadTexture("images\\data\\grass.bmp");

	terrainTexture = LoadTexture("images\\data\\Terrain005_1K_Details.bmp");
	terrainTexture = LoadTexture("images\\data\\Terrain005_1K_Color.bmp");

	//game
	game_machine=LoadTexture("images\\G\\game.bmp",255);
	game_machine_screan=LoadTexture("images\\G\\scren_game.bmp",255);
	game_place=LoadTexture("images\\G\\game_place.bmp",255);
	monitor=LoadTexture("images\\G\\monitor.bmp",255);
    ImageSofa=LoadTexture("images\\Carpet.bmp",255);
	ImageSofa2=LoadTexture("images/blue.bmp",255);
	//Kitchen
	texWood = LoadTexture("mytex\\wood.bmp");
	texFridge = LoadTexture("mytex\\Fridge.bmp");
	texFrontFridge = LoadTexture("mytex\\FrontFradge.bmp");
	texOven = LoadTexture("mytex\\Fridge.bmp");
	texTopOven = LoadTexture("mytex\\topoven.bmp");
	texFrontOven=LoadTexture("mytex\\frontoven.bmp");
	texInWall = LoadTexture("mytex\\InWall.bmp");
	texOutWall=LoadTexture("mytex\\yy.bmp");
	texFrontCab=LoadTexture("mytex\\front-cabinets.bmp");
	texCab=LoadTexture("mytex\\cab.bmp");
	texSkin=LoadTexture("mytex\\tifal.bmp");
	texFrontDoor = LoadTexture("mytex\\front-door.bmp");
	texSideDoor = LoadTexture("mytex\\side-door.bmp");
	woodtex = LoadTexture("mytex\\woodtex.bmp");


	//case
	case_back = LoadTexture("case/back.bmp");
	case_front = LoadTexture("case/front.bmp");
	case_left = LoadTexture("case/left.bmp");
	case_right = LoadTexture("case/right.bmp");
	case_top = LoadTexture("case/top.bmp");
	case_down = LoadTexture("case/dwon.bmp");
	case_inner = LoadTexture("case/inner.bmp");

	//sleeping


	
	 bed2=LoadTexture("images/pinck1.bmp "); 
	 bed3=LoadTexture("images/pillow.bmp ");
	   image=LoadTexture("images/brown-wood3.bmp",255);
	

	
}

void initLight(){

	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDir);

	glLightfv(GL_LIGHT2, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpec);
	//glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, Light2Dir);
	//glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 50.0f);
}

void initMaterial(){
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);
}

//camera mouse

int fromRadian(float angle)
{
	return (angle / 3.14f) * 180;
}


float cam_rad = 400.0f;
int cam_ax = 0, cam_ay = 15;
POINT mouse_pos;
bool main_menu = false;


void cameraMouse(){

	GetCursorPos(&mouse_pos);
	if (keys[VK_ESCAPE]){ main_menu = !main_menu; KillGLWindow();}
	ShowCursor(main_menu);
	if (!main_menu) cam_ax = (cam_ax % 360) - fromRadian(asin((mouse_pos.x - 320)*1.0 / cam_rad));
	if (!main_menu) cam_ay = (cam_ay % 360) + fromRadian(asin((mouse_pos.y - 240)*1.0 / cam_rad));
	if (cam_ay > 80) cam_ay = 80;
	if (cam_ay < -88) cam_ay = -88;
	if (!main_menu) SetCursorPos(320, 240);
	MyCamera.RotateY(cam_ax);
	MyCamera.MoveUpward(-cam_ay);
	cam_ax=0;
	cam_ay=0;
	if(MyCamera.Position.y>40)MyCamera.Position.y=40;
	if(MyCamera.Position.y<10)MyCamera.Position.y=10;
}

void terrain(){
		glPushMatrix();
	Shapes::DrowBoxWithTexture(Point(0,-3,-2500),75,3,5000,terrainTexture,10,100);
	glScaled(1,2,10);
	glTranslated(-245,-7,0);
	glPushMatrix();
	glRotated(180,0,1,0);
	Terrain::drawMyTerrain(terrainWidth,terrainDepth,terrainTexture,texSStep,texTStep,heightData);
	
	glPopMatrix();
		glTranslated(575,0,0);
		Terrain::drawMyTerrain(terrainWidth,terrainDepth,terrainTexture,texSStep,texTStep,heightData);

	glPopMatrix();
		
	
}


void terrainMove(){

	glPushMatrix();
	glTranslated(0,0,terrainZ-2500);
		terrain();
	glPopMatrix();
	
	terrainZ+=10;
	
	if(terrainZ>500&&terrainZRep<4){terrainZ=0;terrainZRep++;}
	if(terrainZ>5000&&terrainZRep>=4){terrainZ=4000;terrainZRep++;}
	

}







// Kitchen

void drawTexQuad(int tex, float repX, float repY){
	float xxx = 1, yyy = 1;
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, tex);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(repX, 0);
		glVertex3f(-xxx, -yyy, 0);
		glTexCoord2f(repX, repY);
		glVertex3f(-xxx, yyy, 0);
		glTexCoord2f(0, repY);
		glVertex3f(xxx, yyy, 0);
		glTexCoord2f(0, 0);
		glVertex3f(xxx, -yyy, 0);
	}
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void drawTexWall(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texOutWall,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texInWall,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texOutWall,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texOutWall,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texOutWall,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texOutWall,1,1);
	}glPopMatrix();
}
void drawTexDoor(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texFrontDoor,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texFrontDoor,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texSideDoor,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texSideDoor,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texSideDoor,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texSideDoor,1,1);
	}glPopMatrix();
}
void drawDoor(){
	static float w =6.5 , h =6, doorX=0;
	int doorOpenState =0;
	if (doorX < 2 && keys[VK_NUMPAD9]){
		doorX += 0.01;
	}
	if (doorX > 0 && keys[VK_NUMPAD7]){
		doorX -= 0.01;
	}

	if (keys[VK_NUMPAD6]){
		doorOpenState = 1;
	}

	if (keys[VK_NUMPAD4]){
		doorOpenState = 2;
	}

	while(doorX < 2 && doorOpenState == 1){
		doorX += 0.01;
	}
	while(doorX > 0 && doorOpenState == 2){
		doorX -= 0.01;
	}


	//above door
	glPushMatrix();{
		glTranslatef(4.5,9,0.5);
		glRotatef(180,0,1,0);
		glScalef(0.33*(w),0.25*(h),0.01);
		drawTexWall();
	}glPopMatrix();
	//door
	glPushMatrix(); {
		glTranslatef(4.5,0,0.5);
		glRotatef(180,0,1,0);
		glScalef(0.33*(w),0.75*(h),0.01);
		glTranslatef(doorX,0,0);
		drawTexDoor();
	}glPopMatrix();
}
void drawWalls(){
	static float w =6.5 , h =6; 
	//door
	glPushMatrix();{
		drawDoor();
	}glPopMatrix();
	//front
	glPushMatrix(); {
		glTranslatef(-2,0,0.5);
		glRotatef(180,0,1,0);
		glScalef(0.7*(w),h,0.02);
		drawTexWall();
	}glPopMatrix();
	//right
	glPushMatrix(); {
		glTranslatef(6.5,0,-6.19);
		glRotatef(270,0, 1, 0);	
		glScalef(6.7,6,0.2);
		drawTexWall();
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslatef(-6.1,0,-6.21);
		glRotatef(90,0, 1, 0);	
		glScalef(6.5,6,0.2);
		drawTexWall();
	}glPopMatrix();
	//back
	glPushMatrix(); {
		glTranslatef(0,0,-12.5);
		glScalef(6.3,6,0.2);
		drawTexWall();
	}glPopMatrix();
	//floor
	glPushMatrix(); {
		glTranslatef(0.2,11.8,-13);
		glScalef(6.5,6.5,0.2);
		glRotatef(270,1,0,0);
		drawTexWall();
	}glPopMatrix();
	//roof
	glPushMatrix(); {
		glTranslatef(0.2,11.8,-13);
		glRotatef(-270,1,0,0);
		glScalef(6.5,6.5,0.2);
		drawTexWall();
	}glPopMatrix();
}
void drawWood(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texWood,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texWood,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texWood,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texWood,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texWood,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texWood,1,1);
	}glPopMatrix();
}
void drawFoot(){
	glPushMatrix();{
		glTranslatef(0.49,-1.2,1.3);
		glScalef(0.02,0.6,0.04);
		drawWood();
	}glPopMatrix();
	glColor3f(1,1,1);
}
void drawChair(){
	//back
	glPushMatrix();{
		glTranslatef(0,0.02,0.28);
		glScalef(0.6,0.8,0.03);
		drawWood();
	}glPopMatrix();
	//seat
	glPushMatrix();{
		glTranslatef(0,0,0.25);
		glScalef(0.6,0.04,0.6);
		glRotatef(90,1,0,0);
		drawWood();
	}glPopMatrix();
	//foot right front
	glPushMatrix();{
		drawFoot();
	}glPopMatrix();
	//foot right back
	glPushMatrix();{
		glTranslatef(0,0,-0.9);
		drawFoot();
	}glPopMatrix();
	//foot left back
	glPushMatrix();{
		glTranslatef(-1,0,-0.9);
		drawFoot();
	}glPopMatrix();
	//foot left front
	glPushMatrix();{
		glTranslatef(-1,0,0);
		drawFoot();
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
}
void drawTable(){
	//base
	glPushMatrix();{
		glTranslatef(0,-0.7,0.6);
		//glTranslatef(0,0,0.6);
		glScalef(2,0.06,1.3);
		glRotatef(90,1,0,0);
		drawWood();
	}glPopMatrix();
	//foot right front
	glPushMatrix();{
		glTranslatef(0.7,-0.7,0.3);
		glScalef(2,2,2);
		drawFoot();
	}glPopMatrix();
	//foot right back
	glPushMatrix();{
		glTranslatef(0.7,-0.7,-1.6);
		glScalef(2,2,2);
		drawFoot();
	}glPopMatrix();
	//foot left front
	glPushMatrix();{
		glTranslatef(-2.7,-0.7,0.3);
		glScalef(2,2,2);
		drawFoot();
	}glPopMatrix();
	//foot leftt back
	glPushMatrix();{
		glTranslatef(-2.7,-0.7,-1.6);
		glScalef(2,2,2);
		drawFoot();
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
}
void drawSideCab(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
}
void drawFrontCab(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texFrontCab,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texCab,1,1);
	}glPopMatrix();
}
void drawLeftSkin(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texSkin,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texSkin,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texSkin,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texSkin,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texSkin,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texSkin,1,1);
	}glPopMatrix();
}
void drawG(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texOven,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texFrontOven,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texOven,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texOven,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(270,1,0,0);
		drawTexQuad(texTopOven,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texOven,1,1);
	}glPopMatrix();
}
void drawOven(){
	glPushMatrix();{
		drawG();
	}glPopMatrix();
}
void drawFrontFridge(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texFrontFridge,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
}
void drawSideFridge(){
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1);	
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//front
	glPushMatrix();{
		glTranslatef(0,1,1);
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslated(1, 1, 0);	
		glRotatef(90,0, 1, 0);	
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	glColor3f(1.0f,1.0f,1.0f);
	//top
	glPushMatrix(); {	
		glTranslated(0, 2, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
	//bottom
	glPushMatrix(); {	
		glTranslated(0, 0.04, 0);	
		glRotatef(90,1,0,0);
		drawTexQuad(texFridge,1,1);
	}glPopMatrix();
}
void drawFridge()
{
	//front
	glPushMatrix(); {
		glTranslated(0, 1, 1);	
		glScalef(1.1f,2.8f,0.2f);
		glPushMatrix();
		glRotated(90,0,1,0);
		drawFrontFridge();
		glPopMatrix();
	}glPopMatrix();
	//back
	glPushMatrix(); {
		glTranslated(0, 1, -1.1);	
		glScalef(1.1f,2.8f,0.2f);
		drawSideFridge();
	}glPopMatrix();
	//right
	glPushMatrix(); {
		glTranslated(0.89, 1, 0);	
		glRotatef(90,0,1,0);
		glScalef(1.1f,2.8f,0.2f);
		drawSideFridge();
	}glPopMatrix();
	//left
	glPushMatrix(); {
		glTranslated(-0.9, 1, 0);	
		glRotatef(90,0,1,0);
		glScalef(1.1f,2.8f,0.2f);
		drawSideFridge();
	}glPopMatrix();
	//top
	glPushMatrix(); {
		glTranslated(0, 6.7, 0);
		glRotatef(180,1,0,0);
		glScalef(1.1f,0.1f,1.1f);
		drawSideFridge();
	}glPopMatrix();
}
void drawCabent(){
	//front
	glPushMatrix();{
		glScalef(0.6,0.8,0.03);
		//glRotatef(180,0,1,0);
		drawFrontCab();
	}glPopMatrix();
	//right
	glPushMatrix();{
		glTranslatef(0.57,0,-0.6);
		glRotatef(90,0,1,0);
		glScalef(0.6,0.8,0.03);
		drawSideCab();
	}glPopMatrix();
	//left
	glPushMatrix();{
		glTranslatef(-0.57,0,-0.6);
		glRotatef(90,0,1,0);
		glScalef(0.6,0.8,0.03);
		drawSideCab();
	}glPopMatrix();
	//back
	glPushMatrix();{
		glTranslatef(0,0,-1.2);
		glScalef(0.6,0.8,0.03);
		drawSideCab();
	}glPopMatrix();
	//top
	glPushMatrix();{
		glTranslatef(0,1.56,-1.2);
		glRotatef(90,1,0,0);
		glScalef(0.56,0.6,0.03);
		drawSideCab();
	}glPopMatrix();
	//bottom
	glPushMatrix();{
		glTranslatef(0,0.01,-1.2);
		glRotatef(90,1,0,0);
		glScalef(0.56,0.6,0.03);
		drawSideCab();
	}glPopMatrix();
}
void drawFullCabs(){
	glPushMatrix();
	for (int i = 0; i <= 5; i++)
	{
	
		glTranslatef(0,0,-10);
		glPushMatrix();
			glTranslatef(-26,30,-50);
			glPushMatrix();{
				//glTranslatef(-14,13,-55.8);
				glRotatef(90,0,1,0);
				glScalef(8,10,8);
				drawCabent();
			}glPopMatrix();
		glPopMatrix();
	}
	glPopMatrix();
/*

	glPushMatrix();{
		glTranslatef(-7,13,-55.8);
		glScalef(6,4.5,4.5);
		drawCabent();
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(0,13,-55.8);
		glScalef(6,4.5,4.5);
		drawCabent();
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(7,13,-55.8);
		glScalef(6,4.5,4.5);
		drawCabent();
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(14,13,-55.8);
		glScalef(6,4.5,4.5);
		drawCabent();
	}glPopMatrix();


	glPushMatrix();{
		glTranslatef(-3.7,8.8,-55.8);
		glScalef(14,0.4,2.5);
		drawLeftSkin();
	}glPopMatrix();*/
	 
	
}


void drowSphere(){
	
	glPushMatrix();

		glBegin(GL_LINES);
		glVertex3f(0,2,0);
		glVertex3f(0,10,0);
		glEnd();
	if(statusLight>0)glEnable(GL_LIGHT2);
		glColor4f(1.0f,0.9f,0.1f,10.0f);
		gluSphere(quadricS,2,32,32);

		
	glPopMatrix();
	glColor3ub(255,255,255);
	glDisable(GL_LIGHT2);
}
void tablewithchair(){

	glPushMatrix();
		glTranslated(20,3,-50);
		glPushMatrix();{
			glTranslatef(0,8,-80);
			glScalef(7,7,7);
			drawChair();
		}glPopMatrix();
		glPushMatrix();{
			glTranslatef(0,10,-60);
			glScalef(5,5,5);
			drawTable();
		}glPopMatrix();
	glPopMatrix();
}
void drawKitchen(){
	glPushMatrix();
	
		for (int i = 0; i <= 7; i++)
		{
			if(i==3||i==4)continue;
			Shapes::DrowBoxWithTexture(Point(0,0,450-(10*i)),10,17,-10,texCab,texCab,texCab,woodtex,texCab,texCab,1,1);
		}
		Shapes::DrowBoxWithTexture(Point(0,17,450),10,0.4,-30,texSkin,1,1);
		Shapes::DrowBoxWithTexture(Point(0,17,400),10,0.4,-30,texSkin,1,1);

		Shapes::DrowBoxWithTexture(Point(0,12,420),10,0.4,-20,marbleWhite,1,1);
		Shapes::DrowBoxWithTexture(Point(1,12,420),0.4,5,-20,texSkin,1,1);
		Shapes::DrowBoxWithTexture(Point(9.6,12,420),0.4,5,-20,texSkin,1,1);
		Shapes::DrowBoxWithTexture(Point(0,12,420),10,5,-0.4,texSkin,1,1);
		Shapes::DrowBoxWithTexture(Point(0,12,400),10,5,0.4,texSkin,1,1);




			glPushMatrix();
			
			glTranslated(35,55,375);

		 drowSphere();

		
		glPopMatrix();
		
		glPushMatrix();
			glTranslated(5,12,410);
			glPushMatrix();
				glRotated(90,1,0,0);
				glColor3ub(50,50,50);
				gluCylinder(quadricS, 0.5, 0.5, 20, 32, 70);
			glPopMatrix();
		glPopMatrix();
		glTranslated(35,0,500);

		/*glPushMatrix();
			glTranslated(125,0,-100);
			glPushMatrix();
				glRotated(90,0,1,0);
				glPushMatrix();
			
					tablewithchair();
					glTranslated(20,0,0);
					tablewithchair();
					glTranslated(20,0,0);
					tablewithchair();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();*/

		glPushMatrix();{
			glScalef(10,15,12);
			glTranslatef(2.5,0,-5);
			glRotatef(-90,0,1,0);
			drawOven();
		}glPopMatrix();
		glPushMatrix();{
			glTranslatef(-20.5,-5,-25);
			glRotatef(90,0,1,0);
			glScalef(7,7,7);
			drawFridge();
			glPopMatrix();
		}


		glPushMatrix();{
			
			drawFullCabs();
		}glPopMatrix();

	glPopMatrix();
}




void DrowCarriageSleeping(){

	  
/*

	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glTranslated(50,0,20);
	glScaled(50,50,50);
	Parts2::draw_sofa(ImageSofa,ImageSofa2);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_TEXTURE_2D);
	glTranslated(80,0,20);
	glScaled(50,50,50);
	Parts2::draw_sofa(ImageSofa,ImageSofa2);
	glPopMatrix();*/

	//glPushMatrix();
	//glTranslated(0,0,0);
	//Parts2::draw_office_carriage(monitor);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslated(40,3,120);
	//glRotated(0,1,0,90);
	//glScaled(10,10,10);
	//Parts2::draw_game_machine(game_machine,game_machine_screan,game_place);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslated(0,0,0);
	//glScaled(0.8,1,1);
	//Parts2::table(image);	
	//Parts2::draw_advanced_monitor( monitor);
	//glPopMatrix();
	
	Parts::DrowCarriage (Point(0,0,750),70.0f,70.0f,-250.0f,0,shutdownLevel,0,0,metalPlates2,plates,fabric);
	
		//Parts2::draw_eating_carriageTexture(img,img1,img4,img5);
	
	glPushMatrix();
	glTranslated(-65,-5,630);
		Parts2::draw_sleeping_carriageTexture(image,bed2,bed3);
	glPopMatrix();

		
	glPushMatrix();
	glTranslated(-65,-5,690);
		Parts2::draw_sleeping_carriageTexture(image,bed2,bed3);
	glPopMatrix();

		glPushMatrix();
	glTranslated(-65,-5,730);
		Parts2::draw_sleeping_carriageTexture(image,bed2,bed3);
	glPopMatrix();

}



