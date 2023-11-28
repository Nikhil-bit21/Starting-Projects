#include<iostream>
#include<math.h>
#include<map>
using namespace std;

map<int , int> Notes;

void Add(int note , int count){
    Notes[note] = Notes[note] + count;
}

void Remove(int note , int count){
    if(Notes[note] < count){
        cout<<"Error: You Don't Have Enough Amount of Note "<<note<<endl;
        return;
    }
    Notes[note] = Notes[note] - count;
}

int Total(){
    int total = 0;
    for(auto it = Notes.begin(); it!=Notes.end(); it++){
        total = total + ((it->first)*(it->second));
    }
    return total;
}

void Print(){
    for(auto it = Notes.begin() ; it!=Notes.end() ;it++){
        cout<<it->second<<" notes of $"<<it->first<<endl;
    }
}

int main(){

    int note , count , bal;
    string input;

    while(true){
        cout<<endl;
        cout<<"Welcome! *.*"<<endl;
        cout<<"Enter What You Want to do (ADD,Remove,Total,Notes,Exit) "<<endl;
        cin>>input;

        if(input == "ADD" || input == "add" || input == "a" || input == "A" || input == "Add"){
            cout<<"Enter What kind of Note You have"<<endl;
            cin>>note;
            cout<<"Enter the Amount of Notes You have"<<endl;
            cin>>count;

            Add(note , count);
            cout<<"Amount Added Successfully. *.*"<<endl;
        }
        else if(input == "REMOVE" || input == "remove" || input == "r" || input == "R" || input == "Remove"){
            cout<<"Enter What kind of Note You want to Remove"<<endl;
            cin>>note;
            cout<<"Enter the Amount of Notes You want to Remove"<<endl;
            cin>>count;

            Add(note , count);
            cout<<"Amount Remove Successfully. *.*"<<endl;
        }
        else if(input == "TOTAL" || input == "total" || input == "t" || input == "T" || input == "Total"){
            bal = Total();
            cout << "Total balance: $ " << bal << endl;
        }
        else if(input == "NOTES" || input == "notes" || input == "n" || input == "N" || input == "Notes"){
            Print();
        }
        else if(input == "EXIT" || input == "exit" || input == "e" || input == "E" || input == "Exit"){
            break;
        }
        else{
            cout<<"Invalid Command. Currently we have limited Options in Future more will be added. Please Try Again."<<endl;
        }
    }
    
    return 0;
}