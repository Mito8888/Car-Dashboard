#include "shape.h"

Shape::Shape(){}

Shape::Shape(GLfloat x, GLfloat y){
	this->x = x;
	this->y = y;
}

Shape::~Shape(){}

void Shape::drawPoint(GLfloat x, GLfloat y, GLfloat size){
	glPushMatrix();
	glPointSize(size);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glPopMatrix();	
}

void Shape::drawQuad(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, bool isFill){
	glPushMatrix();
	if(isFill){
		glBegin(GL_QUADS);
	}
	else{
		glBegin(GL_LINE_LOOP);
	}
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
		glVertex2i(x4, y4);
	glEnd();
	glPopMatrix();
}

void Shape::drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height){
	glPushMatrix();
	for(this->x = x; this->x < x + width; this->x++){
		for(this->y = y; this->y < y + height; this->y++){
			this->drawPoint(this->x, this->y, 1.0);
		}
	}
	glPopMatrix();
}

void Shape::drawTriangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, bool isFill){
	glPushMatrix();
	if(isFill){
		glBegin(GL_TRIANGLES);
	}
	else{
		glBegin(GL_LINE_LOOP);
	}
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
	glEnd();
	glPopMatrix();	
}

void Shape::drawPolygon(GLfloat cx, GLfloat cy, GLfloat r, int num_segments, bool isFill){
	glPushMatrix();
	if(isFill){
		glBegin(GL_POLYGON);
	}
	else{
		glBegin(GL_LINE_LOOP);
	}
    for(int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex2f(x + cx, y + cy);

    }
    glEnd();
    glPopMatrix();
}

void Shape::drawCircle(GLfloat x, GLfloat y, GLfloat radius, bool isFill){
	glPushMatrix();
	if(isFill){
		glBegin(GL_POLYGON);
	}
	else{
		glBegin(GL_LINE_LOOP);
	}
	
    float theta;

    for(int i = 0 ; i<360; i++ ){

        theta=i*3.1415926f/180;
        glVertex2i(x + radius*cos(theta), y + radius*sin(theta));
    }
    glEnd();
	glPopMatrix();
}

void Shape::drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat thickness){
	glPushMatrix();
	glLineWidth(thickness);
	glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
	glEnd();
	glPopMatrix();	
	glLineWidth(1);
}

void Shape::drawText(const char *text, GLint length, GLint x, GLint y, void *font){
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	
	glOrtho(0, 1200, 0, 750, -5, 5);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glPushMatrix();
		glLoadIdentity();
		glRasterPos2i(x, y);
		for(int i=0; i<length; i++){
			glutBitmapCharacter(font, (int)text[i]);
		}
	glPopMatrix();
	
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void Shape::drawArc(GLfloat x, GLfloat y, GLfloat scale, GLfloat thickness, int arc_length){
	glPushMatrix();
	glTranslated(x, y, 0);
	glLineWidth(thickness);
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (float angle = 320 - 30; angle <= 320 + 30 + arc_length; angle += 5) {
		glVertex2f((240 * scale) * cos(angle*0.0174532f), (240 * scale) * sin(angle*0.0174532f));
	}
	glEnd();
	
	glPopMatrix();
	
	glTranslated(-x, -y, 0);
}
