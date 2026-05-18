#include "mainwindow.h"
#include "rooms.h"
#include "booking.h"
#include "reservations.h"

#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initializeRooms();
    setupUI();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    setWindowTitle("Fahmak Ya Expensive Hotel");
    resize(800, 550);

    // ── Gold/Brown Luxury Theme ───────────────────────────
    this->setStyleSheet(R"(
QMainWindow {
            background-color: #1B2E45;
        }
        QWidget {
            background-color: #1B2E45;
            color: #F0D9A0;
            font-family: Georgia, serif;
            font-size: 14px;
        }
        QTabWidget::pane {
            border: 1px solid #6B4C0A;
            background-color: #243B55;
        }
        QTabBar::tab {
            background-color: #2E4A6A;
            color: #F0D9A0;
            padding: 10px 24px;
            border: 1px solid #6B4C0A;
            border-bottom: none;
            font-weight: bold;
            font-size: 13px;
        }
        QTabBar::tab:selected {
            background-color: #8B6914;
            color: #F0D9A0;
        }
        QTabBar::tab:hover:!selected {
            background-color: #3A5F82;
        }
        QPushButton {
            background-color: #8B6914;
            color: #F0D9A0;
            border: none;
            border-radius: 14px;
            padding: 12px 28px;
            font-weight: bold;
            font-size: 14px;
            min-height: 20px;
        }
        QPushButton:hover {
            background-color: #A07830;
        }
        QPushButton:pressed {
            background-color: #6B4C0A;
        }
        QLineEdit, QSpinBox {
            background-color: #243B55;
            color: #F0D9A0;
            border: 1px solid #6B4C0A;
            border-radius: 8px;
            padding: 7px 10px;
            font-size: 14px;
            min-height: 20px;
        }
        QLineEdit:focus, QSpinBox:focus {
            border: 2px solid #8B6914;
        }
        QTableWidget {
            background-color: #243B55;
            color: #F0D9A0;
            gridline-color: #2E4A6A;
            border: 1px solid #6B4C0A;
            font-size: 14px;
        }
        QTableWidget::item {
            padding: 6px;
        }
        QTableWidget::item:selected {
        background-color: #243B55;
        color: #F0D9A0;
        }
        QHeaderView::section {
            background-color: #2E4A6A;
            color: #F0D9A0;
            font-weight: bold;
            border: 1px solid #6B4C0A;
            padding: 8px;
            font-size: 14px;
        }
        QListWidget {
            background-color: #243B55;
            color: #F0D9A0;
            border: 1px solid #6B4C0A;
            border-radius: 6px;
            font-size: 14px;
        }
        QListWidget::item {
            padding: 8px;
            border-bottom: 1px solid #2E4A6A;
        }
        QListWidget::item:selected {
            background-color: #8B6914;
            color: #F0D9A0;
        }
        QListWidget::item:hover {
            background-color: #3A5F82;
        }
        QLabel {
            color: #F0D9A0;
            font-size: 14px;
        }
        QScrollBar:vertical {
            background: #1B2E45;
            width: 10px;
        }
        QScrollBar::handle:vertical {
            background: #8B6914;
            border-radius: 5px;
        }
    )");


    QTabWidget *tabs = new QTabWidget(this);
    setCentralWidget(tabs);

    // ── Tab 0: Welcome ────────────────────────────────────
    QWidget *tab0 = new QWidget();
    QVBoxLayout *lay0 = new QVBoxLayout(tab0);
    lay0->setAlignment(Qt::AlignCenter);

    QLabel *hotelName = new QLabel("FAHMAK YA EXPENSIVE \n HOTEL", tab0);
    hotelName->setAlignment(Qt::AlignCenter);
    hotelName->setStyleSheet("font-size: 28px; font-weight: bold; color: #F0D9A0; letter-spacing: 4px;");

    QLabel *tagline = new QLabel("~ 2w3a 7ad Ykon fahem 7aga ~", tab0);
    tagline->setAlignment(Qt::AlignCenter);
    tagline->setStyleSheet("font-size: 19px; color: #8B6914; font-style: italic;");

    QLabel *divider = new QLabel("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", tab0);
    divider->setAlignment(Qt::AlignCenter);
    divider->setStyleSheet("color: #6B4C0A; font-size: 14px;");

    lay0->addStretch();
    lay0->addWidget(hotelName);
    lay0->addSpacing(10);
    lay0->addWidget(divider);
    lay0->addSpacing(10);
    lay0->addWidget(tagline);
    lay0->addStretch();

    tabs->addTab(tab0, "Home");

    // ── Tab 1: Rooms ─────────────────────────────────────
    QWidget *tab1 = new QWidget();
    QVBoxLayout *lay1 = new QVBoxLayout(tab1);

    roomsTable = new QTableWidget(Max_rooms, 4, tab1);
    roomsTable->setHorizontalHeaderLabels({"Room", "Type", "Price", "Status"});
    roomsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    roomsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QPushButton *refreshBtn = new QPushButton("Refresh", tab1);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refreshRooms);

    lay1->addWidget(roomsTable);
    lay1->addWidget(refreshBtn);
    tabs->addTab(tab1, "Rooms");
    refreshRooms();

    // ── Tab 2: Book Room ──────────────────────────────────
    QWidget *tab2 = new QWidget();
    QVBoxLayout *lay2 = new QVBoxLayout(tab2);
    QFormLayout *form = new QFormLayout();

   roomNumberInput = new QComboBox(tab2);
for (int i = 0; i < Max_rooms; i++)
    roomNumberInput->addItem(QString::number(rooms[i].room_number));

    guestNameInput = new QLineEdit(tab2);
    guestNameInput->setPlaceholderText("Enter guest name");

    nightsInput = new QSpinBox(tab2);
    nightsInput->setRange(1, 365);
    nightsInput->setValue(1);

    form->addRow("Room Number:", roomNumberInput);
    form->addRow("Guest Name:", guestNameInput);
    form->addRow("Nights:", nightsInput);

    QPushButton *bookBtn = new QPushButton("Book Room", tab2);
    connect(bookBtn, &QPushButton::clicked, this, &MainWindow::bookRoom);

    bookStatusLabel = new QLabel("", tab2);
    bookStatusLabel->setAlignment(Qt::AlignCenter);

    lay2->addLayout(form);
    lay2->addWidget(bookBtn);
    lay2->addWidget(bookStatusLabel);
    lay2->addStretch();
    tabs->addTab(tab2, "Book Room");

    // ── Tab 3: Reservations ───────────────────────────────
    QWidget *tab3 = new QWidget();
    QVBoxLayout *lay3 = new QVBoxLayout(tab3);

    reservationsList = new QListWidget(tab3);

    QPushButton *refreshResBtn = new QPushButton("Refresh", tab3);
    connect(refreshResBtn, &QPushButton::clicked, this, &MainWindow::refreshReservations);

    lay3->addWidget(reservationsList);
    lay3->addWidget(refreshResBtn);
    tabs->addTab(tab3, "Reservations");

    // ── Tab 4: Cancel / Checkout ──────────────────────────
    QWidget *tab4 = new QWidget();
    QVBoxLayout *lay4 = new QVBoxLayout(tab4);

    // Cancel section
    QLabel *cancelTitle = new QLabel("<b>Cancel Reservation</b>", tab4);
   cancelRoomInput = new QComboBox(tab4);
for (int i = 0; i < Max_rooms; i++)
    cancelRoomInput->addItem(QString::number(rooms[i].room_number));

    QPushButton *cancelBtn = new QPushButton("Cancel Reservation", tab4);
    connect(cancelBtn, &QPushButton::clicked, this, &MainWindow::cancelReservation);

    cancelStatusLabel = new QLabel("", tab4);
    cancelStatusLabel->setAlignment(Qt::AlignCenter);

    // Checkout section
    QLabel *checkoutTitle = new QLabel("<b>Checkout & Print Receipt</b>", tab4);
    checkoutRoomInput = new QComboBox(tab4);
for (int i = 0; i < Max_rooms; i++)
    checkoutRoomInput->addItem(QString::number(rooms[i].room_number));

    QPushButton *checkoutBtn = new QPushButton("Checkout", tab4);
    connect(checkoutBtn, &QPushButton::clicked, this, &MainWindow::checkoutRoom);

    checkoutStatusLabel = new QLabel("", tab4);
    checkoutStatusLabel->setAlignment(Qt::AlignCenter);

    lay4->addWidget(cancelTitle);
    lay4->addWidget(new QLabel("Room Number:"));
    lay4->addWidget(cancelRoomInput);
    lay4->addWidget(cancelBtn);
    lay4->addWidget(cancelStatusLabel);
    lay4->addSpacing(20);
    lay4->addWidget(checkoutTitle);
    lay4->addWidget(new QLabel("Room Number:"));
    lay4->addWidget(checkoutRoomInput);
    lay4->addWidget(checkoutBtn);
    lay4->addWidget(checkoutStatusLabel);
    lay4->addStretch();
    tabs->addTab(tab4, "Cancel / Checkout");
}

// ── Slots ─────────────────────────────────────────────────
void MainWindow::refreshRooms() {
    roomsTable->verticalHeader()->setDefaultSectionSize(40);
    roomsTable->verticalHeader()->setVisible(false);
    for (int i = 0; i < Max_rooms; i++) {
        auto *roomItem   = new QTableWidgetItem(QString::number(rooms[i].room_number));
        auto *typeItem   = new QTableWidgetItem(QString::fromStdString(rooms[i].room_type));
        auto *priceItem  = new QTableWidgetItem("$" + QString::number(rooms[i].room_price, 'f', 2));
        auto *statusItem = new QTableWidgetItem(rooms[i].isAvailable ? "Available" : "Booked");

        roomItem->setTextAlignment(Qt::AlignCenter);
        typeItem->setTextAlignment(Qt::AlignCenter);
        priceItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setTextAlignment(Qt::AlignCenter);

        if (rooms[i].isAvailable)
            statusItem->setForeground(QColor("#4CAF50"));
        else
            statusItem->setForeground(QColor("#E53935"));

        roomsTable->setItem(i, 0, roomItem);
        roomsTable->setItem(i, 1, typeItem);
        roomsTable->setItem(i, 2, priceItem);
        roomsTable->setItem(i, 3, statusItem);
    }
}

void MainWindow::bookRoom() {
    int rNum = roomNumberInput->currentText().toInt();
    QString name = guestNameInput->text().trimmed();
    int nights = nightsInput->value();

    if (name.isEmpty()) {
        bookStatusLabel->setStyleSheet("color: red;");
        bookStatusLabel->setText("Please enter a guest name.");
        return;
    }

    for (int i = 0; i < Max_rooms; i++) {
        if (rooms[i].room_number == rNum) {
            if (!rooms[i].isAvailable) {
                bookStatusLabel->setStyleSheet("color: red;");
                bookStatusLabel->setText("Room is already booked!");
                return;
            }
            Reservation newRes;
            newRes.room_number = rNum;
            newRes.isActive = true;
            newRes.guestname = name.toStdString();
            newRes.nights = nights;

            rooms[i].isAvailable = false;
            reservations[Reservation_count++] = newRes;

            double total = rooms[i].room_price * nights;

            bookStatusLabel->setStyleSheet("color: green;");
            bookStatusLabel->setText("Booked successfully!");

            // Show receipt in a message box
            QString receipt = QString(
                "------- BOOKING RECEIPT -------\n"
                "Guest Name  : %1\n"
                "Room Number : %2\n"
                "Nights      : %3\n"
                "Total Price : $%4\n"
                "-------------------------------"
            ).arg(name).arg(rNum).arg(nights).arg(total, 0, 'f', 2);
            QMessageBox::information(this, "Booking Receipt", receipt);

            guestNameInput->clear();
            refreshRooms();
            return;
        }
    }
    bookStatusLabel->setStyleSheet("color: red;");
    bookStatusLabel->setText("Room not found!");
}

void MainWindow::refreshReservations() {
    reservationsList->clear();
    bool found = false;
    for (int i = 0; i < Reservation_count; i++) {
        if (reservations[i].isActive) {
            QString entry = QString("Guest: %1  |  Room: %2  |  Nights: %3")
                .arg(QString::fromStdString(reservations[i].guestname))
                .arg(reservations[i].room_number)
                .arg(reservations[i].nights);
            reservationsList->addItem(entry);
            found = true;
        }
    }
    if (!found)
        reservationsList->addItem("No active reservations.");
}

void MainWindow::cancelReservation() {
    int rNum = cancelRoomInput->currentText().toInt();
    for (int i = 0; i < Reservation_count; i++) {
        if (reservations[i].room_number == rNum && reservations[i].isActive) {
            reservations[i].isActive = false;
            for (int j = 0; j < Max_rooms; j++) {
                if (rooms[j].room_number == rNum) {
                    rooms[j].isAvailable = true;
                    break;
                }
            }
            cancelStatusLabel->setStyleSheet("color: green;");
            cancelStatusLabel->setText("Reservation cancelled!");
            refreshRooms();
            return;
        }
    }
    cancelStatusLabel->setStyleSheet("color: red;");
    cancelStatusLabel->setText("No active reservation for this room.");
}

void MainWindow::checkoutRoom() {
   int rNum = checkoutRoomInput->currentText().toInt();
    for (int i = 0; i < Reservation_count; i++) {
        if (reservations[i].room_number == rNum && reservations[i].isActive) {
            double price = 0;
            for (int j = 0; j < Max_rooms; j++) {
                if (rooms[j].room_number == rNum) {
                    price = rooms[j].room_price;
                    rooms[j].isAvailable = true;
                    break;
                }
            }
            reservations[i].isActive = false;
            double total = price * reservations[i].nights;

            QString receipt = QString(
                "------- BOOKING RECEIPT -------\n"
                "Guest Name  : %1\n"
                "Room Number : %2\n"
                "Nights      : %3\n"
                "Total Price : $%4\n"
                "-------------------------------"
            ).arg(QString::fromStdString(reservations[i].guestname))
             .arg(rNum)
             .arg(reservations[i].nights)
             .arg(total, 0, 'f', 2);

            QMessageBox::information(this, "Checkout Receipt", receipt);
            checkoutStatusLabel->setStyleSheet("color: green;");
            checkoutStatusLabel->setText("Checkout successful!");
            refreshRooms();
            return;
        }
    }
    checkoutStatusLabel->setStyleSheet("color: red;");
    checkoutStatusLabel->setText("No active reservation for this room.");
}
