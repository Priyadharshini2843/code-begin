#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Base class
class Account {
private:
    string customer_name;
    int account_number;
protected:
    double balance;
public:
    Account(string name, int acc_num, double bal)
        : customer_name(name), account_number(acc_num), balance(bal) {}

    virtual void credit(double amount) = 0;
    virtual void debit(double amount) {}
    virtual void display() const {
        cout << "Name: " << customer_name
             << "\nAccount Number: " << account_number
             << "\nBalance: ₹" << balance << endl;
    }

    virtual ~Account() {}
};

// Derived class - Savings Account
class SavingsAccount : public Account {
public:
    SavingsAccount(string name, int acc_num, double bal)
        : Account(name, acc_num, bal) {}

    void credit(double amount) override {
        balance += amount;
        cout << "₹" << amount << " credited to Savings Account.\n";
    }

    void debit(double amount) override {
        try {
            if (amount > 50000)
                throw overflow_error("Amount exceeds ₹50,000 limit.");
            if (amount > balance)
                throw underflow_error("Insufficient balance.");

            balance -= amount;
            cout << "₹" << amount << " debited from Savings Account.\n";
        } catch (const overflow_error& e) {
            cout << "Debit Error: " << e.what() << endl;
        } catch (const underflow_error& e) {
            cout << "Debit Error: " << e.what() << endl;
        }
    }
};

// Derived class - Current Account
class CurrentAccount : public Account {
public:
    CurrentAccount(string name, int acc_num, double bal)
        : Account(name, acc_num, bal) {}

    void credit(double amount) override {
        balance += amount;
        cout << "₹" << amount << " credited to Current Account.\n";
    }
};

int main() {
    SavingsAccount sa("Alice", 1001, 30000);
    CurrentAccount ca("Bob", 1002, 50000);

    cout << "\n--- Savings Account ---\n";
    sa.display();
    sa.credit(10000);
    sa.debit(60000); // triggers overflow_error
    sa.debit(45000); // triggers underflow_error
    sa.debit(20000); // success
    sa.display();

    cout << "\n--- Current Account ---\n";
    ca.display();
    ca.credit(5000);
    ca.display();

    return 0;
}