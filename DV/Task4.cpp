//#include <iostream>
//#include <Windows.h>
//#include <tchar.h>
//#include "glut.h"
//#include <cmath>
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glut32.lib")
//using namespace std;
//void init() {
//	glClearColor(0, 0, 0, 0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(-35, 35, -35, 35);
//}
//void setPixel(int x, int y) {
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	glFlush();
//}
//void circlePlotPoint(int xc, int yc, int x, int y) {
//	setPixel(xc + x, yc + y);
//	setPixel(xc + x, yc - y);
//	setPixel(xc - x, yc + y);
//	setPixel(xc - x, yc - y);
//	setPixel(xc + y, yc + x);
//	setPixel(xc + y, yc - x);
//	setPixel(xc - y, yc + x);
//	setPixel(xc - y, yc - x);
//}
//void circleMiddlePoint(int xc, int yc, int r) {
//	int p = 1 - r;
//	int x = 0, y = r;
//	while (x <= y) {
//		circlePlotPoint(xc, yc, x, y);
//		x++;
//		if (p < 0)
//			p += 2 * x + 1;
//		else {
//			y--;
//			p += 2 * (x - y) + 1;
//		}
//	}
//}
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 1, 1);
//	circleMiddlePoint(0, 17, 15);
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Task 4");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//}