#include <fstream>
#include <cstdlib>
#include<bits/stdc++.h>
int cnt =0;
using namespace std;
class Acc
{    public:
  int accountNumber;
    string accountHolderName;
    double balance;
  
    Acc(){ accountNumber = 0;
        accountHolderName = " ";
        balance = 0;
        
    }
    Acc(int n, string s,double b)
    {
    accountNumber = n;
    accountHolderName = s;
    balance = b;
        
    }
};
    

class BankAccount {
private:
    vector<Acc> vec;
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount()
    {
        ofstream file;
        file.open("bank_account.txt");
        file<<"Acc no"<<"  ";
        file<<"Acc name "<<" ";
        file<<" balance  "<<endl;
        file.close();
    }
    
    void createAccount();
    void displayAccountDetails();
    void deposit();
    void withdraw();
    void updateFile();
    
};

void BankAccount::createAccount() {
    cin.ignore();
    int i =0;
    
    cout << "Enter Account Holder Name: ";
    // getline(cin, accountHolderName);
    cin>>accountHolderName;
    while(i< accountHolderName.size())
    {   
        if(accountHolderName[i]>='a'&& accountHolderName[i]<='z'|| accountHolderName[i]>='A'&& accountHolderName[i]<='Z'|| accountHolderName[i]<=' ')
        i++;
        else 
        {
            cout<<"Invalid Name...Enter Again...\n";
            // cout << "Enter Account Holder Name: ";
            // getline(cin, accountHolderName);
            createAccount();
            break;
        }
    }
    if(i== accountHolderName.size())
    {
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Initial Balance: ";
    cin >> balance;
    }
    vec.push_back(Acc(accountNumber,accountHolderName,balance));
    updateFile();
    cnt++;
}

void BankAccount::displayAccountDetails() {
    for(int i=0;i<cnt ;i++)
    {
    cout << "Account Number: " << vec[i].accountNumber << endl;
    cout << "Account Holder Name: " << vec[i].accountHolderName << endl;
    cout << "Balance: $" << vec[i].balance << endl;
    }
}

void BankAccount::deposit() {
    double amount;
    int accno;
    bool check = false;
    cout << "Enter account number"<<endl;
    cin >> accno;
   
    for(int i=0;i<cnt ;i++)
    {
        
    if(accno == vec[i].accountNumber)
    {
    cout << "Enter Deposit Amount: $";
    cin >> amount;

    if (amount > 0) {
        vec[i].balance += amount;
        cout << "Deposit Successful.\n";
        updateFile();
    } else {
        cout << "Invalid Amount for Deposit.\n";
    }
    
    check = true;
    break;
    }
    
    }
    if(check == false )
    {
        cout<<"Account not found";
    }
}

void BankAccount::withdraw() {
    double amount;
    int accno1;
    bool check = false;
    cout<<"Enter account number"<<endl;
    cin  >>accno1;
   
    for(int i=0;i< cnt ;i++)
    { 
    if( accno1 == vec[i].accountNumber)
    {
    cout << "Enter Withdrawal Amount: $";
    cin >> amount;
   
    if (amount > 0 && amount <= vec[i].balance) {
        vec[i].balance -= amount;
        cout << "Withdrawal Successful.\n";
        updateFile();
    } else {
        cout << "Invalid Amount for Withdrawal or Insufficient Balance.\n";
    }
    check = true;
    break;
    }
    
    
    }
     if(check == false )
    {
        cout<<"Account not found";
    }
}

void BankAccount::updateFile() {
    ofstream file("bank_account.txt", ios::app);

    if (!file) {
        cerr << "Error opening file.\n";
        exit(1);
    }

    file << accountNumber << "  " << accountHolderName << "  " << balance << endl;

    file.close();
}

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\nBank Account System\n";
        cout << "1. Create Account\n";
        cout << "2. Display Account Details\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                account.displayAccountDetails();
                break;
            case 3:
                account.deposit();
                break;
            case 4:
                account.withdraw();
                break;
            case 0:
                cout << "Exiting Program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}