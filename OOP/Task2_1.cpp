//#include <iostream>
//#include <conio.h>
//#include <string>
//using namespace std;
//
//template <class T>
//struct Status {
//	T* ptr;
//	int counter;
//};
//
//template <class T>
//class SmartPointer {
//	Status<T>* smartPtr;
//public:
//	SmartPointer(T* ptr = nullptr);
//	SmartPointer(const SmartPointer&);
//	~SmartPointer();
//	SmartPointer& operator=(const SmartPointer&);
//	T* operator->() const;
//	void showCounter() { cout << smartPtr->counter; }
//};
//
//template <class T>
//SmartPointer<T>::SmartPointer(T* ptr) {
//	if (!ptr) smartPtr = nullptr;
//	else {
//		smartPtr = new Status<T>;
//		smartPtr->ptr = ptr;
//		smartPtr->counter = 1;
//	}
//}
//
//template <class T>
//SmartPointer<T>::SmartPointer(const SmartPointer& obj) : smartPtr(obj.smartPtr) {
//	if (smartPtr) smartPtr->counter++;
//}
//
//template <class T>
//SmartPointer<T>::~SmartPointer() {
//	if (smartPtr) {
//		smartPtr->counter--;
//		if (smartPtr->counter <= 0) {
//			delete smartPtr->ptr;
//			delete smartPtr;
//		}
//	}
//}
//
//template <class T>
//T* SmartPointer<T>::operator->() const {
//	if (smartPtr) return smartPtr->ptr;
//	else return nullptr;
//}
//
//template <class T>
//SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& obj) {
//	if (smartPtr) {
//		smartPtr->counter--;
//		if (smartPtr->counter <= 0) {
//			delete smartPtr->ptr;
//			delete smartPtr;
//		}
//	}
//	smartPtr = obj.smartPtr;
//	if (smartPtr) smartPtr->counter++;
//	return *this;
//}
//
//template <class T>
//class Transaction {
//	T* currentState;
//	T* prevState;
//public:
//	Transaction() : prevState(nullptr), currentState(new T) {}
//	Transaction(const Transaction& obj) : currentState(new T(*(obj.currentState))), prevState(nullptr) {}
//	~Transaction() { delete currentState; delete prevState; }
//	Transaction& operator=(const Transaction& obj);
//	void show(int, string);
//	int BeginTransactions(int);
//	void commit();
//	void DeleteTransactions();
//	T* operator->();
//};
//
//template <class T2>
//Transaction<T2>& Transaction<T2>::operator=(const Transaction<T2>& obj)
//{
//	if (this != &obj)
//	{
//		delete currentState;
//		currentState = new T2(*(obj.currentState));
//	}
//	return *this;
//}
//
//template <class T2>
//T2* Transaction<T2>::operator->()
//{
//	return currentState;
//}
//
//template <class T2>
//void Transaction<T2>::show(int account, string surname) {
//	cout << "\n" + surname + "'s mark ";
//	if (!account) cout << "before answer " << endl;
//	else cout << "after answer " << endl;
//	if (prevState) cout << "prevState = " << prevState->getMark() << endl;
//	else cout << "prevState = NULL" << endl;
//	cout << "currentState = " << currentState->getMark() << endl;
//}
//
//template <class T2>
//int Transaction<T2>::BeginTransactions(int number) {
//	delete prevState;
//	prevState = currentState;
//	currentState = new T2(*prevState);
//	if (!currentState) return 0;
//	currentState->setMark(number);
//	return 1;
//}
//
//template <class T2>
//void Transaction<T2>::commit() {
//	delete prevState;
//	prevState = nullptr;
//}
//
//template <class T2>
//void Transaction<T2>::DeleteTransactions() {
//	if (prevState != nullptr) {
//		delete currentState;
//		currentState = prevState;
//		prevState = nullptr;
//	}
//}
//
//class Student {
//	string surname;
//	int mark;
//
//public:
//	Student() : surname(""), mark(0) {};
//
//	void setSurname(string surname) { this->surname = surname; }
//	void setMark(int mark) { this->mark = mark; }
//
//	string getSurname() { return surname; }
//	int getMark() { return mark; }
//};
//
//struct Day {
//	string dayOfweek;
//	string task;
//	bool isDone;
//};
//
//class Timetable {
//	Day week[7];
//public:
//	Timetable();
//
//	void show();
//	void writeTask(int day, string task) {
//		week[day - 1].task = task;
//		week[day - 1].isDone = false;
//	}
//	void doHomework(int day) { week[day - 1].isDone = true; }
//};
//
//Timetable::Timetable() {
//	string days[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
//	string tasks[] = { "Task_1", "Task_2", "Task_3", "Task_4", "Task_5", "Task_6", "Task_7" };
//	for (int i = 0; i < 7; i++)
//	{
//		week[i].task = tasks[i];
//		week[i].dayOfweek = days[i];
//		week[i].isDone = false;
//	}
//}
//
//void Timetable::show() {
//	for (int i = 0; i < 7; i++)
//		cout << week[i].dayOfweek + "\t" + ((week[i].isDone == true) ? "+" : "-") + "\t" + week[i].task << endl;
//}
//
//class Statement {
//	string text;
//	bool isSignatured;
//public:
//
//	Statement() : text(""), isSignatured(false) {};
//	void setSignature() { isSignatured = true; }
//	void setText(string text) { this->text = text; }
//	void show() { cout << "\n\tStatement\n" << text << "\n\t\t" << (isSignatured ? "Sign =)" : "No sign =(\n") << endl; }
//};
//
//int main() {
//	bool repeat = true;
//	while (repeat)
//	{
//		cout << "\nChoose operation:\n\t1 - do homework\n\t2 - write the statement\n\t3 - get mark\n\tdefault - exit\n" << endl;
//		switch (_getch())
//		{
//		case '1':
//		{
//			SmartPointer<Timetable> student(new Timetable);
//			cout << "Your tasks:" << endl;
//			student->show();
//			student->doHomework(1);
//			cout << "You done Task_1" << endl;
//			SmartPointer<Timetable> mate = student;
//			cout << "\nYour classmate arrived...\nNumber of working students now: "; student.showCounter();
//			mate->doHomework(2);
//			student->doHomework(3);
//			cout << "\nGreat! Together, you done Task_2 and Task_3" << endl; mate->show();
//			SmartPointer<Timetable> teacher(student);
//			cout << "\nTeacher connected to server...\nNumber of people working on your table now: "; teacher.showCounter();
//			teacher->writeTask(1, "Task_666");
//			teacher->writeTask(2, "Task_666");
//			teacher->writeTask(3, "Task_666");
//			cout << "\n\nOh shit! Teacher has changed your homework: " << endl; student->show();
//			break;
//		}
//		case '2':
//		{
//			SmartPointer<Statement> student(new Statement);
//			cout << "What a great idea not to go to school!\nLet's write a statement..." << endl;
//			student->setText("My son won't go to school tomorrow.");
//			student->show();
//			cout << "Oh, you need a signature." << endl;
//			SmartPointer<Statement> parents = student;
//			cout << "\nYour dad can help you with that trouble.\nAmount of people, writing the statement: "; parents.showCounter();
//			parents->setSignature();
//			cout << "\n\nGreat! The signature has been placed." << endl;
//			student->show();
//			break;
//		}
//		case '3':
//		{
//			Transaction<Student> student;
//			student->setSurname("Ivanov");
//			student.show(0, student->getSurname());
//			cout << "\nQuestion..." << endl;
//			if (student.BeginTransactions(8)) {
//				cout << "Correct answer. Ivanov got 8" << endl;
//				student.show(1, student->getSurname());
//				student.commit();
//			}
//			cout << "\nAnother question..." << endl;
//			if (student.BeginTransactions(9)) {
//				cout << "Uncorrect answer.";
//				student.DeleteTransactions();
//			}
//			cout << endl;
//			student.show(1, student->getSurname());
//			break;
//		}
//		default:
//			repeat = false;
//			break;
//		}
//	}
//}