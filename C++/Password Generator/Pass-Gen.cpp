#include<iostream>
#include<math.h>
#include<cstdlib> // provides several general-purpose functions, such as memory allocation, random number generation, and type conversion.
#include<ctime> // provides functions for working with time and date, including getting the current system time and converting between different time formats.
using namespace std;

int main(){
    cout<<endl;
    cout<<"Welcome to Armin's Password Generator! *.* "<<endl;
    srand(time(NULL)); // sirf random se vho hr br seed value 1 leta hai and value itni random nahi aati hai tho srand so that hr bar vho seed value bhi change karde according to current time
    
    string bucket = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    cout<<"Enter the length of Password: "<<endl;
    int len;
    cin>>len;

    string pass;
    for(int i=0;i<len;i++){
        int random = rand() % bucket.length();
        pass = pass + bucket[random];
    }

    cout<<"Your Password is: "<<pass<<endl;
    cout<<"Hope You enjoyed using it *.* "<<endl;
    return 0;
}