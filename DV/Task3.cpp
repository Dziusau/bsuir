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
//	gluOrtho2D(0, 30, 0, 20);
//}
//void setPixel(int x, int y) {
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	glFlush();
//}
//void linesBrasenhem() {
//	int x0, y0, xEnd, yEnd;
//	cout << "Enter position of the first point: "; cin >> x0 >> y0;
//	cout << "Enter position of the last point: "; cin >> xEnd >> yEnd;
//	int dx = abs(xEnd - x0), dy = abs(yEnd - y0);
//	int x, y;
//	if (dx > dy) {
//		int p = 2 * dy - dx;
//		if (x0 > xEnd) 
//		{
//			x = xEnd;
//			y = yEnd;
//			yEnd = y0;
//			y0 = y;
//			xEnd = x0;
//		}
//		else {
//			x = x0;
//			y = y0;
//		}
//		setPixel(x, y);
//		while (x < xEnd) {
//			x++;
//			if (p < 0) {
//				p += 2 * dy;
//			}
//			else {
//				if (y0 < yEnd)
//					y++;
//				else
//					y--;
//				p += 2 * (dy - dx);
//			}
//			setPixel(x, y);
//		}
//	}
//	else {
//		int p = 2 * dx - dy;
//		if (y0 > yEnd) {
//			x = xEnd;
//			y = yEnd;
//			xEnd = x0;
//			x0 = x;
//			yEnd = y0;
//		}
//		else {
//			x = x0;
//			y = y0;
//		}
//		setPixel(x, y);
//		while (y < yEnd) {
//			y++;
//			if (p < 0) {
//				p += 2 * dx;
//			}
//			else {
//				if (x0 < xEnd)
//					x++;
//				else
//					x--;
//				p += 2 * (dx - dy);
//			}
//			setPixel(x, y);
//		}
//	}
//}
//void myDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 1, 1);
//	linesBrasenhem();
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 300);
//	glutCreateWindow("Task 3");
//	init();
//	glutDisplayFunc(myDisplay);
//	glutMainLoop();
//}