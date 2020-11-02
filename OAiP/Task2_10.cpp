//#include <iostream>
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
//int main(int argc, char* argv[]) {
//	int n, it;
//	double eps, w, de, s, dif, * x, * x0, * d;
//	double** matrix;
//	bool checkDiagonal = false;
//	n = getValue("Enter n value: ");
//	matrix = new double* [n];
//	x = new double[n];
//	x0 = new double[n];
//	d = new double[n];
//	do { 
//		system("cls");
//		cout << "Enter values of elements of matrix and free column\nDiagolan elements must be > then sum of others in row!!!" << endl;
//		for (int i = 0; i < n; i++) {
//			s = 0;
//			matrix[i] = new double[n];
//			for (int j = 0; j < n; j++) {
//				cout << "a[" << i << "][" << j << "]\t";
//				matrix[i][j] = getValue("");
//				if (j != i) s += matrix[i][j]; 
//			}
//			cout << "d[" << i << "]\t";
//			d[i] = getValue("");
//			if (matrix[i][i] < s) {
//				checkDiagonal = true;
//				break;
//			}
//		}
//	} while (checkDiagonal);
//	cout << "Your matrix:" << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			cout << matrix[i][j] << "\t";
//		cout << "|\t" << d[i] << endl;
//	}
//	eps = getValue("Enter epselen value: ");
//	w = 0.2;
//	while (w <= 2) {
//		cout << "-----------------------------------------------------------------------------\nw = " << w << endl;
//		it = 0;
//		for (int i = 0; i < n; i++)
//		{
//			x0[i] = 0;
//			x[i] = 0;
//		}
//		do {
//			de = 0;
//			for (int i = 0; i < n; i++) {
//				s = d[i];
//				for (int j = 0; j < n; j++) {
//					if (i != j)
//						s -= matrix[i][j] * x0[j];
//					else continue;
//				}
//				s /= matrix[i][i];
//				s = w * s + (1 - w) * x[i];
//				dif = abs(x[i] - s);
//				x[i] = s;
//				if (dif > de) de = dif;
//				else continue;
//			}
//			it++;
//			cout << "Iteration: " << it << "\tDelta: " << dif << endl;
//			for (int i = 0; i < n; i++) {
//				x0[i] = x[i];
//				cout << "x[" << i << "] -> " << x[i] << endl;
//			}
//		} while (it <= 100 && de > eps);
//		cout << "\t\tCheck" << endl;
//		for (int i = 0; i < n; i++) {
//			s = 0;
//			for (int j = 0; j < n; j++) {
//				cout << matrix[i][j] << " * " << x[j] << (j == n - 1 ? " = " : " + ");
//				s += matrix[i][j] * x[j];
//			}
//			cout << s << "\t-->\t" << d[i] << endl;
//		}
//		w += 0.2;
//	}
//	for (int i = 0; i < n; i++)
//		delete[] matrix[i];
//	delete[] matrix;
//	delete[] x;
//	delete[] x0;
//	delete[] d;
//}