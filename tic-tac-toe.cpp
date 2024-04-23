#include <bits/stdc++.h>
using namespace std;

void printBoard(const vector<vector<char>> &board){
    for(const auto& row: board){
        for(char cell: row){
            cout<<"_|"<<cell<<"_";
        }
        cout<<endl;
    }
}
//Function call if there is a winner
char checkWinner(const vector<vector<char>> &board){
    //Check rows and cols
    for(int i=0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ') return board[i][0];
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ') return board[0][i];
    }
    //Check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ') return board[0][0];
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ') return board[0][2];
    return ' ';
}
//Function's call to check if the board is full
bool isFull(const vector<vector<char>>& board){
    for(const auto& row: board){
        for(char cell: row){
            if(cell==' ') return false;
        }
    }
    return true;
}
int main(){
    vector<vector<char>> board(3, vector<char>(3,' '));
    char currPlayer='X';
    while(true){
        //Print the board
        printBoard(board);
        //Ask the player to move
        int row,col;
    cout<<"Player "<<currPlayer<<",enter your move (row and column): ";
    cin>>row>>col;
    //Check if the the move is valid or not
    if(row<0 || row>2 || col<0 || col>2 || board[row][col]!=' '){
        cout<<"Invalid Move!! Try again."<<endl;
        continue;
    }
    //Make the move
    board[row][col]=currPlayer;
    //Check for a winner or draw
    char winner=checkWinner(board);
    if(winner!=' '){
        cout<<"Player "<<winner<<" wins the match!!";
        break;
    }
    else if(isFull(board)){
        cout<<"Match draw!!";
    }
    //Switch Players
    
    currPlayer=(currPlayer=='X')?'O':'X';
    }
    cout<<endl;
    printBoard(board);
    return 0;
}
