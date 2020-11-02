//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//struct Hash {
//	string name;
//	int pages;
//	int year;
//	Hash* next;
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
//Hash** createHashTable(int amount) {
//	Hash** hash = new Hash * [amount];
//	for (int i = 0; i < amount; i++) hash[i] = nullptr;
//	return hash;
//}
////void add(string name, int pages, int year, int amount, Hash** hash) {
////	Hash* t = new Hash;
////	t->year = year;
////	t->pages = pages;
////	t->name = name;
////	int r[30], p;
////	srand(time(NULL));
////	for (int i = 0; i < 30; i++)
////		r[i] = rand() % 11;
////	p = abs(year % amount);
////	if (hash[p]) {
////		int i = 0;
////		while (hash[p]) {
////			p += r[i];
////			i++;
////			if (p >= amount) p -= amount;
////		}
////	}
////	hash[p] = t;
////}
//void add(string name, int pages, int year, int amount, Hash** hash) {
//	Hash* t = new Hash;
//	t->year = year;
//	t->pages = pages;
//	t->name = name;
//	int p = abs(year % amount);
//	if (!hash[p]) {
//		hash[p] = t;
//		t->next = nullptr;
//	}
//	else {
//		t->next = hash[p];
//		hash[p] = t;
//	}
//}
////Hash* search(int year, int amount, Hash** hash) {
////	int i = abs(year % amount);
////	if (hash[i] && hash[i]->year == year) return hash[i];
////	else {
////		for (i = 0; i < amount; i++)
////			if (!hash[i]) continue;
////			else if (hash[i]->year == year) return hash[i];
////		return nullptr;
////	}
////}
//Hash* search(int year, int amount, Hash** hash) {
//	int i = abs(year % amount);
//	Hash* t = hash[i];
//	while (t) {
//		if (t->year == year) return t;
//		t = t->next;
//	}
//	return nullptr;
//}
////void viewTable(int amount, Hash** hash) {
////	for (int i = 0; i < amount; i++) {
////		if (hash[i]) cout << hash[i]->name << ":\t" << hash[i]->pages << "\t" << hash[i]->year << endl;
////		else cout << endl;
////	}
////}
//void viewTable(int amount, Hash** hash) {
//	Hash* t;
//	for (int i = 0; i < amount; i++) {
//		t = hash[i];
//		while (t) {
//			cout << t->name << ":\t" << t->pages << "\t" << t->year << "\t\t";
//			t = t->next;
//		}
//		cout << endl;
//	}
//}
////void deleteTable(int amount, Hash** hash) {
////	Hash* t;
////	for (int i = 0; i < amount; i++) {
////		t = hash[i];
////		delete t;
////	}
////	delete[] hash;
////}
//void deleteTable(int amount, Hash** hash) {
//	Hash* t, * prev;
//	for (int i = 0; i < amount; i++) {
//		t = hash[i];
//		while (t) {
//			prev = t;
//			t = t->next;
//			delete prev;
//		}
//	}
//	delete[] hash;
//}
//int main(int argc, char* argv[]) {
//	int n, amount; 
//	char a;
//	cout << "Press 1, if you want to input values by yourself" << endl; a = _getch();
//	if (a == '1') {
//		n = getValue("Enter n value: ");
//		amount = getValue("Enter amount: ");
//	}
//	else {
//		n = 9;
//		amount = 10;
//	}
//	int* year = new int[n];
//	int* pages = new int[n];
//	string* names = new string[n];
//	Hash** hash;
//	if (a == '1') {
//		for (int i = 0; i < n; i++) {
//			year[i] = getValue("Enter year: ");
//			pages[i] = getValue("Enter amount of pages: ");
//			cout << "Enter name of the book: "; cin >> names[i];
//		}
//	}
//	else {
//		srand(time(0));
//		for (int i = 0; i < n; i++) {
//			year[i] = 1600 + rand() % 450;
//			pages[i] = rand() % 100;
//			names[i] = "book";
//			names[i] += i + 49;
//		}
//	}
//	cout << "Name\tPages\tYear" << endl;
//	for (int i = 0; i < n; i++)
//		cout << names[i] << ":\t" << pages[i] << "\t" << year[i] << endl;
//	hash = createHashTable(amount);
//	for (int i = 0; i < n; i++) add(names[i], pages[i], year[i], amount, hash);
//	cout << "Hashed table:\nName\tPages\tYear" << endl;
//	viewTable(amount, hash);
//	int key;
//	Hash* t;
//	bool b;
//	do {
//		key = getValue("Enter year: ");
//		t = search(key, amount, hash);
//		if (!t) cout << "No element with such value" << endl;
//		else {
//			while (t) {
//				if (key == t->year)
//					cout << "Element: " << t->name << "\t" << t->pages << "\t" << t->year << endl;
//				t = t->next;
//			}
//		}
//		cout << "Do you want to find one more element?(Y/N)" << endl; char k = _getch();
//		if (k == 'Y' || k == 'y') b = true;
//		else b = false;
//	} while (b);
//	deleteTable(amount, hash);
//	delete[] year;
//	delete[] pages;
//	delete[] names;
//}