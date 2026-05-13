#pragma once
#include <string>
using namespace std;

const int Max_rooms = 5;
const int Max_reservations = 100;

struct Room {
    int room_number;
    string room_type;
    double room_price;
    bool isAvailable;
};

struct Reservation {
    string guestname;
    int room_number;
    string check_IN_date;
    string check_OUT_date;
    int nights;
    bool isActive;
};

extern Room rooms[Max_rooms];
extern Reservation reservations[Max_reservations];
extern int Reservation_count;
