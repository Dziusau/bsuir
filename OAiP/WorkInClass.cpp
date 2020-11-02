//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//int findIndexMax(double* a, int n) {
//	int i_max = 0;
//	for (int i = 1; i < n; i++) {
//		if (a[i_max] < a[i])
//			i_max = i;
//	}
//	return i_max;
//}
//int findIndexMaxRec(double* a, int i_max, int i) {
//	if (i >= 0) {
//		if (a[i_max] < a[i])
//			i_max = i; 
//		findIndexMaxRec(a, i_max, i - 1);
//	}
//	else
//		return i_max;
//
//}
//int findIndexMaxRec(double* a, int n) {
//	if (n < 1)
//		return 0;
//	if (a[n] > a[0])
//		a[0] = a[n];
//	findIndexMaxRec(a, n - 1);
//}
//int main(int argc, char* argv[]) {
//	int n = 5, i;
//	double a[5], p;
//	srand(time(0));
//	for (i = 0; i < n; i++) {
//		a[i] = rand() % 10;
//		cout << a[i] << endl;
//	}
//	cout << "Max element: " << a[findIndexMax(a, n)] << endl;
//	cout << "Max element: " << a[findIndexMaxRec(a, n - 1, n - 2)] << endl;
//	p = a[0];
//	cout << "Max element: " << a[findIndexMaxRec(a, n-1)] << endl;
//	a[0] = p;
//	for (i = 0; i < n; i++) {
//		cout << a[i] << endl;
//	}
//	for (int i = 0; i < 256; i++)
//	{
//		cout << i << "\t" << char(i) << endl;
//	}
//}