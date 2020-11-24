//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//double getValue(const char* text) {
//    double value;
//    while (true) {
//        cout << text;
//        cin >> value;
//        if (cin.fail()) {
//            cin.clear();
//            cin.ignore(32767, '\n');
//            cout << "Your input is invalid. Please, try again.\n" << endl;
//        }
//        else
//            return value;
//    }
//}
//
//class Transport {
//private:
//    double tariff;
//    double speed;
//protected:
//    Transport(double tariff, double speed) {
//        this->tariff = tariff;
//        this->speed = speed;
//    }
//    Transport() : tariff(0), speed(0) {}
//    void setTariff(double tariff) {
//        this->tariff = tariff;
//    }
//    void setSpeed(double speed) {
//        this->speed = speed;
//    }
//    double getTariff() const {
//        return tariff;
//    }
//    double getSpeed() const {
//        return speed;
//    }
//public:
//    double time(double distance) const {
//        return distance / speed;
//    }
//    double cost(double distance) const {
//        return distance * tariff;
//    }
//};
//class Car : public Transport {
//private:
//    int model;
//    void improveSpeed();
//public:
//    Car() : model(0), Transport(5, 60) {}
//    void setModel(int model) {
//        this->model = model;
//        improveSpeed();
//    }
//    int getModel() const {
//        return model;
//    }
//};
//class Plane : public Transport {
//private:
//    int planeClass;
//    void improveTariff();
//public:
//    Plane() : planeClass(0), Transport(100, 1000) {}
//    void setPlaneClass(int planeClass) {
//        this->planeClass = planeClass;
//        improveTariff();
//    }
//    int getPlaneClass() const {
//        return planeClass;
//    }
//
//};
//class Train : public Transport {
//private:
//    int type;
//    void improveFeatures();
//public:
//    Train() : type(0), Transport(30, 200) {}
//    void setType(int type) {
//        this->type = type;
//        improveFeatures();
//    }
//    int getType() {
//        return type;
//    }
//};
//int main() {
//    bool repeat = true;
//    Car car;
//    Plane plane;
//    Train train;
//    do {
//        cout << "Choose function:\n\t1 - choose object\n\t2 - find the most quick transport\n\t3 - find the most cheap transport\n\tdefault - exit" << endl;
//        switch (_getch()) {
//        case '1':
//            cout << "Objects:\n\t1 - car\n\t2 - plane\n\t3 - train" << endl;
//            switch (_getch()) {
//            case '1':
//                cout << "Car:\n\t1 - set model\n\tdefault - get model" << endl;
//                if (_getch() == '1') {
//                    int model = getValue("Enter car model (1 or 2): ");
//                    while (!(model == 1 || model == 2)) {
//                        cout << "Your input is invalid. Please, try again." << endl;
//                        model = getValue("Enter car model (1 or 2): ");
//                    }
//                    if (!(model == car.getModel())) {
//                        car.setModel(model);
//                    }
//                    else {
//                        cout << "This model is the current model of your car." << endl;
//                    }
//                }
//                else {
//                    cout << "Current car model: " << car.getModel() << endl;
//                }
//                break;
//            case '2':
//                cout << "Plane:\n\t1 - set plane class\n\tdefault - get plane class" << endl;
//                if (_getch() == '1') {
//                    int planeClass = getValue("Enter plane class (1 or 2): ");
//                    while (!(planeClass == 1 || planeClass == 2)) {
//                        cout << "Your input is invalid. Please, try again." << endl;
//                        planeClass = getValue("Enter plane class (1 or 2): ");
//                    }
//                    if (!(planeClass == plane.getPlaneClass())) {
//                        plane.setPlaneClass(planeClass);
//                    }
//                    else {
//                        cout << "This class is the current class of your plane." << endl;
//                    }
//                }
//                else {
//                    cout << "Current plane class: " << plane.getPlaneClass() << endl;
//                }
//                break;
//            case '3':
//                cout << "Train:\n\t1 - set type\n\tdefault - get type" << endl;
//                if (_getch() == '1') {
//                    int type = getValue("Enter train type (1 or 2): ");
//                    while (!(type == 1 || type == 2)) {
//                        cout << "Your input is invalid. Please, try again." << endl;
//                        type = getValue("Enter train tyoe (1 or 2): ");
//                    }
//                    if (!(type == train.getType())) {
//                        train.setType(type);
//                    }
//                    else {
//                        cout << "This type is the current type of your train." << endl;
//                    }
//                }
//                else {
//                    cout << "Current train type: " << train.getType() << endl;
//                }
//                break;
//            }
//            break;
//        case '2': {
//            double distance = getValue("Enter distance: ");
//            double times[] = { car.time(distance) , plane.time(distance) , train.time(distance) };
//            cout << "Time of each type of transport:\nCar = " << times[0] << "\nPlane = " << times[1] << "\nTrain = " << times[2] << endl;
//            double minTime = times[0];
//            for (int i = 1; i < 3; i++) {
//                if (minTime > times[i]) {
//                    minTime = times[i];
//                }
//            }
//            cout << "The smallest time: " << minTime << endl;
//            break;
//        }
//        case '3': {
//            double distance = getValue("Enter distance: ");
//            double costs[] = { car.cost(distance) , plane.cost(distance) , train.cost(distance) };
//            cout << "Cost of each type of transport:\nCar = " << costs[0] << "\nPlane = " << costs[1] << "\nTrain = " << costs[2] << endl;
//            double minCost = costs[0];
//            for (int i = 1; i < 3; i++) {
//                if (minCost > costs[i]) {
//                    minCost = costs[i];
//                }
//            }
//            cout << "The cheapest cost: " << minCost << endl;
//            break;
//        }
//        default:
//            repeat = false;
//            break;
//        }
//    } while (repeat);
//}
//void Car::improveSpeed() {
//    switch (model) {
//    case 1:
//        this->setSpeed(this->getSpeed() * 2);
//        cout << "Car speed improved: x2\nCurrent speed: " << this->getSpeed() << endl;
//        break;
//    case 2:
//        this->setSpeed(this->getSpeed() / 2);
//        cout << "Car speed degraded: /2\nCurrent speed: " << this->getSpeed() << endl;
//        break;
//    default:
//        cout << "Car speed stay unchangeable.\nCurrent speed: " << this->getSpeed() << endl;
//        break;
//    }
//}
//void Plane::improveTariff() {
//    switch (planeClass) {
//    case 1:
//        this->setTariff(this->getTariff() * 2);
//        cout << "Plane class - business.\nCurrent tariff: " << this->getTariff() << endl;
//        break;
//    case 2:
//        this->setTariff(this->getTariff() / 2);
//        cout << "Plane class - lowcost.\nCurrent tariff: " << this->getTariff() << endl;
//        break;
//    default:
//        cout << "Plane class stay unchangeable.\nCurrent tariff: " << this->getTariff() << endl;
//        break;
//    }
//}
//void Train::improveFeatures() {
//    switch (type) {
//    case 1:
//        this->setTariff(this->getTariff() * 1.5);
//        this->setSpeed(this->getSpeed() * 3);
//        cout << "Train type - fast electric train.\nCurrent tariff: " << this->getTariff() << "\nCurrent speed: " << this->getSpeed() << endl;
//    case 2:
//        this->setTariff(this->getTariff() * 0.7);
//        this->setSpeed(this->getSpeed() * 0.9);
//        cout << "Train type - old steam train.\nCurrent tariff: " << this->getTariff() << "\nCurrent speed: " << this->getSpeed() << endl;
//    default:
//        cout << "Train type stay unchangeable.\nCurrent tariff: " << this->getTariff() << "\nCurrent speed: " << this->getSpeed() << endl;
//    }
//}