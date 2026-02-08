#include "seats.h"

Seat plane[MAX_ROWS][MAX_COLS];

// ────────────────────────────────────────────────
// Tatenda – Initialization
// ────────────────────────────────────────────────
void initPlane() {
    // Clear every seat in the 2D array
    for (int r = 0; r < MAX_ROWS; r++) {
        for (int c = 0; c < MAX_COLS; c++) {
            plane[r][c].passengerID = "";
            plane[r][c].name        = "";
            plane[r][c].classType   = "";
            plane[r][c].occupied    = false;
        }
    }
    std::cout << "Plane initialized – all seats cleared.\n";
}

// ────────────────────────────────────────────────
// Tatenda – Reservation (Insertion)
// ────────────────────────────────────────────────
bool reserveSeat(std::string id, std::string name, std::string cls) {
    // Find first empty seat (simple first-come-first-served)
    for (int r = 0; r < MAX_ROWS; r++) {
        for (int c = 0; c < MAX_COLS; c++) {
            if (!plane[r][c].occupied) {
                plane[r][c].passengerID = id;
                plane[r][c].name        = name;
                plane[r][c].classType   = cls.empty() ? "Economy" : cls;
                plane[r][c].occupied    = true;

                char letter = 'A' + c;
                std::cout << "Reserved seat " << (r+1) << letter
                          << " for " << name << " (" << id << ")\n";
                return true;
            }
        }
    }

    std::cout << "No available seats left.\n";
    return false;
}

// ────────────────────────────────────────────────
// Tatenda – Cancellation (Deletion)
// ────────────────────────────────────────────────
bool cancelBooking(std::string id) {
    for (int r = 0; r < MAX_ROWS; r++) {
        for (int c = 0; c < MAX_COLS; c++) {
            if (plane[r][c].occupied && plane[r][c].passengerID == id) {
                plane[r][c].passengerID = "";
                plane[r][c].name        = "";
                plane[r][c].classType   = "";
                plane[r][c].occupied    = false;

                std::cout << "Cancelled booking for ID: " << id << "\n";
                return true;
            }
        }
    }

    std::cout << "No passenger found with ID: " << id << "\n";
    return false;
}

// ────────────────────────────────────────────────
// Xuan Min – Seat Report / Seating Chart
// ────────────────────────────────────────────────
void printSeatingChart() {
    std::cout << "\nSeating Chart   (* = empty,  X = occupied)\n";
    std::cout << "      A   B   C     D   E   F\n";

    for (int r = 0; r < MAX_ROWS; r++) {
        std::cout << "Row " << std::setw(2) << (r+1) << "  ";
        for (int c = 0; c < MAX_COLS; c++) {
            if (c == 3) std::cout << "  ";  // visual aisle gap
            std::cout << (plane[r][c].occupied ? "X" : "*") << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// ────────────────────────────────────────────────
// Xuan Min – Manifest & Passenger List Report
// ────────────────────────────────────────────────
void printPassengerManifest() {
    std::cout << "\nPassenger Manifest\n";
    std::cout << std::left
              << std::setw(12) << "ID"
              << std::setw(25) << "Name"
              << std::setw(8)  << "Seat"
              << "Class\n";
    std::cout << std::string(55, '-') << "\n";

    bool hasAnyone = false;
    for (int r = 0; r < MAX_ROWS; r++) {
        for (int c = 0; c < MAX_COLS; c++) {
            if (plane[r][c].occupied) {
                hasAnyone = true;
                char letter = 'A' + c;
                std::string seatStr = std::to_string(r+1) + letter;

                std::cout << std::left
                          << std::setw(12) << plane[r][c].passengerID
                          << std::setw(25) << plane[r][c].name
                          << std::setw(8)  << seatStr
                          << plane[r][c].classType << "\n";
            }
        }
    }

    if (!hasAnyone) {
        std::cout << "No passengers currently booked.\n";
    }
}

// ────────────────────────────────────────────────
// Xuan Min – Seat Lookup (Search by PassengerID)
// ────────────────────────────────────────────────
void searchPassengerID() {
    std::string searchID;
    std::cout << "[Xuan Min] Enter Passenger ID to search: ";
    std::cin >> searchID;
    std::cin.ignore();  // clear leftover newline

    bool found = false;
    for (int r = 0; r < MAX_ROWS; r++) {
        for (int c = 0; c < MAX_COLS; c++) {
            if (plane[r][c].occupied && plane[r][c].passengerID == searchID) {
                char seatLetter = 'A' + c;

                std::cout << "\nPassenger Found!\n";
                std::cout << "  ID     : " << plane[r][c].passengerID << "\n";
                std::cout << "  Name   : " << plane[r][c].name << "\n";
                std::cout << "  Class  : " << plane[r][c].classType << "\n";
                std::cout << "  Seat   : Row " << (r + 1) << " - " << seatLetter << "\n\n";

                found = true;
                return;
            }
        }
    }

    if (!found) {
        std::cout << "[Xuan Min] No passenger found with ID: " << searchID << "\n";
    }
}

// ────────────────────────────────────────────────
// Shared – CSV Loading (can be called from main)
// ────────────────────────────────────────────────
bool loadCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Cannot open " << filename << "\n";
        return false;
    }

    std::string line;
    std::getline(file, line); // skip header

    int loaded = 0;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string id, name, rowStr, colStr, cls;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, rowStr, ',');
        std::getline(ss, colStr, ',');
        std::getline(ss, cls);

        if (id.empty() || rowStr.empty() || colStr.empty()) continue;

        try {
            int row = std::stoi(rowStr) - 1;
            int col = colStr[0] - 'A';

            if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) continue;
            if (plane[row][col].occupied) continue;

            plane[row][col].passengerID = id;
            plane[row][col].name        = name;
            plane[row][col].classType   = cls.empty() ? "Economy" : cls;
            plane[row][col].occupied    = true;

            loaded++;
        } catch (...) {
            // skip invalid line
        }
    }

    file.close();
    std::cout << "Loaded " << loaded << " passengers from CSV.\n";
    return true;
}