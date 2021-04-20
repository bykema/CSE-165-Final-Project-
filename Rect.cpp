#include "Rect.h"
#include "GlutApp.h"

Rect::Rect(){
	x = 0;
	y = 0;
	w = 0.5;
	h = 0.5;
	r = 1;
	g = 0;
	b = 0;

	selected = false;
}

Rect::Rect(float x, float y, float w, float h, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	
	selected = false;
}

void Rect::moveUp(float inc){
	y+=inc;
}

void Rect::moveDown(float inc){
	y-=inc;
}

void Rect::moveLeft(float inc){
	x-=inc;
}

void Rect::moveRight(float inc){
	x+=inc;
}

void Rect::draw(float z) const {

	if (selected){
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);

		glVertex3f(x, y, z);
		glVertex3f(x+w, y, z);

		glVertex3f(x+w, y, z);
		glVertex3f(x+w, y-h, z);

		glVertex3f(x+w, y-h, z);
		glVertex3f(x, y-h, z);

		glVertex3f(x, y-h, z);
		glVertex3f(x, y, z);
		glEnd();
	}

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);

	glVertex3f(x, y, z);
	glVertex3f(x+w, y, z);
	glVertex3f(x+w, y-h, z);
	glVertex3f(x, y-h, z);

	glEnd();
}


void Rect::setY(float y){
	this-> y = y;
}

void Rect::setX(float x){
	this-> x = x;
}

float Rect::getY() const {
	return y;
}

float Rect::getX() const {
	return x;
}

float Rect::getW() const {
	return w;
}

float Rect::getH() const {
	return h;
}

void Rect::select(){
	selected = true;
}

void Rect::deselect(){
	selected = false;
}

bool Rect::contains(float x, float y) const{
	return x >= this->x && x <= this->x + w && y <= this->y && y >= this->y - h;
}

bool Rect::didCollide(Rect* anotherRect) const{
	 return anotherRect->contains(x, y) ||
        anotherRect->contains(x + w, y) ||
        anotherRect->contains(x + w, y - h) ||
        anotherRect->contains(x, y - h) || 
		contains(anotherRect->x, anotherRect->y) ||
		contains(anotherRect->x + anotherRect->w, anotherRect->y) ||
		contains(anotherRect->x + anotherRect->w, anotherRect->y - anotherRect->h) ||
		contains(anotherRect->x + anotherRect->w, anotherRect->y - anotherRect->h);
}

