#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Class illustrating OOP principles (Encapsulation)
class BankAccount {
private:
    string accountHolder;
    int accountType; // 1 for Savings, 2 for Current
    double balance;

public:
    // Function to create a new account and write to file
    void createAccount() {
        cout << "\n=========================================" << endl;
        cout << "         CREATE NEW BANK ACCOUNT         " << endl;
        cout << "=========================================" << endl;
        
        cout << "Enter Account Holder Full Name: ";
        cin.ignore();
        getline(cin, accountHolder);
        
        cout << "Select Account Type (1 for Savings, 2 for Current): ";
        cin >> accountType;
        
        cout << "Enter Initial Deposit Amount ($): ";
        cin >> balance;

        // File Handling: Saving transaction data permanently
        ofstream outFile("bank_database.txt", ios::app);
        if (outFile.is_open()) {
            outFile << accountHolder << "," << accountType << "," << balance << "\n";
            outFile.close();
            cout << "\n🎉 Account successfully registered and saved!" << endl;
        } else {
            cout << "\n❌ Error: Unable to open database file." << endl;
        }
    }

    // Function to read all records from the text file
    void displayAllAccounts() {
        ifstream inFile("bank_database.txt");
        if (!inFile) {
            cout << "\n❌ No records found. Please create an account first." << endl;
            return;
        }

        cout << "\n==================================================" << endl;
        cout << "               ALL REGISTERED ACCOUNTS            " << endl;
        cout << "==================================================" << endl;
        cout << left << setw(25) << "Account Holder" << setw(15) << "Type" << setw(10) << "Balance" << endl;
        cout << "--------------------------------------------------" << endl;

        string name, typeStr, balStr;
        // Reading comma-separated values from the file
        while (getline(inFile, name, Kishor_Delimiter = ',') && 
               getline(inFile, typeStr, ',') && 
               getline(inFile, balStr, '\n')) {
            
            string typeDisplay = (typeStr == "1") ? "Savings" : "Current";
            cout << left << setw(25) << name 
                 << setw(15) << typeDisplay 
                 << setw(10) << "$" + balStr << endl;
        }
        inFile.close();
        cout << "--------------------------------------------------" << endl;
    }
};

int main() {
    // Styling the console (Light Gray background, Black text or standard dark setup)
    system("Color 0F");

    BankAccount accountObj;
    int userChoice;

    // Execution loop for the desktop system menu
    do {
        cout << "\n=========================================" << endl;
        cout << "        ATM & BANK MANAGEMENT SYSTEM      " << endl;
        cout << "=========================================" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. View All Registered Accounts" << endl;
        cout << "3. Exit System" << endl;
        cout << "--------------------------------=========" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> userChoice;

        switch (userChoice) {
            case 1: 
                accountObj.createAccount(); 
                break;
            case 2: 
                accountObj.displayAllAccounts(); 
                break;
            case 3: 
                cout << "\nThank you for using the Banking Automation System. Terminating software..." << endl; 
                break;
            default: 
                cout << "\n❌ Invalid option selected. Please retry." << endl;
        }
    } while (userChoice != 3);

    return 0;
}
