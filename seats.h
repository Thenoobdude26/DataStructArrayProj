#ifndef SEATS_H
#define SEATS_H

#include <string>
#include <iostream>
#include <iomanip>      // for nicer table printing (setw)
#include <fstream>      // for reading CSV
#include <sstream>      // for parsing CSV lines

// ────────────────────────────────────────────────
// CONSTANTS (used by both team members)
// ────────────────────────────────────────────────
const int MAX_ROWS = 50;
const int MAX_COLS = 6;

// ────────────────────────────────────────────────
// DATA STRUCTURE (used by both team members)
// ────────────────────────────────────────────────
struct Seat {
    std::string passengerID = "";
    std::string name        = "";
    std::string classType   = "";   // e.g. "Economy", "Business", "First"
    bool        occupied    = false;
};

extern Seat plane[MAX_ROWS][MAX_COLS];

// ────────────────────────────────────────────────
// FUNCTION DECLARATIONS
// ────────────────────────────────────────────────

// Tatenda – Initialization & core booking/cancel logic
void initPlane();
bool reserveSeat(std::string id, std::string name, std::string cls);
bool cancelBooking(std::string id);

// Xuan Min – Display & search / report functions
void printSeatingChart();
void printPassengerManifest();
void searchPassengerID();

bool loadCSV(const std::string& filename);  // shared, but can be called from main

#endif