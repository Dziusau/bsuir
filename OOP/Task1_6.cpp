//#include <iostream>
//#include <string>
//using namespace std;
//
//class MotherBoard
//{
//private:
//	string processor;
//	float speed;
//	int RAM;
//public:
//	MotherBoard(string processor = "", float speed = 0, int RAM = 0) : processor(processor), speed(speed), RAM(RAM){};
//	string getProcessor() { return processor; }
//	void setProcessor(string processor) { this->processor = processor; }
//	float getSpeed() { return speed; }
//	void setSpeed(float speed) { this->speed = speed; }
//	int getRAM() { return RAM; }
//	void setRAM(int RAM) { this->RAM = RAM; }
//	void showMotherBoard(void)
//	{
//		cout << "Processor: " << processor << endl;
//		cout << "Speed: " << speed << " MGhz" << endl;
//		cout << "RAM: " << RAM << "Gb" << endl;
//	}
//};
//
//class Screen
//{
//private: 
//	string type;
//	int width;
//	int height;
//public:
//	Screen(string type = "",  int width = 0, int height = 0) : type(type), width(width), height(height) {};
//	string getType() { return type; }
//	void setType(string type) { this->type = type; }
//	int getWidth() { return width; }
//	void setWidth(int width) { this->width = width; }
//	int getHeight() { return height; }
//	void setHeight(int height) { this->height = height; }
//	void showScreen() 
//	{
//		cout << "Screen type: " << type << endl;
//		cout << "Resolution: " << width << " x " << height << endl;
//	}
//};
//
//class Computer : public Screen, private MotherBoard
//{
//private:
//	string name;
//	int hardDrive;
//public:
//	Computer(string name = "", int hardDrive = 0) : name(name), hardDrive(hardDrive) {};
//	string getName() { return name; }
//	void setName(string name) { this->name = name; }
//	int getHardDrive() { return hardDrive; }
//	void setHardDrive(int hardDrive) { this->hardDrive = hardDrive; }
//	void setMotherBoard(string processor, float speed, int RAM)
//	{
//		setProcessor(processor);
//		setSpeed(speed);
//		setRAM(RAM);
//	}
//	void setScreen(string type, int width, int height)
//	{
//		setType(type);
//		setWidth(width);
//		setHeight(height);
//	}
//	void virtual showComputer()
//	{
//		showMotherBoard();
//		showScreen();
//		cout << "Type: " << name << endl;
//		cout << "Hard drive: " << hardDrive << " Gb" << endl;
//	}
//};
//
//class WorkStation : private Computer
//{
//private:
//	string OS;
//public:
//	WorkStation(string OS = "") : OS(OS) {};
//	string getOS() { return OS; }
//	void setOS(string OS) { this->OS = OS; }
//	void showComputer() override
//	{
//		showScreen();
//		cout << "Type: " << getName() << endl;
//		cout << "Hard drive: " << getHardDrive() << " Gb" << endl;
//		cout << "Operating System: " << OS << endl;
//	}
//	void setComputer(string name, int hardDrive, string processor, float speed, int RAM, string type, int width, int height)
//	{
//		setName(name);
//		setHardDrive(hardDrive);
//		setMotherBoard(processor, speed, RAM);
//		setScreen(type, width, height);
//	}
//};
//
//class Labtop : public WorkStation
//{
//private:
//	int battery;
//	int weight;
//public:
//	Labtop(int battery = 0, int weight = 0) : battery(battery), weight(weight) {};
//	int getBattery() { return battery; }
//	int getWeight() { return weight; }
//	void work() 
//	{ 
//		if (battery >= 10)
//		{
//			cout << "Doing something..." << endl;
//			this->battery -= 10;
//		}
//		else
//		{
//			cout << "Labtop is uncharged!" << endl;
//		}
//	}
//	void charge() { this->battery = 100; }
//};
//
//int main() 
//{
//	Labtop labtop(100, 2);
//	labtop.setOS("MacOS");
//	labtop.setComputer("Lenovo", 20, "Intel", 2.2, 4, "LED", 30, 20);
//	WorkStation workStation("Linux");
//	workStation.setComputer("PC", 15, "AMD", 4.4, 6, "RGB", 15, 15);
//	Computer computer("PC", 10);
//	computer.setMotherBoard("AMD", 2.4, 2);
//	computer.setScreen("LTE", 25, 20);
//	bool repeat = true;
//	char key;
//	while (repeat)
//	{
//		cout << "Choose object:\n\t1 - labtop\n\t2 - work station\n\t3 - computer\n\tdefault - exit" << endl;
//		cin >> key;
//		switch (key)
//		{
//		case '1':
//			while (repeat)
//			{
//				cout << "\nChoose function:\n\t1 - get battery\n\t2 - get weight\n\t3 - get OS\n\t4 - charge labtop\n\t5 - set OS\n\t6 - show features\n\t7 - work\n\t default - exit" << endl;
//				cin >> key;
//				switch (key)
//				{
//				case '1':
//					cout << "Battery charge: " << labtop.getBattery() << endl;
//					break;
//				case '2':
//					cout << "Weight: " << labtop.getWeight() << " kg" << endl;
//					break;
//				case '3':
//					cout << "OS: " << labtop.getOS() << endl;
//					break;
//				case '4':
//					labtop.charge();
//					break;
//				case '5':
//				{
//					cout << "Enter OS: ";
//					string OS;
//					cin.ignore(32767, '\n');
//					getline(cin, OS);
//					labtop.setOS(OS);
//					break;
//				}
//				case '6':
//					labtop.showComputer();
//					break;
//				case '7':
//					labtop.work();
//					break;
//				default:
//					repeat = false;
//					break;
//				}
//			}
//			repeat = true;
//			break;
//		case '2':
//			while (repeat)
//			{
//				cout << "\nChoose function:\n\t1 - get OS\n\t2 - show features\n\t3 - set OS\n\t4 - reset features\n\t default - exit" << endl;
//				cin >> key;
//				switch (key)
//				{
//				case '1':
//					cout << "OS: " << workStation.getOS() << endl;
//					break;
//				case '2':
//					workStation.showComputer();
//					break;
//				case '3':
//				{
//					cout << "Enter OS: ";
//					string OS;
//					cin.ignore(32767, '\n');
//					getline(cin, OS);
//					workStation.setOS(OS);
//					break;
//				}
//				case '4':
//				{
//					cout << "Enter processor type: ";
//					string processor;
//					cin.ignore(32767, '\n');
//					getline(cin, processor);
//					cout << "Enter screen type: ";
//					string screen;
//					cin.ignore(32767, '\n');
//					getline(cin, screen);
//					cout << "Enter station type: ";
//					string name;
//					cin.ignore(32767, '\n');
//					getline(cin, name);
//					cout << "Enter HD capacity: ";
//					int HD;
//					cin >> HD;
//					cout << "Enter processor speed: ";
//					float speed;
//					cin >> speed;
//					cout << "Enter RAM: ";
//					int RAM;
//					cin >> RAM;
//					cout << "Enter screen width: ";
//					int width;
//					cin >> width;
//					cout << "Enter screen height: ";
//					int height;
//					cin >> height;
//					workStation.setComputer(name, HD, processor, speed, RAM, screen, width, height);
//					break;
//				}
//				default:
//					repeat = false;
//					break;
//				}
//			}
//			repeat = true;
//			break;
//		case '3':
//			while (repeat)
//			{
//				cout << "\nChoose function:\n\t1 - get type\n\t2 - get hard drive\n\t3 - show features\n\t4 - show screen features\n\t5 - set type\n\t6 - set hard drive\n\t7 - set mother board\n\t8 - set screen\n\tdefault - exit" << endl;
//				cin >> key;
//				switch (key)
//				{
//				case '1':
//					cout << "Type: " << computer.getName() << endl;
//					break;
//				case '2':
//					cout << "Hard drive: " << computer.getHardDrive() << " Gb" << endl;
//					break;
//				case '3':
//					computer.showComputer();
//					break;
//				case '4':
//					computer.showScreen();
//					break;
//				case '5':
//				{
//					cout << "Enter type: ";
//					string name;
//					cin.ignore(32767, '\n');
//					getline(cin, name);
//					computer.setName(name);
//					break;
//				}
//				case '6':
//				{
//					cout << "Enter HD capacity: ";
//					int HD;
//					cin >> HD;
//					computer.setHardDrive(HD);
//					break;
//				}
//				case '7':
//				{
//					cout << "Enter processor type: ";
//					string processor;
//					cin.ignore(32767, '\n');
//					getline(cin, processor);
//					cout << "Enter processor speed: ";
//					float speed;
//					cin >> speed;
//					cout << "Enter RAM: ";
//					int RAM;
//					cin >> RAM;
//					computer.setMotherBoard(processor, speed, RAM);
//					break;
//				}
//				case '8':
//				{
//					cout << "Enter screen type: ";
//					string screen;
//					cin.ignore(32767, '\n');
//					getline(cin, screen);
//					cout << "Enter screen width: ";
//					int width;
//					cin >> width;
//					cout << "Enter screen height: ";
//					int height;
//					cin >> height;
//					computer.setScreen(screen, width, height);
//				}
//				default:
//					repeat = false;
//					break;
//				}
//			}
//			repeat = true;
//			break;
//		default:
//			repeat = false;
//			break;
//		}
//	}
//	return 0;
//}