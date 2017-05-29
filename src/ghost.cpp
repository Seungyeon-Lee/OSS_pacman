#include "ghost.h"

Ghost::Ghost(float x, float y, int id)
{
	this->x = x;
	this->y = y;
	this->id = id;
	squareSize = 50.0;
}

Ghost::~Ghost()
{

}

void Ghost::setGhost(float x, float y, int id)
{
	this->x = x;
	this->y = y;
	this->id = id;
}

//Method to draw the monster character through consecutive circles algorithm
void Ghost::drawGhost2D(float r, float g, float b)
{
	int x, y;
	glBegin(GL_LINE_LOOP);
	glColor3f(r, g, b);
	//draw the head
	for (int k = 0; k < 32; k++){
		x = (float)k / 2.0 * cos(360 * M_PI / 180.0) + (this->x*squareSize);
		y = (float)k / 2.0* sin(360 * M_PI / 180.0) + (this->y*squareSize);
		for (int i = 180; i <= 360; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos(i * M_PI / 180.0) + (this->x*squareSize);
			y = (float)k / 2.0* sin(i * M_PI / 180.0) + (this->y*squareSize);
			glVertex2f(x, y);
		}
	}
	glEnd();

	//draw body
	glRectf((this->x*squareSize) - 17, this->y*squareSize, (this->x*squareSize) + 15, (this->y*squareSize) + 15);
	glBegin(GL_POINTS);
	glColor3f(0, 0.2, 0.4);

	glPointSize(5.0);
	//draw eyes and legs
	glVertex2f((this->x*squareSize) - 11, (this->y*squareSize) + 14); //legs
	glVertex2f((this->x*squareSize) - 1, (this->y*squareSize) + 14); //legs
	glVertex2f((this->x*squareSize) + 8, (this->y*squareSize) + 14); //legs
	glVertex2f((this->x*squareSize) + 4, (this->y*squareSize) - 3); //eyes
	glVertex2f((this->x*squareSize) - 7, (this->y*squareSize) - 3); //eyes 
	glEnd();
}


//Method to draw the monster character through consecutive circles algorithm
void Ghost::drawGhost3D(float r, float g, float b){

	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(this->x*squareSize, this->y*squareSize, 0);
	glScaled(1, 1, 2);
	glutSolidSphere(16, 10, 10);

	glPopMatrix();
}