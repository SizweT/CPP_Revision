#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class BankAccount {
private:
// Attributes of the class
    int accountNumber;
    string accountHolder;
    double balance;

public:
// Parameterized constructor
    BankAccount(int accNum, string accHolder, double initialBalance):accountNumber(accNum), accountHolder(accHolder), balance(0.0) {
        if (initialBalance < 0) {
            throw invalid_argument("Invalid opening balance.");
        }
        balance = initialBalance;
    }
// Setters
     bool setBalance(double newBalance){
        if (newBalance >= 0) {
            balance = newBalance;
            return true;
        }
        return false;
    }

    double deposit(double amount){
        if (amount > 0) {
            balance += amount;
            return amount;
        }
        return 0.0;
    }

    double withdraw(double amount){
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return amount;
        }
        return 0.0;
    }

    double getBalance() const{
        return balance;
    }

    int getAccountNumber() const{
        return accountNumber;
    }

    string getAccountHolder() const{
        return accountHolder;
    }

    void DisplayAccount() const{
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Opening Balance: R" << balance << endl;
        cout << endl; // Adding a line break for better readability

    }

    ~BankAccount() {
        cout << "\nAccount destroyed: " << accountHolder << endl;
    }


};

int main() {
        try {

        BankAccount account1(1001, "Sizwe", 5000.0);
        BankAccount account2(1002, "Nandi", 3000.0);

        account1.DisplayAccount();

        cout << "\nDeposit: R"
             << account1.deposit(1500.0) << endl;

        cout << "Withdrawal: R"
             << account1.withdraw(2000.0) << endl;

        cout << "Final Balance: R"
             << account1.getBalance() << endl;

        cout << "\n-------------------------\n";
        account2.DisplayAccount();

        cout << "\nDeposit: R"
             << account2.deposit(1000.0) << endl;

        cout << "Withdrawal: R"
             << account2.withdraw(500.0) << endl;

        cout << "Final Balance: R"
             << account2.getBalance() << endl;

    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }   

    return 0;
}