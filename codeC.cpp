#include <stdio.h>
#include <stdlib.h>
//Windows edit #include <conio.h>
#include "conio.h"
/*
file conio for ubuntu :
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

//reads from keypress, doesn't echo 
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

//reads from keypress, echoes 
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
*/
void Draw(int n, int m,int Map[3][3]);
int check_win(int Map[3][3]);
int main(){
    Menu:
    int n = 0;
    int m = 0;
    int turn = 1;
    int Map[3][3]={ 0 };
    while(true)
    {
        int ch;
        system("clear");
        printf("=======Game CARO======\n");
        printf("=Turn: Play %d        =\n",turn);
        printf("======================\n");
        Draw(n,m,Map);
        ch = getch();
        if(ch == 102)
        {
            break;
        }
        if(ch == 10)
        {   
            if (Map[n][m] == 0)
            {
                 Map[n][m] = turn;
                if ( turn == 1)
                {
                    turn = 2;
                }
                else
                {
                    turn = 1;
                }
            }
        }
        if(ch == 119)
        {
            if (n - 1 >= 0)
            {
                n--;
            }
        }
        if(ch == 115)
        {
            if(n + 1 <= 2)
            {
                n++;
            }
        }
        if(ch == 97)
        {
            if(m - 1 >= 0)
            {
                m--;
            }
        }
        if(ch == 100)
        {
            if(m + 1 <= 2)
            {
                m++;
            }
        }
        int win =  check_win(Map);
        if(win != 0)
        {
            system("clear");
            printf("=======Game CARO======\n");
            printf("=Turn: Play %d        =\n",turn);
            printf("======================\n");
            Draw(n,m,Map);
            printf("Player %d Win\n", win);
            getch();
            goto Menu;
        }
    }
        return 0;
}
void Draw(int n, int m, int Map[3][3]){
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if (Map[i][j] == 0)
            {
                if ( i == n && j == m)
                {
                    printf("[_]");    
                }
                else
                {   
                    printf(" _ ");
                }
            }
            else
            {
                if ( i == n && j == m)
                {
                    printf("[%d]", Map[i][j]);
                }
                else
                {
                    printf(" %d ", Map[i][j]);
                }
            }
        }
        printf("\n");      
    }
}
int check_win(int Map[3][3]){
    int win = 0;
    for(int i = 0; i <= 2; ++i)
    {
        if(Map[i][0] != 0 && Map[i][0] == Map[i][1] && Map[i][0] == Map[i][2])
        {
            return Map[i][0];
        }
        if(Map[0][i] != 0 && Map[0][i] == Map[1][i] && Map[0][i] == Map[2][i])
        {
            return Map[0][i];
        }
    }
    if(Map[0][0] != 0 && Map[0][0] == Map[1][1] && Map[0][0] == Map[2][2])
    {
        return Map[0][0];
    }
    if(Map[0][2] != 0 && Map[0][2] == Map[1][1] && Map[0][2] == Map[2][0])
    {
        return Map[0][2];
    }
    return win;    
}
