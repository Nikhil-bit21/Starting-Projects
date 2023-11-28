#include<iostream>
#include<math.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

bool duplicate(string str , char c){

    for(int i=0;i<str.length();i++){
        if(str[i]==c){
            return true;
        }
    }
    return false;
}

string generate(int l , string str){

    srand(time(NULL));

    string pass = "";
    for(int i=0;i<l;i++){
        int rdm = rand() % str.length();
        pass = pass + str[rdm];
    }

    return pass;
}

int main(){

    cout<<endl;
    cout<<"Welcome to Mikasa Adv-Pass-Gen! *.* "<<endl;

    string bucket = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    cout<<"Enter the length of Password: "<<endl;
    int len;
    cin>>len;

    string choice;

    cout<<"Do you want to customize your Password? (y/n): "<<endl;
    char reply;
    cin>>reply;

    if(reply == 'y' || reply == 'Y'){
        cout<<"Enter your desired Characters to include in Password: "<<endl;
        cin>>choice;

        string desired = "";
        for(int i=0;i<choice.length();i++){
            if(!duplicate(desired, choice[i])){
                desired = desired + choice[i];
            }
        }
        choice = desired;
    }else{
        choice = bucket;
    }

    string pass = generate(len , choice);

    cout<<"Your Password: "<<pass<<endl;
    
    return 0;
}