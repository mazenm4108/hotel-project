#pragma once
#include <iostream>
#include <iomanip>
#include "structures.h"
#include "menu.h"
using namespace std;

void printReceipt(string name, int room, int nights, double total) {
    cout << "\n------- BOOKING RECEIPT -------\n";
    cout << "Guest Name   : " << name   << "\n";
    cout << "Room Number  : " << room   << "\n";
    cout << "Nights       : " << nights << "\n";
    cout << "Total Price  : $" << fixed << setprecision(2) << total << "\n";
    cout << "-------------------------------\n";
}

void bookRoom() {
    int rNum;
    cout << "\nEnter Room Number to book: ";
    cin >> rNum;

    for (int i = 0; i < Max_rooms; i++) {
        if (rooms[i].room_number == rNum) {
            if (!rooms[i].isAvailable) {
                roomBooked();
                return;
            }
            Reservation newRes;
            newRes.room_number = rNum;
            newRes.isActive = true;

            cout << "Enter Guest Name: ";
            cin.ignore();
            getline(cin, newRes.guestname);

            cout << "Enter Number of Nights: ";
            int nights;
            cin >> nights;

            newRes.nights = nights;
            rooms[i].isAvailable = false;
            reservations[Reservation_count++] = newRes;

            double total = rooms[i].room_price * nights;
            bookingDone(newRes.guestname, rNum);
            return;
        }
    }
    roomNotFound();
}
