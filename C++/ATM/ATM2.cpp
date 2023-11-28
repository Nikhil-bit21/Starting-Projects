#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<ctime>

using namespace std;

class BankAccount{

    private:
    string user;
    int pin;
    int balance;
    int AccountNumber;
    vector<string> TransactionHistory;

    void AddtoHistory(const string& transaction , int amount){
        time_t now = time(nullptr);
        string timestamp = ctime(&now);
        string t = "[" + timestamp.substr(0 , timestamp.length()-1) + "]" + transaction + ": $" + to_string(amount);
        TransactionHistory.push_back(t);
    }

    public:

    BankAccount() {
        user = "";
        pin = 0;
        balance = 0;
        AccountNumber = 0;
    }

    BankAccount(string user , int pin , int balance , int AccountNumber){
        this->user = move(user);
        this->pin = pin;
        this->balance = balance;
        this->AccountNumber = AccountNumber;
    }

    string GetUser(){
        return user;
    }

    int GetPin(){
        return pin;
    }

    int GetBalance(){
        return balance;
    }

    int GetAccountNumber(){
        return AccountNumber;
    }

    void SetBalance(int value){
        balance = balance + value;
    }

    void DisplayBalance(){
        cout<<"Your Balance is : $"<<balance<<endl;
    }

    void Withdraw(int amount){
        if(amount<=balance){
            balance = balance - amount;
            cout<<"Please Take Your Cash! *.*"<<endl;
            cout<<"Your Remaining balance is : $"<<balance<<endl;
            AddtoHistory("Withdrawal ",amount);
        }else{
            cout<<"Insufficient Balance! *.*"<<endl;
        }
    }

    void Deposit(int amount){
        balance = balance + amount;
        cout<<"Your new Balance is : $"<<balance<<endl;
        AddtoHistory("Deposit ",amount);
    }

    void Transfer(int amount , BankAccount& receiver){
        if(amount<=balance){
            balance = balance - amount;
            receiver.SetBalance(receiver.GetBalance() + amount);
            cout<<"Transaction Successful! *.*"<<endl;
            cout<<"Your Remaining balance is : $"<<balance<<endl;
            AddtoHistory("Transfer to "+receiver.GetUser(),amount);
        }else{
            cout<<"Insufficient Balance! *.*"<<endl;
        }
    }

    void ChangePin(int oldPin , int newPin){
        if(pin == oldPin){
            pin = newPin;
            cout<<"Pin changed Successfully *.*"<<endl;
        }else{
            cout<<"Incorrect Pin *.*"<<endl;
        }
    }

    void DisplayHistory(){
        if(TransactionHistory.empty()){
            cout<<"No Transaction History Available"<<endl;
        }else{
            cout<<"Transaction History:"<<endl;
            for(auto transaction : TransactionHistory){
                cout<<transaction<<endl;
            }
        }
    }

    void PayBill(const string& BillType , int amount){
        if(amount<=balance){
            balance = balance - amount;
            cout<<"Payment of $"<<amount<<" for "<<BillType<<"Successful *.*"<<endl;
            cout<<"Your Remaining Balance is : $ "<<balance<<endl;
            AddtoHistory("Bill Payment: "+BillType,amount);
        }else{
            cout<<"Insufficient Balance . Payment cannot Processed"<<endl;
        }
    }


};

void DisplayMenu(){
    cout<<"Welcome To New Branch of Eren's Bank ATM *.*"<<endl;
    cout<<"Select A Option"<<endl;
    cout << "1. Create Account" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
}

int GenerateAccountNumber(){
    static int accountnumber = 1000;
    return accountnumber++;
}

void CreateAccount(map<int, BankAccount>& Accounts){
    string user;
    int pin;
    int balance;

    cout<<"Enter User Name: "<<endl;
    cin.ignore();
    getline(cin,user);

    cout<<"Enter PIN: "<<endl;
    cin>>pin;

    cout<<"Enter Initial Balance: "<<endl;
    cin>>balance;

    int accountnumber = GenerateAccountNumber();
    BankAccount newAccount(user , pin , balance , accountnumber);
    Accounts[accountnumber] = newAccount;

    cout<<"Account Created Successfully . Your Account Number is : "<<accountnumber<<endl;
}

int main(){

        map<int,BankAccount> Accounts;
        int choice;
        int accountnumber = 0;
        bool logged = false;
        int Pin;
        BankAccount* account = nullptr;

        while(true){
            DisplayMenu();
            cin>>choice;

            if(choice == 1){
                CreateAccount(Accounts);
            }else if(choice==2){
                cout<<"Enter Account Number"<<endl;
                cin>>accountnumber;
                cout<<"Enter PIN!"<<endl;
                cin>>Pin;

                auto it = Accounts.find(accountnumber);
                if(it!=Accounts.end()){
                    account = &(it->second);

                    if(account->GetPin() == Pin){
                        logged = true;
                        cout<<"Login Successful. *.*"<<endl;
                        cout<<"Welcome, "<<account->GetUser()<<"!"<<endl;
                    }else{
                        cout<<"Incorrect PIN . Login Failed"<<endl;
                    }
                }else{
                    cout<<"Invalid Account Number . Login Failed"<<endl;
                }
            }else if(choice == 3){
                cout<<"Thank You for Using Eren's Bank ATM . GoodBye! *.*"<<endl;
                break;
            }

            if(logged){
                while(true){

                cout << endl;
                cout << "Select an option:" << endl;
                cout << "1. Display Balance" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Deposit" << endl;
                cout << "4. Transfer" << endl;
                cout << "5. Change PIN" << endl;
                cout << "6. Display Transaction History" << endl;
                cout << "7. Pay Bill" << endl;
                cout << "8. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    account->DisplayBalance();
                } else if (choice == 2) {
                    int amount;
                    cout << "Enter the amount to withdraw: $";
                    cin >> amount;
                    account->Withdraw(amount);
                } else if (choice == 3) {
                    int amount;
                    cout << "Enter the amount to deposit: $";
                    cin >> amount;
                    account->Deposit(amount);
                } else if (choice == 4) {
                    int amount;
                    int receiver;
                    cout << "Enter the amount to transfer: $";
                    cin >> amount;
                    cout << "Enter the account number of the receiver: ";
                    cin >> receiver;

                    auto It = Accounts.find(receiver);
                    if (It != Accounts.end()) {
                        BankAccount& receiverAccount = It->second;
                        account->Transfer(amount, receiverAccount);
                    } else {
                        cout << "Receiver account does not exist. Transfer failed." << endl;
                    }
                } else if (choice == 5) {
                    int oldPin, newPin;
                    cout << "Enter your old PIN: ";
                    cin >> oldPin;
                    cout << "Enter your new PIN: ";
                    cin >> newPin;
                    account->ChangePin(oldPin, newPin);
                } else if (choice == 6) {
                    account->DisplayHistory();
                } else if (choice == 7) {
                    string billType;
                    int billAmount;
                    cout << "Enter the type of bill: ";
                    cin >> billType;
                    cout << "Enter the amount of the bill: $";
                    cin >> billAmount;
                    account->PayBill(billType, billAmount);
                } else if (choice == 8) {
                    cout << "Logout Successful. *.*" << endl;
                    logged = false;
                    break;
                }
            }
        }
    }

    return 0;
}