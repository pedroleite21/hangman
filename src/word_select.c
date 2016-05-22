#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

char *WordSelect(int difficult)
{
    FILE *wordsDB = NULL;

    switch (difficult)
    {
        case 0:
            wordsDB = fopen("../res/words/peaceful.txt", "r");
            break;
        case 1:
            wordsDB = fopen("../res/words/easy.txt", "r");
            break;
        case 2:
            wordsDB = fopen("../res/words/medium.txt", "r");
            break;
        case 3:
            wordsDB = fopen("../res/words/hard.txt", "r");
            break;
    }
    if (wordsDB == NULL)
    {
        printf("Words database not found.\n");
        return NULL;
    }

    int wordsAmount = 0, wordLength = 0;
    char str[10];

    while (!feof(wordsDB))
    {
        fgets(str, 10, wordsDB);
        wordsAmount++;
    }
    
    srand(time(NULL));
    int newWordNum = rand() % wordsAmount;

    fseek(wordsDB, 0, SEEK_SET);

    int i = 0;
    while (i != newWordNum)
    {
        fgets(str, 10, wordsDB);
        i++;
    }
    
    wordLength = strlen(str) - 1;
    char *newWord;
    newWord = (char*)malloc(wordLength*sizeof(char));

    for (i = 0; i < wordLength; i++)
        newWord[i] = str[i];
    newWord[i] = '\0';

    fclose(wordsDB);
    
    return newWord;
}
