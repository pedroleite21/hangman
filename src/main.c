#include <stdio.h>
#include <stdlib.h>
#include "word_select.h"
#include "hangman.h"
#include "conio.h"

#define peaceful 0
#define easy 1
#define medium 2
#define hard 3

int main()
{
    int gamesWin = 0, gamesLose = 0;
    char prompt = 'y';
    while (prompt != 'n')
    {
        int gameRes;
        char *wordOfTheGame;
        system("clear");
        wordOfTheGame = WordSelect(peaceful);
        printf("Word of the game: %s.\n", wordOfTheGame);
        gameRes = Hangman(wordOfTheGame);
        if (gameRes)
            gamesWin++;
        else
            gamesLose++;
        printf("Win: %d\tLose: %d\n", gamesWin, gamesLose);
        printf("Another try? [y/n] ");
        prompt = getche();
    }
    printf("\n");
    
    return 0;
}
