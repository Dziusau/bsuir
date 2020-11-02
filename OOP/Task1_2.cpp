//#include <iostream>
//#include <iomanip>
//#include <conio.h>
//using namespace std;
//
//ostream& table(ostream& stream) {
//	stream << setw(3) << setfill(' ') << '|' << setw(3) << setprecision(3);
//	return stream;
//}
//double getValue(const char* text) {
//	double value;
//	while (true) {
//		cout << text;
//		cin >> value;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(32767, '\n');
//			cout << "Your input is invalid. Please, try again.\n" << endl;
//		}
//		else
//			return value;
//	}
//}
//
//template <typename T>
//class Array {
//private:
//	T ** array;
//	int size;
//public:
//	Array(int);
//	Array(const Array&);
//	Array(const Array&, int);
//	~Array();
//	void ViewArray();
//	T FindMax();
//};
// template<typename T>
// Array<T>::Array(int size) {
//	 this->size = size;
//	 array = new T * [size];
//	 for (int i = 0; i < size; i++) {
//		 array[i] = new T[size];
//		 for (int j = 0; j < size; j++) {
//			 cout << "Enter array[" << i << "][" << j << "] value:";
//			 array[i][j] = getValue(" ");
//		 }
//	 }
// }
// template<typename T>
// Array<T>::Array(const Array& ob) {
//	 size = ob.size;
//	 array = new T * [size];
//	 for (int i = 0; i < size; i++) {
//		 array[i] = new T[size];
//		 for (int j = 0; j < size; j++) {
//			 array[i][j] = ob.array[i][j];
//		 }
//	 }
// }
// template<typename T>
// Array<T>::Array(const Array& ob, int number) {
//	 size = ob.size - 1;
//	 array = new T * [size];
//	 for (int i = 0; i < size; i++) {
//		 array[i] = new T[size];
//		 for (int j = 0; j < size; j++) {
//			 array[i][j] = ob.array[(i < number) ? i : (i + 1)][(j < number) ? j : (j + 1)];
//		 }
//	 }
// }
// template<typename T>
// Array<T>::~Array() {
//	 for (int i = 0; i < size; i++) {
//		 delete[] array[i];
//	 }
//	 delete[] array;
// }
// template<typename T>
// void Array<T>::ViewArray() {
//	 for (int i = 0; i < size; i++) {
//		 for (int j = 0; j < size; j++) {
//			 cout << table << array[i][j];
//		 }
//		 cout << endl;
//	 }
// }
// template<typename T>
// T Array<T>::FindMax() {
//	 T max = array[0][0];
//	 for (int i = 0; i < size; i++) {
//		 for (int j = 0; j < size; j++) {
//			 if (abs(array[i][j]) > max) {
//				 max = array[i][j];
//			 }
//		 }
//	 }
//	 return max;
// }
//
//int main() {
//	bool repeat;
//	int size;
//	size = getValue("Enter size of the Matrix: ");
//	Array<double> matrix(size);
//	do {
//		repeat = true;
//		cout << "Choose function:\n\t1 - view Matrix\n\t2 - find max element\n\t3 - create new Matrix\n\tdefault - exit" << endl;
//		switch (_getch()) {
//		case '1':
//			matrix.ViewArray();
//			break;
//		case '2':
//			cout << "Max element of the Matrix: " << matrix.FindMax() << endl;
//			break;
//		case '3': 
//		{
//			int number = getValue("Enter number of column and line, that you want to delete: ") - 1;
//			Array<double> newMatrix(matrix, number);
//			newMatrix.ViewArray();
//			break; 
//		}
//		default:
//			repeat = false;
//			break;
//		}
//	} while (repeat);
//}