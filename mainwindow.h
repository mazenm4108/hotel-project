#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QSpinBox>
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
    QSpinBox  *roomNumberInput;
    QSpinBox  *nightsInput;
    QLabel    *bookStatusLabel;

    // Tab 3 - Reservations
    QListWidget *reservationsList;

    // Tab 4 - Cancel / Checkout
    QSpinBox  *cancelRoomInput;
    QLabel    *cancelStatusLabel;
    QSpinBox  *checkoutRoomInput;
    QLabel    *checkoutStatusLabel;

    void setupUI();
};
