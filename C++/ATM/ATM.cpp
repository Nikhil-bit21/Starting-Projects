#include<iostream>
#include<math.h>
#include <map>
#include <algorithm>
using namespace std;

class BankAccount{
    private:

    string user;
    int pin;
    int balance;
    string AccountNumber;

    public:

    BankAccount() {
        user = "";
        pin = 0;
        balance = 0;
        AccountNumber = "";
    }

    BankAccount(string user , int pin , int balance , string accountNumber){
        this->user = move(user); // for transferring the ownership to another object
        transform(this->user.begin(), this->user.end(), this->user.begin(), ::toupper);
        this->pin  = pin;
        this->balance = balance;
        this->AccountNumber = move(accountNumber);
    }

    string getuser() const{
        return user;
    }

    int getPin() const{
        return pin;
    }

    int getBalance() const{
        return balance;
    }

    string getAccountNumber() const {
        return AccountNumber;
    }

    void setBalance(int value){
        balance = value;
    }

    void displayBalance() const{
        cout<<"Your balance is : $"<<balance<<endl;
    }

    void withdraw(int amount){
        if(amount<=balance){
            balance = balance - amount;
            cout<<"Please take your cash. *.*"<<endl;
            cout<<"Your remaining balance is : $"<<balance<<endl;
        }else{
            cout<<"Insufficient Balance. *.*"<<endl;
        }
    }

    void deposit(int amount){
        balance = balance + amount;
        cout<<"Your new balance is : $"<<balance<<endl;
    }

    void transfer(int amount , BankAccount& receiver){
        if(amount<=balance){
            balance = balance - amount;
            receiver.setBalance(receiver.getBalance() + amount);
            cout<<"Transaction Successful. *.*"<<endl;
            cout<<"Your remaining balance is : $"<<balance<<endl;
        }else{
            cout<<"Insufficient balance. *.*"<<endl;
        }
    }

    void changePin(int oldPin , int newPin){
        if(pin == oldPin){
            pin = newPin;
            cout<<"Pin Changed Successful. *.*"<<endl;
        }else{
            cout<<"Incorrect Pin"<<endl;
        }
    }

    void displayAccountData() const {
        cout << "Name: " << user << endl;
        cout << "Pin: " << pin << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Account Number: " << AccountNumber << endl;
    }

};

void DisplayMenu(){
    cout<<"Welcome! to Eren's Bank ATM. *.*"<<endl;
    cout<<" 1. Balance Inquiry" <<endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. Pin Change" << endl;
    cout << "6. Display User Data" << endl;
    cout << "7. Display All Users Data" << endl;
    cout << "8. Switch User" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter option: "<<endl;
    
}

int main(){

    map<string , BankAccount> Accounts;

    string username;
    string accountNumber;
    int pin;
    int option;

    Accounts["HARSHU"] = BankAccount("Harshu",1111,5000,"AC1001");
    Accounts["SAVITA"] = BankAccount("Savita",2222,10000,"AC1002");
    Accounts["TEJPAL"] = BankAccount("Tejpal",3333,15000,"AC1003");

    cout<<"Enter Username :"<<endl;
    cin>>username;
    transform(username.begin(), username.end(), username.begin(), ::toupper);

    cout << "Enter pin: "<<endl;
    cin >> pin;

    while(Accounts.find(username) == Accounts.end() || Accounts[username].getPin() != pin){
        cout << "Invalid username or pin. Please try again." << endl;
        cout << "Enter username: "<<endl;
        cin >> username;
        transform(username.begin(), username.end(), username.begin(), ::toupper);

        cout << "Enter pin: "<<endl;
        cin >> pin;
    }

    BankAccount& currentAccount = Accounts[username];

    do{
        DisplayMenu();
        cin >> option;

        switch(option){
            case 1:
                currentAccount.displayBalance();
                break;
            case 2:{
                int amount;
                cout << "Enter the amount to withdraw: $"<<endl;
                cin >> amount;
                currentAccount.withdraw(amount);
                break;
            }
            case 3:{
                int amount;
                cout << "Enter the amount to deposit: $"<<endl;
                cin >> amount;
                currentAccount.deposit(amount);
                break;
            }
            case 4:{
                string receiver;
                int amount;
                cout << "Enter the username of the receiver: "<<endl;
                cin >> receiver;
                transform(receiver.begin(), receiver.end(), receiver.begin(), ::toupper);

                while(Accounts.find(receiver) == Accounts.end()){
                    cout << "Invalid receiver username. Please try again." << endl;
                    cout << "Enter the username of the receiver: "<<endl;
                    cin >> receiver;
                    transform(receiver.begin(), receiver.end(), receiver.begin(), ::toupper);
                }

                cout << "Enter the amount to transfer: $"<<endl;
                cin >> amount;
                currentAccount.transfer(amount, Accounts[receiver]);
                break;
            }
            case 5:{
                int oldPin, newPin;
                cout << "Enter the old pin: "<<endl;
                cin >> oldPin;
                cout << "Enter the new pin: "<<endl;
                cin >> newPin;
                currentAccount.changePin(oldPin, newPin);
                break;
            }
            case 6:{
                currentAccount.displayAccountData();
                break;
            }
            case 7:{
                for(auto& account : Accounts){
                    cout << "-----------------------" << endl;
                    account.second.displayAccountData();
                    cout << "-----------------------" << endl;
                }
                break;
            }
            case 8:{
                cout << "Enter username: "<<endl;
                cin >> username;
                transform(username.begin(), username.end(), username.begin(), ::toupper);

                cout << "Enter pin: "<<endl;
                cin >> pin;

                while(Accounts.find(username) == Accounts.end() || Accounts[username].getPin() != pin){
                    cout << "Invalid username or pin. Please try again." << endl;
                    cout << "Enter username: "<<endl;
                    cin >> username;
                    transform(username.begin(), username.end(), username.begin(), ::toupper);

                    cout << "Enter pin: "<<endl;
                    cin >> pin;
                }

                currentAccount = Accounts[username];
                break;
            }
            case 9:{
                cout << "Thank you for using Eren's Bank ATM. Have a nice day!" << endl;
                break;
            }
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while(option != 9);

    return 0;
}