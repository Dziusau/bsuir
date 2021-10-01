//#include <iostream>
//#include <fstream>
//#include <string>
//#include <map>
//
//using namespace std;
//
////int main() {
////	/*fstream file("example.txt", ios::in | ios::out | ios::app);
////	string msg;
////	cout << "Enter messege: ";
////	getline(cin, msg);
////	file << msg << endl;
////	cout << "\nEnter 2nd messege: ";
////	getline(cin, msg);
////	file << msg << "\n";
////	file.close();
////
////	fstream file1("example.txt", ios::in | ios::out | ios::app);
////	while (!file1.eof())
////	{
////		msg = "";
////		getline(file1, msg);
////		cout << msg;
////	}
////	file1.close();*/
////
////	setlocale(LC_ALL, "rus");
////
////	/*multimap<int, string> map;
////	map.emplace(1, "вопрос_1");
////	map.emplace(2, "вопрос_2");
////	map.emplace(3, "вопрос_3");
////	map.emplace(1, "вопрос_4");
////	map.emplace(1, "вопрос_5");
////
////	for (auto i: map)
////	{
////		if (i.first == 1)
////			cout << i.second << endl;
////	}
////
////	string str = "вопрос_1:\n1. ответ\n2. ответ\n2. ответ";
////	cout << str << endl;*/
////}
//
//class Distance {//класс английских расстояний
//
//private:
//	int feet;
//	float inches;
//public:
//	Distance() : feet(0), inches(0.0) { }
//	Distance(int ft, float in) : feet(ft), inches(in) { }
//	friend istream& operator>>(istream& s, Distance& d);
//	friend ostream& operator<<(ostream& s, Distance& d);
//};
////получить данные из файла или с клавиатуры
////для ('), (-) и (") с помощью перегруженного >>
//istream& operator>>(istream& s, Distance& d) {
//	char dummy;
//	s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
//	return s;
//}
////послать данные в файл или на экран перегруженным <<
//ostream& operator<<(ostream& s, Distance& d) {
//	s << d.feet << "\'-" << d.inches << '\"';
//	return s;
//}
//int main() {
//	system("chcp 1251");
//	system("cls");
//	char ch;
//	Distance dist1;
//	ofstream ofile;
//	ofile.open("Dist.dat");
//	do {
//		cout << "Введите расстояние: ";
//		cin >> dist1;//получить данные от пользователя
//		ofile << dist1;//записать их в выходной поток
//		cout << "Продолжать (y/n)? ";
//		cin >> ch;
//	} while (ch != 'n');
//	ofile.close();//закрыть выходной поток
//	ifstream ifile;//создать и открыть
//	ifile.open("DIST.DAT");//входной поток
//	cout << "\nСодержимое файла:\n";
//	while (true) {
//		ifile >> dist1;//чтение данных из потока
//		if (ifile.eof()) break;
//		cout << "Расстояние = " << dist1 << endl;
//	}
//	return 0;
//}