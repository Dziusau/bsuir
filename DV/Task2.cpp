//#include <iostream>
//#include <Windows.h>
//#include <tchar.h>
//#include "glut.h"
//#include <cmath>
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glut32.lib")
//
//void init() {
//	glClearColor(0, 0, 0, 0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(-20, 20, -20, 20);
//}
//void setPixel(int x, int y) {
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	glFlush();
//}
//inline int round_k(const float a) {
//	return int(a + 0.5);
//}
//void lineCDA(int x0, int y0, int xEnd, int yEnd) {
//	int dx = xEnd - x0, dy = yEnd - y0, step;
//	float xInc, yInc, x = x0, y = y0;
//	step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
//	xInc = float(dx) / float(step);
//	yInc = float(dy) / float(step);
//	setPixel(round_k(x), round_k(y));
//	for (int i = 0; i < step; i++){
//		x += xInc;
//		y += yInc;
//		setPixel(round_k(x), round_k(y));
//	}
//}
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 1, 1);
//	lineCDA(-1, 2, -8, -10);
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 300);
//	glutCreateWindow("Task 2");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//}