//#include <iostream>
//#include <fstream>
//#include <conio.h>
//#include <windows.h>
//#include <list>
//#include <iomanip>
//#include <string>
//
//#define pause system("pause")
//#define cls system("cls")
//
//using namespace std;
//
//class Product;
//class Human;
//class Customer;
//class Seller;
//class Store;
//template<typename T>
//T getValue(const char*);
//
//class Product {
//	string name;
//	float price;
//
//public:
//	Product(string name = "", float price = 0) : name(name), price(price) {}
//
//	void setName(string name) { this->name = name; }
//	string getName() { return name; }
//
//	void setPrice(float price) { this->price = price; }
//	float getPrice() { return price; }
//};
//
//class Human {
//	int key;
//	string name;
//
//public:
//	Human(string name, int key) : name(name), key(key) {}
//
//	void setName(string name) { this->name = name; }
//	string getName() { return name; }
//
//	int getKey() { return key; }
//};
//
//class Seller : public Human {
//	float sum;
//	string phoneNumber;
//public:
//	Seller(string name = "", string phoneNumber = "") : sum(0), phoneNumber(phoneNumber), Human(name, 1) {}
//
//	void sayHello() { cout << "Good afternoon. My name is " << this->getName() << "\nCan I help you?" << endl; }
//	float sumPrice(list<Product> order) {
//		sum = 0;
//		for (Product n : order)
//			sum += n.getPrice();
//		return sum;
//	}
//	void setPrice(Product& good) {
//		float price = getValue<float>("price");
//		good.setPrice(price);
//	}
//
//	string getPhoneNumber() { return phoneNumber; }
//};
//
//class Customer : public Human {
//	float cash;
//
//public:
//	Customer(float cash = 0, string name = "") : cash(cash), Human(name, 0) {}
//
//	void setCash(float cash) { this->cash = cash; }
//	float getCash() { return cash; }
//
//	void buy(float price) {
//		if (price > cash) throw 0;
//		cash -= price;
//	}
//	void viewGoods(list<Product> goods) {
//		if (goods.empty()) throw "Empty";
//		int i = 1;
//		cout << setw(17) << right << "Name" << setw(15) << "Price" << endl;
//		for (Product n : goods)
//			cout << setw(3) << i++ << "\t" << setw(10) << n.getName() << setw(10) << n.getPrice() << " $" << endl;
//	}
//	void callSeller(Seller seller) {
//		for (int j = 0; j < 2; j++) {
//			cls;
//			cout << seller.getPhoneNumber() << "\nRinning ";
//			for (int i = 0; i < 3; i++) {
//				Sleep(1000);
//				cout << ".";
//			}
//		}
//		cout << "Noone has answered(((" << endl;
//	}
//	list<Product> findGood(char key, list<Product> assortment) {
//		list<Product> goods;
//		if (key == '1') {
//			cout << "Enter name: ";
//			string name;
//			cin.ignore(10, '\n');
//			getline(cin, name);
//			for (Product n : assortment) {
//				if (n.getName() == name)
//					goods.push_back(n);
//			}
//		}
//		else {
//			float price = getValue<float>("price");
//			for (Product n : assortment) {
//				if (n.getPrice() == price)
//					goods.push_back(n);
//			}
//		}
//		return goods;
//	}
//};
//
//class Store {
//	bool isOpen;
//	list<Product> assortment;
//
//public:
//	Store() : isOpen(false), assortment{} {}
//
//	void openStore(int key) {
//		if (!key) throw 0;
//		else if (isOpen) throw "Already opened...";
//		isOpen = true;
//		cout << "Opened..." << endl;
//	}
//	void closeStore(int key) {
//		if (!key) throw 0;
//		else if (!isOpen) throw "Already closed...";
//		isOpen = false;
//		cout << "Closed..." << endl;
//	}
//	void fillShelfs(int key, list<Product> goods) {
//		if (!isOpen) throw false;
//		else if (!key) throw "You don't work here.";
//		for (Product n : goods)
//			assortment.push_back(n);
//	}
//	void addProduct() {
//		if (!isOpen) throw false;
//		cout << "Enter name: ";
//		string name;
//		cin.ignore(10, '\n');
//		getline(cin, name);
//		float price = getValue<float>("price");
//		Product good(name, price);
//		assortment.push_back(good);
//	}
//	void clearShelves() {
//		if (!isOpen) throw false;
//		else if (assortment.empty()) throw 1;
//		assortment.clear();
//	}
//	void toStorage(const char* name) {
//		if (!isOpen) throw false;
//		else if (assortment.empty()) throw 1;
//		ofstream file;
//		file.open(name, ios::app);
//		if (!file.is_open()) throw "File openning error!!!";
//		for (Product n : assortment)
//			file.write(reinterpret_cast<char*>(&n), sizeof(Product));
//		assortment.clear();
//		file.close();
//	}
//	void getStorage(const char* name) {
//		if (!isOpen) throw false;
//		ifstream file;
//		file.open(name);
//		if (!file.is_open()) throw "File openning error!!!";
//		/*file.seekg(0, ios::end);
//		int length = (int)file.tellg() / sizeof(Product);
//		Product n;
//		file.seekg(0);
//		for (int i = 0; i < length; i++) {
//			file.read(reinterpret_cast<char*>(&n), sizeof(n));
//			assortment.push_back(n);
//		}*/
//		Product n;
//		file.read(reinterpret_cast<char*>(&n), sizeof(n));
//		while (!file.eof()) {
//			assortment.push_back(n);
//			file.read(reinterpret_cast<char*>(&n), sizeof(n));
//		}
//		file.close();
//	}
//
//	bool isOpened() { return isOpen; }
//	list<Product> getAssortment() { return assortment; }
//};
//
//
//int main() {
//	bool repeat;
//	Store store;
//	Customer customer(50, "Vasya");
//	Seller seller("Jim", "+8-800-555-35-35");
//	list<Product> order;
//	list<Product> goods{ {"hammer", 10}, {"screwdriver", 7}, {"knife", 5}, {"glue", 3}, {"saw", 15},
//							{"screw", 2}, {"nail", 1}, {"bar", 9}, {"paint", 20}, {"brush", 9} };
//	string file = "storage.txt";
//	while (true)
//	{
//		repeat = true;
//		cls;
//		cout << "Choose user:\n1 - seller\n2 - customer\n3 - exit" << endl;
//		switch (_getch())
//		{
//		case '1':
//			while (repeat) {
//				cls;
//				cout << "1 - open the store\n2 - fill the shelves\n3 - change price\n4 - add good\n5 - clear shelves\n6 - take goods away to the storage\n7 - bring goods from the storage\n8 - close the store\ndefault - exit" << endl;
//				switch (_getch())
//				{
//				case '1':
//				{
//					cls;
//					try {
//						store.openStore(seller.getKey());
//					}
//					catch (const char* s) {
//						cout << s << endl;
//					}
//					pause;
//					break;
//				}
//				case '2':
//				{
//					cls;
//					try {
//						store.fillShelfs(seller.getKey(), goods);
//						customer.viewGoods(store.getAssortment());
//					}
//					catch (bool) {
//						cout << "The store is closed." << endl;
//					}
//					pause;
//					break;
//				}
//				case '3':
//				{
//					cls;
//					try {
//						if (!store.isOpened()) throw false;
//						int n;
//						customer.viewGoods(store.getAssortment());
//						list<Product> assortment = store.getAssortment();
//						auto iter = assortment.begin();
//						cout << "Enter number of good: ";
//						cin >> n;
//						if (n < 1 || n > assortment.size()) throw 0;
//						for (int i = 1; i < n; i++, iter++);
//						seller.setPrice(*iter);
//						store.fillShelfs(seller.getKey(), assortment);
//						customer.viewGoods(store.getAssortment());
//					}
//					catch (bool) {
//						cout << "The store is closed." << endl;
//					}
//					catch (int) {
//						cout << "Incorrect number." << endl;
//					}
//					catch (const char* s) {
//						cout << s << " shelves(" << endl;
//					}
//					pause;
//					break;
//				}
//				case '4':
//				{
//					cls;
//					try {
//						store.addProduct();
//						customer.viewGoods(store.getAssortment());
//					}
//					catch (bool) {
//						cout << "The store is closed." << endl;
//					}
//					pause;
//					break;
//				}
//				case '5':
//				{
//					cls;
//					try {
//						store.clearShelves();
//						cout << "Clear..." << endl;
//					}
//					catch (bool) {
//						cout << "The store is closed." << endl;
//					}
//					catch (int) {
//						cout << "The shelves are clear." << endl;
//					}
//					pause;
//					break;
//				}
//				case '6':
//				{
//					cls;
//					try {
//						store.toStorage(file.c_str());
//						cout << "Stored..." << endl;
//					}
//					catch (bool) {
//						cout << "The store is closed." << endl;
//					}
//					catch (int) {
//						cout << "The shelves are clear." << endl;
//					}
//					catch (const char* s) {
//						cout << s << endl;
//					}
//					pause;
//					break;
//				}
//				case '7':
//				{
//					cls;
//					try {
//						store.getStorage(file.c_str());
//						customer.viewGoods(store.getAssortment());
//					}
//					catch (bool) {
//						cout << "The store is closed." << endl;
//					}
//					catch (const char* s) {
//						cout << s << endl;
//					}
//					pause;
//					break;
//				}
//				case '8':
//				{
//					cls;
//					try {
//						store.closeStore(seller.getKey());
//					}
//					catch (const char* s) {
//						cout << s << endl;
//					}
//					pause;
//					break;
//				}
//				default:
//					repeat = false;
//					break;
//				}
//			}
//			break;
//		case '2':
//			try {
//				if (!store.isOpened()) throw false;
//				while (repeat) {
//					cls;
//					seller.sayHello();
//					cout << "\n1 - view goods\n2 - check cash\n3 - make order\n4 - view order\n5 - buy\n6 - help the seller\n7 - find good\ndefault - exit" << endl;
//					switch (_getch())
//					{
//					case '1':
//					{
//						cls;
//						try {
//							customer.viewGoods(store.getAssortment());
//						}
//						catch (const char* s) {
//							cout << s << " shelves(" << endl;
//						}
//						pause;
//						break;
//					}
//					case '2':
//					{
//						cls;
//						cout << "Cash: " << customer.getCash() << "$" << endl;
//						pause;
//						break;
//					}
//					case '3':
//					{
//						try {
//							while (repeat)
//							{
//								cls;
//								customer.viewGoods(store.getAssortment());
//								int n;
//								list<Product> assortment = store.getAssortment();
//								auto iter = assortment.begin();
//								cout << "Enter number of good: ";
//								cin >> n;
//								if (n < 1 || n > assortment.size()) throw 0;
//								for (int i = 1; i < n; i++, iter++);
//								order.push_back(*iter);
//								assortment.erase(iter);
//								store.fillShelfs(seller.getKey(), assortment);
//								cout << "Do you want to choose one more?(Y/N)" << endl; char k = _getch();
//								if (!(k == 'Y' || k == 'y'))
//									repeat = false;
//							}
//							repeat = true;
//						}
//						catch (const char* s) {
//							cout << s << " shelves(" << endl;
//						}
//						catch (int) {
//							cout << "Incorrect number." << endl;
//						}
//						pause;
//						break;
//					}
//					case '4':
//					{
//						cls;
//						try {
//							customer.viewGoods(order);
//						}
//						catch (const char* s) {
//							cout << s << " order" << endl;
//						}
//						pause;
//						break;
//					}
//					case '5':
//					{
//						cls;
//						try {
//							if (order.empty()) throw "You didn't choose goods.";
//							cout << "Great choice. Thanks." << endl;
//							cout << "Total cost of order: " << seller.sumPrice(order) << " $" << endl;
//							customer.buy(seller.sumPrice(order));
//							cout << "Your current cash: " << customer.getCash() << " $" << endl;
//							order.clear();
//						}
//						catch (const char* s) {
//							cout << s << endl;
//						}
//						catch (int) {
//							cout << "Oow. Go away and find some money." << endl;
//							list<Product> assortment = store.getAssortment();
//							for (Product n : order)
//								assortment.push_back(n);
//							order.clear();
//							store.fillShelfs(seller.getKey(), assortment);
//						}
//						pause;
//						break;
//					}
//					case '6':
//					{
//						cls;
//						try {
//							store.fillShelfs(customer.getKey(), goods);
//						}
//						catch (const char* s) {
//							cout << s << endl;
//						}
//						pause;
//						break;
//					}
//					case '7':
//					{
//						cls;
//						try {
//							list<Product> goods;
//							list<Product> assortment(store.getAssortment());
//							cout << "1 - by name\ndefault - by price" << endl; char key = _getch();
//							goods = customer.findGood(key, assortment);
//							if (goods.empty()) throw false;
//							customer.viewGoods(goods);
//						}
//						catch (bool) {
//							cout << "No such goods in assortment..." << endl;
//						}
//						pause;
//						break;
//					}
//					default:
//						repeat = false;
//						break;
//					}
//				}
//			}
//			catch (bool) {
//				while (repeat) {
//					cls;
//					cout << "The store is closed.\n1 - try to open\n2 - call the seller\ndefault - exit" << endl;
//					switch (_getch())
//					{
//					case '1':
//						cls;
//						try {
//							store.openStore(customer.getKey());
//						}
//						catch (int) {
//							cout << "The glass of the door's windows is too strong. \nIt's bad idea to break it, because it can break your had..." << endl;
//						}
//						pause;
//						break;
//					case '2':
//						customer.callSeller(seller);
//						pause;
//						break;
//					default:
//						repeat = false;
//						break;
//					}
//				}
//			}
//			break;
//		default:
//			return 0;
//		}
//	}
//}
//
//template<typename T>
//T getValue(const char* text) {
//	T value;
//	while (true) {
//		cout << "Enter " << text << " value: ";
//		cin >> value;
//		if (cin.fail()) {
//			cin.clear();
//			cin.ignore(10, '\n');
//			cout << "Your input is invalid. Please, try again." << endl;
//		}
//		else if (value <= 0) cout << "Price can't be less then 0. Please, try again." << endl;
//		else
//			return value;
//	}
//}