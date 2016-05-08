#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define peaceful 0
#define easy 1
#define medium 2
#define hard 3

char *wordSelect(int difficult)
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
            wordsDB = fopen("../res/words/peaceful.txt", "r");
            break;
        case hard:
            wordsDB = fopen("../res/words/peaceful.txt", "r");
            break;
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
    printf("Words amount: %d\n", wordsAmount);
    printf("Word length: %d\n", wordLength);
    
    srand(time(NULL));
    int newWordNum = rand() % wordsAmount;
    printf("New word num: %d\n", newWordNum);
    char newWord[wordLength];
    
    int i;
    while (i != newWordNum)
    {
        ch = fgetc(wordsDB);
        if (ch == '\n')
            i++;
    }
    
    for (i = 0; i < wordLength; i++)
        newWord[i] = fgetc(wordsDB);
        
    return newWord;
}
