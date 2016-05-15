#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Hangman(char *word)
{
    int i, wordSize, gameStatus = 0, errAmount = 0;
    char symbol;

    for (wordSize = 0; word[wordSize] != '\0'; wordSize++);
    printf("Word size is: %d.\n", wordSize);
    
    char *hiddenWord;
    hiddenWord = (char*)malloc(wordSize*sizeof(char));
    for (i = 0; i < wordSize; i++)
            hiddenWord[i] = '-';
    
    printf("Press any key to start...\n");
    system("read contscr");
    system("clear");

    while (gameStatus == 0 && errAmount != 3)
    {
        int symExists = 0;
        printf("Errors: %d\n\n", errAmount);
        for (i = 0; i < wordSize; i++)
            printf("%c", hiddenWord[i]);

        printf("\n\nEnter symbol: ");
        scanf(" %c", &symbol);

        for (i = 0; i < wordSize; i++)
            if (word[i] == symbol)
            {
                symExists = 1;
                break;
            }

        if (symExists)
        {
            for (i = 0; i < wordSize; i++)
                if (word[i] == symbol)
                    hiddenWord[i] = symbol;
            if (!strcmp(word, hiddenWord))
                gameStatus = 1;
        }
        else
            errAmount++;

        system("clear");
    }
    if (gameStatus == 1)
        printf("You win!\n");
    else
        printf("You lose!\n");
    return 0;
}
