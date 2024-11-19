//Yahya Mohamed DCS-02-8487/2024
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal = 0) : accountNumber(accNum), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Kshs " << amount << ". New balance: Kshs " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Kshs " << amount << ". New balance: Kshs " << balance << endl;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    void checkBalance() const {
        cout << "Current balance: Kshs " << balance << endl;
    }
};

class ATM {
public:
    void start(Account &account) {
        int choice;
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            if (choice == 1) {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
            } else if (choice == 2) {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
            } else if (choice == 3) {
                account.checkBalance();
            } else if (choice == 4) {
                cout << "Thank you for using the ATM.\n";
            } else {
                cout << "Invalid option.\n";
            }

        } while (choice != 4);
    }
};

int main() {
    Account myAccount("10555", 100000.0); 
    ATM atm;
    atm.start(myAccount); 
    return 0; 
}
