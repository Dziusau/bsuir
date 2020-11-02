//#include <Windows.h>
//#include <tchar.h>
//#include "glut.h"
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glut32.lib")
//using namespace std;
//void init(void) {
//	glClearColor(0, 0, 0, 0);
//	glMatrixMode(GL_PROJECTION);
//	gluOrtho2D(0, 50, 0, 50);
//}
//void line(void) {
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLineWidth(10);
//	glEnable(GL_LINE_SMOOTH);
//	glEnable(GL_LINE_STIPPLE);
//	glLineStipple(1, 0x1C47);
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0);
//	glVertex2f(10, 20);
//	glColor3f(0, 0.8, 1);
//	glVertex2f(20, 20);
//	glEnd();
//	glDisable(GL_LINE_SMOOTH);
//	glDisable(GL_LINE_STIPPLE);
//	glFlush();
//}
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Task 7");
//	init();
//	glutDisplayFunc(line);
//	glutMainLoop();
//}