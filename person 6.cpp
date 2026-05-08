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
