#include<iostream>
using namespace std;
static char board[3][3]= {{'.','.','.'}, {'.','.','.'}, {'.','.','.'}},ch,symbol,ch1;
string P1,P2;
int temp=0,c,r;
void boardReset()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = '.';
}
void printBoard()
{
    system("cls");
    for(int i = 0; i < 3; i++)
    {
        cout << "\t\t\t";
        for(int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j] << " ";
            }
        cout << "\n";

    }
}
void movetime(char c1)
{
    if(board[r-1][c-1] == '.')
        board[r-1][c-1] = c1;
    else
    {
        cout << "\nThis Position is Already Occupied!\n\n";
        temp--;
    }
}
bool winner(char ch1)
{
    return((board[0][0] == ch1 && board[0][1] == ch1 && board[0][2] == ch1) ||
     (board[1][0] == ch1 && board[1][1] == ch1 && board[1][2] == ch1) ||
     (board[2][0] == ch1 && board[2][1] == ch1 && board[2][2] == ch1) ||
     (board[0][0] == ch1 && board[1][0] == ch1 && board[2][0] == ch1) ||
     (board[0][1] == ch1 && board[1][1] == ch1 && board[2][1] == ch1) ||
     (board[0][2] == ch1 && board[1][2] == ch1 && board[2][2] == ch1) ||
     (board[0][0] == ch1 && board[1][1] == ch1 && board[2][2] == ch1) ||
     (board[0][2] == ch1 && board[1][1] == ch1 && board[2][0] == ch1));
}
bool nospace()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == '.')
                return false;
    return true;
}
void gametime()
{
    do
    {

        if(temp%2==0)
        {
            cout<<P1<<" is the player of current turn:\n";
            symbol='X';
        }
        else if(temp%2!=0)
        {
            cout<<P2<<" is the player of current turn:\n";
            symbol='O';
        }
        while(1)
        {
            cout << "Enter Column No. you want to make move: ";
            cin >> c;
            if(c < 1 || c > 3)
                cout << "Enter Coulmn in Range 1 to 3\n";
            else
                break;
        }
        while(1)
        {
            cout << "Enter Row No. you want to make move: ";
            cin >> r;
            if(r < 1 || r > 3)
                cout << "Enter Row in Range 1 to 3\n";
            else
            break;
        }
        movetime(symbol);
        temp++;
        printBoard();
    }while(!winner(symbol)&&!nospace());
}
bool boardfull()
{
   for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return false;
    return true;
}


int main()
{
    char ch;
    system("cls");
    do
    {
    cout<<"\t\t-----------------------TIC-TAC-TOE---------------------------- ";
    cout<<"\n\tEnter the name for the First player : ";
    cin>>P1;
    cout<<"\n\tSymbol assigned to "<<P1<<" is X";
    cout<<"\n\n\tEnter the name for the O player: ";
    cin>>P2;
    cout<<"\n\tSymbol assigned to "<<P2<<" is O\n";
    cout<<"\t\t\t\tGame Board\n";
    printBoard();
    gametime();
    cout << "\t\t\t\tRESULT: ";
    if(boardfull() && !(winner('X') || winner('O')))
        cout << "Game Tie!\n";
    else if(temp % 2 == 0)
        cout << P2 << " is the winner\n";
    else
        cout << P1 << " is the winner\n";
	boardReset();
    cout << "\nDo You Want to Play Again? (Y / N): ";
    
    temp = 0;
    cin >> ch;
    }
    while(ch=='y' || ch=='Y');
}
