#include <bits/stdc++.h>
using namespace std;

struct Flight {
    string flightNumber;
    string destination;
    string time;
};

struct Passenger {
    int id;
    string name;
    string flightNumber;
    string seatNumber;
    string bookingTime;
};

class AirlineSystem {
private:
    vector<Passenger> bookings;
    vector<Flight> flights;
    int nextId;

public:
    AirlineSystem() {
        nextId = 1;

        // Initialize some flights
        flights.push_back({"AA101", "New York", "10:00 AM"});
        flights.push_back({"BA202", "London", "12:00 PM"});
        flights.push_back({"CA303", "Tokyo", "6:00 PM"});
    }

    string getCurrentTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0'; // Remove newline
        return string(dt);
    }

    void showFlightInfo() {
        cout << "\n--- Available Flights ---" << endl;
        cout << "Flight No | Destination | Time" << endl;
        for (const auto& f : flights) {
            cout << f.flightNumber << "     | "
                 << f.destination << "    | "
                 << f.time << endl;
        }
    }

    void bookTicket() {
        Passenger p;
        p.id = nextId++;

        cin.ignore();
        cout << "\nEnter passenger name: ";
        getline(cin, p.name);

        showFlightInfo();
        cout << "Enter flight number from the list above: ";
        getline(cin, p.flightNumber);

        // Check if flight exists
        bool flightFound = false;
        for (const auto& f : flights) {
            if (f.flightNumber == p.flightNumber) {
                flightFound = true;
                break;
            }
        }

        if (!flightFound) {
            cout << "Invalid flight number. Booking cancelled.\n";
            return;
        }

        cout << "Enter seat number: ";
        getline(cin, p.seatNumber);

        // Check if seat is already booked
        for (const auto& b : bookings) {
            if (b.flightNumber == p.flightNumber && b.seatNumber == p.seatNumber) {
                cout << "Seat already taken on this flight. Booking cancelled.\n";
                return;
            }
        }

        p.bookingTime = getCurrentTime();
        bookings.push_back(p);

        cout << "\nTicket booked successfully!" << endl;
        cout << "Booking ID: " << p.id << endl;
        cout << "Booking Time: " << p.bookingTime << endl;
    }

    void viewBookings() {
        if (bookings.empty()) {
            cout << "\nNo bookings found.\n";
            return;
        }

        cout << "\n--- All Bookings ---" << endl;
        for (const auto& p : bookings) {
            cout << "ID: " << p.id
                 << " | Name: " << p.name
                 << " | Flight: " << p.flightNumber
                 << " | Seat: " << p.seatNumber
                 << " | Booked At: " << p.bookingTime << endl;
        }
    }

    void cancelTicket() {
        int id;
        cout << "\nEnter booking ID to cancel: ";
        cin >> id;

        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->id == id) {
                cout << "Cancelling ticket for " << it->name << " on flight " << it->flightNumber << endl;
                bookings.erase(it);
                cout << "Ticket canceled.\n";
                return;
            }
        }

        cout << "Booking ID not found.\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n===== Airline Management System =====" << endl;
            cout << "1. Book Ticket" << endl;
            cout << "2. View Bookings" << endl;
            cout << "3. Cancel Ticket" << endl;
            cout << "4. Show Flight Info" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: bookTicket(); break;
                case 2: viewBookings(); break;
                case 3: cancelTicket(); break;
                case 4: showFlightInfo(); break;
                case 5: cout << "Exiting system. Goodbye!\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    AirlineSystem system;
    system.menu();
    return 0;
}
