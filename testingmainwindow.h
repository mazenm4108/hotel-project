#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include "structures.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void refreshRooms();
    void bookRoom();
    void refreshReservations();
    void cancelReservation();
    void checkoutRoom();

private:
    // Tab 1 - Rooms
    QTableWidget *roomsTable;

    // Tab 2 - Book
    QLineEdit *guestNameInput;
    QComboBox *roomNumberInput; //change number 1 hna
    QSpinBox  *nightsInput;
    QLabel    *bookStatusLabel;

    // Tab 3 - Reservations
    QListWidget *reservationsList;

    // Tab 4 - Cancel / Checkout
   QComboBox  *cancelRoomInput;  //change 2 hna (el changes kolah mn Qspinbox to Qcombobox 
    QLabel    *cancelStatusLabel;
    QComboBox  *checkoutRoomInput; //change 3 hna
    QLabel    *checkoutStatusLabel;

    void setupUI();
};
