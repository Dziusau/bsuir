//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//struct Hash {
//	int info;
//	Hash* next;
//};
//double getValue(const char* t) {
//	while (true) {
//		cout << "Enter " << t << " value = ";
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
//void add(int info, int amount, Hash** hash) {
//	Hash* t = new Hash;
//	t->info = info;
//	int i = abs(info % amount);
//	if (!hash[i]) {
//		hash[i] = t;
//		t->next = nullptr;
//	}
//	else {
//		t->next = hash[i];
//		hash[i] = t;
//	}
//}
//Hash* search(int info, int amount, Hash** hash) {
//	int i = abs(info % amount);
//	Hash* t = hash[i];
//	while (t) {
//		if (t->info == info) return t;
//		t = t->next;
//	}
//	return nullptr;
//}
//void viewTable(int amount, Hash** hash) {
//	Hash* t;
//	for (int i = 0; i < amount; i++) {
//		t = hash[i];
//		while (t) {
//			cout << t->info << " ";
//			t = t->next;
//		}
//		cout << endl;
//	}
//}
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
//	int n, amount, * arr;
//	Hash** hash;
//	char a;
//	cout << "Press 1, if you want to input amount by yourself" << endl; a = _getch();
//	if (a == '1') {
//		n = getValue("n");
//		amount = getValue("amount");
//	}
//	else {
//		n = 9;
//		amount = 10;
//	}
//	arr = new int[n];
//	srand(time(0));
//	cout << "\tInitial values: " << endl;
//	for (int i = 0; i < n; i++) {
//		arr[i] = 39000 + rand() % 37001;
//		cout << arr[i] << "	";
//	}
//	cout << endl;
//	hash = createHashTable(amount);
//	for (int i = 0; i < n; i++) add(arr[i], amount, hash);
//	cout << "\tHashed table: " << endl;
//	viewTable(amount, hash);
//	int key;
//	Hash* t;
//	bool b;
//	do {
//		key = getValue("key");
//		t = search(key, amount, hash);
//		if (!t) cout << "No element with such value" << endl;
//		else cout << "Element: " << t->info << endl;
//		cout << "Do you want to find one more element?(Y/N)" << endl; char k = _getch();
//		if (k == 'Y' || k == 'y') b = true;
//		else b = false;
//	} while (b);
//	deleteTable(amount, hash);
//	delete[] arr;
//}