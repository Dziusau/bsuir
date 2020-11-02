//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//struct Tree {
//	int info;
//	string str;
//	Tree* left, * right;
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
//Tree* leaf(int info, string string) {
//	Tree* t = new Tree;
//	t->info = info;
//	t->str = string;
//	t->left = t->right = nullptr;
//	return t;
//}
//void createTree(Tree*& top) {
//	Tree* prev, * t;
//	prev = t = nullptr;
//	bool find = false;
//	int amount, info;
//	string str;
//	cout << "Input amount of leafs: "; cin >> amount;
//	if (!top) {
//		cout << "Enter string: ";
//		cin >> str;
//		amount--;
//		top = leaf(getValue("top"), str);
//	}
//	for (int i = 1; i <= amount; i++) {
//		t = top;
//		cout << "Enter string: ";
//		cin >> str;
//		info = getValue("info");
//		while (t && !find) {
//			prev = t;
//			if (info == t->info) {
//				find = true;
//				cout << "\n\tLeaf with such value exists!!!" << endl;
//			}
//			else {
//				if (info < t->info) t = t->left;
//				else t = t->right;
//			}
//		}
//		if (find) {
//			i--;
//			find = false;
//			continue;
//		}
//		else {
//			t = leaf(info, str);
//			if (info < prev->info) prev->left = t;
//			else prev->right = t;
//		}
//	}
//}
//void addTree(Tree* top, int info, string str) {
//	Tree* prev, * t;
//	prev = nullptr;
//	bool find = false;
//	t = top;
//	while (t && !find) {
//		prev = t;
//		if (info == t->info) {
//			find = true;
//			cout << "\n\tLeaf with such value exists!!!" << endl;
//		}
//		else
//			if (info < t->info)
//				t = t->left;
//			else
//				t = t->right;
//	}
//	if (!find) {
//		t = leaf(info, str);
//		if (info < prev->info) prev->left = t;
//		else prev->right = t;
//	}
//}
//void deleteNode(Tree*& top) {
//	Tree* t, * prev_t, * node, * prev_node;
//	t = prev_t = prev_node = nullptr;
//	bool find;
//	do {
//		find = true;
//		node = top;
//		int info = getValue("info");
//		while (node && node->info != info) {
//			prev_node = node;
//			if (info < node->info) node = node->left;
//			else node = node->right;
//		}
//		if (!node) {
//			cout << "\tNo node with such info!!!" << endl;
//			find = false;
//		}
//	} while (!find);
//	if (!node->right) t = node->left;
//	else if (!node->left) t = node->right;
//	else {
//		prev_t = node;
//		t = node->left;
//		while (t->right) {
//			prev_t = t;
//			t = t->right;
//		}
//		if (prev_t == node) t->right = node->right;
//		else {
//			t->right = node->right;
//			prev_t->right = t->left;
//			t->left = prev_t;
//		}
//	}
//	if (node == top) top = t;
//	else if (node->info < prev_node->info) prev_node->left = t;
//	else prev_node->right = t;
//	delete node;
//}
//void viewTree(Tree* t, int level) {
//	if (t) {
//		viewTree(t->left, level + 1);
//		for (int i = 0; i < level; i++)
//			cout << "	";
//		cout << t->info << "; " << t->str << endl;
//		viewTree(t->right, level + 1);
//	}
//}
//void deleteTree(Tree*& top) {
//	if (top) {
//		deleteTree(top->left);
//		deleteTree(top->right);
//		delete top;
//	}
//}
//int countNodes(Tree* top) {
//	if (!top) return 0;
//	int n = 1;
//	if (top->left)
//		n += countNodes(top->left);
//	if (top->right)
//		n += countNodes(top->right);
//	return n;
//}
//int convertToArr(Tree* t, int* arr, int i) {
//	if (!t) return 0;
//	int n = 1;
//	arr[i] = t->info;
//	if (t->left)
//		n += convertToArr(t->left, arr, i - n);
//	if (t->right)
//		n += convertToArr(t->right, arr, i - n);
//	return n;
//}
//int* makeArr(Tree* top) {
//	Tree* prev, * t;
//	prev = t = nullptr;
//	int n = countNodes(top), temp, m;
//	int* arr = new int[n];
//	n = convertToArr(top, arr, n - 1);
//	//deleteTree(top);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n - 1; j++)
//			if (arr[j] > arr[j + 1]) {
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//	return arr;
//	/*temp = n / 2;
//	top = leaf(arr[temp], " ");
//	for (int i = 0; i < n; i++) {
//		t = top;
//		while (t) {
//			prev = t;
//			if (i < temp)
//				m = (temp - i) / 2;
//			else if (i > temp)
//				m = (n - i) / 2 + temp; ??????????????
//			else break;
//			if (arr[m] < t->info) t = t->left;
//			else t = t->right;
//		}
//		if (i == temp) continue;
//		t = leaf(arr[m], " ");
//		if (arr[m] < prev->info) prev->left = t;
//		else prev->right = t;
//	}
//	cout << "\tTree" << endl;
//	viewTree(top, 0);*/
//}
//void balansTree(Tree*& t, int n, int k, int* arr) {
//	if (n == k) {
//		t = nullptr;
//		return;
//	}
//	else {
//		int m = (n + k) / 2;
//		t = new Tree;
//		t->info = arr[m];
//		balansTree(t->left, n, m, arr);
//		balansTree(t->right, m + 1, k, arr);
//	}
//}
//int main(int argc, char* argv[]) {
//	Tree* top = nullptr;
//	bool on_off = true;
//	int info;
//	string str;
//	char kod;
//	do
//	{
//		cout << "\nChoose function:\n\t1 - Create\n\t2 - Add\n\t3 - View\n\t4 - Delete Tree\n\t5 - Delete Node\n\t6 - Balans Tree\n\t7 - Task: find amount of elements in the left branch\n\tdefault - Exit" << endl; kod = _getch();
//		switch (kod)
//		{
//		case '1':
//			cout << "\nYou chose creating new Tree" << endl;
//			if (top) {
//				cout << "\nClear memory!!!" << endl;
//				break;
//			}
//			createTree(top);
//			break;
//		case '2':
//			cout << "\nYou chose adding to the Tree" << endl;
//			if (!top) {
//				cout << "\nEmpty Tree!!!" << endl;
//				break;
//			}
//			cout << "Enter string: ";
//			cin >> str;
//			addTree(top, getValue("info"), str);
//			break;
//		case '3':
//			cout << "\nYou chose viewing Tree" << endl;
//			if (!top) {
//				cout << "\nEmpty Tree!!!" << endl;
//				break;
//			}
//			cout << "\tTree" << endl;
//			viewTree(top, 0);
//			break;
//		case '4':
//			cout << "\nYou chose deleting Tree" << endl;
//			if (!top) {
//				cout << "\nEmpty Tree!!!" << endl;
//				break;
//			}
//			deleteTree(top);
//			top = nullptr;
//			cout << "\nMemory free!!!" << endl;
//			break;
//		case '5':
//			cout << "\nYou chose deleting Leaf" << endl;
//			if (!top) {
//				cout << "\nEmpty Tree!!!" << endl;
//				break;
//			}
//			deleteNode(top);
//			cout << "\nMemory free!!!" << endl;
//			break;
//		case '6':
//			cout << "\nYou chose balansing Tree" << endl;
//			if (!top) {
//				cout << "\nEmpty Tree!!!" << endl;
//				break;
//			}
//			balansTree(top, 0, countNodes(top), makeArr(top));
//			viewTree(top, 0);
//			break;
//		case '7':
//			cout << "\nYou chose doing task" << endl;
//			if (!top) {
//				cout << "\tEmpty Tree!!!" << endl;
//				break;
//			}
//			cout << "In the left branch " << countNodes(top->left) << " leafs";
//			break;
//		default:
//			cout << "\nDo you really want to exit?\n\t1 - Yes\n\telse - No";
//			if (_getch() == '1') {
//				on_off = false;
//				if (top)
//					deleteTree(top);
//			}
//			else
//				break;
//		}
//	} while (on_off);
//}