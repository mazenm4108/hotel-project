#pragma once
#include <iostream>
#include <iomanip>
#include "structures.h"
using namespace std;

void initializeRooms() {
    rooms[0] = {101, "Single", 50.0, true};
    rooms[1] = {102, "Single", 50.0, true};
    rooms[2] = {201, "Double", 80.0, true};
    rooms[3] = {202, "Double", 80.0, true};
    rooms[4] = {301, "Suite",  150.0, true};
}

void displayRooms() {
    cout << "\nRoom\tType\t\tPrice\tStatus\n";
    cout << "--------------------------------------\n";
    for (int i = 0; i < Max_rooms; i++) {
        cout << rooms[i].room_number << "\t";
        cout << rooms[i].room_type << "\t\t";
        cout << "$" << rooms[i].room_price << "\t";
        if (rooms[i].isAvailable)
            cout << "Available\n";
        else
            cout << "Booked\n";
    }
}
