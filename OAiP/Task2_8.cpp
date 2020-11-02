//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//struct Stack {
//	double root;
//	int iteration;
//	Stack* next;
//};
//void inStackRoot(Stack* begin, double root) {
//	begin->root = root;
//}
//Stack* inStackIteration(Stack* begin, int iteration) {
//	Stack* t = new Stack;
//	t->iteration = iteration;
//	t->next = begin;
//	return t;
//}
//double outStack(Stack*& begin, int& iteration) {
//	Stack* t = begin;
//	double root = t->root;
//	iteration = t->iteration;
//	begin = begin->next;
//	delete t;
//	return root;
//}
//double f(double x) {
//	return x * x * x - 50 * cos(x);
//}
//double df(double x) {
//	return 3 * x * x + 50 * sin(x);
//}
//double d2f(double x) {
//	return 6 * x + 50 * cos(x);
//}
//double getValue(const char* t) {
//	while (true) {
//		cout << t;
//		double x;
//		cin >> x;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(32767, '\n');
//			cout << "Your input is invalid. Please, try again.\n" << endl;
//		}
//		else
//			return x;
//	}
//}
//double MN(Stack*& begin,double alpha, double beta, double eps) {
//	double x0, x, def;
//	int iteration = 0;
//	if (f(alpha) * d2f(alpha) > 0) x0 = alpha;
//	else x0 = beta;
//	do {
//		iteration++;
//		x = x0 - f(x0)/ df(x0);
//		def = abs(x0 - x);
//		x0 = x;
//	} while (def > eps);
//	begin = inStackIteration(begin, iteration);
//	return x0;
//}
//int main(int argc, char* argv[]) {
//	do {
//		Stack* begin = nullptr;
//		int iteration = 0;
//		double a, b, m, eps, y, root;
//		a = getValue("Enter a value: ");
//		b = getValue("Enter b value: ");
//		m = getValue("Enter m value: ");
//		eps = getValue("Enter eps value: ");
//		double x = a, h = (b - a) / m;
//		cout << "x\t\ty" << endl;
//		while (x <= b) {
//			y = f(x);
//			cout << x << "\t\t" << y << endl;
//			x += h;
//			if (y * f(x) <= 0) inStackRoot(begin, MN(begin, x - h, x, eps));
//		}
//		if (begin) {
//			cout << "\tRoots\t\tIterations\t\tCheck" << endl;
//			for (int i = 0; begin; i++) {
//				root = outStack(begin, iteration);
//				cout << i + 1 << "\t" << root << "\t\t" << iteration << "\t\t" << root << "^3 - cos(" << root << ") = " << f(root) << " -> " << int(f(root)) << endl;
//			}
//		}
//		else cout << "There is no roots with such a huge step! Please, try again" << endl;
//		delete begin;
//		cout << "Press 1 if you want to work with another interval" << endl;
//	} while (_getch() == '1');
//}