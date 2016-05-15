#include <stdio.h>
#include <stdlib.h>
#include "word_select.h"
#include "hangman.h"

#define peaceful 0
#define easy 1
#define medium 2
#define hard 3

int main()
{
    char *wordOfTheGame, try = 'y';
    while (try != 'n')
    {
        system("clear");
        wordOfTheGame = WordSelect(peaceful);
        printf("Word of the game: %s.\n", wordOfTheGame);
        Hangman(wordOfTheGame);
        printf("Another try? [y/n] ");
        scanf(" %c", &try);
    }
    
    return 0;
}
