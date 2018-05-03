/* 
 * Flood Fill algorithm to change a connected component to a different value
 * Used in bucket fill in MS Paint
 */ 
#include <iostream>

using namespace std;
int movex[]={1,0,0,-1,1,-1,1,-1};
int movey[]={0,1,-1,0,1,-1,-1,1};

void floodfill(char board[9][9],int x,int y,char changeto,char initial)
{
    if(x<0 || y<0 || x>=9 || y>=9)
        return;
    if(initial!=board[x][y])
        return ;
    board[x][y]=changeto;
    for(int i=0;i<8;i++)
    {
        int xmove=x+movex[i];
        int ymove=y+movey[i];
        floodfill(board,xmove,ymove,changeto,initial);
    }
    return;
}

int main()
{
    char board[][9]={{'L','L','L','L','L','L','L','L','L'},
                    {'L','L','W','W','L','L','W','L','L'},
                    {'L','W','W','L','L','L','L','L','L'},
                    {'L','W','W','W','L','W','W','L','L'},
                    {'L','L','L','W','W','W','L','L','L'},
                    {'L','L','L','L','L','L','L','L','L'},
                    {'L','L','L','W','W','L','L','W','L'},
                    {'L','L','W','L','W','L','L','L','L'},
                    {'L','L','L','L','L','L','L','L','L'}};
    floodfill(board,2,2,'R','W');
    floodfill(board,0,0,'.','L');
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<board[i][j];
        cout<<endl;
    }
    return 0;
}
