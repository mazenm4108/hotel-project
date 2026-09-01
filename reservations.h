#pragma once
#include <iostream>
#include <iomanip>
#include "structures.h"
#include "menu.h"
#include "booking.h"
using namespace std;

inline void viewReservations() {
    bool found = false;
    cout << "\n--- Active Reservations ---\n";
    for (int i = 0; i < Reservation_count; i++) {
        if (reservations[i].isActive) {
            cout << "Guest: " << reservations[i].guestname
                 << " | Room: " << reservations[i].room_number << "\n";
            found = true;
        }
    }
    if (!found)
        noReservations();
}

inline void cancelReservation() {
    int rNum;
    cout << "\nEnter Room Number to cancel: ";
    cin >> rNum;

    for (int i = 0; i < Reservation_count; i++) {
        if (reservations[i].room_number == rNum && reservations[i].isActive) {
            reservations[i].isActive = false;
            for (int j = 0; j < Max_rooms; j++) {
                if (rooms[j].room_number == rNum) {
                    rooms[j].isAvailable = true;
                    break;
                }
            }
            cancelDone(rNum);
            return;
        }
    }
    roomNotFound();
}

inline void checkoutAndReceipt() {
    int rNum;
    cout << "\nEnter Room Number to checkout: ";
    cin >> rNum;

    for (int i = 0; i < Reservation_count; i++) {
        if (reservations[i].room_number == rNum && reservations[i].isActive) {
            double price = 0;
            for (int j = 0; j < Max_rooms; j++) {
                if (rooms[j].room_number == rNum) {
                    price = rooms[j].room_price;
                    rooms[j].isAvailable = true;
                    break;
                }
            }
            reservations[i].isActive = false;
            double total = price * reservations[i].nights;
            printReceipt(reservations[i].guestname, rNum, reservations[i].nights, total);
            return;
        }
    }
    roomNotFound();
}
