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
////	map.emplace(1, "������_1");
////	map.emplace(2, "������_2");
////	map.emplace(3, "������_3");
////	map.emplace(1, "������_4");
////	map.emplace(1, "������_5");
////
////	for (auto i: map)
////	{
////		if (i.first == 1)
////			cout << i.second << endl;
////	}
////
////	string str = "������_1:\n1. �����\n2. �����\n2. �����";
////	cout << str << endl;*/
////}
//
//class Distance {//����� ���������� ����������
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
////�������� ������ �� ����� ��� � ����������
////��� ('), (-) � (") � ������� �������������� >>
//istream& operator>>(istream& s, Distance& d) {
//	char dummy;
//	s >> d.feet >> dummy >> dummy >> d.inches >> dummy;
//	return s;
//}
////������� ������ � ���� ��� �� ����� ������������� <<
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
//		cout << "������� ����������: ";
//		cin >> dist1;//�������� ������ �� ������������
//		ofile << dist1;//�������� �� � �������� �����
//		cout << "���������� (y/n)? ";
//		cin >> ch;
//	} while (ch != 'n');
//	ofile.close();//������� �������� �����
//	ifstream ifile;//������� � �������
//	ifile.open("DIST.DAT");//������� �����
//	cout << "\n���������� �����:\n";
//	while (true) {
//		ifile >> dist1;//������ ������ �� ������
//		if (ifile.eof()) break;
//		cout << "���������� = " << dist1 << endl;
//	}
//	return 0;
//}