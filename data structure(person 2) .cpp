#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const int Max_rooms= 5;
const int Max_reservations= 100;

struct Room{
    int room_number;
    string room_type;
    double room_price;
    bool isAvailable;

};

struct Reservation{
string guestname;
int room_number;
string check_IN_date;
string check_OUT_date;
bool isActive;  //el mafrood de htfyd person 6 fe 7aga fa ento adra//

};

Room rooms[Max_rooms];
Reservation reservations [Max_reservations];
int Reservation_count=0;

void initializeRooms();
void showMenu();
void bookingDone(string name, int room);
void roomNotFound();
void roomBooked();
void noReservations();
void cancelDone(int room);
void bye();
void displayRooms();
void bookRoom();
void viewReservations();
void cancelReservation();
