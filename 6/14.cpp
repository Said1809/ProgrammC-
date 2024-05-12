#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Bus {
public:
    string driverName;
    int routeNumber;

    Bus(string driver, int route) : driverName(driver), routeNumber(route) {}
};

int main() {
    map<int, Bus> busPark;
    map<int, Bus> busRoute;

    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add bus to park\n";
        cout << "2. Simulate bus leaving park\n";
        cout << "3. Simulate bus entering park\n";
        cout << "4. Display buses in park and on route by bus number\n";
        cout << "5. Display buses in park and on route by route number\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch(choice) {
            case 1: {
                int busNumber, routeNumber;
                string driverName;
                cout << "Enter bus number: ";
                cin >> busNumber;
                cout << "Enter driver name: ";
                cin >> driverName;
                cout << "Enter route number: ";
                cin >> routeNumber;
                busPark[busNumber] = Bus(driverName, routeNumber);
                break;
            }
            case 2: {
                int busNumber = 0;
                cout << "Enter the bus number leaving the park: ";
                cin >> busNumber;
                if (busPark.find(busNumber) != busPark.end()) {
                    busRoute[busNumber] = busPark[busNumber];
                    busPark.erase(busNumber);
                }
                break;
            }
            case 3: {
                int busNumber = 0;
                cout << "Enter the bus number entering the park: ";
                cin >> busNumber;
                if (busRoute.find(busNumber) != busRoute.end()) {
                    busPark[busNumber] = busRoute[busNumber];
                    busRoute.erase(busNumber);
                }
                break;
            }
            case 4: {
                cout << "Buses in park:\n";
                for (auto& entry : busPark) {
                    cout << "Bus Number: " << entry.first << " | Driver Name: " << entry.second.driverName << " | Route Number: " << entry.second.routeNumber << endl;
                }
                cout << "Buses on route:\n";
                for (auto& entry : busRoute) {
                    cout << "Bus Number: " << entry.first << " | Driver Name: " << entry.second.driverName << " | Route Number: " << entry.second.routeNumber << endl;
                }
                break;
            }
            case 5: {
                cout << "Buses in park:\n";
                for (auto& entry : busPark) {
                    cout << "Bus Number: " << entry.first << " | Driver Name: " << entry.second.driverName << " | Route Number: " << entry.second.routeNumber << endl;
                }
                cout << "Buses on route:\n";
                for (auto& entry : busRoute) {
                    cout << "Bus Number: " << entry.first << " | Driver Name: " << entry.second.driverName << " | Route Number: " << entry.second.routeNumber << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting the program...";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 6);

    return 0;
}