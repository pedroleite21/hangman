#include <stdio.h>
#include "word_select.h"
#include "hangman.h"

#define peaceful 0
#define easy 1
#define medium 2
#define hard 3

int main()
{
    char *wordOfTheGame;
    wordOfTheGame = wordSelect(peaceful);
    printf("Word of the game: %s.\n", wordOfTheGame);
    Hangman(wordOfTheGame);
    
    return 0;
}
