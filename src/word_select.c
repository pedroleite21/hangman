#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    char ch;

    while (ch != EOF)
    {
        ch = fgetc(wordsDB);
        if (ch != '\n')
            wordLength++;
        if (ch == '\n')
            wordsAmount++;
    }
    fseek(wordsDB, 0, SEEK_SET);
    wordLength /= wordsAmount;

    srand(time(NULL));
    int newWordNum = rand() % wordsAmount;

    char *newWord;
    newWord = (char*)malloc(wordLength*sizeof(char));

    int i = 0;
    while (i != newWordNum)
    {
        ch = fgetc(wordsDB);
        if (ch == '\n')
            i++;
    }

    for (i = 0; i < wordLength; i++)
        newWord[i] = fgetc(wordsDB);

    fclose(wordsDB);

    return newWord;
}
