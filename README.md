# DataStructArrayProj
# Flight Reservation & Seating Management System – Array-Based Version 

## Project Overview

This is the **Array-based component** of the Flight Reservation & Seating Management System assignment.

The system manages passenger bookings using a **fixed-size 2D array** to represent airplane seats (50 rows × 6 columns).  
No STL containers (`vector`, `list`, `map`, etc.) are used — all data structures are hand-implemented as required.

### Implemented Features (Core Requirements)

- Load initial passenger data from `flight_passenger_data.csv`
- Reservation (Insertion): Book a new passenger → assign first available seat
- Cancellation (Deletion): Cancel by PassengerID → free the seat
- Seat Lookup (Search): Find passenger by ID and display details
- Manifest & Seat Report: Print full seating chart + passenger list
- Basic error handling (invalid seat, passenger not found, etc.)

### Team Roles & Contribution (for video & workload matrix)

| Team Member   | Main Responsibilities                              | Implemented Functions / Files                  |
|---------------|----------------------------------------------------|------------------------------------------------|
| **Tatenda**   | Driver program, initialization, reservation, cancellation | `main.cpp`, `initPlane()`, `reserveSeat()`, `cancelBooking()` |
| **Xuan Min**  | Seat report, manifest, lookup/search               | `printSeatingChart()`, `printPassengerManifest()`, `searchPassengerID()` |
