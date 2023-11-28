#include<iostream>
#include<math.h>
using namespace std;

//Global Varibales 
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player = 'X';
int moves = 0;

void drawBoard(){
    cout<<"Tic-Tac-Toe"<<endl;
    cout << "-----------" << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool Gameover(){
    // Checking on one diagonal 
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return true;
    }
    // Checking on another diagonal
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return true;
    }

    // checking rows and columns
    for(int i=0;i<3;i++){
        //rows
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return true;
        }
        //columns
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return true;
        }
    }

    //if moves completed 
    if(moves==9){
        return false;
    }

    //game not over 
    return false;
}

void SwitchTurn(){
    if(player=='X'){
        player='O';
    }else{
        player='X';
    }
}

void MakeMove(){
    int row , col;
    cout<<endl;
    cout<<"Player "<<player<<" Turn"<<endl;
    cout<<endl;
    cout<<"Enter The row you want to make move in: "<<endl;
    cin>>row;
    cout<<endl;
    cout<<"Enter The col you want to make move in: "<<endl;
    cin>>col;

    // for adjusting index
    row--;
    col--;

    if(row<0 || row>2 || col<0 || col>2){
        cout<<"Invalid move. Try Again. *.*"<<endl;
        MakeMove();
    }else if(board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]=player;
        moves++;
    }else{
        cout<<"This is Occupied . Try Again *.*"<<endl;
        MakeMove();
    }
}

int main(){

    while(!Gameover()){
        drawBoard();
        MakeMove();
        SwitchTurn();
    }



    drawBoard();
    if(moves==9){
        cout<<"It's A TIE *.*"<<endl;
    }else{
        if(player=='X'){
            player='O';
        }else{
            player='X';
        }
        cout<<endl;
        cout<<"Player "<<player<<" WINS! *.*"<<endl;
    }
    
    return 0;
}