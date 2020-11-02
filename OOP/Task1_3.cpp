//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//namespace myString {
//	class String {
//	private:
//		char* str;
//		int size;
//	public:
//		String(const char*);
//		String(const String&);
//		~String();
//		friend void setStr(String&, const char*);
//		friend void getStr(String&);
//		int operator-(const String&);
//		int operator>(const String&);
//		char* operator++();
//		char* operator++(int);
//		String& operator=(const String&);
//	};
//	void setStr(String& ob, const char* str) {
//		ob.size = strlen(str);
//		ob.str = new char[ob.size + 1];
//		strcpy(ob.str, str);
//	}
//	void getStr(String& ob) {
//		cout << ob.str << endl;
//	}
//}
//using namespace myString;
//String::String(const char* str = "Hello World") {
//	this->size = strlen(str);
//	this->str = new char[size + 1];
//	strcpy(this->str, str);
//}
//String::String(const String& ob) {
//	size = ob.size;
//	str = new char[size + 1];
//	strcpy(str, ob.str);
//}
//String::~String() {
//	delete[] str;
//}
//int String::operator-(const String& ob) {
//	return fabs(strlen(str) - strlen(ob.str));
//}
//int String::operator>(const String& ob) {
//	for (int i = 0; str[i] != '\0' ; i++) {
//		if (str[i] != ob.str[i]) {
//			return fabs((int)str[i] - (int)ob.str[i]);
//		}
//	}
//	return 0;
//}
//char* String::operator++() {
//	char* newStr = new char[++size];
//	strcpy(newStr, str);
//	newStr[strlen(str)] = '*';
//	newStr[size] = '\0';
//	return newStr;
//}
//char* String::operator++(int) {
//	char* newStr = new char[++size];
//	newStr[0] = '*';
//	for (int i = 0; str[i] != '\0' ; i++) {
//		newStr[i + 1] = str[i];
//	}
//	newStr[size] = '\0';
//	return newStr;
//}
//String& String::operator=(const String& ob) {
//	if (str != nullptr) {
//		delete[] str;
//	}
//	size = ob.size;
//	str = new char[size + 1];
//	strcpy(str, ob.str);
//	return *this;
//}
//
//int main() {
//	bool repeat;
//	String str1;
//	String str2;
//	do {
//		repeat = true;
//		char key;
//		cout << "Choose function:\n\t1 - view string\n\t2 - set string\n\t3 - copy one string to another\n\t4 - find difference of length of the strings\n\t5 - find difference of the first different symbols\n\t6 - use operator++\n\t7 - use ++operator\n\tdefault - exit" << endl;
//		switch (_getch())
//		{
//		case '1':
//			cout << "1 - the first string\ndefault - the second string" << endl; key = _getch();
//			getStr(((key == '1') ? str1 : str2));
//			break;
//		case '2':
//			cout << "1 - the first string\ndefault - the second string" << endl; key = _getch();
//			cout << "Enter string: ";
//			char userstr[255]; 
//			cin.getline(userstr, 255, '\n');
//			setStr(((key == '1') ? str1 : str2), userstr);
//			break;
//		case '3': {
//			cout << "1 - the first string to the new string\ndefault - the second string to the new string" << endl; key = _getch();
//			String str3((key == '1') ? str1 : str2);
//			break; 
//		}
//		case '4':
//			cout << "The difference: " << str2 - str1 << endl;
//			break;
//		case '5':
//			cout << "The difference of the first different symbols: " << (str2 > str1) << endl;
//			break;
//		case '6':
//			cout << "1 - the first string\n2 - the second string" << endl; key = _getch();
//			((key == '1') ? str1 : str2) = ((key == '1') ? str1 : str2)++;
//			break;
//		case '7':
//			cout << "1 - the first string\n2 - the second string" << endl; key = _getch();
//			((key == '1') ? str1 : str2) = ++((key == '1') ? str1 : str2);
//			break;
//		default:
//			repeat = false;
//			break;
//		}
//	} while (repeat);
//}