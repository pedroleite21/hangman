#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "word_select.h"
#include "hangman.h"

int main(int argc, char *argv[])
{
    int gamesWin = 0, gamesLose = 0;
    char prompt = 'y';
    while (prompt != 'n')
    {
        int gameRes, difficult = -1;
        char *wordOfTheGame;
        while (difficult < 0 || difficult > 3)
        {
            printf("0 - Peaceful\n");
            printf("1 - Easy\n");
            printf("2 - Medium\n");
            printf("3 - Hard\n");
            printf("\nSelect difficult: ");
            difficult = getche() - '0';
            if (difficult < 0 || difficult > 3)
            {
                printf("\nYou should enter [0..3] symbols only.");
                getch();
            }
        }
        system("clear");
        if (!(wordOfTheGame = WordSelect(difficult)))
            return 0;
        printf("Word of the game: %s.\n", wordOfTheGame);
        gameRes = Hangman(wordOfTheGame);
        if (gameRes)
            gamesWin++;
        else
            gamesLose++;
        printf("Win: %d\tLose: %d\n", gamesWin, gamesLose);
        printf("Another try? [y/n] ");
        prompt = getche();
        if (prompt == 'y')
            system("clear");
    }
    printf("\n");
    
    return 0;
}
