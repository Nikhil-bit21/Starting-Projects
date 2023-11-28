#include<iostream>
#include<math.h>
using namespace std;

int main(){
    cout<<endl;
    cout<<"Welcome to Marvel's Calculator."<<endl;

    char operand;
    int num1 , num2;

    cout<<"What you want to do ?"<<endl;
    cin>>operand;
    cout<<endl;

    if(operand != '+' && operand != '-' && operand != '*' && operand != '/' && operand != '%'){
        cout << "Sorry! for your inconvenience . For Now We Haven't included " << 
        "this feature/Operation to our Calculator . We have saved your id we'll let you "<<
        "known if in future we add this . Thank you for Using . Hope you enjoyed it *.*"<<endl;
        return 0;
    }

    cout<<"Enter your 1st number"<<endl;
    cin>>num1;
    cout<<"Enter your 2nd number"<<endl;
    cin>>num2;

    switch(operand){
        case '+':
        cout<<"Result: "<<num1+num2<<endl;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '-':
        cout<<"Result: "<<num1-num2<<endl;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '*':
        cout<<"Result: "<<num1*num2<<endl;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '/':
        cout<<"Result: "<<num1/num2<<endl;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '%':
        cout<<"Result: "<<num1%num2<<endl;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        default:
        cout << "Sorry! for your inconvenience . For Now We Haven't include" << 
        "this property/Operation to our Calculator . We have saved your id we'll let you "<<
        "known if in future we add this . Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;
    }



    return 0;
}