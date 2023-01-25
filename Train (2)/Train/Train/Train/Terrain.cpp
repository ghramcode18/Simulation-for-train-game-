#include "Terrain.h"




void Terrain::drawMyTerrain(int terrainWidth,int terrainDepth,int terrainTexture,double texSStep,double texTStep,GLubyte* heightData) {

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glTranslatef(-terrainWidth / 2.0, 0, -terrainDepth / 2.0);
	glScaled(1, 0.3, 1);
	glBindTexture(GL_TEXTURE_2D, terrainTexture);
	for (int i = 5; i < terrainDepth - 5; i++) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 5; j < terrainWidth - 5; j++) {

			glTexCoord2d(j*texSStep, i*texTStep);
			glVertex3f(j, heightData[j + i*terrainDepth], i);

			glTexCoord2d(j*texSStep, (i + 1)*texTStep);
			glVertex3f(j, heightData[j + (i + 1)*terrainDepth], i + 1);

			glTexCoord2d((j + 1)*texSStep, i*texTStep);
			glVertex3f(j + 1, heightData[(j + 1) + i*terrainDepth], i);

			glTexCoord2d((j + 1)*texSStep, (i + 1)*texTStep);
			glVertex3f(j + 1, heightData[(j + 1) + (i + 1)*terrainDepth], i + 1);

		}
		glEnd();
	}

	glDisable(GL_TEXTURE_2D);

	glPopMatrix();


}
