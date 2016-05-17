#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define peaceful 0
#define easy 1
#define medium 2
#define hard 3

char *WordSelect(int difficult)
{
    FILE *wordsDB = NULL;

    switch (difficult)
    {
        case peaceful:
            wordsDB = fopen("../res/words/peaceful.txt", "r");
            break;
        case easy:
            wordsDB = fopen("../res/words/easy.txt", "r");
            break;
        case medium:
            wordsDB = fopen("../res/words/medium.txt", "r");
            break;
        case hard:
            wordsDB = fopen("../res/words/hard.txt", "r");
            break;
    }
    if (wordsDB == NULL)
    {
        printf("File not found.\n");
        return 0;
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
