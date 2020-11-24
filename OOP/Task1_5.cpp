#include <iostream>
#include <ctime>
#include <time.h>
#include <thread>
#include <conio.h>
#include <string>
using namespace std;

void setTime(tm& time) {
	const time_t timer = std::time(NULL);
	localtime_s(&time, &timer);
}

class EnergySource {
private:
	int power;
public:
	EnergySource(int power = 0) : power(power) {};

	int getPower() { return power; }

	void setPower(int power) { this->power = power; }
};

class Clock {
private:
	class ClockFace {
	private:
		struct tm time;
	public:
		ClockFace() { setTime(time); }

		struct tm getCurrentTime() {
			setTime(time);
			return time;
		}
	};

	EnergySource* energySource;
	ClockFace clockFace;
	int energyPerHour;
	unsigned int startTime;

public:
	Clock(EnergySource* energySource, int energyPerHour) {
		this->energySource = energySource;
		this->energyPerHour = energyPerHour;
		startTime = clock();
	};

	Clock(const Clock& ob) {
		clockFace = ob.clockFace;
		energyPerHour = ob.energyPerHour;
		energySource = new EnergySource;
		*energySource = *ob.energySource;
		startTime = clock();
	}

	~Clock() { delete energySource; }

	EnergySource* getEnergySource() { return energySource; }

	void setEnergySource(EnergySource* energySource) { this->energySource = energySource; }

	int getEnergyPerHour() { return energyPerHour; }

	void setEnergyPerHour(int energyPerHour) { this->energyPerHour = energyPerHour; }

	int lifeTimeLeft() { return energySource->getPower() / energyPerHour; }

	bool dischargeEnergySource() {
		unsigned int endTime = clock();
		unsigned int workingTime = (endTime - startTime) / 60000.;
		if (energySource->getPower() > 0) {
			energySource->setPower(energySource->getPower() - workingTime * energyPerHour);
			return true;
		}
		else {
			energySource->setPower(0);
			return false;
		}
	}

	virtual tm turnClock(int value) { return Clock::clockFace.getCurrentTime(); }

	virtual void lookAtClockFace() {
		tm time = clockFace.getCurrentTime();
		char date[9];
		strftime(date, 9, "%T", &time);
		cout << "Current time: " << date << endl;
	}
};

class MechanicalClock : public Clock {
private:
	string brand;
public:
	MechanicalClock(EnergySource* energySource = nullptr, string brand = "") : Clock(energySource, 1), brand(brand) {};

	void setBrand(string brand) { this->brand = brand; }

	string getBrand() { return brand; }

	tm turnClock(int value) override {
		tm time;
		if (this->dischargeEnergySource()) {
			time = Clock::turnClock(value);
			time.tm_min += value;
			if (time.tm_min >= 60) {
				time.tm_hour++;
				time.tm_min -= 60;
			}
			char date[10];
			strftime(date, 10, "%T", &time);
			cout << "Turned time: " << date << endl;
		}
		else {
			cout << "Battary is uncharged!!!" << endl;
		}
		return time;
	}

	void lookAtClockFace() override {
		if (this->dischargeEnergySource()) {
			Clock::lookAtClockFace();
			tm time;
			setTime(time);
			char date[11];
			strftime(date, 11, "%F", &time);
			cout << "Current date: " << date << endl;
		}
		else {
			cout << "Battary is uncharged!!!" << endl;
		}
	}
};

class ElectronicClock : public Clock {
	float price;
public:
	ElectronicClock(EnergySource* energySource = nullptr, float price = 0) : Clock(energySource, 10), price(price) {};

	void setPrice(float price) { this->price = price; }

	float getPrice() { return price; }

	void alarmClock(int delay) {
		if (this->dischargeEnergySource()) {
			thread([=]() {
				this_thread::sleep_for(chrono::seconds(delay));
				cout << "Beap-Beap-Beap" << endl;
				}).detach();
		}
		else {
			cout << "Battary is uncharged!!!" << endl;
		}
	}

	tm turnClock(int value) override {
		tm time;
		if (this->dischargeEnergySource()) {
			time = Clock::turnClock(value);
			time.tm_min += value;
			if (time.tm_min >= 60) {
				time.tm_hour++;
				time.tm_min -= 60;
			}
			char date[11];
			strftime(date, 11, "%I:%M %p", &time);
			cout << "Turned time: " << date << endl;
		}
		else {
			cout << "Battary is uncharged!!!" << endl;
		}
		return time;
	}

	void lookAtClockFace() override {
		if (this->dischargeEnergySource()) {
			tm time;
			setTime(time);
			char date[11];
			strftime(date, 11, "%I:%M %p", &time);
			cout << "Current time: " << date << endl;
			strftime(date, 11, "%d.%m.%Y", &time);
			cout << "Current date: " << date << endl;
		}
		else {
			cout << "Battary is uncharged!!!" << endl;
		}
	}
};

int main() {
	bool repeat = true;
	string bufS;
	double bufD;
	EnergySource AA(50);
	EnergySource AAA(100);
	MechanicalClock mechanicalClock(&AA);
	ElectronicClock electronicClock(&AAA);
	do {
		cout << "Choose function:\n\t1 - choose object\n\t2 - get time\n\t3 - turn clock\n\t4 - remaining life time of clock\n\tdefault - exit" << endl;
		char fun = _getch();
		cout << "\n1 - Mechanical clock\ndefault - Electronic clock" << endl;
		char clock = _getch();
		switch (fun)
		{
		case '1':
		{
			if (clock == '1') {
				while (clock) {
					cout << "\nMechanical clock:\n\t1 - set Brand\n\t2 - get Brand\n\t3 - set Energy per hour\n\t4 - get Energy per hour\n\tdefault - exit" << endl;
					switch (_getch())
					{
					case '1':
						cout << "Enter brand: ";
						getline(cin, bufS, '\n');
						mechanicalClock.setBrand(bufS);
						break;
					case '2':
						cout << "Brand: " << mechanicalClock.getBrand() << endl;
						break;
					case '3':
						cout << "Enter Energy per hour: ";
						cin >> bufD;
						mechanicalClock.setEnergyPerHour(bufD);
						break;
					case '4':
						cout << "Energy per hour: " << mechanicalClock.getEnergyPerHour() << endl;
						break;
					default:
						clock = '\0';
						break;
					}
				}
			}
			else {
				while (clock) {
					cout << "\Electronic clock:\n\t1 - set Price\n\t2 - get Price\n\t3 - set Energy per hour\n\t4 - get Energy per hour\n\t5 - alarm clock\n\tdefault - exit" << endl;
					switch (_getch())
					{
					case '1':
						cout << "Enter Price: ";
						cin >> bufD;
						electronicClock.setPrice(bufD);
						break;
					case '2':
						cout << "Price: " << electronicClock.getPrice() << endl;
						break;
					case '3':
						cout << "Enter Energy per hour: ";
						cin >> bufD;
						electronicClock.setEnergyPerHour(bufD);
						break;
					case '4':
						cout << "Energy per hour: " << electronicClock.getEnergyPerHour() << endl;
						break;
					case '5':
						cout << "Enter delay(seconds): ";
						cin >> bufD;
						electronicClock.alarmClock(bufD);
						break;
					default:
						clock = '\0';
						break;
					}
				}
			}
			break;
		}
		case '2':
			(clock == '1') ? mechanicalClock.lookAtClockFace() : electronicClock.lookAtClockFace();
			break;
		case '3':
			cout << "\nEnter value: ";
			cin >> bufD;
			(clock == '1') ? mechanicalClock.turnClock(bufD) : electronicClock.turnClock(bufD);
			break;
		case '4':
			cout << "Life time left: " << ((clock == '1') ? mechanicalClock.lifeTimeLeft() : electronicClock.lifeTimeLeft()) << endl;
			break;
		default:
			repeat = false;
			break;
		}
	} while (repeat);
}