#include <iostream>
#include <string>
#include <iomanip>
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
    bool isActive;
};

Room rooms[Max_rooms];
Reservation reservations[Max_reservations];
int Reservation_count = 0;

// Function Declarations
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

// ── Person 3 ──────────────────────────────────────────────
void initializeRooms() {
    rooms[0] = {101, "Single", 50.0, true};
    rooms[1] = {102, "Single", 50.0, true};
    rooms[2] = {201, "Double", 80.0, true};
    rooms[3] = {202, "Double", 80.0, true};
    rooms[4] = {301, "Suite",  150.0, true};
}

// ── Person 4 ──────────────────────────────────────────────
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

// ── Person 5 ──────────────────────────────────────────────
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

            rooms[i].isAvailable = false;
            reservations[Reservation_count++] = newRes;

            bookingDone(newRes.guestname, rNum);
            return;
        }
    }
    roomNotFound();
}

// ── Person 6 ──────────────────────────────────────────────
void viewReservations() {
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

void cancelReservation() {
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

// ── Person 7 ──────────────────────────────────────────────
void showMenu() {
     cout << "\n====================================\n";
    cout << "\nWELCOME TO FAHMAK YA EXPENSIVE HOTEL\n";
    cout << "====================================\n";
    cout << "1. Show Rooms\n";
    cout << "2. Book Room\n";
    cout << "3. Show Reservations\n";
    cout << "4. Cancel Reservation\n";
    cout << "5. Exit\n";
    cout << "Choose: ";
}

void bookingDone(string name, int room) {
    cout << "Booked successfully\n";
    cout << "Name: " << name << endl;
    cout << "Room: " << room << endl;
}

void roomNotFound() {
    cout << "Room not found\n";
}

void roomBooked() {
    cout << "Room already booked\n";
}

void noReservations() {
    cout << "No reservations\n";
}

void cancelDone(int room) {
    cout << "Reservation canceled for room " << room << endl;
}

void bye() {
    cout << "Bye\n";
}

// ── main ──────────────────────────────────────────────────
int main() {
    initializeRooms();

    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: displayRooms();      break;
            case 2: bookRoom();          break;
            case 3: viewReservations();  break;
            case 4: cancelReservation(); break;
            case 5: bye();               break;
            default: cout << "Invalid choice! Enter 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}
