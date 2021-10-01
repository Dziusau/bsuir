#include "Teacher.h"

void Teacher::viewQuestions(Test<string>& test)
{
	for (auto i : *(test.getQuestions()))
	{
		string str = i.second.getQuestion();

		cout << i.second.getIndex() << ") ";
		switch (i.second.getType())
		{
		case 2:
			cout << str << endl << endl;
			break;
		case 1:
		{
			size_t pos = 0;
			string variant;
			int k = 0;
			while ((pos = str.find('/')) != std::string::npos) {
				variant = str.substr(0, pos);
				cout.setf(ios::left);
				if (k % 2 == 1)	cout << setw(30) << variant;
				else cout << setw(20) << variant << endl;
				k++;
				str.erase(0, pos + 1);
			}
			cout << str << endl << endl;
			break;
		}
		}
	}
}

void Teacher::viewQuestions(Test<int>& test) {
	for (auto i : *(test.getQuestions()))
	{
		string str = i.second.getQuestion();
		cout << i.second.getIndex() << ") ";
		size_t pos = 0;
		string variant;
		while ((pos = str.find('/')) != std::string::npos) {
			variant = str.substr(0, pos);
			cout << variant << endl;
			str.erase(0, pos + 1);
		}
		cout << str << endl << endl;
	}
}

void Teacher::newQuestion(Test<string>& test, int type)
{
	Question<string> question;
	test.setAmount(test.getAmount() + 1);
	question.setIndex(test.getAmount());
	question.setType(type);
	string str;
	string answer;

	if (type == 1) {
		str = "������� ������������:";
		cout << endl << "������� ����������� 1-1: ";
		getline(cin, answer);
		str += "/1. "; str += answer;
		cout << "������� ����������� 2-1: ";
		getline(cin, answer);
		str += "/�. "; str += answer;
		cout << "������� ����������� 1-2: ";
		getline(cin, answer);
		str += "/2. "; str += answer;
		cout << "������� ����������� 2-2: ";
		getline(cin, answer);
		str += "/�. "; str += answer;
		cout << "������� ����������� 1-3: ";
		getline(cin, answer);
		str += "/3. "; str += answer;
		cout << "������� ����������� 2-3: ";
		getline(cin, answer);
		str += "/�. "; str += answer;

		checkAnswer(answer, 0);
	}
	else {
		cout << "������� ������������ �������: ";
		getline(cin, str);
		cout << endl << "������� ���������� �����: ";
		getline(cin, answer);
	}
	question.setQuestion(str);

	question.setAnswer(answer);

	(*test.getQuestions()).emplace(type, question);
	question.write2file(1);
}

void Teacher::newQuestion(Test<int>& test)
{
	Question<int> question;
	test.setAmount(test.getAmount() + 1);
	question.setIndex(test.getAmount());
	question.setType(0);

	cout << "������� ������������ �������: ";
	string str;
	getline(cin, str);

	cout << "������� ������� ������� ������: ";
	string answer;
	getline(cin, answer);
	str += "/1. "; str += answer;
	cout << "������� ������� ������� ������: ";
	getline(cin, answer);
	str += "/2. "; str += answer;
	cout << "������� ������� �������� ������: ";
	getline(cin, answer);
	str += "/3. "; str += answer;

	question.setQuestion(str);

	cout << endl << "������� ���������� �����: ";
	int answer_int;

	while (true) {
		cin >> answer_int;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "������������ ����. ����������, ���������� ���.\n" << endl;
			continue;
		}
		else if (answer_int < 1 || answer_int > 3)
		{
			cout << "������������ ������� ������. ����������, ���������� ���.\n" << endl;
			continue;
		}
		break;
	}
	cin.ignore(10, '\n');
	question.setAnswer(answer_int);

	(*test.getQuestions()).emplace(0, question);
	question.write2file(0);
}

void Teacher::printUser()
{
	cout << "������� �����: " << this->getLogin() << endl;
	cout << "������� ������: " << this->getPassword() << endl << endl;
}

istream& operator>>(istream& stream, Teacher& teacher)
{
	string login;
	string password;

	getline(stream, login);
	getline(stream, password);

	for (int i = 0; i < password.size(); i++) password[i] -= 6;
	teacher.setLogin(login);
	teacher.setPassword(password);

	return stream;
}

ostream& operator<<(ostream& stream, Teacher& teacher)
{
	string password = teacher.getPassword();
	for (int i = 0; i < password.size(); i++) password[i] += 6;
	stream << teacher.getLogin() << "\n" << password << "\n";
	return stream;
}

void checkAnswer(string& answer, int key)
{
	bool isCorrect = false;
	while (!isCorrect) {
		isCorrect = true;
		cout << endl << ((key == 0)?"������� ���������� ���������� (������: 1�2�3�): ": "��� �����: ");
		getline(cin, answer);
		for (int i = 0; i < answer.size(); i++) answer[i] = tolower(answer[i]);

		if (answer.find("12") != string::npos || answer.find("13") != string::npos || answer.find("21") != string::npos || answer.find("23") != string::npos || answer.find("31") != string::npos || answer.find("32") != string::npos) {
			cout << "������������ ����: ������ ������ ��� ����� ������!\n����������, ��������� �������." << endl;
			isCorrect = false;
			continue;
		}
		if (answer.find("��") != string::npos || answer.find("��") != string::npos || answer.find("��") != string::npos || answer.find("��") != string::npos || answer.find("��") != string::npos || answer.find("��") != string::npos) {
			cout << "������������ ����: ������ ������ ��� ����� ������!\n����������, ��������� �������." << endl;
			isCorrect = false;
			continue;
		}
		if (answer.find("1") == string::npos || answer.find("2") == string::npos || answer.find("3") == string::npos) {
			cout << "������������ ����: � ���������� ������ �������������� ��� ����� �� 1 �� 3!\n����������, ��������� �������." << endl;
			isCorrect = false;
			continue;
		}
		if (answer.find("�") == string::npos || answer.find("�") == string::npos || answer.find("�") == string::npos) {
			cout << "������������ ����: � ���������� ������ �������������� ��� ����� �� � �� �!\n����������, ��������� �������." << endl;
			isCorrect = false;
			continue;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == '1') {
			if (i == 0) continue;
			else {
				char c = answer[0];
				answer[0] = '1';
				answer[i] = c;

				c = answer[1];
				answer[1] = answer[i + 1];
				answer[i + 1] = c;
				continue;
			}
		}
		else if (answer[i] == '2') {
			if (i == 2) continue;
			else {
				char c = answer[2];
				answer[2] = '2';
				answer[i] = c;

				c = answer[3];
				answer[3] = answer[i + 1];
				answer[i + 1] = c;
				continue;
			}
		}
		else if (answer[i] == '3') {
			if (i == 4) continue;
			else {
				char c = answer[4];
				answer[4] = '3';
				answer[i] = c;

				c = answer[5];
				answer[5] = answer[i + 1];
				answer[i + 1] = c;
				continue;
			}
		}
	}
}
