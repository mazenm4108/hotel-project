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
