
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Account {
    int accountNumber;
    string holderName;
    double balance;
};

int main() {
    vector<Account> accounts;
    int choice;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Account a;

            cout << "Enter Account Number: ";
            cin >> a.accountNumber;

            auto it = find_if(accounts.begin(), accounts.end(),
                [&](const Account &x) {
                    return x.accountNumber == a.accountNumber;
                });

            if (it != accounts.end()) {
                cout << "Account number already exists!\n";
                continue;
            }

            cin.ignore();
            cout << "Enter Account Holder Name: ";
            getline(cin, a.holderName);

            cout << "Enter Initial Balance: ";
            cin >> a.balance;

            if (a.balance < 0) {
                cout << "Balance cannot be negative!\n";
                continue;
            }

            accounts.push_back(a);
            cout << "Account created successfully!\n";
        }
        else if (choice >= 2 && choice <= 4) {
            int number;

            cout << "Enter Account Number: ";
            cin >> number;

            auto it = find_if(accounts.begin(), accounts.end(),
                [&](const Account &x) {
                    return x.accountNumber == number;
                });

            if (it == accounts.end()) {
                cout << "Account not found!\n";
                continue;
            }

            if (choice == 2) {
                double amount;
                cout << "Enter deposit amount: ";
                cin >> amount;

                if (amount > 0) {
                    it->balance += amount;
                    cout << "Deposit successful!\n";
                } else {
                    cout << "Enter a valid amount!\n";
                }
            }
            else if (choice == 3) {
                double amount;
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount <= 0) {
                    cout << "Enter a valid amount!\n";
                } else if (amount > it->balance) {
                    cout << "Insufficient balance!\n";
                } else {
                    it->balance -= amount;
                    cout << "Withdrawal successful!\n";
                }
            }
            else {
                cout << fixed << setprecision(2);
                cout << "Account Holder: " << it->holderName << "\n";
                cout << "Current Balance: Rs. "
                     << it->balance << "\n";
            }
        }
        else if (choice == 5) {
            cout << fixed << setprecision(2);

            for (const Account &a : accounts) {
                cout << "\nAccount Number: " << a.accountNumber
                     << "\nHolder: " << a.holderName
                     << "\nBalance: Rs. " << a.balance << "\n";
            }

            if (accounts.empty())
                cout << "No accounts available.\n";
        }
        else if (choice == 6) {
            cout << "Thank you for using the bank system!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
