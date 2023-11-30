#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;

int AND(int a , int b){
    return a&b;
}

int OR(int a , int b){
    return a | b;
}

int XOR(int a , int b){
    return a^b;
}

int NOT(int a){
    return ~a;
}

int leftshift(int a , int num){
    return a<<num;
}

int rightshift(int a , int num){
    return a>>num;
}

int setbits(int a ){
    return __builtin_popcount(a);
}

int Rotateleft(int a , int num){
    return (a<<num) | (a>> (sizeof(int) * 8 - num ));
}

int Rotateright(int a , int num){
    return (a>>num) | (a << (sizeof(int) * 8 - num));
}

int setbit(int a , int num){
    return a | (1<<num);
}

int toggelbit(int a , int num){
    return a ^ (1<<num);
}

unsigned long binaryToDecimal(const string& binaryString) {
    bitset<32> binary(binaryString);
    return binary.to_ulong();
}

int main(){

    int choice ;
    int num1 , num2 , shift , position;
    string binary;

    cout << "Choose an operation:"<<endl;
    cout << "1. Bitwise AND"<<endl;
    cout << "2. Bitwise OR"<<endl;
    cout << "3. Bitwise XOR"<<endl;
    cout << "4. Bitwise NOT"<<endl;
    cout << "5. Bitwise Left Shift"<<endl;
    cout << "6. Bitwise Right Shift"<<endl;
    cout << "7. Count Set Bits"<<endl;
    cout << "8. Bitwise Rotate Left"<<endl;
    cout << "9. Bitwise Rotate Right"<<endl;
    cout << "10. Bitwise Set (Set a specific bit)"<<endl;
    cout << "11. Toggle Bit (Toggle a specific bit)"<<endl;
    cout << "12. Binary to Decimal Conversion"<<endl;
    cout<<endl;
    cout << "Enter your choice (1-12):"<<endl;
    cin >> choice;

    cout << "Enter the first integer: ";
    cin >> num1;

    if (choice >= 1 && choice <= 3 || choice == 5 || choice == 6 || (choice >= 8 && choice <= 11)) {
        cout << "Enter the Second integer: ";
        cin >> num2;
    }

    switch (choice) {
        case 1:
            cout << "Bitwise AND result: " << AND(num1, num2) << endl;
            break;

        case 2:
            cout << "Bitwise OR result: " << OR(num1, num2) << endl;
            break;

        case 3:
            cout << "Bitwise XOR result: " << XOR(num1, num2) << endl;
            break;

        case 4:
            cout << "Bitwise NOT result: " << NOT(num1) << endl;
            break;

        case 5:
            cout << "Bitwise Left Shift result: " << leftshift(num1, num2) << endl;
            break;

        case 6:
            cout << "Bitwise Right Shift result: " << rightshift(num1, num2) << endl;
            break;

        case 7:
            cout << "Number of set bits: " << setbits(num1) << endl;
            break;

        case 8:
            cout << "Bitwise Rotate Left result: " << Rotateleft(num1, num2) << endl;
            break;

        case 9:
            cout << "Bitwise Rotate Right result: " << Rotateright(num1, num2) << endl;
            break;

        case 10:
            cout << "Enter the position of the bit to set: ";
            cin >> position;
            cout << "Result after setting bit: " << setbit(num1, position) << endl;
            break;

        case 11:
            cout << "Enter the position of the bit to toggle: ";
            cin >> position;
            cout << "Result after toggling bit: " << toggelbit(num1, position) << endl;
            break;

        case 12:
            cout << "Enter a binary number: ";
            cin >> binary;

            cout << "Decimal representation of the binary number: " << binaryToDecimal(binary) << endl;
            break;

        default:
            cout << "Invalid choice. Exiting.\n";
            return 1;
    }

    return 0;
}