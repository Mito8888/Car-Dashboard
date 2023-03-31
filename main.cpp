#include <iostream>
#include <windows.h>
#include <gl/glut.h>
#include "shape.h"
#include <typeinfo>
#include <string>
#include <sstream>

using namespace std;

Shape sprite = Shape();
Shape sprite01 = Shape(100, 100); //Store the base x and y axis values

//General Variable (Common or Temporary Variable)
string text;
GLfloat temp_offset;

/* ===============================================================
 * Functions for Setting Colors Brush (Common Color)
 * =============================================================== */
 void red(){glColor3ub(255, 0, 0);}
 void orange(){glColor3ub(255, 160, 0);}
 void yellow(){glColor3ub(255, 255, 0);}
 void green(){glColor3ub(0, 255, 0);}
 void blue(){glColor3ub(0, 0, 255);}
 void white(){glColor3ub(255, 255, 255);}
 void black(){glColor3ub(0, 0, 0);}
 
 void light_red(){glColor3ub(255, 153, 153);}
 void dark_red(){glColor3ub(178, 0, 0);}
 void light_orange(){glColor3ub(255, 200, 0);}
 void light_blue(){glColor3ub(182, 196, 234);}

/* ===============================================================
 * Functions for Basic Drawing Algorithms
 * =============================================================== */
void simplify_drawQuad(GLfloat left, GLfloat bottom, GLfloat right, GLfloat top){ //position of faces => left with x axis, right with x axis, top with y axis, bottom with y axis
	GLfloat loc_bottom = 750 - bottom;
	GLfloat loc_top = 750 - top;
	
	sprite.drawQuad(left, loc_bottom, right, loc_bottom, right, loc_top, left, loc_top, false);
}

//Inner Line for Speed Meter
void drawMeter(GLfloat x, GLfloat y, GLfloat radius){
	for(GLfloat angle = 0 - 70; angle <= 320 - 70; angle += 10){
		sprite.drawLine(radius * cos(angle * 0.0174532f) + x, radius * sin(angle*0.0174532f) + y, (radius - 15) * cos(angle*0.0174532f) + x, (radius - 15) * sin(angle * 0.0174532f) + y, 3.0);
	}
}

//Outter Line for Speed Meter
void drawMeterLine(GLfloat x, GLfloat y, GLfloat radius, int multiplier){
	for(GLfloat angle = 0 - 70; angle <= 320 - 70; angle += 20 * multiplier){
		sprite.drawLine(radius * cos(angle * 0.0174532f) + x, radius * sin(angle*0.0174532f) + y, (radius - 15) * cos(angle*0.0174532f) + x, (radius - 15) * sin(angle * 0.0174532f) + y, 3.0);
	}
}

//Draw Number in Speed Meter
void drawNumber(GLfloat x, GLfloat y, GLfloat radius, int multiplier, int increasement, int max){
	int number = max;
	
	for(GLfloat angle = 0 - 70; angle <= 320 - 70; angle += 20 * multiplier){
		
		//Convert int to string
		stringstream ss;
		ss << number;
		
		string str_number = ss.str();

		sprite.drawText(str_number.data(), str_number.size() , radius * cos(angle * 0.0174532f) + x, radius * sin(angle*0.0174532f) + y, GLUT_BITMAP_HELVETICA_18);
		
		number = number - increasement;
	}
}

//Draw needle
void drawIndicator(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat radius){ //Need to repair
	glColor3ub(236, 50, 5);
	sprite.drawCircle(x1, y1, 12, true);

	sprite.drawLine(x1, y1, x2, y2, 5);

	black();
	sprite.drawCircle(x1, y1, 7, true);
}

//Draw all temperature bars in engine temperature
void drawTemperatureBar(GLfloat offset, GLfloat thickness){
	glColor3ub(0, 0, 255);
	sprite.drawLine(1012 + offset, 750 - 595, 1012 + offset, 750 - 565, thickness); // default thickness = 10
	glColor3ub(0, 125, 255);
	sprite.drawLine(1024 + offset, 750 - 595, 1024 + offset, 750 - 565, thickness);
	glColor3ub(0, 255, 255);
	sprite.drawLine(1036 + offset, 750 - 595, 1036 + offset, 750 - 565, thickness);
	glColor3ub(0, 255, 125);
	sprite.drawLine(1048 + offset, 750 - 595, 1048 + offset, 750 - 565, thickness);
	glColor3ub(0, 255, 0);
	sprite.drawLine(1060 + offset, 750 - 595, 1060 + offset, 750 - 565, thickness);
	glColor3ub(125, 255, 0);
	sprite.drawLine(1072 + offset, 750 - 595, 1072 + offset, 750 - 565, thickness);
	glColor3ub(255, 255, 0);
	sprite.drawLine(1084 + offset, 750 - 595, 1084 + offset, 750 - 565, thickness);
	glColor3ub(255, 125, 0);
	sprite.drawLine(1096 + offset, 750 - 595, 1096 + offset, 750 - 565, thickness);
	glColor3ub(255, 0, 0);
	sprite.drawLine(1108 + offset, 750 - 595, 1108 + offset, 750 - 565, thickness);
}

/* ===============================================================
 * Layers for Main Drawing Function
 * =============================================================== */
void layer_one(){
/* ===============================================================
 * Create Layout of Dashboard Container
 * =============================================================== */
	orange();
	
	//Container 1
	simplify_drawQuad(420, 650, 770, 20);
	//Container 2
	simplify_drawQuad(30, 650, 370, 440);
	//Container 3
	//simplify_drawQuad(820, 650, 980, 430);
	sprite.drawRect(820, 750 - 650, 160, 220);
	//Container 4
	simplify_drawQuad(1000, 510, 1170, 650);
	//simplify_drawQuad(1000, 490, 1170, 430);
	sprite.drawRect(1000, 750 - 490, 170, 60);
	
	//Inner Container (Top)
	simplify_drawQuad(430, 370, 760, 30);
	simplify_drawQuad(431, 369, 759, 31);
	simplify_drawQuad(432, 368, 758, 32);
	
	//Inner Container 2 (Center)
	simplify_drawQuad(430, 430, 760, 380);
	
	//Inner Container 3 (Bottom)
	simplify_drawQuad(430, 640, 760, 440);
	
/* ===============================================================
 * Draw two Circle for Speed Meter and RPM
 * =============================================================== */
	sprite.drawCircle(210, 750 - 210, 180, false);
	sprite.drawCircle(980, 750 - 210, 180, false);
}

void layer_two(){
/* ===============================================================
 * Speed Meter and RPM Meter
 * =============================================================== */
	glColor3ub(250, 140, 50);
	sprite.drawCircle(210, 750 - 210, 175, false);
	sprite.drawCircle(980, 750 - 210, 175, false);
	
	sprite.drawArc(210, 750 - 210, 0.67, 1, 260);
	sprite.drawArc(980, 750 - 210, 0.67, 1, 260);
 
 	//Draw Danger Zone of Speed and RPM
	//glColor3ub(245, 0, 0);
	red();
	sprite.drawArc(210, 750 - 210, 0.7, 12, 0);
	sprite.drawArc(980, 750 - 210, 0.7, 12, 20);
 
	//Draw Line for speed indicator
	glColor3ub(250, 140, 10);
	drawMeter(210, 750 - 210, 175);
	drawMeter(980, 750 - 210, 175);
	
	drawMeterLine(210, 750 - 210, 160, 1);
	drawMeterLine(980, 750 - 210, 160, 2);
 
	//Draw Text for Speed Value
	light_orange();
	text = "0 KM/H";
	sprite.drawText(text.data(), text.size(), 180, 380, GLUT_BITMAP_HELVETICA_18);
	drawNumber(200, 750 - 215, 130, 1, 20, 320);
	
	text = "0 x1000r/m";
	sprite.drawText(text.data(), text.size(), 935, 380, GLUT_BITMAP_HELVETICA_18);
	drawNumber(975, 750 -215, 130, 2, 1, 8);
}

void layer_three(){
	//Needle for Speed Meter
	//glColor3ub(255, 0, 0);
	red();
	drawIndicator(210, 750 - 210, 160, 750 - 340, 248);
	drawIndicator(980, 750 - 210, 930, 750 - 340, 248);
	
	//Double Signals
	green();
	sprite.drawTriangle(380, 750 - 410, 380, 750 - 370, 340, 750 - 390, true);
	sprite.drawTriangle(800, 750 - 410, 800, 750 - 370, 840, 750 - 390, true);
	
	//Nav map
	//glColor3ub(158, 255, 136);
	//orange();
	glColor3ub(170, 170, 170);
	sprite.drawRect(435, 750 - 365, 320, 330);
}

void layer_four(){
	//Mileage
	//glColor3ub(213, 255, 255);
	black();
	text = "ODO";
	sprite.drawText(text.data(), text.size(), 1010, 750 - 450, GLUT_BITMAP_HELVETICA_12);
	
	text = "KM";
	sprite.drawText(text.data(), text.size(), 1130, 750 - 475, GLUT_BITMAP_HELVETICA_18);
	
	//glColor3ub(210, 253, 250);
	text = "15540";
	sprite.drawText(text.data(), text.size(), 1060, 750 - 475, GLUT_BITMAP_HELVETICA_18);
	
	//Temperature and Fuel Level
	//glColor3ub(213, 255, 255);
	orange();
	text = "Engine Temperature";
	sprite.drawText(text.data(), text.size(), 1010, 750 - 525, GLUT_BITMAP_HELVETICA_12);
	
	text = "*C";
	sprite.drawText(text.data(), text.size(), 1130, 750 - 550, GLUT_BITMAP_HELVETICA_18);
	
	//glColor3ub(210, 253, 250);
	text = "90";
	sprite.drawText(text.data(), text.size(), 1090, 750 - 550, GLUT_BITMAP_HELVETICA_18);
	
	blue();
	text = "C";
	sprite.drawText(text.data(), text.size(), 1018, 750 - 620, GLUT_BITMAP_HELVETICA_18);
	
	red();
	text = "H";
	sprite.drawText(text.data(), text.size(), 1138, 750 - 620, GLUT_BITMAP_HELVETICA_18);
	
	//glColor3ub(213, 255, 255);
	black();
	text = "Fuel Level";
	sprite.drawText(text.data(), text.size(), 830, 750 - 450, GLUT_BITMAP_HELVETICA_12);
	
	sprite.drawLine(900, 750 - 635, 900, 750 - 480, 4);
	
	text = "F";
	sprite.drawText(text.data(), text.size(), 880, 750 - 495, GLUT_BITMAP_HELVETICA_18);
	
	text = "E";
	sprite.drawText(text.data(), text.size(), 880, 750 - 635, GLUT_BITMAP_HELVETICA_18);
}

void layer_five(){
	//Temperature Level
	orange();
	sprite.drawLine(1018, 750 - 600, 1148, 750 - 600, 2);
	drawTemperatureBar(25, 10);
	
	//Fuel Level
	black();
	for(int n = 0;n < 8 * 20;n = n + 20){
		sprite.drawLine(910, 750 - 489 - n, 970, 750 - 489 - n, 15);
	}
	
	//Content of Nav map
	black();
	sprite.drawLine(595, 750 - 365, 595, 750 - 35, 10);
	sprite.drawLine(470, 750 - 236, 680, 750 - 236, 10);
	sprite.drawLine(510, 750 - 315, 510, 750 - 146, 10);
	sprite.drawLine(568, 750 - 120, 730, 750 - 120, 10);
	
	//compass
	glColor3ub(142, 142, 142);
	sprite.drawCircle(470, 750 - 70, 24, true);
	red();
	sprite.drawTriangle(460, 750 - 85, 480, 750 - 85, 470, 750 - 65, true);
	
	text = "N";
	sprite.drawText(text.data(), text.size(), 465, 750 - 60, GLUT_BITMAP_HELVETICA_12);
	
	//glColor3ub(255, 255, 0);
	orange();
	sprite.drawLine(595, 750 - 330, 595, 750 - 35, 6);
	
	red();
	sprite.drawTriangle(580, 750 - 340, 610, 750 - 340, 595, 750 - 310, true);
}

void layer_six(){
	//State of Gear
	//glColor3ub(213, 255, 255);
	orange();
	sprite.drawLine(638, 750 - 570, 720, 750 - 570, 2);
	
	//Draw Gear Number "N" with plot point
	temp_offset = 10;
	sprite.drawPoint(660 - temp_offset, 750 - 560, 8);
	sprite.drawPoint(660 - temp_offset, 750 - 545, 8);
	sprite.drawPoint(660 - temp_offset, 750 - 530, 8);
	sprite.drawPoint(660 - temp_offset, 750 - 515, 8);
	sprite.drawPoint(660 - temp_offset, 750 - 500, 8);
	
	sprite.drawPoint(675 - temp_offset, 750 - 515, 8);
	
	sprite.drawPoint(690 - temp_offset, 750 - 530, 8);
	
	sprite.drawPoint(705 - temp_offset, 750 - 545, 8);
	
	sprite.drawPoint(720 - temp_offset, 750 - 560, 8);
	sprite.drawPoint(720 - temp_offset, 750 - 545, 8);
	sprite.drawPoint(720 - temp_offset, 750 - 530, 8);
	sprite.drawPoint(720 - temp_offset, 750 - 515, 8);
	sprite.drawPoint(720 - temp_offset, 750 - 500, 8);
	
	//Clock
	//green();
	//glColor3ub(100, 255, 0);
	text = "10:10 AM";
	sprite.drawText(text.data(), text.size(), 640, 750 - 610, GLUT_BITMAP_HELVETICA_18);
	
	//glColor3ub(213, 255, 255);
	sprite.drawLine(638, 750 - 620, 720, 750 - 620, 2);

	//Air Condition, indoor and outdoor Temperature
	//glColor3ub(100, 255, 0);
	text = "Outdoor Temperature";
	sprite.drawText(text.data(), text.size(), 450, 750 - 460, GLUT_BITMAP_HELVETICA_12);
	text = "32 *C";
	sprite.drawText(text.data(), text.size(), 450, 750 - 490, GLUT_BITMAP_HELVETICA_18);
	
	text = "Indoor Temperature";
	sprite.drawText(text.data(), text.size(), 450, 750 - 520, GLUT_BITMAP_HELVETICA_12);
	text = "24 *C";
	sprite.drawText(text.data(), text.size(), 450, 750 - 550, GLUT_BITMAP_HELVETICA_18);
	
	text = "Fan Level";
	sprite.drawText(text.data(), text.size(), 450, 750 - 580, GLUT_BITMAP_HELVETICA_12);
	
	//sprite.drawLine(460, 750 - 610, 460, 750 - 590, 20);
	
	for(int n = 0; n <= 120; n=n+30){
		sprite.drawLine(460 + n, 750 - 610, 460 + n, 750 - 590, 20);
	}
	
	//glColor3ub(213, 255, 255);
	sprite.drawLine(450, 750 - 620, 590, 750 - 620, 2);
	
	//Music Player/Radio
	orange();
	//sprite.drawLine(480, 750 - 420, 480, 750 - 390, 10);
	sprite.drawTriangle(440, 750 - 390, 440, 750 - 420, 470, 750 - 405, true);
	sprite.drawLine(480, 750 - 410, 640, 750 - 410, 4);
	sprite.drawCircle(560, 750 - 410, 8, true);
	
	text = "Song";
	sprite.drawText(text.data(), text.size(), 485, 750 - 400, GLUT_BITMAP_HELVETICA_18);
	
	text = "2:42";
	sprite.drawText(text.data(), text.size(), 485, 750 - 425, GLUT_BITMAP_HELVETICA_12);
	
	text = "4:43";
	sprite.drawText(text.data(), text.size(), 620, 750 - 425, GLUT_BITMAP_HELVETICA_12);
	
	text = "FM";
	sprite.drawText(text.data(), text.size(), 650, 750 - 395, GLUT_BITMAP_HELVETICA_12);
	
	text = "AM";
	sprite.drawText(text.data(), text.size(), 650, 750 - 410, GLUT_BITMAP_HELVETICA_12);
	
	text = "Local";
	sprite.drawRect(648, 750 - 427, 34, 14);
	black();
	sprite.drawText(text.data(), text.size(), 650, 750 - 425, GLUT_BITMAP_HELVETICA_12);
	
	orange();
	text = "Volume";
	sprite.drawText(text.data(), text.size(), 700, 750 - 393, GLUT_BITMAP_HELVETICA_12);
	sprite.drawLine(710, 750 - 425, 710, 750 - 415, 12);
	sprite.drawLine(730, 750 - 425, 730, 750 - 405, 12);
	sprite.drawLine(750, 750 - 425, 750, 750 - 395, 12);
}

void layer_seven(){
	//Fuel Symbol
	orange();
	sprite.drawRect(310, 750 - 635, 45, 60);
	sprite.drawRect(305, 750 - 635, 54, 10);
	black();
	sprite.drawRect(314, 750 - 605, 38, 25);
	
	black();
	sprite.drawRect(844, 750 - 565, 30, 40);
	sprite.drawRect(839, 750 - 565, 40, 10);
	orange();
	sprite.drawRect(848, 750 - 540, 20, 10);
	black();
	sprite.drawTriangle(836, 750 - 550, 836, 750 - 530, 826, 750 - 540, true);
	
	//Break Symbol
	red();
	sprite.drawTriangle(290, 750 - 635, 235, 750 - 635, 265, 750 - 580, true);
	black();
	sprite.drawLine(265, 750 - 618, 265, 750 - 600, 6);
	sprite.drawPoint(265, 750 - 625, 6);
	
	//Temperature Symbol
	blue();
	sprite.drawCircle(200, 750 - 625, 10, true);
	sprite.drawLine(200, 750 - 624, 200, 750 - 580, 6);
	sprite.drawLine(200, 750 - 592, 220, 750 - 592, 4);
	sprite.drawLine(200, 750 - 600, 220, 750 - 600, 4);
	sprite.drawLine(200, 750 - 608, 220, 750 - 608, 4);
	
	//ECO Symbol
	//glColor3ub(50, 255, 52);
	green();
	sprite.drawRect(120, 750 - 630, 50, 50);
	black();
	text = "ECO";
	sprite.drawText(text.data(), text.size(), 125, 750 - 610, GLUT_BITMAP_HELVETICA_18);
	
	//Battery Symbol
	glLineWidth(3);
	orange();
	simplify_drawQuad(40, 630, 100, 580);
	text = "+";
	sprite.drawText(text.data(), text.size(), 45, 750 - 595, GLUT_BITMAP_HELVETICA_18);
	text = "-";
	sprite.drawText(text.data(), text.size(), 85, 750 - 595, GLUT_BITMAP_HELVETICA_18);
	
	//Warning Symbol
	red();
	sprite.drawCircle(330, 750 - 530, 25, false);
	sprite.drawLine(330, 750 - 536, 330, 750 - 510, 6);
	sprite.drawPoint(330, 750 - 545, 6);
	
	//Steering Error Symbol
	orange();
	glLineWidth(4);
	sprite.drawCircle(265, 750 - 530, 12, false);
	sprite.drawCircle(265, 750 - 530, 4, true);
	sprite.drawLine(265, 750 - 530, 274, 750 - 522, 5);
	sprite.drawLine(265, 750 - 530, 251, 750 - 522, 5);
	//"!" Sign
	sprite.drawLine(285, 750 - 540, 285, 750 - 510, 6);
	sprite.drawPoint(285, 750 - 545, 6);
	glLineWidth(1);
	
	//Engine Symbol
	orange();
	sprite.drawRect(186, 750 - 550, 45, 30);
	sprite.drawLine(190, 750 - 530, 240, 750 - 530, 8);
	sprite.drawLine(240, 750 - 520, 240, 750 - 550, 6);
	sprite.drawLine(190, 750 - 515, 220, 750 - 515, 6);
	sprite.drawLine(183, 750 - 519, 183, 750 - 555, 5);
	
	//Oil Symbol
	sprite.drawRect(118, 750 - 550, 32, 18);
	sprite.drawLine(148, 750 - 542, 162, 750 - 536, 5);
	sprite.drawLine(166, 750 - 538, 170, 750 - 543, 4);
	sprite.drawLine(132, 750 - 538, 132, 750 - 526, 4);
	sprite.drawLine(122, 750 - 526, 144, 750 - 526, 6);
	sprite.drawLine(110, 750 - 530, 124, 750 - 536, 5);
}

void render(){
/* ===============================================================
 * Basic Setup
 * =============================================================== */
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Black Background easy to manage
	
	//Canvas settings
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1200, 0, 750); //Resolution of the Screen
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
/* ===============================================================
 * Layers for Drawing Whole Car Dashboard
 * =============================================================== */
	layer_one(); //Layout of the Car Dashboard
	layer_two(); //Speed and RPM Meter
	layer_three(); //Basic Components
	layer_four(); //Basic Temperature and Fuel Level info (Display Text Info)
	layer_five(); //Temperature, Fuel Level, and Nav map content
	layer_six(); //State Gear and Clock
	layer_seven(); //Signals (Extras)
	
/* ===============================================================
 * Display All Drawing
 * =============================================================== */
	glFlush();
	glFinish();
}

int main(){
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 750);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("2D objects");
	glutDisplayFunc(render); // Load render function
	glutMainLoop(); // Loop forever
	
	system("PAUSE");
	return 0;
}
