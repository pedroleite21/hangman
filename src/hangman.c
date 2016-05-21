#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "interface.h"

int getSymbol(GtkButton *button)
{
    symbol = gtk_button_get_label(button);
    gtk_widget_hide(GTK_WIDGET(button));

    int symExists = 0;
    char msgKilled[20], msgSaved[20];

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
            gtk_widget_hide(gameWindow);
            gamesWin++;
            sprintf(msgSaved, "Cats saved: %d", gamesWin);
            sprintf(msgKilled, "Cats killed: %d", gamesLose);
            gtk_label_set_text(gameMsg, "You saved the cat!");
            gtk_label_set_text(winAmount, msgSaved);
            gtk_label_set_text(loseAmount, msgKilled);
            gtk_widget_show(msgWindow);
        }
    }
    else if (!symExists)
    {
        errAmount++;
        sprintf(errPath, "../res/pics/%d.png", errAmount);
        gtk_image_set_from_file(hangmanImage, errPath);
    }

    if (errAmount == 5)
    {
        gtk_widget_hide(gameWindow);
        gamesLose++;
        sprintf(msgSaved, "Cats saved: %d", gamesWin);
        sprintf(msgKilled, "Cats killed: %d", gamesLose);
        gtk_label_set_text(gameMsg, "You killed the cat!");
        gtk_label_set_text(winAmount, msgSaved);
        gtk_label_set_text(loseAmount, msgKilled);
        gtk_widget_show(msgWindow);
    }

    return 0;
}
