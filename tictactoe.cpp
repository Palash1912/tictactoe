#include<iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice,r,c;
char turn='X';
bool draw=false;

void display(){
    system("cls");

    cout<<"\tTIC-TAC-TOE GAME   "<<endl<<endl;

    cout<<"  PLAYER 1 --> X  "<<"\t"<<"  PLAYER 2 --> O  "<<endl<<endl;

    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl;
    cout<<"\t     |     |     "<<endl<<endl;

}

void playerTurn(){

    if(turn=='X'){
        cout<<" ---  PLAYER 1 TURN  --- "<<endl<<endl;
    }
    else{
        cout<<" ---  PLAYER 2 TURN  --- "<<endl<<endl;
    }

    cout<<"Enter Number --> "<<endl;
    cin>>choice;

    switch(choice){

        case 1:r=0;c=0;break;
        case 2:r=0;c=1;break;
        case 3:r=0;c=2;break;
        case 4:r=1;c=0;break;
        case 5:r=1;c=1;break;
        case 6:r=1;c=2;break;
        case 7:r=2;c=0;break;
        case 8:r=2;c=1;break;
        case 9:r=2;c=2;break;
    }

    if(turn=='X' && board[r][c]!='X' && board[r][c]!='O'){
        board[r][c]='X';
        turn='O';
    }
    else if(turn=='O' && board[r][c]!='X' && board[r][c]!='O'){
        board[r][c]='O';
        turn='X';
    }
    else{
        cout<<"Enter Valid Number ranging from 1-9"<<endl;
        playerTurn();
    }
}

bool gameOver(){

    for(int i=0;i<3;i++){  //checking for winner - horizontally,vertically and diagonally
        if( (board[0][i]==board[1][i] && board[0][i]==board[2][i]) || (board[i][0]==board[i][1] && board[i][0]==board[i][2])
           || (board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0]) ){
            return false;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='X' && board[i][j]!='O'){  //if a box is not filled yet (i.e. neither X nor O), then game shall proceed
                return true;
            }
        }
    }

    draw=true;  //if we reach here, it means all boxes are filled, and we haven't found a winner, thus DRAW
    return false;

}


int main(){

    while(gameOver()){
        display();
        playerTurn();
        display();
    }

    if(turn=='X' && draw==false){
        cout<<"PLAYER 2 CONGRATULATIONS ---> WINS !!!!!"<<endl<<endl;
    }
    else if(turn=='O' && draw==false){
        cout<<"PLAYER 1 CONGRATULATIONS ---> WINS !!!!!"<<endl<<endl;
    }
    else if(draw==true){
        cout<<"GAME DRAWN !!!!!"<<endl<<endl;
    }

}
