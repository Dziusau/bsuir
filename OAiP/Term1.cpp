//#include <iostream>
//#include <fstream>
//#include <cstdio>
//#include <cstdlib>
//#include <io.h>
//#include <conio.h>
//#include <iomanip>
//#include <Windows.h>
//#include <math.h>
//#include <time.h>
//#define PI 3.1415926
//using namespace std;
//
//struct Marks
//{
//	int math;
//	int physics;
//	int compScience;
//};
//struct Student {
//	char surname[100];
//	int groupNumber;
//	Marks raiting;
//	double avMark;
//};
//
//double getValue(char);
//double findMax(double, double);
//double findMin(double, double);
//double findY(double, int);
//int arraySize(int);
//double findSum(double, double, double, int&);
//void squareMatrix(double**, int, double&, double&);
//int stringLength(char*);
//void changeSecondWord(char*);
//double findS_8_2(double, int);
//double findDif_8_2(double, int);
//void out_Rez(double (*fun)(double, int), double, double, double, int, const char*);
//int binom(int, int);
//int fakt(int);
//int binomRec(int, int);
//Student fillStudent(void);
//Student* readFile(char*, int, int&);
//void writeFile(char*, Student*, int, int);
//
//double getValue(char t) {
//	while (true) {
//		cout << "Enter " << t << " value = ";
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
//double findMax(double a, double b) {
//	return a > b ? a : b;
//}
//double findMin(double a, double b) {
//	return a < b ? a : b; 
//}
//double findSum(double x, double eps, double y, int& k) {
//	double r, sum;
//	r = sum = x;
//	for (k = 1; fabs(y - sum) >= eps; k++) {
//		r = r * x * x / (2. * k * (2. * k + 1));
//		sum += r;
//	}
//	return sum;
//}
//double findY(double x, int n) {
//	return (exp(x) - exp(-x)) / 2;
//}
//int arraySize(int upperBound) {
//	int n;
//	while (true) {
//		cout << "Enter array size: 1 <= n <= " << upperBound << "" << endl;
//		n = getValue('n');
//		if (n < 1 || n > upperBound) {
//			cout << "Your input is invalid. Please, try again.\n" << endl;
//		}
//		else
//			return n;
//	}
//}
//void squareMatrix(double** a, int n, double& sum, double& prod) {
//	int i, j, k, l, mid = n / 2;
//	for (j = 0, k = 0, l = n - 1; j < n; j++) {
//		for (i = 1; i < n; i++) {
//			if (j < mid) {
//				if (i > k&& i != l) {
//					sum += a[i][j];
//					prod *= a[i][j];
//				}
//			}
//			else {
//				if (i > l&& i != k) {
//					sum += a[i][j];
//					prod *= a[i][j];
//				}
//			}
//		}
//		k++;
//		l--;
//	}
//}
//int stringLength(char* a) {
//	int i = 0;
//	while (a[i] != '\0') {
//		i++;
//	}
//	return i;
//}
//void changeSecondWord(char* a) {
//	int i, h, num, n;
//	i = h = 0;
//	num = 1;
//	n = stringLength(a);
//	while (a[i] != '\0') {
//		if (a[i] == ' ' || i == n - 1) {	
//			if (num % 2 == 0)
//				a[h] = '?';
//			num++;
//			h = i + 1;
//		}
//		i++;
//	}
//}
//double findS_8_2(double x, int n) {
//	double r, s;
//	r = s = x;
//	for (int k = 1; k <= n; k++) {
//		r = r * x * x / (2. * k * (2. * k + 1));
//		s += r;
//	}
//	return s;
//}
//double findDif_8_2(double x, int n) {
//	return fabs(findY(x, n) - findS_8_2(x, n));
//}
//void out_Rez(double (*fun)(double, int), double a, double b, double h, int n, const char *str) {
//	int t;
//	for (double x = a, t = 1; x <= b + h / 2; x += h, t++) {
//		cout << t << "\t\tx = " << x << "\t\t" << str << " = " << fun(x, n) << endl;
//	}
//}
//int binom(int n, int k) {
//	int a, b, c;
//	a = b = c = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		a *= i;
//	}
//	for (int i = 1; i <= k; i++) {
//		b *= i;
//	}
//	for (int i = 1; i <= (n-k); i++)
//	{
//		c *= i;
//	}
//	return a / (b * c);
//}
//int fakt(int x) {
//	int r;
//	for (r = 1; x > 0; x--)
//	{
//		r *= x;
//	}
//	return r;
//}
//int binomRec(int n, int k) {
//	return fakt(n) / (fakt(k) * fakt(n - k));
//}
//Student fillStudent(void) {
//	cin.clear();
//	cin.ignore(32767, '\n');
//
//	Student stud;
//	cout << "\nEnter surname: "; cin.getline(stud.surname, 255);
//	cout << "Enter number of group: "; cin >> stud.groupNumber;
//	cout << "Enter marks" << endl;
//	cout << "\tMath: "; cin >> stud.raiting.math;
//	cout << "\tPhysics: "; cin >> stud.raiting.physics;
//	cout << "\tComputer science: "; cin >> stud.raiting.compScience;
//	stud.avMark = (stud.raiting.physics + stud.raiting.math + stud.raiting.compScience) / 3;
//	return stud;
//}
//Student* readFile(char* name, int size_st, int& amountStudents)
//{
//	FILE* file;
//
//	if (!(file = fopen(name, "rb"))) {
//		cout << "Error of file opening!!!" << endl;
//		return 0;
//	}
//	else {
//		int length = _filelength(_fileno(file));
//		amountStudents = length / size_st;
//		Student* stud = new Student[amountStudents];
//		fread(stud, size_st, amountStudents, file);
//		fclose(file);
//		return stud;
//	}
//}
//void writeFile(char* name, Student* stud, int size_st, int amountStudents)
//{
//	FILE* file;
//
//	if (!(file = fopen(name, "wb")))
//		cout << "Error of file opening!!!" << endl;
//	else
//	{
//		fwrite(stud, size_st, amountStudents, file);
//		fclose(file);
//	}
//}
//
///*example
//int main(int argc, char* argv[]) {
//	double x, y, z, a, b, c, rez;
//	puts("\n\tx, y, z = ");
//	scanf_s("%lf%lf%lf", &x, &y, &z);
//	a = pow(tan(x + y), 2);
//	b = exp(y - z);
//	c = sqrt(cos(x * x) + sin(z * z));
//	rez = a - b * c;
//	printf("\n x = %7.3lf\n y = %7.3lf\n z = % 7.3lf\n Result = % lf\n", x, y, z, rez);
//		_getch();
//}*/
///*task 1.1
//int main(int argc, char* argv[]) {
//	double z1, z2, a, b, c, d, e;
//	puts("\n\ta = \n\tb = ");
//	scanf_s("%lf%lf", &a, &b);
//	c = (a - 1) * sqrt(a) - (b - 1) * sqrt(b);
//	d = sqrt(pow(a, 3) * b) + a * b + a * a - a;
//	z1 = c / d;
//	e = sqrt(a) - sqrt(b);
//	z2 = e / a;
//	printf("\n z1 = %7.3lf\n z2 = %7.3lf\n", z1, z2);
//	_getch();
//}*/
///*task 1.2
//int main(int argc, char* argv[]) {
//	double z1, z2, a;
//	do {
//		cout << "a = ";
//		cin >> a;
//	} while (a < 0);
//	z1 = 1 - 0.25 * pow(sin(2 * a), 2) + cos(2 * a);
//	z2 = pow(cos(a), 2) + pow(cos(a), 4);
//	cout << "\nz1 = " << z1 << "\nz2 = " << z2<<endl;
//	system("pause");
//}*/
///*task 1.3
//double getValue(char t) {
//	while (true) {
//		cout << "Enter " << t << " value = " << endl;
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
//int main(int argc, char* argv[]) {
//	double g, x, y, z, a, b, c, d, e;
//	cout << "Chose variant:\n\t1 - your input\n\telse - certain value" << endl;
//	if (_getch() == '1')
//	{
//		x = getValue('x');
//		y = getValue('y');
//		z = getValue('z');
//	}
//	else {
//		x = 12.3E-1, y = 15.4, z = 0.252E3;
//	}
//	d = (pow(fabs(y - 2), 1. / 3) + 3);
//	a = pow(y, x + 1) / d;
//	e = 2. * fabs(x + y);
//	b = (x + y / 2.) / e;
//	c = pow(x + 1, -1 / sin(z));
//	g = a + b * c;
//	cout << "g = " << g << endl;
//}*/
///*task 2.1
//int main(int argc, char* argv[]) {
//	double x, y, z;
//	cout << "Put z = ";
//	z = getValue('z');
//	if (z > 0) {
//		cout << "\nYou put number > 0" << endl;
//		x = sqrt(z);
//	}
//	else {
//		cout << "\nYou put numder <= 0" << endl;
//		x = (3 * pow(z, 3) - z) - 5;
//	}
//	y = cos(5 * x) + sin(1. / 5 * x) + exp(x);
//	cout << "\n\ty = " << y << endl;
//}*/
///*task 2.2
//int main(int argc, char* argv[]) {
//	double x, y, z, a, b, f;
//	z = getValue('z');
//	if (z > 0) {
//		cout << "\nYou put number > 0" << endl;
//		x = sqrt(z);
//	}
//	else {
//		cout << "\nYou put numder <= 0" << endl;
//		x = 3 * z + 1;
//	}
//	cout << "Choose function f(x):\n\t1 - 2x\n\t2 - x^2\n\t3(default) - x/3" << endl;
//	int i;
//	cin >> i;
//	switch (i) {
//	case 1:
//		f = 2 * x;
//		cout << "You chose the first variant" << endl;
//		break;
//	case 2:
//		f = x * x;
//		cout << "You chose the second variant" << endl;
//		break;
//	default:
//		f = x / 3;
//		cout << "You chose the third variant" << endl;
//		break;
//	}
//	cout << "Do you want to put A and B?\n\t1 - Yes\n\telse - No" << endl;
//	if (_getch() == '1') {
//		cout << "\tYou said Yes" << endl;
//		a = getValue('a');
//		b = getValue('b');
//	}
//	else
//	{
//		cout << "\tYou said No (a = b = 1)" << endl;
//		a = b = 1;
//	}
//	y = b * cos(a * f) + sin(x / 5) + a * exp(x);
//	cout << "\ny = " << y << endl;
//}*/
///*task 2.3
//int main(int argc, char* argv[]) {
//	double min, max, x, y, F;
//	x = getValue('x');
//	y = getValue('y');
//	if (x > 0 && y >= 0) {
//		max = findMax(x, (y + sqrt(x)));
//		F = max;
//		cout << "You put x > 0 and y >= 0" << endl;
//	}
//	else if (x < 0){
//		min = findMin(x, y);
//		F = min + sin(x) * sin(x) - cos(y) * cos(y);
//		cout << "You put x < 0" << endl;
//	}
//	else {
//		F = 0.5 * x + exp(y);
//		cout << "You input = variant Else" << endl;
//	}
//	cout << "\tF = " << F << endl;
//}*/
////double mostFrequentMin(double *a) {
////	double n;
////	return n;
////}
//int main(int argc, char* argv[]) {
////TASK 3
////task 3.1
//	/*{
//		double min, max, x, a, b, h, y;
//		cout << "Chose variant:\n\t1 - your input\n\telse - certain value" << endl;
//		if (_getch() == '1') {
//			a = getValue('a');
//			b = getValue('b');
//			h = getValue('h');
//		}
//		else  a = -0.1, b = 2, h = 0.1;
//		min = max = 1 / (x * x - x + 1);
//		for (int n = 1, x = a; x <= b + h / 2; x += h, n++) {
//			y = 1 / (x * x - x + 1);
//			min = findMin(min, y);
//			max = findMax(max, y);
//			cout << "\tn = " << n << "\t\tx = " << x << "\t\tY = " << y << endl;
//		}
//		cout << "\tmin = " << min << "\tmax = " << max << endl;
//	} 
//	system("pause");
////task 3.2
//	{
//		double n, a, b, h, x, y, s, dif;
//		cout << "Chose variant:\n\t1 - your input\n\telse - certain value" << endl;
//		if (_getch() == '1') {
//			a = getValue('a');
//			b = getValue('b');
//			h = getValue('h');
//			n = getValue('n');
//		}
//		else  a = 0.1, b = 1, h = 0.1, n = 10;
//		for (x = a; x <= b + h / 2; x += h) {
//			y = findY(x);
//			double r = s = x;
//			for (int k = 1; k <= n; k++) {
//				r = r * x * x / (2. * k * (2. * k + 1));
//				s += r;
//			}
//			dif = fabs(y - s);
//			cout << "\tx = " << x << "\tS(x) = " << s << "\t\tY(x) = " << y << "\t\t|Y(x) - S(x)| = " << dif << endl;
//		}
//	}
//	system("pause");*/
////task 3.3
//	/*{
//		double a, b, h, x, y, s, eps;
//		int k = 0;
//		cout << "Chose variant:\n\t1 - your input\n\telse - certain value" << endl;
//		if (_getch() == '1') {
//			a = getValue('a');
//			b = getValue('b');
//			h = getValue('h');
//			eps = getValue('eps');
//		}
//		else  a = 0.1, b = 1, h = 0.1, eps = 0.0001;
//		cout << "\tEps = " << eps << endl;
//		for (x = a; x <= b + h / 2; x += h) {
//			y = findY(x);
//			s = findSum(x, eps, y, k);
//			cout << "\tS(x) = " << s << "\t\tY(x) = " << y << "\t\tk = " << k << endl;
//		}
//	}
//	system("pause");*/
////TASK 4
////task 4.1
//	/*{
//		int n, i, b = 20;
//		double a[20], sum = 0;
//		cout << "Chose variant : \n\t1 - your input\n\telse - certain value" << endl;
//		if (_getch() == '1') {
//			n = arraySize(b);
//			cout << "Enter values of arrays' elements" << endl;
//			for (i = 0; i < n ; i++) {		
//				cout << "a[" << i << "] :\t";
//				a[i] = getValue(' ');
//			}
//		}
//		else {
//			n = 20;
//			srand(time(0));
//			for (i = 0; i <= 19; i++) {
//				a[i] = rand() % 21;
//				cout << a[i] << endl;
//			}
//		}
//		for (i = 0; i < n - 1 && a[i] != 0; i++);
//		if (i != n-1) {
//			for (; i < n; i++)
//				sum += abs(a[i]);
//			cout << "Sum = " << sum << endl;
//		}
//		else {
//			if (a[i] != 0)
//				cout << "0 isn't exist" << endl;
//			else
//				cout << "0 is the last element" << endl;
//		}
//	}
//	system("pause");
////task 4.2
//	{
//		int n, i, b = 20;
//		double a[20], sum = 0;
//		cout << "Chose variant : \n\t1 - your input\n\telse - certain value" << endl;
//		if (_getch() == '1') {
//			n = arraySize(b);
//			cout << "Enter values of arrays' elements" << endl;
//			for (i = 0; i < n ; i++) {
//				cout << "a[" << i << "] :\t" << endl;
//				a[i] = getValue('a');
//				cout << a[i] << endl;
//			}
//		}
//		else {
//			n = 20;
//			srand(time(0));
//			for (i = 0; i <= 19; i++) {
//				a[i] = rand() % 21;
//				cout << a[i] << endl;
//			}
//		}
//		int i_min = 0;
//		for (i = 1; i < n; i++) {
//			if (fabs(a[i]) <= fabs(a[i_min]))
//				i_min = i;
//		}
//		cout << "min = " << a[i_min] << "\ni_min = " << i_min << endl;
//		if (i_min != n-1) {
//			for (i = i_min + 1; i <= n - 1; i++)
//				sum += fabs(a[i]);
//			cout << "Sum = " << sum << endl;
//		}
//		else {
//			cout << "Min is the last element" << endl;
//		}
//	}
//	system("pause");*/
//	//task 4.3
///*	{
//		int n, i;
//		cout << "Enter array size\t\t";
//		n = getValue('n');
//		double *a = new double [n];
//		cout << "Chose variant : \n\t1 - your input\n\telse - certain value" << endl;
//		if (_getch() == 1) {
//			cout << "Enter values of arrays' elements" << endl;
//			for (i = 0; i < n; i++) {
//				cout << "a[" << i << "]\t";
//				a[i] = getValue(' ');
//				cout << a[i] << endl;
//			}
//		}
//		else {
//			srand(time(0));
//			for (i = 0; i < n; i++) {
//				a[i] = rand() % 21;
//				cout << a[i] << endl;
//			}
//		}
//		mostFrequentMin(a);
//		delete[]a;
//	}
//	system("pause");*/
////TASK 5
////task 5.1
//	/*{
//		do {
//			int n, m, i, j;
//			double **a;
//			cout << "Enter ammount of lines\t";
//			n = getValue('n');
//			cout << "Enter ammount of columns\t";
//			m = getValue('m');
//			a = new double* [n];
//			cout << "Enter values of arrays' elements" << endl;
//			for (i = 0; i < n; i++) {
//				a[i] = new double[m];
//				for (j = 0; j < m; j++) {
//					cout << "a[" << i << "][" << j << "]\t";
//					a[i][j] = getValue(' ');
//				}
//			}
//			cout << "Your array:" << endl;
//			for (i = 0; i < n; i++) {
//				for (j = 0; j < m; j++) {
//					cout << a[i][j] << "\t";
//				}
//				cout << endl;
//			}
//			for (j = 0; j < m; j++) {
//				for (i = 0; i < n; i++) {
//					if (a[i][j] < 0)
//						break;
//				}
//				if (i == n)
//					break;
//			}
//			if (j == m) {
//				cout << "There is no column only with elements >= 0 !" << endl;
//			}else 
//				cout << "Number of the column only with elements >= 0 :\t" << j+1 << endl;
//			for (i = 0; i < n; i++)
//				delete[]a[i];
//			delete[]a;
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	}
//	system("pause");*/
////task 5.2
//	/*{
//		do {
//			int n, m, i, j, k, i_min, i_max, j_min, j_max;
//			double** a, *z;
//			cout << "Enter ammount of lines:\t\t";
//			n = getValue('n');
//			cout << "Enter ammount of columns:\t";
//			m = getValue('m');
//			a = new double* [n];
//			cout << "Enter values of arrays' elements" << endl;
//			for (i = 0; i < n; i++) {
//				a[i] = new double[m];
//				for (j = 0; j < m; j++) {
//					cout << "a[" << i << "][" << j << "] :\t";
//					a[i][j] = getValue(' ');
//				}
//			}
//			i_min = j_min = i_max = j_max = 0;
//			cout << "Your array:" << endl;
//			for (i = 0; i < n; i++) {
//				for (j = 0; j < m; j++) {
//					cout << a[i][j] << "\t";
//					if (a[i][j] < a[i_min][j_min]) {
//						i_min = i;
//					}
//					if (a[i][j] > a[i_max][j_max]) {
//						i_max = i;
//					}
//				}
//				cout << endl;
//			}
//			cout << "Line with max element: " << i_max << "\nLine with min element: " << i_min << endl;
//				z = a[i_min];
//				a[i_min] = a[i_max];
//				a[i_max] = z;
//			cout << "Array with changed lines:" << endl;
//			for (i = 0; i < n; i++) {
//				for (j = 0; j < m; j++)
//					cout << a[i][j] << "\t";
//				cout << endl;
//			}
//			for (i = 0; i < n; i++)
//				delete[]a[i];
//			delete[]a;
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	}
//	system("pause");*/
////task 5.3
//	/*{
//		do {
//			int n, i, j, k;
//			double** a;
//			double sum = 0, prod = 1;
//			cout << "Enter side of the a square:\t\t";
//			n = getValue('n');
//			a = new double* [n];
//			cout << "Enter values of arrays' elements" << endl;
//			for (i = 0; i < n; i++) {
//				a[i] = new double[n];
//				for (j = 0; j < n; j++) {
//					cout << "a[" << i << "][" << j << "] :\t";
//					a[i][j] = getValue(' ');
//				}
//			}
//			cout << "Your array:" << endl;
//			for (i = 0; i < n; i++) {
//				for (j = 0; j < n; j++) {
//					cout << a[i][j] << "\t";
//				}
//				cout << endl; 
//			}
//			squareMatrix(a, n, sum, prod);
//			cout << "\nSum = " << sum << "\nProduct = " << prod << endl;
//			for (i = 0; i < n; i++)
//				delete[]a[i];
//			delete[]a;
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	}
//	system("pause");*/
////TASK 6
////task 6.1
//	/*{
//		do {
//			setlocale(LC_ALL, "ru");
//			char a[255];
//			cout << "Enter string(10 symbols):\n";
//			cin.getline(a, 255);
//			int n = stringLength(a);
//			if (n == 10) {
//				for (int i = 0; i <= n; i++) {
//					if (a[i] >= 'A' && a[i] <= 'Z') {
//						for (int k = i; k < n; k++)
//							a[k] = a[k + 1];
//						n--;
//						i--;
//					}
//				} 
//				cout << "Modyfied string: " << a << endl;
//			}
//			else
//				cout << "You didn't enter string with 10 symbols!!!" << endl;
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	}
//	system("pause");*/
////task 6.2
//	//{
//	//	do {
//	//		setlocale(LC_ALL, "ru");
//	//		char a[255];
//	//		int strLen, i, k, pos, num, maxWordLen, wordLen;
//	//		cout << "Enter string:\n";
//	//		cin.getline(a, 255);
//	//		strLen = stringLength(a);
//	//		maxWordLen = 0;
//	//		for (i = 0, k = 0, num = 1; i <= strLen; i++){
//	//			if (a[i] == ' ' || i == strLen) {
//	//				wordLen = i - k;
//	//				if (wordLen > maxWordLen) {
//	//					maxWordLen = wordLen;
//	//					pos = k;
//	//					num++;
//	//				}
//	//				k = i + 1;
//	//			} 
//	//		}
//	//		cout << "Position of the largest word: " << pos + 1 << "\nSerial number of the largest word: " << num << endl;
//	//		cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//	//	} while (_getch() == '1');
//	//}
//	//system("pause");
////task 6.3
//	/*{
//		do {
//			setlocale(LC_ALL, "ru");
//			char a[255];
//			cout << "Enter string:\n";
//			cin.getline(a, 255);
//			changeSecondWord(a);
//			cout << "Modyfied string: " << a << endl;
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	}
//	system("pause");*/
////TASK 7
////task 7.2
//	{
//	int size_st = sizeof(Student);
//	do {
//		FILE* file;
//		bool on_off = true;
//		cout << "Enter file name: " << endl;
//		char name[255];
//		cin.getline(name, 255);
//		do {
//			cout << "\nChoose option:\n\t1 - Create\n\t2 - View\n\t3 - Add\n\t4 - Do task\n\t5 - Modify\n\t6 - Delete\n\t7 - Sort\n\tdefault - Exit" << endl;
//			switch (_getch())
//			{
//			case '1':
//				cout << "\nYou chose creating new file" << endl;
//				if (!(file = fopen(name, "wb")))
//					cout << "Error of opening file!!!" << endl;
//				else {
//					Student stud;
//					stud = fillStudent();
//					fwrite(&stud, size_st, 1, file);
//					fclose(file);
//				}
//				break;
//			case '2':
//				cout << "\nYou chose viewing file" << endl;
//				if (!(file = fopen(name, "rb")))
//					cout << "Error of file opening!!!" << endl;
//				else {
//					int length = _filelength(_fileno(file));
//					int amountStudents = length / size_st;
//					Student* stud = new Student[amountStudents];
//					fread(stud, size_st, amountStudents, file);
//					cout << "¹\t\tSurname\t\tGroup number\tMath\tPhysics\tComputer Science\tAverage mark" << endl;
//					for (int i = 0; i < amountStudents; i++) {
//						cout << i + 1 << "\t\t" << stud[i].surname << "\t\t" << stud[i].groupNumber << "\t\t" << stud[i].raiting.math << "\t\t" << stud[i].raiting.physics << "\t\t" << stud[i].raiting.compScience << "\t\t" << stud[i].avMark << endl;
//					}
//					fclose(file);
//					delete[] stud;
//				}
//				break;
//			case '3':
//				cout << "\nYou chose adding to file" << endl;
//				if (!(file = fopen(name, "ab")))
//					cout << "Error of file opening!!!" << endl;
//				else {
//					do {
//						Student stud;
//						stud = fillStudent();
//						fwrite(&stud, size_st, 1, file);
//						cout << "Press '1' if you want to add one more";
//					} while (_getch() == '1');
//					fclose(file);
//				}
//				break;
//			case '4':
//				cout << "\nYou chose doing the task" << endl;
//				if (!(file = fopen(name, "rb")))
//					cout << "Error of file opening!!!" << endl;
//				else {
//					int groupNumb;
//					int length = _filelength(_fileno(file));
//					int amountStudents = length / size_st;
//					Student* stud = new Student[amountStudents];
//					fread(stud, size_st, amountStudents, file);
//					cout << "Enter group number: ";
//					cin >> groupNumb;
//					cout << "\t¹\tSurname\t\tGroup number\tMath\tPhysics\tComputer Science\tAverage mark" << endl;
//					int k = 0;
//					for (int i = 0; i < amountStudents; i++) {
//						if (stud[i].groupNumber == groupNumb && stud[i].raiting.math > 8 && stud[i].raiting.physics > 8 && stud[i].raiting.compScience > 8) {
//							cout << "\t" << i + 1 << "\t" << stud[i].surname << "\t\t" << stud[i].groupNumber << "\t\t" << stud[i].raiting.math << "\t\t" << stud[i].raiting.physics << "\t\t" << stud[i].raiting.compScience << "\t\t" << stud[i].avMark << endl;
//							k++;
//						}
//					}
//					if (k == 0)
//						cout << "There is no student with marks > 8";
//					delete[] stud;
//				}
//				fclose(file);
//				break;
//			case '5':
//			{
//				cout << "\nYou chose modifying file" << endl;
//				int amountStudents;
//				Student* stud = readFile(name, size_st, amountStudents);
//				int i;
//				cout << "Choose number of record, that you want to change: ";
//				cin >> i;
//				i--;
//				cout << "¹\t\tSurname\t\tGroup number\tMath\tPhysics\tComputer Science\tAverage mark" << endl;
//				cout << i + 1 << "\t\t" << stud[i].surname << "\t\t" << stud[i].groupNumber << "\t\t" << stud[i].raiting.math << "\t\t" << stud[i].raiting.physics << "\t\t" << stud[i].raiting.compScience << "\t\t" << stud[i].avMark << endl;
//				cout << "Change: \n\t1 - Surname\n\t2 - group\n\t3 - math mark\n\t4 - physics mark\n\t5 - computer science mark\n\tdefault - the whole record" << endl;
//				switch (_getch()) {
//				case '1':
//					cout << "Enter new surname: ";
//					cin >> stud[i].surname;
//					break;
//				case '2':
//					cout << "Enter new group: ";
//					cin >> stud[i].groupNumber;
//					break;
//				case '3':
//					cout << "Enter new math mark: ";
//					cin >> stud[i].raiting.math;
//					stud[i].avMark = (stud[i].raiting.math + stud[i].raiting.physics + stud[i].raiting.compScience) / 3;
//					break;
//				case '4':
//					cout << "Enter new physics mark: ";
//					cin >> stud[i].raiting.physics;
//					stud[i].avMark = (stud[i].raiting.math + stud[i].raiting.physics + stud[i].raiting.compScience) / 3;
//					break;
//				case '5':
//					cout << "Enter new computer science mark: ";
//					cin >> stud[i].raiting.compScience;
//					stud[i].avMark = (stud[i].raiting.math + stud[i].raiting.physics + stud[i].raiting.compScience) / 3;
//					break;
//				default:
//					stud[i] = fillStudent();
//					break;
//				}
//				writeFile(name, stud, size_st, amountStudents);
//				delete[] stud;
//				break;
//			}
//			case '6':
//			{
//				cout << "You chose deleting file" << endl;
//				int amountStudents;
//				Student* stud = readFile(name, size_st, amountStudents);
//				int i;
//				cout << "Choose number of record, that you want to delete: ";
//				cin >> i;
//				i--;
//				cout << "¹\t\tSurname\t\tGroup number\tMath\tPhysics\tComputer Science\tAverage mark" << endl;
//				cout << i + 1 << "\t\t" << stud[i].surname << "\t\t" << stud[i].groupNumber << "\t\t" << stud[i].raiting.math << "\t\t" << stud[i].raiting.physics << "\t\t" << stud[i].raiting.compScience << "\t\t" << stud[i].avMark << endl;
//				cout << "Do you really want to delete this record?(Y/N)";
//				if (_getch() == 'y' || _getch() == 'Y') {
//					for (; i < amountStudents - 1; i++)
//						stud[i] = stud[i + 1];
//					amountStudents--;
//				}
//				writeFile(name, stud, size_st, amountStudents);
//				delete[] stud;
//				break;
//			}
//			case '7':
//			{
//				cout << "You chose sorting file" << endl;
//				int amountStudents;
//				Student buf;
//				Student* stud = readFile(name, size_st, amountStudents);
//				cout<<"\nChose sort:\n\t1 - Group number\n\t2 - Math marks\n\t3 - Physics marks\n\t4 - Computer Science marks\n\t5 - Average marks\n\tdefault - Surname";
//				switch (_getch()) {
//				case '1':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1') {
//						for (int j = 0; j < amountStudents; j++){
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].groupNumber > stud[i + 1].groupNumber) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					else {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].groupNumber < stud[i + 1].groupNumber) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					writeFile(name, stud, size_st, amountStudents);
//					break;
//				case '2':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1') {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].raiting.math > stud[i + 1].raiting.math) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					else {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].raiting.math < stud[i + 1].raiting.math) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					writeFile(name, stud, size_st, amountStudents);
//					break;
//				case '3':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1') {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].raiting.physics > stud[i + 1].raiting.physics) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					else {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].raiting.physics < stud[i + 1].raiting.physics) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					writeFile(name, stud, size_st, amountStudents);
//					break;
//				case '4':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1') {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].raiting.compScience > stud[i + 1].raiting.compScience) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					else {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].raiting.compScience < stud[i + 1].raiting.compScience) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					writeFile(name, stud, size_st, amountStudents);
//					break;
//				case '5':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1') {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].avMark > stud[i + 1].avMark) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					else {
//						for (int j = 0; j < amountStudents; j++) {
//							for (int i = 0; i < amountStudents - 1; i++) {
//								if (stud[i].avMark < stud[i + 1].avMark) {
//									buf = stud[i];
//									stud[i] = stud[i + 1];
//									stud[i + 1] = buf;
//								}
//							}
//						}
//					}
//					writeFile(name, stud, size_st, amountStudents);
//					break;
//				default:
//					for (int j = 0; j < amountStudents; j++) {
//						for (int i = 0; i < amountStudents - 1; i++) {
//							if (strcmp(stud[i].surname, stud[i + 1].surname) > 0) {
//								buf = stud[i];
//								stud[i] = stud[i + 1];
//								stud[i + 1] = buf;
//							}
//						}
//					}
//					writeFile(name, stud, size_st, amountStudents);
//					break;
//				}
//				delete[] stud;
//				break;
//			}
//			default:
//				cout << "Do you really want to exit?\n\t1 - Yes\n\telse - No";
//				if (_getch() == '1')
//					on_off = false;
//				else
//					break;
//			}
//		} while (on_off);
//		cout << "\nDo you want to work with another file? (Y/N)";
//	} while (_getch() == 'y' || _getch() == 'Y');
//	}
////TASK 8
////task 8.2
//	/*{
//		do {
//			double a, b, h, n;
//			cout << "Chose variant:\n\t1 - your input\n\telse - certain value" << endl;
//			if (_getch() == '1') {
//				a = getValue('a');
//				b = getValue('b');
//				h = getValue('h');
//				n = getValue('n');
//			}
//			else  a = -0.1, b = 2, h = 0.1, n = 10;
//			cout << "Chose function:\n\t1 - Y(x)\n\t2 - S(x)\n\t3 - |Y(x)-S(x)|" << endl;
//			switch (_getch()) {
//			case '1':
//				cout << "You chose Y(x)" << endl;
//				out_Rez(findY, a, b, h, n, "Y(x)");
//				break;
//			case '2':
//				cout << "You chose S(x)" << endl;
//				out_Rez(findS_8_2, a, b, h, n, "S(x)");
//				break;
//			case '3':
//				cout << "You chose |Y(x)-S(x)|" << endl;
//				out_Rez(findDif_8_2, a, b, h, n, "|Y(x)-S(x)|");
//				break;
//			}
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	} 
//	system("pause");*/
////task 8.3
//	/*{
//		do
//		{
//			int n, k;
//			cout << "Enter n and k" << endl;
//			n = getValue('n');
//			k = getValue('k');
//			cout << "Binom = " << binom(n, k) << endl;
//			cout << "BinomRec = " << binomRec(n, k) << endl;
//			cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
//		} while (_getch() == '1');
//	}
//	system("pause");*/
//}