//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
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
//double fun(double x) {
//	//return x * x * x - 50 * cos(x);
//	return sin(x) * sin(x) - x / 5.;
//}
//double middle(double a, double b, int n) {
//	double s = 0, h, x;
//	h = (b - a) / n;
//	x = a;
//	for (int i = 0; i < n; i++) {
//		s += fun(x + h / 2);
//		x += h;
//	}
//	return h * s;
//}
//double trapezium(double a, double b, int n) {
//	double s = 0, h, x;
//	h = (b - a) / n;
//	x = a;
//	for (int i = 0; i < n; i++) {
//		s += (fun(x) + fun(x + h)) / 2;
//		x += h;
//	}
//	return h * s;
//}
//double simpson(double a, double b, int n) {
//	double s = 0, h, x;
//	h = (b - a) / n;
//	x = a;
//	for (int i = 0; i < n; i++) {
//		s += fun(x) + 4 * fun(x + h / 2) + fun(x + h);
//		x += h;
//	}
//	return s * h / 6;
//}
//double gauss2(double a, double b, int n) {
//	double s = 0, h, x;
//	h = (b - a) / n;
//	x = a;
//	for (int i = 0; i < n; i++) {
//		s += fun(x + h / 2 * (1 - 0.5773502692)) + fun(x + h / 2 * (1 + 0.5773502692));
//		x += h;
//	}
//	return s * h / 2;
//}
//double gauss3(double a, double b, int n) {
//	double s = 0, h, x;
//	h = (b - a) / n;
//	x = a;
//	for (int i = 0; i < n; i++) {
//		s += 5. / 9 * fun(x + h / 2 * (1 - 0.7745966692)) + 8. / 9 * fun(x + h / 2) + 5. / 9 * fun(x + h / 2 * (1 + 0.7745966692));
//		x += h;
//	}
//	return s * h / 2;
//}
//void epselen(double method(double, double, int), double a, double b, double eps, const char* name) {
//	double I1, I2, err;
//	int n1 = 2;
//	I1 = method(a, b, n1);
//	do {
//		n1 *= 2;
//		I2 = method(a, b, n1);
//		err = abs(I2 - I1);
//		I1 = I2;
//	} while (err > eps);
//	cout << name << endl;
//	cout << "n = " << n1 << endl;
//	cout << "Integral = " << I1 << endl;
//}
//int main(int argc, char* argv[]) {
//	double a, b, eps = 0, h, I;
//	int n;
//	cout << "Function: f(x) = x^3 - 50cos(x)" << endl;
//	do {
//		a = getValue("Input a: ");
//		b = getValue("Input b: ");
//		cout << "Choose method:\n\t1 - Middle\n\t2 - Trapezium\n\t3 - Simpson\n\t4 - Gauss 2\n\t5 - Gauss 3\n\tdefault - Checking efficiency of each method" << endl;
//		switch (_getch()) {
//		case '1':
//			n = getValue("Input n: ");
//			I = middle(a, b, n);
//			break;
//		case '2':
//			n = getValue("Input n: ");
//			I = trapezium(a, b, n);
//			break;
//		case '3':
//			n = getValue("Input n: ");
//			I = simpson(a, b, n);
//			break;
//		case '4':
//			n = getValue("Input n: ");
//			I = gauss2(a, b, n);
//			break;
//		case '5':
//			n = getValue("Input n: ");
//			I = gauss3(a, b, n);
//			break;
//		default:
//			eps = getValue("Input eps: ");
//			epselen(middle, a, b, eps, "Middle: ");
//			epselen(trapezium, a, b, eps, "Trapezium: ");
//			epselen(simpson, a, b, eps, "Simpson: ");
//			epselen(gauss2, a, b, eps, "Gauss 2: ");
//			epselen(gauss3, a, b, eps, "Gauss 3: ");
//			break;
//		}
//		if (!eps) cout << "Integral: " << I << endl;
//		cout << "Press 1, if you want to repeat" << endl;
//	} while (_getch() == '1');
//}