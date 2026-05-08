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
