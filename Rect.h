// #ifndef RECT_H
// #define RECT_H

// #include "Shape.h"

// class Rect: public Shape{
// protected:
// 	float x;
// 	float y;
// 	float w;
// 	float h;
// 	float r;
// 	float g;
// 	float b;

// public:
// 	Rect();
// 	Rect(float, float, float, float, float r=1, float g=0, float b=0);

// 	void draw(float z=0) const;

// 	void setY(float y);
// 	float getY() const;
// 	float getX() const;
// 	void setX(float x);


// 	bool contains(float, float) const;
// };

// #endif

#ifndef RECT_H
#define RECT_H

class Rect{
protected:
	float x;
	float y;
	float w;
	float h;
	float r;
	float g;
	float b;

	bool selected;

public:
	Rect();
	Rect(float, float, float, float, float r=1, float g=0, float b=0);

	void draw(float z = 0) const;

	void setY(float y);
	float getY() const;
	float getX() const;
	void setX(float x);

	float getW () const;
	float getH () const;

	void moveUp(float inc=0.01);
	void moveDown(float inc=0.01);
	void moveLeft(float inc=0.01);
	void moveRight(float inc=0.01);

	void select();
	void deselect();

	bool contains(float, float) const;

	bool didCollide(Rect* anotherRect) const;
};

#endif
