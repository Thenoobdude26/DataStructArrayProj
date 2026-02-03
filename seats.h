#ifndef SEATS_H
#define SEATS_H

#include <string>
#include<iostream> //maybe iomanip

const int MAX_ROWS = 50; // well. . . max rows
const int MAX_COLS = 6; //A B C D E F

//STEAT STRUCTURE WITH DA FOKEN DEFAULT VALUES
struct seats
{
    /* data */
    std::string passengerID = "";
    std::string name        = "";
    std::string classType   = ""; //ECONOMY-BUSINESS-FIRST
    bool        occupied    = false;
};

extern seats plane[MAX_ROWS][MAX_COLS];

extern int passengerCount;
void    initPlane();

bool    loadCSV(const std::string& filename);

void    printSeatingChart();//xuan min
void    printPassengerlist();// xuan min

bool    reserveSeat(const std::string& id, const std ::string& name, 
                    const std::string& cls, int& outRow, int& outCol);
bool    cancelBooking(const std::string& id);

bool    findPassenger(const std::string& id,Passenger& result);

#endif



void initPlane(){
    for(int r = 0; r < MAX_ROWS; r++)
        for(int c = 0; c < MAX_COLS; c++)
            plane[r][c] = seats();
    }
}