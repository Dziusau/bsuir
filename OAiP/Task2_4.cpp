//#include <iostream>
//#include <cstdio>
//#include <conio.h>
//#include <time.h>
//using namespace std;
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
//struct List
//{
//	int info;
//	List* prev, * next;
//};
//void createList(List*& b, List*& e, int in) {
//	List* t = new List;
//	t->info = in;
//	t->next = t->prev = nullptr;
//	b = e = t;
//}
//void addList(List*& b, List*& e, int in, char kod) {
//	List* t = new List;
//	t->info = in;
//	if (kod == '1') {
//		t->prev = nullptr;
//		t->next = b;
//		b->prev = t;
//		b = t;
//	}
//	else {
//		t->prev = e;
//		t->next = nullptr;
//		e->next = t;
//		e = t;
//	}
//}
//void viewList(List* b, List* e) {
//	List* t = new List;
//	t = b;
//	cout << "\tList from the begining" << endl;
//	while (t != nullptr) {
//		cout << t->info << "\t";
//		t = t->next;
//	}
//	t = e;
//	cout << "\n\tList from the end" << endl;
//	while (t != nullptr) {
//		cout << t->info << "\t";
//		t = t->prev;
//	}
//}
//void deleteList(List*& b, List* e) {
//	List* t;
//	while (e)
//	{
//		t = e;
//		e = e->prev;
//		delete t;
//	}
//	b = nullptr;
//}
//void delSecList(List*& b, List*& e, char kod) {
//	List* t, * r;
//	if (kod == '1') {
//		cout << "\nDeleting every second from the begining" << endl;
//		t = b;
//		while (t->next) {
//			r = t->next;
//			t->next = r->next;
//			if (!t->next) {
//				delete r;
//				break;
//			}
//			else {
//				r->next->prev = t;
//				delete r;
//			}
//			t = t->next;
//		}
//		e = t;
//	}
//	else {
//		cout << "\nDeleting every second from the end" << endl;
//		t = e;
//		while (t->prev) {
//			r = t->prev;
//			t->prev = r->prev;
//			if (!t->prev) {
//				delete r;
//				break;
//			}
//			else {
//				r->prev->next = t;
//				delete r;
//			}
//			t = t->prev;
//		}
//		b = t;
//	}
//	viewList(b, e);
//}
//int main(int argc, char* argv[]) {
//	List* begin = nullptr, * end = nullptr;
//	bool on_off = true;
//	int in, n;
//	char kod;
//	do
//	{
//		cout << "\nChoose function:\n\t1 - Create\n\t2 - Add\n\t3 - View\n\t4 - Delete\n\t5 - Task: delete every second element\n\tdefault - Exit" << endl; kod = _getch();
//		switch (kod) {
//		case '1':
//			cout << "\nYou chose creating new List" << endl;
//			if (begin != nullptr) {
//				cout << "\tClear memory!!!" << endl;
//				break;
//			}
//			in = getValue("info");
//			createList(begin, end, in);
//			break;
//		case'2':
//			cout << "\nYou chose adding to List" << endl;
//			if (!begin) {
//				cout << "\tEmpty List!!!" << endl;
//				break;
//			}
//			cout << "1 - add to Begin\ndefault - add to End" << endl; kod = _getch();
//			cout << "Enter amount: "; cin >> n;
//			for (int i = 0; i < n; i++)
//			{
//				in = getValue("info");
//				addList(begin, end, in, kod);
//			}
//			break;
//		case'3':
//			cout << "\nYou chose viewing the List" << endl;
//			if (!begin) {
//				cout << "\tEmpty List!!!" << endl;
//				break;
//			}
//			viewList(begin, end);
//			break;
//		case '4':
//			cout << "\nYou chose deleting the List" << endl;
//			if (!begin) {
//				cout << "\tEmpty List!!!" << endl;
//				break;
//			}
//			deleteList(begin, end);
//			cout << "Memory free!!!" << endl;
//			break;
//		case '5':
//			cout << "\nYou chose doing task" << endl;
//			if (!begin) {
//				cout << "\tEmpty List!!!" << endl;
//				break;
//			}
//			cout << "1 - delete every second from the Begin\ndefault - delete every second from the End" << endl; kod = _getch();
//			delSecList(begin, end, kod);
//			break;
//		default:
//			cout << "\nDo you really want to exit?\n\t1 - Yes\n\telse - No";
//			if (_getch() == '1') {
//				on_off = false;
//				if (begin != nullptr)
//					deleteList(begin, end);
//			}
//			else
//				break;
//		}
//	} while (on_off);
//}