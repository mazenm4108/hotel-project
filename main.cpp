#include "structures.h"
#include "rooms.h"
#include "menu.h"
#include "booking.h"
#include "reservations.h"

// Global definitions (declared extern in structures.h)
Room rooms[Max_rooms];
Reservation reservations[Max_reservations];
int Reservation_count = 0;

int main() {
    initializeRooms();

    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: displayRooms();       break;
            case 2: bookRoom();           break;
            case 3: viewReservations();   break;
            case 4: cancelReservation();  break;
            case 5: checkoutAndReceipt(); break;
            case 6: bye();                break;
            default: cout << "Invalid choice! Enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
