//#include <iostream>
//#include <Windows.h>
//#include <tchar.h>
//#include "glut.h"
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glut32.lib")
//
//void init() {
//	glClearColor(1, 1, 1, 0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0, 200, 0, 150);
//}
//void line() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 0, 0);
//	glBegin(GL_POINT);
//	glVertex2i(0, 0);
//	glVertex2i(50, 145);
//	glEnd();
//	glFlush();
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(0, 100);
//	glutInitWindowSize(400, 300);
//	glutCreateWindow("Example");
//	init();
//	glutDisplayFunc(line);
//	glutMainLoop();
//}