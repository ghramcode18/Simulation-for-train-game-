#include "Collider.h"



int Collider::myPosition(Point position){

	if (position.x>=23&&position.x<=46&&position.z>=-20&&position.z<=-1)return 1;
	if (position.x>=23&&position.x<=46&&position.z>=-249&&position.z<=-229)return 2;
	return 0;
	/*
	1 door1
	2 door2
	
	*/
}

	

int Collider::checkHitSphier(Point camera,Point P,int partNum)
{

	if((P.x-camera.x)*(P.x-camera.x) + (P.y-camera.y)*(P.y-camera.y) + (P.z-camera.z)*(P.z-camera.z) <=100)return partNum;
	return 0;
}

bool Collider::SquareInCollider(float minX,float minZ,float maxX,float maxZ,Point camera)
{
	if(camera.x>minX&&camera.x<maxX &&camera.z>minZ&&camera.z<maxZ ){
		return false;
	}
	
		return true;
	
}

bool Collider::SquareOutCollider(float minX,float minZ,float maxX,float maxZ,Point camera)
{
	if(camera.x<=minX||camera.x>=maxX ||camera.z<=minZ||camera.z>=maxZ ){
		return false;
	}
	
	return true;
	
}



bool Collider::chairsCollider(Point camera)
{
	bool isCollider =false;
	

		for(int i=0; i<=10;i++){
		for(int j=0; j<=2;j++){
			isCollider=Collider::SquareOutCollider(1+(j*10),-25-(i*16)-10,1+(j*10)+9,-40-(i*16)+1,Point (camera.x,camera.y,camera.z));
			if (isCollider==true)break;
			isCollider=Collider::SquareOutCollider(40+(j*10),-25-(i*16)-10,40+(j*10)+9,-40-(i*16)+1,Point (camera.x,camera.y,camera.z));
			if (isCollider==true)break;
			
		}
		if (isCollider==true)break;
	}
		return isCollider;
}






bool Collider::wallsCollider(Point camera)
{
	bool isCollider =false;
	
	isCollider=Collider::SquareOutCollider(-5,-500,1,2000,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(70,-500,75,2000,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(0,-5,23,5,Point (camera.x,camera.y,camera.z));//z=0
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(46,-5,70,5,Point (camera.x,camera.y,camera.z));//z=0
		if (isCollider==true)return isCollider;


	isCollider=Collider::SquareOutCollider(0,-255,23,-245,Point (camera.x,camera.y,camera.z));//z=-250
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(46,-255,70,-245,Point (camera.x,camera.y,camera.z));//z=-250
		if (isCollider==true)return isCollider;


		//driver
	isCollider=Collider::SquareOutCollider(0,-370,70,-360,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(0,-370,30,-340,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(40,-370,70,-340,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;


	isCollider=Collider::SquareOutCollider(1,-200,30,-40,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;
	isCollider=Collider::SquareOutCollider(40,-200,70,-40,Point (camera.x,camera.y,camera.z));
		if (isCollider==true)return isCollider;

	return isCollider;
}