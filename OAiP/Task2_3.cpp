//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
//struct Stack {
//	double info;
//	Stack* next;
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
//
//Stack* inStack(Stack* p, double in) {
//	Stack* t = new Stack;
//	t->info = in;
//	t->next = p;
//	return t;
//}
//
//Stack* outStack(Stack* p, double& out) {
//	Stack* t = p;
//	out = t->info;
//	p = p->next;
//	delete t;
//	return p;
//}
//void viewStack(Stack* p) {
//	Stack* t = p;
//	while (t != NULL) {
//		cout << t->info << "\t";
//		t = t->next;
//	}
//}
//void deleteStack(Stack*& p) {
//	Stack* t;
//	while (p) {
//		t = p;
//		p = p->next;
//		delete t;
//	}
//}
//void delSecStack(Stack* p) {
//	Stack* t = p, * r;
//	while (t->next) {
//		r = t->next;
//		t->next = t->next->next;
//		delete r;
//		t = t->next;
//		if (!t) break;
//	}
//}
//void delBetweenStack(Stack* p) {
//	Stack* t = p->next;
//	Stack* min = p, * max = p, * r, * c;
//	while (t) {
//		if (t->info < min->info)
//			min = t;
//		else if (t->info > max->info)
//			max = t;
//		t = t->next;
//	}
//	t = p;
//	viewStack(p);
//	cout << "\nMAX element: " << max->info << "\tMIN element: " << min->info << endl;
//	if (max->next == min || min->next == max)
//		cout << "No elements between MIN and MAX" << endl;
//	else if (max->info == min->info)
//		cout << "MAX = MIN" << endl;
//	else {
//		while (t) {
//			if (t == max || t == min) {
//				c = t;
//				t = t->next;
//				do {
//					r = t;
//					t = t->next;
//					delete r;
//				} while (t != min && t != max);
//				c->next = t;
//				break;
//			}
//			t = t->next;
//		}
//		cout << "\tNew Stack" << endl;
//		viewStack(p);
//	}
//}
//int main(int argc, char* argv[]) {
//	Stack* begin = NULL;
//	bool on_off = true;
//	double in;
//	int i, n;
//	char kod;
//	srand(time(0));
//	do
//	{
//		cout << "\nChoose function:\n\t1 - Create\n\t2 - Add\n\t3 - View\n\t4 - Delete\n\t5 - Task: delete every second element\n\t6 - Additional task: delete between max and min elements\n\tdefault - Exit" << endl; kod = _getch();
//		switch (kod)
//		{
//		case '1': case '2':
//			if (kod == '1')
//				cout << "\nYou chose creating new Stack" << endl;
//			else
//				cout << "\nYou chose adding to Stack" << endl;
//			if (kod == '1' && begin != NULL) {
//				cout << "\nClear memory!!!" << endl;
//				break;
//			}
//			cout << "Enter amount:"; cin >> n;
//			cout << "1 - Your input\ndefault - Certain values" << endl; kod = _getch();
//			if (kod == '1') {
//				for (int i = 0; i < n; i++)
//				{
//					in = getValue("in");
//					begin = inStack(begin, in);
//				}
//			}
//			else {
//				for (i = 0; i < n; i++)
//				{
//					in = rand() % 10;
//					begin = inStack(begin, in);
//				}
//			}
//			break;
//		case '3':
//			cout << "\nYou chose viewing Stack" << endl;
//			if (!begin) {
//				cout << "\nEmpty stack!!!" << endl;
//				break;
//			}
//			cout << "\tStack" << endl;
//			viewStack(begin);
//			break;
//		case '4':
//			cout << "\nYou chose deleting Stack" << endl;
//			if (!begin) {
//				cout << "\nEmpty stack!!!" << endl;
//				break;
//			}
//			deleteStack(begin);
//			cout << "Memory free!!!" << endl;
//			break;
//		case '5':
//			cout << "\nYou chose doing task" << endl;
//			if (!begin) {
//				cout << "\tEmpty stack!!!" << endl;
//				break;
//			}
//			if (!begin->next) {
//				cout << "\tOnly one element in stack!!!" << endl;
//				break;
//			}
//			delSecStack(begin);
//			cout << "\tNew Stack" << endl;
//			viewStack(begin);
//			delBetweenStack(begin);
//			break;
//		case '6':
//			cout << "\nYou chose doing additional task" << endl;
//			if (!begin) {
//				cout << "\tEmpty stack!!!" << endl;
//				break;
//			}
//			if (!begin->next) {
//				cout << "\tOnly one element in stack!!!" << endl;
//				break;
//			}
//			delBetweenStack(begin);
//			break;
//		default:
//			cout << "\nDo you really want to exit?\n\t1 - Yes\n\telse - No";
//			if (_getch() == '1') {
//				on_off = false;
//				if (begin != NULL)
//					deleteStack(begin);
//			}
//			else
//				break;
//		}
//	} while (on_off);
//}