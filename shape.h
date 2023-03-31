#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <iostream>
#include "math.h"
#include <GL/glut.h>

using namespace std;

class Shape{
public:
	GLfloat x, y;
	
	Shape();
	Shape(GLfloat x, GLfloat y);
	~Shape();
	
	void drawPoint(GLfloat x, GLfloat y, GLfloat size);
	void drawQuad(GLfloat x1, GLfloat y1,
			  GLfloat x2, GLfloat y2,
			  GLfloat x3, GLfloat y3,
			  GLfloat x4, GLfloat y4,
			  bool isFill);
	void drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
	void drawPolygon(GLfloat cx, GLfloat cy, GLfloat r, int num_segments, bool isFill);
	void drawTriangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, bool isFill);
	void drawCircle(GLfloat x, GLfloat y, GLfloat radius, bool isFill);
	void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness);
	void drawText(const char *text, GLint length, GLint x, GLint y, void *font);
	void drawArc(GLfloat x, GLfloat y, GLfloat scale, GLfloat thickness, int arc_length);
};

#endif
