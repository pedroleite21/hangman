#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "game.h"
#include "interface.h"

#define alphabetSize 26

int count = 0, errAmount = 0;

int symUsed(const char sym, char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == sym)
            return 1;
    return 0;
}

int getSymbol(GtkButton *button)
{
    symbol = gtk_button_get_label(button);
    gtk_widget_hide(GTK_WIDGET(button));
    printf("%s\n", symbol);

    int symExists = 0;

    for (i = 0; i < wordSize; i++)
    {
        if (wordOfTheGame[i] == *symbol)
        {
            symExists = 1;
            break;
        }
    }

    if (symExists)
    {
        for (i = 0; i < wordSize; i++)
            if (wordOfTheGame[i] == *symbol)
                hiddenWord[i] = *symbol;
        gtk_label_set_text(hiddenWordLabel, hiddenWord);
        if (!strcmp(wordOfTheGame, hiddenWord))
        {
            system("echo WINNER");
        }
    }
    else if (!symExists && !symUsed(*symbol, usedSymbols))
        errAmount++;

    if (!symUsed(*symbol, usedSymbols))
    {
        usedSymbols[count] = *symbol;
        count++;
    }

    system("echo WTF");

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
    return 0;
}
