#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    float balance;

public:
    // Constructor to initialize account
    BankAccount(string accNum, float initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Display current balance
    void getBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    // Create an account
    BankAccount acc1("ACC12345", 1000);

    acc1.deposit(500);     // Add ₹500
    acc1.withdraw(200);    // Withdraw ₹200
    acc1.getBalance();     // Check balance

    return 0;
}
