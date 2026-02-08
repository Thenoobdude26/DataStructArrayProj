#include <iostream>
#include <string>
#include "seats.h"

using namespace std;

int main() {
    cout << "Flight Reservation System – Array Version\n";
    cout << "----------------------------------------\n\n";

    // Tatenda: initialize plane
    initPlane();

    // Try to load real data (change path if needed)
    string csvPath = "data/flight_passenger_data.csv";   // fix path if it's in subfolder
    if (loadCSV(csvPath)) {
        cout << "Initial bookings loaded.\n";
    } else {
        cout << "CSV not found – you can still test manually.\n";
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "  1. Show seating chart             \n"; //(Xuan Min)
        cout << "  2. Show passenger manifest        \n";//(Xuan Min)
        cout << "  3. Reserve a seat                 \n";//(Tatenda)
        cout << "  4. Cancel a booking               \n";//(Tatenda)
        cout << "  5. Lookup passenger by ID         \n";//(Xuan Min)
        cout << "  0. Exit\n";
        cout << "Choice → ";
        cin >> choice;
        cin.ignore();  // important after cin >>

        if (choice == 1) {
            printSeatingChart();
        }
        else if (choice == 2) {
            printPassengerManifest();
        }
        else if (choice == 3) {
            string id, name, cls;
            cout << "Passenger ID: ";   getline(cin, id);
            cout << "Name: ";           getline(cin, name);
            cout << "Class (Economy/Business/First): "; getline(cin, cls);
            reserveSeat(id, name, cls);
        }
        else if (choice == 4) {
            string id;
            cout << "Enter Passenger ID to cancel: ";
            getline(cin, id);
            cancelBooking(id);
        }
        else if (choice == 5) {
            searchPassengerID();
        }
        else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    cout << "\nGoodbye.\n";
    return 0;
}