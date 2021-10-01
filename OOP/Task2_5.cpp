#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Bank {
	map<int, Client> clients;
	list<string> operations;
	int fund;
	int percent;
	int index;

public:
	Bank() : index(1), fund(10000000), percent(7) {}

	int getIndex(string name) {
		for (auto c: clients)
		{
			if (c.second.getName() == name) {
				return c.first;
			}
		}
		return 0;
	}

	void addClient(Client client) {
		clients[index++] = client;
	}

	bool giveCredit(string clientName) {
		if (fund >= 100000) {
			clients[getIndex(clientName)].setCash(100000);
			fund -= 100000;
			operations.push_back("Выдан кредит клиенту " + clientName + " на сумму 100000$");
			return 1;
		}
		else return 0;
	}

	void creditRepay(string clientName) {
		int payment = 100000;
		payment *= 1 + percent / 100.;
		Client client = clients[getIndex(clientName)];
		client.setCash(client.getCash() - payment);
		if (client.getCash() < 0) {
			operations.push_back("Клиент " + clientName + " частично погасил кредит.");
			throw ((-1) * client.getCash());
		}
	}
};

class Client {
	string name;
	int cash;

public:
	Client(string name = "", int cash = 0) : name(name), cash(cash) {}

	string getName() { return name; }
	void setName(string name) { this->name = name; }

	int getCash() { return cash; }
	void setCash(int cash) { this->cash = cash; }

	void makeMoney(int money) { this->cash += money; }
};
bool operator< (Client c1, Client c2) {
	return c1.getName() < c2.getName();
}