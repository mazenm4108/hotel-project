#include <QApplication>
#include "mainwindow.h"
#include "structures.h"

// Global definitions
Room rooms[Max_rooms];
Reservation reservations[Max_reservations];
int Reservation_count = 0;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
