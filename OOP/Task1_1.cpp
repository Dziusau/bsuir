//#include <iostream>
//#include <fstream>
//#include <conio.h>
//#include <list>
//using namespace std;
//double getValue(const char* text) {
//	double side;
//	while (true) {
//		cout << "Enter " << text <<" value: ";
//		cin >> side;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(32767, '\n');
//			cout << "Your input is invalid. Please, try again.\n" << endl;
//		}
//		else if (side <= 0) cout << "Your input is invalid. Please, try again.\n" << endl;
//		else
//			return side;
//	}
//}
//class Square {
//	double side;
//	double diagonal;
//public:
//	Square() {
//		side = 0;
//		diagonal = 0;
//	}
//	void setSide(double side) {
//		this->side = side;
//		this->diagonal = side / sin(45);
//	}
//	double getSide() {
//		return side;
//	}
//	double getDiagonal() {
//		return diagonal;
//	}
//	void printInf() {
//		cout << "Side: " << side << "\tDiagonal: " << diagonal << endl;
//	}
//	double perimetr() {
//		return 4 * side;
//	}
//	double area() {
//		return side * side;
//	}
//	void writeFile() {
//		ofstream fout;
//		cout << "Enter file name: " << endl;
//		char name[255];
//		cin.clear();
//		cin.ignore(32767, '\n');
//		cin.getline(name, 255);
//		fout.open(name);
//		if (!fout.is_open())
//			cout << "File openning error!!!" << endl;
//		else{
//			fout << "Side: " << this->side << "\tDiagonal: " << this->diagonal;
//			cout << "Writing to file complete." << endl;
//		}
//		fout.close();
//	}
//};
//int main() {
//	bool repeat; 
//	Square square;
//	list<double> sides;
//	do {
//		repeat = true;
//		cout << "\n1 - set side\n2 - get side\n3 - get diagonal\n4 - get info\n5 - get perimetr\n6 - get area\n7 - write to file\n8 - exit" << endl;
//		switch (_getch()) {
//		case '1':
//			double side;
//			cout << "Choose side from the list(1) or enter new(default)." << endl;
//			if (_getch() != '1') {
//				side = getValue("side");
//				sides.push_back(side);
//			}
//			else {
//				if (sides.begin() == sides.end()) {
//					cout << "Empty list!" << endl;
//					side = getValue("side");
//					sides.push_back(side);
//				}
//				else {
//					cout << "Choose side: ";
//					for (double n : sides) {
//						cout << n << "\t|\t";
//					}
//					cout << endl;
//					list<double> ::iterator it;
//					while (true) {
//						side = getValue("side");
//						it = find(sides.begin(), sides.end(), side);
//						if (it == sides.end()) {
//							cout << "There is no side with such value in the list!" << endl;
//						} else break;
//					}
//				}
//			}
//			sides.unique();
//			square.setSide(side);
//			break;
//		case '2':
//			cout << "Side: " << square.getSide() << endl;
//			break;
//		case '3':
//			cout << "Diagonal: " << square.getDiagonal() << endl;
//			break;
//		case '4':
//			square.printInf();
//			break;
//		case '5':
//			cout << "Perimetr: " << square.perimetr() << endl;
//			break;
//		case '6':
//			cout << "Area: " << square.area() << endl;
//			break;
//		case '7':
//			square.writeFile();
//			break;
//		case '8':
//			repeat = false;
//			break;
//		}
//	} while (repeat);
//	sides.clear();
//}