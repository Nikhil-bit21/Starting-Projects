#include<iostream>
#include<math.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    const int max = 10;

    const int size = 22;
    const string bucket[size] = {"ERWIN", "LEVI", "EREN", "ARMIN", "MIKASA", "NARUTO", "KAKASHI", "SASUKE", "JIRAYA", "MINATO", "ITACHI", "SUKUNA", "GOJO", "YUJI", "MEGUMI", "GETO", "GARA", "LEE", "HINATA", "NOBARA", "TOJI", "DEIDARA"};

    srand(time(0));
    int rnd = rand() % size;
    
    string word = bucket[rnd];

    int wrong = 0;

    string guess(word.size() , '-');
    string used = "";

    cout<<endl;
    cout<<"Welcome to Levi Hangman. *.*"<<endl;
    cout<<endl;

    char input ;
    cout<<"To start the game enter (p)"<<endl;
    cin>>input;
    if(input != 'p' && input!='P'){
        cout<<"Have a Nice Day *.*"<<endl;
        return 0;
    }
    cout<<endl;
    cout<<"A message from Captain Levi!"<<endl;
    cout<<endl;
    cout<<"If you guessed the word in max attempts then you are save."<<endl;
    cout<<"Otherwise captain Levi is coming to hang you! Good Luck *.*"<<endl;


    while(wrong < max && guess!=word){
        cout<<"You Have "<<max-wrong<<" Guesses left. "<<endl;
        cout<<endl;
        cout<<"So far You've used these characters "<<used<<endl;
        cout<<endl;
        cout<<"So Far , You have guessed :"<<guess<<endl;
        cout<<endl;

        char character ;
        cout<<"/nEnter you guess!"<<endl;
        cin>>character;

        character=toupper(character);

        while(used.find(character)!= -1){
            cout<<"You have already guessed: "<<character<<endl;
            cout<<"Enter your guess: "<<endl;
            cin>>character;
            character = toupper(character);
        }

        used = used + character;

        if(word.find(character) != -1){
            cout<<"That's right! "<<character<<" is in the word."<<endl;
            for(int i = 0;i<word.length();i++){
                if(word[i] == character){
                    guess[i] = character;
                }
            }
            }else{
                cout<<"Sorry, "<<character<<" is not in the word. "<<endl;
                wrong++;
        }
    }

    if(wrong == max){
        cout<<"Captain Levi Caught you & you have been hanged! *.*"<<endl;
    }else{
        cout<<"Congratulations you guessed it! *.* "<<endl;
    }

    cout<<"The word is "<<word<<endl;
    
    return 0;
}