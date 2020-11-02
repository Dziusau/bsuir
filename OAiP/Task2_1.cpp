#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
using namespace std;
double getValue(char t) {
	while (true) {
		cout << "Enter " << t << " value = ";
		double x;
		cin >> x;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Your input is invalid. Please, try again.\n" << endl;
		}
		else
			return x;
	}
}
unsigned binom(int n, int k) {
	if (k > n / 2) k = n - k;
	if (k == 0) return 1;
	if (k == 1) return n;
	unsigned bin = 1;
	for (int i = 1; i <= k; i++) {
		bin *= n - k + i;
		bin /= i;
	}
	return bin;
}
unsigned binomRec(int n, int k) {
	if (k > n / 2) k = n - k;
	if (k == 1) return n;
	if (k == 0) return 1;
	return binomRec(n - 1, k) + binomRec(n - 1, k - 1);
}
int main(int argc, char* argv[]) {
	do
	{
		int n, k;
		cout << "Enter n and k" << endl;
		n = getValue('n');
		k = getValue('k');
		cout << "Binom = " << binom(n, k) << endl;
		cout << "BinomRec = " << binomRec(n, k) << endl;
		cout << "Do you want to repeat?\n\tClick '1', if YES" << endl;
	} while (_getch() == '1');
}