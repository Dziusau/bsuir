#include "Authorization.h"

void menu()
{
	while (true) {
		cls;
		cout << "����� ����������!" << endl;
		cout << "1 - ����� ��� ������������� " << endl;
		cout << "2 - ����� ��� �������" << endl;
		cout << "3 - ������� �������������" << endl;
		cout << "4 - ������� ��������" << endl;
		cout << "default - �����" << endl;
		switch (_getch()) {
		case '1':
			cls;
			teacher_auth();
			break;
		case '2':
			cls;
			student_auth();
			break;
		case '3':
			cls;
			teacher_add();
			pause;
			break;
		case '4':
			cls;
			student_add();
			pause;
			break;
		default:
			return;
		}
	}
}

void sign_in(string& login, string& password, int key)
{
	char c;
	cout << "������� �����: ";
	getline(cin, login);
	if (key) {
		cout << "������� ������: ";
		while ((c = _getch()) != '\r') {
			password += c;
			cout << '*';
		}
	}
	else {
		cout << "������� ����� ������: ";
		getline(cin, password);
	}
	cout << endl;
}

void teacher_auth()
{
	bool check = false;
	Teacher teacher;
	teacher.setKey(1);
	string teacher_log;
	string teacher_pass;
	string login;
	string password;
	sign_in(teacher_log, teacher_pass, teacher.getKey());
	try {
		ifstream file("files/teachers.txt");
		if (!file.is_open()) throw "���� �� ������!\n���������� ������� �������������.";
		while (!file.eof()) {
			getline(file, login);
			getline(file, password);
			if (teacher_log == login) {
				check = true;
				for (int i = 0; i < password.size(); i++) password[i] -= 6;
				break;
			}
		}
		file.close();
		if (!check) throw "������ ������������ ���!";
		else if (teacher_pass != password) throw "������ ��� ����� ������!\n���������� ��� ���.";
		cout << endl;
		cout << "���� ��������!" << endl;
		pause;
		teacher.setLogin(teacher_log);
		teacher.setPassword(teacher_pass);

		Menu menu(teacher);
		menu.menu_teacher();
	}
	catch (const char* ex) {
		cout << ex << endl;
		pause;
	}
}

void teacher_add()
{
	bool check = false;
	string teacher_log;
	string teacher_pass;
	string login;
	string password;
	sign_in(teacher_log, teacher_pass, 1);
	try {
		fstream file("files/teachers.txt", ios::in | ios::out | ios::app);
		if (!file.is_open()) throw "���� �� ������!";
		while (!file.eof()) {
			getline(file, login);
			getline(file, password);
			if (teacher_log == login) check = true;
		}
		if (check) throw "����� ������������ ��� ����!";
		file.clear();
		for (int i = 0; i < teacher_pass.size(); i++) teacher_pass[i] += 6;
		file << teacher_log << "\n" << teacher_pass << "\n";
		cout << "������������ ������� ��������." << endl;
		file.close();
	}
	catch (const char* ex) {
		cout << ex << endl;
		pause;
	}
}

void student_auth()
{
	bool check = false;
	Student student;
	student.setKey(0);
	string student_log;
	string student_group;
	string login;
	string group;
	int mark;
	sign_in(student_log, student_group, student.getKey());
	try {
		ifstream file("files/students.txt");
		if (!file.is_open()) throw "���� �� ������!\n���������� ������� ��������.";
		while (!file.eof()) {
			file >> mark;
			getline(file, login);
			getline(file, group);
			if (student_log == login) {
				check = true;
				break;
			}
		}
		file.close();
		if (!check) throw "������ ������������ ���!";
		else if (student_group != group) throw "������ ��� ����� ������!\n���������� ��� ���.";
		cout << "���� ��������!" << endl;
		pause;
		student.setMark(mark);
		student.setGroup(stoi(student_group));
		student.setLogin(student_log);
		Menu menu(student);
		menu.menu_student();
	}
	catch (const char* ex) {
		cout << ex << endl;
		pause;
	}
}

void student_add()
{
	bool check = false;
	string student_log;
	string student_group;
	string login;
	string password;
	int mark;
	sign_in(student_log, student_group, 0);
	try {
		fstream file("files/students.txt", ios::in | ios::out | ios::app);
		if (!file.is_open()) throw "���� �� ������!";
		while (!file.eof()) {
			file >> mark;
			getline(file, login);
			getline(file, password);
			if (student_log == login) check = true;
		}
		if (check) throw "����� ������������ ��� ����!";
		file.clear();
		file << 0 << student_log << "\n" << student_group << "\n";
		cout << "������������ ������� ��������." << endl;
		file.close();
	}
	catch (const char* ex) {
		cout << ex << endl;
		pause;
	}
}