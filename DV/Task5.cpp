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
//void ellipsPlotPoint(int xc, int yc, int x, int y) {
//	setPixel(xc + x, yc + y);
//	setPixel(xc + x, yc - y);
//	setPixel(xc - x, yc + y);
//	setPixel(xc - x, yc - y);
//}
//void ellipsMiddlePoint(int xc, int yc, int rx, int ry) {
//	int p = ry * ry - rx * rx * ry + 0.25 * rx * rx;
//	int x = 0, y = ry;
//	while ((rx * rx * y) > (x * ry * ry)) {
//		ellipsPlotPoint(xc, yc, x, y);
//		x++;
//		if (p < 0)
//			p += ry * ry * (2 * x + 1);
//		else {
//			y--;
//			p += ry * ry * (2 * x + 1) - 2 * rx * rx * y;
//		}
//	}
//	while (y >= 0) {
//		ellipsPlotPoint(xc, yc, x, y);
//		y--;
//		if (p > 0)
//			p += rx * rx * (1 - 2 * y);
//		else {
//			x++;
//			p += rx * rx * (1 - 2 * y) + 2 * x * ry * ry;
//		}
//	}
//}
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 1, 1);
//	ellipsMiddlePoint(0, 0, 8, 3);
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Task 5");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//}