void displayRooms() {
    cout << "\nRoom\tType\t\tPrice\tStatus\n";
    cout << "--------------------------------------\n";

    // 2. Loop through all rooms
    for (int i = 0; i < Max_rooms; i++) {
        cout << rooms[i].room_number << "\t";
        cout << rooms[i].room_type << "\t\t";
        cout << "$" << rooms[i].room_price << "\t";
        
        if (rooms[i].isAvailable) {
            cout << "Available\n";
        } else {
            cout << "Booked\n";
        }
    }
}
