#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

class Flight {
    string FlightNumber;
    string origin;
    string destination;
    int availableSeats;
    float Fare;

public:
    Flight() {
        FlightNumber = "";
        origin = "";
        destination = "";
        availableSeats = 0;
        Fare = 0.0f;
    }

    Flight(string number, string from, string to, int seats, float fare) {
        FlightNumber = number;
        origin = from;
        destination = to;
        availableSeats = seats;
        Fare = fare;
    }

    string GetNumber() const {
        return FlightNumber;
    }

    string GetOrigin() const {
        return origin;
    }

    string GetDestination() const {
        return destination;
    }

    int GetSeats() const {
        return availableSeats;
    }

    float GetFare() const {
        return Fare;
    }

    void BookSeat() {
        if (availableSeats > 0) {
            availableSeats--;
            cout << "Seat Booked Successfully. *.*" << endl;
        }
        else {
            cout << "No Seats Available on this Flight. *.*" << endl;
        }
    }
};

class User {
private:
    string username;
    string password;
    string role;

public:
    User(string Uname, string pwd, string UserRole) {
    transform(Uname.begin(), Uname.end(), Uname.begin(), ::tolower);
    transform(pwd.begin(), pwd.end(), pwd.begin(), ::tolower);
    username = Uname;
    password = pwd;
    role = UserRole;
}


    string GetUser() const {
        return username;
    }

    string GetPass() const {
        return password;
    }

    string GetRole() const {
        return role;
    }
};


class Reservation {
private:
    vector<Flight> flight;
    vector<string> Booked;
    double Revenue;
    User current;

public:
    Reservation() : Revenue(0.0), current("default", "default", "default") {
    }

    void Add(Flight f) {
        flight.push_back(f);
    }

    void Search(string origin, string destination) {
        cout << "Available Flights:" << endl;
        for (const Flight& f : flight) {
            if (f.GetOrigin() == origin && f.GetDestination() == destination && f.GetSeats() > 0) {
                cout << "Flight Number : " << f.GetNumber() << endl;
                cout << "From : " << f.GetOrigin() << endl;
                cout << "To : " << f.GetDestination() << endl;
                cout << "Available Seats : " << f.GetSeats() << endl;
                cout << "Fare : " << fixed << setprecision(2) << f.GetFare() << endl;
                cout << endl;
            }
        }
    }

    void Book(string flightNumber) {
        for (Flight& f : flight) {
            if (f.GetNumber() == flightNumber) {
                f.BookSeat();
                Booked.push_back(flightNumber);
                Revenue = Revenue + f.GetFare();
                return;
            }
        }
        cout << "Invalid Flight Number. *.*" << endl;
    }

    void Cancel(string flightNumber) {
        auto it = find(Booked.begin(), Booked.end(), flightNumber);
        if (it != Booked.end()) {
            Booked.erase(it);
            cout << "Booking Canceled Successfully" << endl;
        }
        else {
            cout << "Invalid Flight Number or Booking Not Found" << endl;
        }
    }

    void SetUser(User user) {
        current = user;
    }

    bool Authenticate(string username, string password) {
    transform(username.begin(), username.end(), username.begin(), ::tolower);
    transform(password.begin(), password.end(), password.begin(), ::tolower);

    return (current.GetUser() == username && current.GetPass() == password);
}


    bool Permission(string Role) {
        return (current.GetRole() == Role);
    }

    void DisplayMenu() {
        cout << "--------------Flight Reservation System--------------" << endl;
        cout << "1. Search Flights" << endl;
        cout << "2. Book Flight" << endl;
        cout << "3. View Booked Flights" << endl;
        cout << "4. Cancel Booking" << endl;
        cout << "5. View Total Revenue" << endl;
        cout << "6. Exit" << endl;
        cout << endl;
    }

    void Interact() {
        int choice;
        while (true) {
            DisplayMenu();
            cout << "Enter Your Choice: ";
            cin >> choice;

            switch (choice) {

            case 1: {
                string origin, destination;
                cout << "Enter Origin: ";
                cin >> origin;
                cout << "Enter Destination: ";
                cin >> destination;
                Search(origin, destination);
                break;
            }

            case 2: {
                if (!Permission("employee")) {
                    cout << "You Don't Have Permission to Book a flight. *.*" << endl;
                    break;
                }
                string flightNumber;
                cout << "Enter Flight Number: ";
                cin >> flightNumber;
                Book(flightNumber);
                break;
            }

            case 3: {
                if (!Permission("employee")) {
                    cout << "You Don't Have Permission to View Booked flight. *.*" << endl;
                    break;
                }
                if (Booked.empty()) {
                    cout << "No Flights Booked" << endl;
                }
                else {
                    cout << "Booked Flights:" << endl;
                    for (const string& f : Booked) {
                        cout << "Flight Number: " << f << endl;
                    }
                }
                break;
            }

            case 4: {
                if (!Permission("employee")) {
                    cout << "You Don't Have Permission to Cancel a flight. *.*" << endl;
                    break;
                }
                if (Booked.empty()) {
                    cout << "No Flight's Booked" << endl;
                }
                else {
                    string flightNumber;
                    cout << "Enter Flight Number to Cancel Booking: ";
                    cin >> flightNumber;
                    Cancel(flightNumber);
                }
                break;
            }

            case 5: {
                if (!Permission("administrator")) {
                    cout << "You Don't Have Permission to View Total Revenue. *.*" << endl;
                    break;
                }
                cout << "Total Revenue: $ " << fixed << setprecision(2) << Revenue << endl;
                break;
            }

            case 6:
                cout << "Thank you for using the Flight Reservation System. Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;

            }
            cout << endl;
        }
    }
};

int main() {
    Reservation reservation;

    Flight f1("F001", "Delhi", "Bombay", 100, 500.0);
    Flight f2("F002", "Bombay", "Bangalore", 80, 400.0);
    Flight f3("F003", "Bangalore", "Delhi", 120, 450.0);

    reservation.Add(f1);
    reservation.Add(f2);
    reservation.Add(f3);

    User admin("admin", "admin", "administrator");
    User employee("employee", "emp", "employee");

    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    if (username == admin.GetUser() && password == admin.GetPass()) {
        reservation.SetUser(admin);
        reservation.Interact();
    }
    else if (username == employee.GetUser() && password == employee.GetPass()) {
        reservation.SetUser(employee);
        reservation.Interact();
    }
    else {
        cout << "Authentication failed. Exiting..." << endl;
    }

    return 0;
}
