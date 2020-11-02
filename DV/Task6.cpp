//#include <vector>
//#include <Windows.h>
//#include <algorithm>
//#include <tchar.h>
//#include "glut.h"
//#include <iostream>
//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glut32.lib")
//using namespace std;
//struct Vector2
//{
//	GLdouble x;
//	GLdouble y;
//};
//struct Point
//{
//	GLdouble x;
//	GLdouble y;
//};
//bool isConvex(vector<Vector2>, int);
//void setPixel(Point);
//void display();
//bool isInside(vector<Point>, vector<Vector2>, Point, Point, Point, int);
//void DrawLine(Point, Point);
//void display()
//{
//	int countPoints;
//	do
//	{
//		system("cls");
//		cout << "Введите количество точек:";
//		cin >> countPoints;
//	} while (countPoints < 3);
//	vector<Point> points(countPoints);
//	for (int i = 0; i < countPoints; i++)
//	{
//		cout << "Point[" << i << "].x:";
//		cin >> points[i].x;
//		cout << "Point[" << i << "].y:";
//		cin >> points[i].y;
//	}
//	vector<Vector2> vectors(countPoints);
//	for (int i = 0; i < countPoints - 1; i++)
//	{
//		vectors[i].x = points[i + 1].x - points[i].x;
//		vectors[i].y = points[i + 1].y - points[i].y;
//	}
//	vectors[countPoints - 1].x = points[0].x - points[countPoints - 1].x;
//	vectors[countPoints - 1].y = points[0].y - points[countPoints - 1].y;
//	if (!isConvex(vectors, countPoints)) cout << "Многоугольник вогнутый\n";
//	else cout << "Многоугольник выпуклый\n";
//	GLdouble xMin = 1000, xMax = -1000;
//	GLdouble yMin = 1000, yMax = -1000;
//	double r = 1, g = 0, b = 0;
//	glColor3i(r, g, b);
//	for (int i = 0; i < countPoints; i++)
//		if (points[i].x < xMin) xMin = points[i].x;
//		else if (points[i].x > xMax) xMax = points[i].x;
//	for (int i = 0; i < countPoints; i++)
//		if (points[i].y < yMin) yMin = points[i].y;
//		else if (points[i].y > yMax) yMax = points[i].y;
//	Point max = { xMax, yMax };
//	Point min = { xMin, yMin };
//	double delta = 1.0 / double(yMax - yMin);
//	for (GLdouble y = yMin; y < yMax; y++)
//	{
//		for (GLdouble x = xMin; x < xMax; x++)
//		{
//			Point current = { x , y };
//			if (isInside(points, vectors, current, max, min, countPoints)) setPixel(current);
//		}
//		r -= delta;
//		b += delta;
//		glColor3f(r, g, b);
//	}
//}
//bool isInside(vector<Point> points, vector<Vector2> vectors, Point currentPoint, Point maxPoint, Point minPoint, int countPoints)
//{
//	Point cur2 = { maxPoint.x + 1, currentPoint.y + 0.5 };
//	Vector2 vec = { cur2.x - currentPoint.x, cur2.y - currentPoint.y };
//	int intersections = 0;
//	int test = 0;
//	for (int i = 0; i < countPoints; i++)
//	{
//		GLdouble a = vectors[i].y;
//		GLdouble b = -vectors[i].x;
//		GLdouble c = -(points[i].x * a) - (points[i].y * b);
//		GLdouble test1 = currentPoint.x * a + currentPoint.y * b + c;
//		GLdouble test2 = cur2.x * a + cur2.y * b + c;
//		if (!(test1 < 0) ^ (test2 < 0)) continue;
//		else
//		{
//			a = (cur2.y - currentPoint.y);
//			b = -(cur2.x - currentPoint.x);
//			c = -(currentPoint.x * a) - (currentPoint.y * b);
//			test1 = points[i].x * a + points[i].y * b + c;
//			if (i + 1 == countPoints)
//			{
//				test2 = points[0].x * a + points[0].y * b + c;
//			}
//			else
//			{
//				test2 = points[i + 1].x * a + points[i + 1].y * b + c;
//			}
//			if (!(test1 < 0) ^ (test2 < 0)) continue;
//			else
//			{
//				int zComponent = vectors[i].x * vec.y - vectors[i].y * vec.x;
//				if (zComponent > 0) intersections++;
//				else if (zComponent < 0) intersections--;
//			}
//		}
//	}
//	if (intersections) return true;
//	else return false;
//}
//bool isConvex(vector<Vector2> vectors, int countPoints)
//{
//	int zComponent, zPrev;
//	zPrev = vectors[0].x * vectors[1].y - vectors[0].y * vectors[1].x;
//	for (int i = 1; i < countPoints - 1; i++)
//	{
//		zComponent = vectors[i].x * vectors[i + 1].y - vectors[i].y * vectors[i + 1].x;
//		if ((zComponent > 0 && zPrev > 0) || (zComponent < 0 && zPrev < 0)) zPrev = zComponent;
//		else return false;
//	}
//	zComponent = vectors[countPoints - 1].x * vectors[0].y - vectors[countPoints - 1].y * vectors[0].x;
//	if ((zComponent > 0 && zPrev > 0) || (zComponent < 0 && zPrev < 0)) return true;
//	else return false;
//}
//void main(int argc, char** argv)
//{
//	setlocale(LC_ALL, "rus");
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(700, 500);
//	glutInitWindowPosition(1000, 200);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glutCreateWindow("Filling");
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, 700, 0, 500);
//	glutDisplayFunc(display);
//	glutMainLoop();
//}
//void setPixel(Point p)
//{
//	glBegin(GL_POINTS);
//	glVertex2f(p.x, p.y);
//	glEnd();
//	glFlush();
//}