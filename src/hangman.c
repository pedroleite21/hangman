#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define alphabetSize 26

int symUsed(char sym, char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == sym)
            return 1;
    return 0;
}

int Hangman(char *word)
{
    int i, count = 0, wordSize, errAmount = 0;
    char symbol, usedSymbols[alphabetSize];
    for (int k = 0; k < alphabetSize; k++)
        usedSymbols[k] = '-';

    for (wordSize = 0; word[wordSize] != '\0'; wordSize++);
    printf("Word size is: %d.\n", wordSize);
    
    char *hiddenWord;
    hiddenWord = (char*)malloc(wordSize*sizeof(char));
    for (i = 0; i < wordSize; i++)
        hiddenWord[i] = '-';
    hiddenWord[i] = '\0';
    
    printf("Press any key to start...\n");
    getch();
    system("clear");

    while (errAmount != 5)
    {
        int symExists = 0;

        printf("Used symbols:\n");
        for (int k = 0; k < alphabetSize; k++)
            printf("%c", usedSymbols[k]);
        printf("\n\n");
        printf("Errors: %d\n\n", errAmount);
        for (i = 0; i < wordSize; i++)
            printf("%c", hiddenWord[i]);
        printf("\n\nEnter symbol: ");
        symbol = getche();
        if (symbol < 'a' || symbol > 'z')
        {
            printf("\nYou should enter [a..z] symbols only.");
            getch();
            system("clear");
            continue;
        }

        for (i = 0; i < wordSize; i++)
        {
            if (word[i] == symbol)
            {
                symExists = 1;
                break;
            }
        }

        if (symExists)
        {
            for (i = 0; i < wordSize; i++)
                if (word[i] == symbol)
                    hiddenWord[i] = symbol;
            if (!strcmp(word, hiddenWord))
            {
                system("clear");
                break;
            }
        }
        else if (!symExists && !symUsed(symbol, usedSymbols))
            errAmount++;

        if (!symUsed(symbol, usedSymbols))
        {
            usedSymbols[count] = symbol;
            count++;
        }

        system("clear");
    }

    if (errAmount != 5)
    {
        printf("You win!\n");
        return 1;
    }
    else
    {
        printf("You lose!\n");
        return 0;
    }
    return -1;
}
