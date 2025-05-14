#include <bits/stdc++.h>
using namespace std;

bool login(string user, string pass) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == user && p == pass) return true;
    }
    return false;
}

void registerUser(string user, string pass) {
    ofstream file("users.txt", ios::app);
    file << user << " " << pass << endl;
    cout << "Registration successful!\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter option: ";
    cin >> choice;

    string user, pass;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if (choice == 1) registerUser(user, pass);
    else if (choice == 2) {
        if (login(user, pass)) cout << "Login Successful!\n";
        else cout << "Invalid credentials.\n";
    }
}