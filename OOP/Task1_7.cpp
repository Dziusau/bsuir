//#include <iostream>
//
//using namespace std;
//
//template <class T>
//T getValue(const char* text) {
//	T value;
//	while (true) {
//		cout << text;
//		cin >> value;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(32767, '\n');
//			cout << "Your input is invalid. Please, try again.\n" << endl;
//		}
//		else
//			return value;
//	}
//}
//
//template <class T>
//class List
//{
//public:
//	List();
//	List(const List&);
//	~List();
//	void push_back(T);
//	void push_front(T);
//	void pop_back();
//	void pop_front();
//	void clear();
//	T get_last();
//	T get_first();
//	void view_list();
//	int getSize() { return size; }
//	T& operator[] (const int);
//	const T& operator[] (const int) const;
//	bool operator== (const List<T>& ob);
//	template <class T>
//	friend ostream& operator<<(ostream& out, List<T>& list);
//
//private:
//	template<class T>
//	class Node
//	{
//	public:
//		Node* next;
//		Node* prev;
//		T info;
//		Node(T info = T(), Node* next = nullptr, Node* prev = nullptr)
//		{
//			this->info = info;
//			this->next = next;
//			this->prev = prev;
//		}
//	};
//
//	int size;
//	Node<T>* begin, * end;
//};
//
//template <class T>
//List<T>::List()
//{
//	size = 0;
//	begin = end = nullptr;
//}
//
//template<class T>
//List<T>::List(const List& ob)
//{
//	end = begin = nullptr;
//	size = ob.size;
//	int i = 0;
//	while (i < size)
//	{
//		if (!i)
//		{
//			end = new Node<T>(ob[i++]);
//			begin = end;
//		}
//		else
//		{
//			end->next = new Node<T>(ob[i++], nullptr, end);
//			end = end->next;
//		}
//	}
//}
//
//template <class T>
//List<T>::~List()
//{
//	clear();
//}
//
//template<class T>
//void List<T>::push_back(T info)
//{
//	if (!end)
//	{
//		end = new Node<T>(info);
//		begin = end;
//	}
//	else
//	{
//		end->next = new Node<T>(info, nullptr, end);
//		end = end->next;
//	}
//	size++;
//}
//
//template<class T>
//void List<T>::push_front(T info)
//{
//	if (!begin)
//	{
//		begin = new Node<T>(info);
//		end = begin;
//	}
//	else
//	{
//		begin->prev = new Node<T>(info, begin);
//		begin = begin->prev;
//	}
//	size++;
//}
//
//template<class T>
//void List<T>::pop_back()
//{
//	if (end) 
//	{
//		Node<T>* temp = end;
//		if(end->prev)
//			end = end->prev;
//		delete temp;
//		end->next = nullptr;
//		size--;
//	}
//	else
//		cout << "Empty list!" << endl;
//}
//
//template<class T>
//void List<T>::pop_front()
//{
//	if (begin) {
//		Node<T>* temp = begin;
//		if(begin->next)
//			begin = begin->next;
//		delete temp;
//		begin->prev = nullptr;
//		size--;
//	}
//	else
//		cout << "Empty list!" << endl;
//}
//
//template<class T>
//void List<T>::clear()
//{
//	while (size) pop_back();
//}
//
//template<class T>
//T List<T>::get_last()
//{
//	return end->info;
//}
//
//template<class T>
//T List<T>::get_first()
//{ 
//	return begin->info;
//}
//
//template<class T>
//void List<T>::view_list()
//{
//	if (begin)
//	{
//		cout << "List:\t";
//		Node<T>* temp = begin;
//		while (temp)
//		{
//			cout << temp->info << "\t";
//			temp = temp->next;
//		}
//		cout << endl;
//		delete temp;
//	}
//	else
//		cout << "Empty list!" << endl;
//}
//
//template<class T>
//T& List<T>::operator[](const int index)
//{
//	Node<T>* temp = begin;
//	int i = 0;
//	while (index != i)
//	{
//		i++;
//		temp = temp->next;
//	}
//	return temp->info;
//}
//
//template<class T>
//const T& List<T>::operator[](const int index) const
//{
//	Node<T>* temp = begin;
//	int i = 0;
//	while (index != i)
//	{
//		i++;
//		temp = temp->next;
//	}
//	return temp->info;
//}
//
//template<class T>
//bool List<T>::operator==(const List<T>& ob)
//{
//	if (size == ob.size) return true;
//	else return false;
//}
//
//template <class T>
//ostream& operator<<(ostream& out, const List<T>& list)
//{
//	out << "List\t";
//	if (list.begin)
//	{
//		for (int i = 0; i < list.size; i++)
//		{
//			out << list[i] << (i == list.size - 1) ? ", " : endl;
//		}
//	}
//	else
//		out << "Empty list!" << endl;
//	return out;
//}
//
//template <class T>
//void work(List<T> list)
//{
//	bool repeat = true;
//	char key;
//	T info;
//	while (repeat)
//	{
//		cout << "Choose function:\n\t1 - push back\n\t2 - push front\n\t3 - view list\n\t4 - get first element\n\t5 - get last element";
//		cout << "\n\t6 - get element by index\n\t7 - pop back\n\t8 - pop front\n\t9 - clear\n\tdefault - exit" << endl;
//		cin.ignore(32767, '\n');
//		cin >> key;
//		switch (key)
//		{
//		case '1':
//			info = getValue<T>("Enter value: ");
//			list.push_back(info);
//			break;
//		case '2':
//			info = getValue<T>("Enter value: ");
//			list.push_front(info);
//			break;
//		case '3':
//			list.view_list();
//			break;
//		case '4':
//			cout << "First element: " << list.get_first() << endl;
//			break;
//		case '5':
//			cout << "Last element: " << list.get_last() << endl;
//			break;
//		case '6':
//			cout << "Enter index: ";
//			int i;
//			cin >> i;
//			cout << "Element: " << list[i] << endl;
//		case '7':
//			list.pop_back();
//			break;
//		case '8':
//			list.pop_front();
//			break;
//		case '9':
//			list.clear();
//			break;
//		default:
//			repeat = false;
//			break;
//		}
//	}
//}
//
//int main()
//{
//	bool repeat = true;
//	char key;
//	while (repeat)
//	{
//		cout << "Choose type of list:\n\t1 - int\n\t2 - float\n\t3 - double\n\t4 - char\n\t5 - string\n\tdefault - exit" << endl;
//		cin >> key;
//		switch (key)
//		{
//		case '1':
//		{
//			List<int> list;
//			work<int>(list);
//			break;
//		}
//		case '2':
//		{
//			List<float> list;
//			work<float>(list);
//			break;
//		}
//		case '3':
//		{
//			List<double> list;
//			work<double>(list);
//			break;
//		}
//		case '4':
//		{
//			List<char> list;
//			work<char>(list);
//			break;
//		}
//		case '5':
//		{
//			List<string> list;
//			work<string>(list);
//			break;
//		}
//		default:
//			repeat = false;
//			break;
//		}
//	}
//}