#include <iostream>
#include <string>
#include "seats.h"

using namespace std;

int main() {

    //Initializes the plane by clearing all the seats
    initPlane();

    //Load data from the CSV File
    bool loaded = loadFromCSV("data/flight_passenger_data.csv.csv");
    if (loaded) {
        cout << "Loaded" << passengerCount << " passengers\n";
    }

    //Main interactive menu loop
    int choice;
    do {
        cout << "\n1. Show Chart\n";
        cout << "2. Show manifest\n";
        cout << "3. Reserve seat\n";
        cout << "4. Cancel booking\n";
        cout << "5. Lookup passenger\n";
        cout << "0. Exit";
        cout << ". . . ";

        cin >> choice;
        cin.ignore();

        if (choice == 1)    printSeatingChart(); //make print seating chart (Xuan min, it's in seats.h)
        else if (choice == 2)   printPassengerlist();//make print passenger list (xuam min, same here)
        else if (choice == 3) {
            //read id,name,and class
            reserveSeat();//make reserveSeat function(tatenda)
            }
        else if (choice == 4)   cancelBooking();//make cancel booking function(tatenda)
        else if (choice == 5) {
            //read ID
            lookuppass();// Make look up passenger and print result(tatenda)
        }
    } while (choice != 0);
    cout << "Goodbye, have a day!\n";
    return 0;
}