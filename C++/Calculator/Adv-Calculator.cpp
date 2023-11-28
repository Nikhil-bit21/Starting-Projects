#include<iostream>
#include<math.h>
#include <cmath>
#include <limits>
using namespace std;

int main(){
    cout<<endl;
    cout<<"Welcome to Marvel's Calculator."<<endl;
    cout<<"-> As Promised here is the new update of your loving Calculator."<<endl;
    cout<<"-> What are the new features added in this update . "<<endl;
    cout<<"-> We added a new operator in this (^) so that now you can also find power of a number. "<<endl;
    cout<<"-> And by your feedbacks we came to known that our previous calculator is not handling "<<
    "the error's like dividion by zero etc or infinite number case . this also is "<<
    "included in this update . Thank you! Hope you are enjoying it *.*"<<endl;

    char operand;
    float num1 , num2 , result;

    cout<<endl;

    cout<<"What you want to do ?"<<endl;
    cin>>operand;
    cout<<endl;


    if(operand=='+' || operand=='-' || operand=='*' || operand=='/' || 
    operand=='%'){

    cout<<"Enter your 1st number"<<endl;
    cin>>num1;
    cout<<"Enter your 2nd number"<<endl;
    cin>>num2;
    
    cout<<endl;

    switch(operand){
        case '+':
        result = num1+num2;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '-':
        result = num1-num2;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '*':
        result = num1*num2;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        break;

        case '/':
        if(num2 == 0){
            cout<<"Error: Division by Zero"<<endl;
            return 0;
        }else{
        result = num1/num2;
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        }
        break;

        case '%':
        if(num2==0){
            cout<<"Error: Division by Zero"<<endl;
            return 0;
        }else{
        result = fmod(num1,num2);
// fmod() function returns a floating-point value.
//so the result should be stored in a floating-point variable.
//fmod() is a C++ standard library function.
//that calculates the floating-point remainder of num1 divided by num2. 
//It returns the remainder after dividing num1 by num2 as a floating-point value.
        cout<<"Thank you for Using . Hope you enjoyed it *.*"<<endl;
        }
        break;
    }
}
    else if(operand=='^'){
        cout<<"Enter the base: "<<endl;
        cin>>num1;
        cout<<"Enter the power/exponent: "<<endl;
        cin>>num2;

        result = pow(num1,num2);
    
}
else{
    cout<<"Error: Invalid operator"<<endl;
    cout << "Sorry! for your inconvenience . For Now We Haven't included " << 
"this feature/Operation to our Calculator . We have saved your id. We'll let you "<<
"known if in future we add this . Thank you for Using . Hope you enjoyed it *.*"<<endl;
        return 0;
}

if(isfinite(result)){
    cout<<"Result: "<<result<<endl;
}else{
    cout<<"Error: Result is not a finite number"<<endl;
    return 0;
}

    return 0;
}