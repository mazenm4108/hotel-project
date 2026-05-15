#pragma once
#include <iostream>
#include "structures.h"
using namespace std;

inline void showMenu() {
    cout << "\n====================================\n";
    cout << "WELCOME TO FAHMAK YA EXPENSIVE HOTEL\n";
    cout << "====================================\n";
    cout << "1. Show Rooms\n";
    cout << "2. Book Room\n";
    cout << "3. Show Reservations\n";
    cout << "4. Cancel Reservation\n";
    cout << "5. Checkout & Print Receipt\n";
    cout << "6. Exit\n";
    cout << "Choose: ";
}

inline void bookingDone(string name, int room) {
    cout << "Booked successfully\n";
    cout << "Name: " << name << endl;
    cout << "Room: " << room << endl;
}

inline void roomNotFound() {
    cout << "Room not found\n";
}

inline void roomBooked() {
    cout << "Room already booked\n";
}

inline void noReservations() {
    cout << "No reservations\n";
}

inline void cancelDone(int room) {
    cout << "Reservation canceled for room " << room << endl;
}

inline void bye() {
    cout << "Bye\n";
}
