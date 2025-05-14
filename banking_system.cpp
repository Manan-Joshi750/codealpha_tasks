#include <bits/stdc++.h>
using namespace std;

class Account {
    string name;
    int accNo;
    double balance;

public:
    Account(string n, int a, double b) : name(n), accNo(a), balance(b) {}

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited ₹" << amt << ". New Balance : ₹" << balance << endl;
    }

    void withdraw(double amt) {
        if (amt > balance) cout << "Insufficient funds.\n";
        else {
            balance -= amt;
            cout << "Withdrawn ₹" << amt << ". Remaining Balance : ₹" << balance << endl;
        }
    }

    void display() {
        cout << "Name : " << name << "\nAccount No : " << accNo << "\nBalance : ₹" << balance << endl;
    }
};

int main() {
    Account user("Manan Joshi", 123456, 1000);

    int ch;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nChoose : ";
        cin >> ch;

        if (ch == 1) {
            double amt; cout << "Amount : "; cin >> amt;
            user.deposit(amt);
        } else if (ch == 2) {
            double amt; cout << "Amount : "; cin >> amt;
            user.withdraw(amt);
        } else if (ch == 3) user.display();

    } while (ch != 4);
}