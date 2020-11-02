#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include "glut.h"
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")

void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 20, 0, 30);
}
void paral() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.7, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2i(3, 5);
	glVertex2i(7, 25);
	glVertex2i(17, 25);
	glVertex2i(13, 5);
	glEnd();
	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(20, 30);
	glutCreateWindow("Task 1");
	init();
	glutDisplayFunc(paral);
	glutMainLoop();
}