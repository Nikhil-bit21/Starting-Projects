#include<iostream>
#include<math.h>
#include <string>
#include <unordered_map>
#include <cctype> // for converting tolower or toupper case.
using namespace std;

string convert(string user , unordered_map<string , string> &Map){
    string str = "";
    for(int i = 0; i < user.length(); i++){
        char c = user[i];
        str += tolower(c);
    }
    return Map[str];
}

void winner(string user , string comp){
    if(user == comp){
        cout<<"It's a Tie! *.*"<<endl;
    } else if (user == "rock" && comp == "scissors") {
        cout << "You win! *.*" << endl;
    } else if (user == "paper" && comp == "rock") {
        cout << "You win!" << endl;
    } else if (user == "scissors" && comp == "paper") {
        cout << "You win! *.*" << endl;
    }else{
        cout<<"Sasha Wins! *.* , Well Played ! Better Luck Next Time "<<endl;
    }
}

int main(){

    unordered_map<string, string> Map;
Map["r"] = "rock";
Map["rock"] = "rock";
Map["Rock"] = "rock";
Map["ROCK"] = "rock";
Map["p"] = "paper";
Map["paper"] = "paper";
Map["Paper"] = "paper";
Map["PAPER"] = "paper";
Map["s"] = "scissors";
Map["scissors"] = "scissors";
Map["Scissors"] = "scissors";
Map["SCISSORS"] = "scissors";



    string user , comp ;
    int computer;

    cout<<endl;
    cout<<"Welcome to Sasha Rock-Paper-Scissor Competition . We are organising and we have the best Player Sasha herself"<<endl;
    cout<<"Do you want to challenge her"<<endl;

    char play ;
    cout<<"If you want to play type (p)"<<endl;
    cin>>play;
    if(play != 'p' && play != 'P'){
        return 0;
    }

    cout<<"Enter your choice (R)ock, (P)aper, or (S)cissors: "<<endl;
    cin>>user;

    user = convert(user , Map);

    srand(time(NULL));

    computer = (rand() % 3)+ 1;

    if (computer == 1) {
        comp = "rock";
    } else if (computer == 2) {
        comp = "paper";
    } else {
        comp = "scissors";
    }

    cout<<"You Choose "<<user<<endl;
    cout<<"Sasha Choose "<<comp<<endl;

    winner(user , comp);
    
    return 0;
}