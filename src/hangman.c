#include <stdio.h>
#include <stdlib.h>

int Hangman(char *word)
{
    int wordSize = 0;
    for (wordSize = 0; word[wordSize] != '\0'; wordSize++);
    printf("Word size is: %d.\n", wordSize);
    
    char *hiddenWord;
    hiddenWord = (char*)malloc(wordSize*sizeof(char));
    for (int i = 0; i < wordSize; i++)
        hiddenWord[i] = '_';
    for (int i = 0; i < wordSize; i++)
        printf("%c", hiddenWord[i]);
    
    return 0;
}
