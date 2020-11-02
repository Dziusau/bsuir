//#include <iostream>
//#include <string>
//#include <fstream>
//#include <cstdio>
//#include <cstdlib>
//#include <io.h>
//#include <conio.h>
//#include <iomanip>
//#include <Windows.h>
//using namespace std;
//struct Student {
//	char fio[255];
//	int math;
//	int physics;
//	int russian;
//	double avMark;
//};
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
//Student fillStudent(void) {
//	cin.clear();
//	cin.ignore(32767, '\n');
//	Student stud;
//	cout << "\nEnter FIO: "; cin.getline(stud.fio, 255);
//	cout << "Enter marks: " << endl;
//	stud.math = getValue("\tMath: ");
//	stud.physics = getValue("\tPhysics: ");
//	stud.russian = getValue("\tRussian language: ");
//	stud.avMark = (stud.math + stud.physics + stud.russian) / 3.;
//	return stud;
//}
//Student* readFile(char* name, int size_st, int& amountStudents)
//{
//	FILE* file;
//	if (!(file = fopen(name, "rb"))) {
//		cout << "File openning error!!!" << endl;
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
//	if (!(file = fopen(name, "wb")))
//		cout << "File openning error!!!" << endl;
//	else
//	{
//		fwrite(stud, size_st, amountStudents, file);
//		fclose(file);
//	}
//}
//void quickSort(Student* stud, double* arr, int first, int last) {
//	int f = first, l = last;
//	Student buf;
//	double a, mid;
//	mid = arr[(f + l) / 2];
//	do {
//		while (arr[f] < mid) f++;
//		while (arr[l] > mid) l--;
//		if (f <= l) {
//			a = arr[f];
//			arr[f] = arr[l];
//			arr[l] = a;
//			buf = stud[f];
//			stud[f] = stud[l];
//			stud[l] = buf;
//			f++;
//			l--;
//		}
//	} while (f < l);
//	if (first < l) quickSort(stud, arr, first, l);
//	if (f < last) quickSort(stud, arr, f, last);
//}
//int binarySearch(double* arr, int size, double key) {
//	int mid, left = 0, right = size;
//	while (true) {
//		mid = (left + right) / 2;
//		if (key < arr[mid]) right = mid - 1;
//		else if (key > arr[mid]) left = mid + 1;
//		else {
//			while (arr[mid] < key + 0.0005 && arr[mid] > key - 0.0005) mid--;
//			return mid + 1;
//		}
//		if (left > right) return -1;
//	}
//}
//int main(int argc, char* argv[])
//{
//	int size_st = sizeof(Student);
//	bool on_off;
//	do {
//		FILE* file;
//		on_off = true;
//		cout << "Enter file name: " << endl;
//		char name[255];
//		cin.getline(name, 255);
//		do {
//			cout << "\nChoose option:\n\t1 - Create\n\t2 - View\n\t3 - Add\n\t4 - Modify\n\t5 - Delete\n\t6 - Direct selection sort\n\t7 - Quick sort\n\t8 - Linear search\n\t9 - Binary search\n\t10 - Do task\n\tdefault - Exit" << endl; 
//			int option; cin >> option;
//			switch (option)
//			{
//			case 1: case 3:
//			{
//				if (option == 1) {
//					cout << "\nYou chose creating file" << endl;
//					if (!(file = fopen(name, "wb"))) {
//						cout << "File openning error!!!" << endl;
//						break;
//					}
//				}
//				else {
//					cout << "\nYou chose adding to file";
//					if (!(file = fopen(name, "ab"))) {
//						cout << "File openning error!!!" << endl;
//						break;
//					}
//				}
//				do {
//					Student stud;
//					stud = fillStudent();
//					fwrite(&stud, size_st, 1, file);
//					cout << "Press '1' if you want to add one more";
//				} while (_getch() == '1');
//				fclose(file);
//				break;
//			}
//			case 2:
//			{
//				cout << "\nYou chose viewing file" << endl;
//				if (!(file = fopen(name, "rb")))
//					cout << "File openning error!!!" << endl;
//				else {
//					int amountStudents;
//					Student* stud = readFile(name, size_st, amountStudents);
//					cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//					for (int i = 0; i < amountStudents; i++) {
//						cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//					}
//					delete[] stud;
//				}
//				break; 
//			}
//			case 4:
//			{
//				cout << "\nYou chose modifying file" << endl;
//				int amountStudents;
//				Student* stud = readFile(name, size_st, amountStudents);
//				int i;
//				cout << "Choose number of record, that you want to change: ";
//				cin >> i;
//				i--;
//				cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//				cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//				cout << "Change: \n\t1 - FIO\n\t2 - math mark\n\t3 - physics mark\n\t4 - russian mark\n\tdefault - the whole record" << endl;
//				switch (_getch()) 
//				{
//				case '1':
//					cin.clear();
//					cin.ignore(32767, '\n');
//					cout << "Enter new FIO: ";
//					cin.getline(stud[i].fio, 255);
//					break;
//				case '2':
//					stud[i].math = getValue("Enter new math mark: ");
//					stud[i].avMark = (stud[i].math + stud[i].physics + stud[i].russian) / 3.;
//					break;
//				case '3':
//					stud[i].physics = getValue("Enter new physics mark: ");
//					stud[i].avMark = (stud[i].math + stud[i].physics + stud[i].russian) / 3.;					
//					break;
//				case '4':
//					stud[i].russian = getValue("Enter new russian mark: ");
//					stud[i].avMark = (stud[i].math + stud[i].physics + stud[i].russian) / 3.;
//					break;
//				default:
//					stud[i] = fillStudent();
//					break;
//				}
//				writeFile(name, stud, size_st, amountStudents);
//				delete[] stud;
//				break;
//			}
//			case 5:
//			{
//				cout << "\nYou chose deleting file" << endl;
//				int amountStudents;
//				Student* stud = readFile(name, size_st, amountStudents);
//				int i;
//				cout << "Choose number of record, that you want to delete: ";
//				cin >> i;
//				i--;
//				cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//				cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//				cout << "Do you really want to delete this record?\n\t1 - Yes\n\telse - No";
//				if (_getch() == '1') {
//					for (; i < amountStudents - 1; i++)
//						stud[i] = stud[i + 1];
//					amountStudents--;
//				}
//				writeFile(name, stud, size_st, amountStudents);
//				delete[] stud;
//				break;
//			}
//			case 6:
//			{
//				cout << "\nYou chose Direct selection sorting file" << endl;
//				int amountStudents, m;
//				Student buf;
//				Student* stud = readFile(name, size_st, amountStudents);
//				cout << "\nChoose sort:\n\tdefault - FIO\n\t1 - Math marks\n\t2 - Physics marks\n\t3 - Russian language marks\n\t4 - Average marks";
//				switch (_getch()) 
//				{
//				case '1':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1')
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].math < stud[m].math) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					else
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].math > stud[m].math) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					break;
//				case '2':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1')
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].physics < stud[m].physics) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					else
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].physics > stud[m].physics) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					break;
//				case '3':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1')
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].russian < stud[m].russian) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					else
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].russian > stud[m].russian) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					break;
//				case '4':
//					cout << "\nSort ascending(1) or decending(default)?";
//					if (_getch() == '1')
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].avMark < stud[m].avMark) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					else
//						for (int j = 0; j < amountStudents - 1; j++) {
//							m = j;
//							for (int i = j + 1; i < amountStudents; i++)
//								if (stud[i].avMark > stud[m].avMark) m = i;
//							buf = stud[m];
//							stud[m] = stud[j];
//							stud[j] = buf;
//						}
//					break;
//				default:
//					for (int j = 0; j < amountStudents; j++)
//						for (int i = 0; i < amountStudents - 1; i++)
//							if (strcmp(stud[i].fio, stud[i + 1].fio) > 0) {
//								buf = stud[i];
//								stud[i] = stud[i + 1];
//								stud[i + 1] = buf;
//							}
//					break;
//				}
//				writeFile(name, stud, size_st, amountStudents);
//				delete[] stud;
//				break;
//			}
//			case 7:
//			{
//				cout << "\nYou chose Quick sorting file" << endl;
//				int amountStudents;
//				Student* stud = readFile(name, size_st, amountStudents);
//				double* marks = new double[amountStudents];
//				cout << "\nChoose sort:\n\tdefault - Average marks\n\t1 - Math marks\n\t2 - Physics marks\n\t3 - Russian language marks";
//				switch (_getch()) 
//				{
//				default:
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].avMark;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					break;
//				case '1':
//					for (int i = 0; i < amountStudents; i++) 
//						marks[i] = stud[i].math;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					break;
//				case '2':
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].physics;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					break;
//				case '3':
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].russian;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					break;
//				}
//				writeFile(name, stud, size_st, amountStudents);
//				delete[] stud;
//				delete[] marks;
//				break; 
//			}
//			case 8:
//			{
//				cout << "\nYou chose Linear searching in the file" << endl;
//				int amountStudents, k = 0;
//				Student* stud = readFile(name, size_st, amountStudents);
//				cout << "\nChoose field:\n\tdefault - FIO\n\t1 - Math marks\n\t2 - Physics marks\n\t3 - Russian language marks\n\t4 - Average marks";
//				switch (_getch())
//				{
//				case '1':
//				{
//					int mark = getValue("\nEnter math mark: ");
//					cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//					for (int i = 0; i < amountStudents; i++)
//						if (stud[i].math == mark) {
//							cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//							k++;
//						}
//					if (k == 0)
//						cout << "There is no students with such math mark!" << endl;
//					break;
//				}
//				case '2':
//				{
//					int mark = getValue("\nEnter physics mark: ");
//					cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//					for (int i = 0; i < amountStudents; i++)
//						if (stud[i].physics == mark) {
//							cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//							k++;
//						}
//					if (k == 0)
//						cout << "There is no students with such physics mark!" << endl;
//					break;
//				}
//				case '3':
//				{
//					int mark = getValue("\nEnter russian mark: ");
//					cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//					for (int i = 0; i < amountStudents; i++)
//						if (stud[i].russian == mark) {
//							cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//							k++;
//						}
//					if (k == 0)
//						cout << "There is no students with such russian mark!" << endl;
//					break;
//				}
//				case '4':
//				{
//					double mark = getValue("\nEnter average mark: ");
//					cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//					for (int i = 0; i < amountStudents; i++)
//						if (stud[i].avMark < mark + 0.00005 && stud[i].avMark > mark - 0.00005) {
//							cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//							k++;
//						}
//					if (k == 0)
//						cout << "There is no students with such average mark!" << endl;
//					break;
//				}
//				default:
//				{
//					cout << "\nEnter FIO: " << endl;
//					char fio[255];
//					cin.getline(fio, 255);
//					cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//					for (int i = 0; i < amountStudents; i++)
//						if (strcmp(stud[i].fio, fio) == 0) {
//							cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
//							k++;
//						}
//					if (k == 0)
//						cout << "There is no students with such FIO!" << endl;
//					break;
//				}
//				}
//				delete[] stud;
//				break;
//			}
//			case 9:
//			{
//				cout << "\nYou chose Binary searching in the file" << endl;
//				int amountStudents;
//				Student* stud = readFile(name, size_st, amountStudents);
//				double* marks = new double[amountStudents];
//				cout << "\nChoose field:\n\tdefault - Average marks\n\t1 - Math marks\n\t2 - Physics marks\n\t3 - Russian language marks";
//				switch (_getch()) 
//				{
//				case '1':
//				{
//					int mark = getValue("\nEnter math mark: ");
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].math;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					int index = binarySearch(marks, amountStudents - 1, mark);
//					if (index >= 0) {
//						cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//						for (; stud[index].math == mark; index++)
//							cout << index + 1 << "\t" << stud[index].fio << "\t\t" << stud[index].math << "\t\t" << stud[index].physics << "\t\t" << stud[index].russian << "\t\t" << stud[index].avMark << endl;
//					} 
//					else cout << "There is no students with such math mark!" << endl;
//					break;
//				}
//				case '2':
//				{
//					int mark = getValue("\nEnter physics mark: ");
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].physics;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					int index = binarySearch(marks, amountStudents - 1, mark);
//					if (index >= 0) {
//						cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//						for (; stud[index].physics == mark; index++)
//							cout << index + 1 << "\t" << stud[index].fio << "\t\t" << stud[index].math << "\t\t" << stud[index].physics << "\t\t" << stud[index].russian << "\t\t" << stud[index].avMark << endl;
//					}
//					else cout << "There is no students with such physics mark!" << endl;
//					break;
//				}
//				case '3':
//				{
//					int mark = getValue("\nEnter russian language mark: ");
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].russian;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					int index = binarySearch(marks, amountStudents - 1, mark);
//					if (index >= 0) {
//						cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//						for (; stud[index].russian == mark; index++)
//							cout << index + 1 << "\t" << stud[index].fio << "\t\t" << stud[index].math << "\t\t" << stud[index].physics << "\t\t" << stud[index].russian << "\t\t" << stud[index].avMark << endl;
//					}
//					else cout << "There is no students with such russian mark!" << endl;
//					break;
//				}
//				default:
//				{
//					double mark = getValue("\nEnter average mark: ");
//					for (int i = 0; i < amountStudents; i++)
//						marks[i] = stud[i].avMark;
//					quickSort(stud, marks, 0, amountStudents - 1);
//					int index = binarySearch(marks, amountStudents - 1, mark);
//					if (index >= 0) {
//						cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//						for (; stud[index].avMark < mark + 0.0005 && stud[index].avMark > mark - 0.0005; index++)
//							cout << index + 1 << "\t" << stud[index].fio << "\t\t" << stud[index].math << "\t\t" << stud[index].physics << "\t\t" << stud[index].russian << "\t\t" << stud[index].avMark << endl;
//					}
//					else cout << "There is no students with such average mark!" << endl;
//					break;
//				}
//				}
//				delete[] stud;
//				delete[] marks;
//				break;
//			}
//			case 10:
//			{
//				cout << "\nYou chose doing the task" << endl;
//				int amountStudents, m;
//				Student buf;
//				Student* stud = readFile(name, size_st, amountStudents);
//				double avMarkUniversity = 0;
//				for (int i = 0; i < amountStudents; i++)
//					avMarkUniversity += stud[i].avMark;
//				avMarkUniversity /= amountStudents;
//				for (int j = 0; j < amountStudents - 1; j++) {
//					m = j;
//					for (int i = j + 1; i < amountStudents; i++)
//						if (stud[i].avMark > stud[m].avMark) m = i;
//					buf = stud[m];
//					stud[m] = stud[j];
//					stud[j] = buf;
//				}
//				cout << "Average mark for university: " << avMarkUniversity << endl;
//				cout << "\t\tFIO\t\tMath\t\tPhysics\t\tRussian\t\tAverage" << endl;
//				for (int i = 0; stud[i].avMark >= avMarkUniversity; i++)
//					cout << i + 1 << "\t" << stud[i].fio << "\t\t" << stud[i].math << "\t\t" << stud[i].physics << "\t\t" << stud[i].russian << "\t\t" << stud[i].avMark << endl;
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
//		cout << "\nDo you want to work with another file?\n\t1 - Yes\n\telse - No";
//	} while (_getch() == '1');
//}