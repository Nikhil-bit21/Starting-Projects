#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;

// function for suffix like 1st , 2nd etc
string Suffix(int num) {
    int lastDigit = num % 10;
    if (lastDigit == 1 && num != 11) {
        return "st";
    } else if (lastDigit == 2 && num != 12) {
        return "nd";
    } else if (lastDigit == 3 && num != 13) {
        return "rd";
    } else {
        return "th";
    }
}

int main(){

    srand(time(NULL)); // initialize the random number generator with the current time
    int key = (rand()%100) +1; // generate a random number between 1 and 100
    int guess;
    int attempts = 1;

    cout<<endl;
    cout<<"Welcome to Sukuna's Cursed World , I heard that you're very good in guessing.(y/n) "<<endl;
    string reply ;
    cin>>reply;
    if(reply == "no" || reply == "n"){
        return 0;
    }else if(reply !="yes" && reply!="y"){
        cout<<"Invalid input"<<endl;
        return 0;
    }

    cout<<endl;
    cout<<"So you're intresting in guessing the number. So I'm thinking of a number "<<
    "between 0 to 100 . Let's see in how many attempts you will guess it?"<<endl;
    cout<<endl;

    cout<<"Are you aware of Binary Search. (y/n)"<<endl;
    cout<<endl;

    string binary ;
    cin>>binary;
    if(binary == "yes" || binary == "y"){
        cout<<endl;
        cout<<"Good , you can apply it here by telling the mid number . By this you can "<<
        "minimize your attempts . GOOD LUCK *.*"<<endl;
        cout<<endl;
    }else{
       cout<<"Don't Worry you can start the game. GOOD LUCK *.*"<<endl;
        cout<<endl;
    }

    cout<<"Write play/p to continue"<<endl;
    cout<<endl;

    string play ;
    cin>>play;
    cout<<endl;

    if(play == "play" || play=="p"){
    do{
        cout<<"Enter your "<<attempts<<Suffix(attempts)<<" guess" <<endl;
        cin>>guess;
        attempts++;

        if(guess > key){
            cout<<"Too High. Try Again."<<endl;
            cout<<endl;
        }else if(guess < key){
            cout<<"Too Small. Try Again"<<endl;
            cout<<endl;
        }else{
            cout<<"Congratulations! You guessed the number"<<endl;
            cout<<"You have Taken Total "<<attempts<<" to guess"<<endl;
        }

    }while(guess!=key);
    }
    
    return 0;
}