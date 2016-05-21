#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <gtk/gtk.h>
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
        while (difficult < 0 || difficult > 4)
        {
            printf("1 - Peaceful\n");
            printf("2 - Easy\n");
            printf("3 - Medium\n");
            printf("4 - Hard\n");
            printf("0 - Exit from the game\n");
            printf("\nSelect menu number: ");
            difficult = getche() - '0';
            if (difficult == 0)
                return 0;
            if (difficult < 0 || difficult > 4)
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
