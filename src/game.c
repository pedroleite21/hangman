#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "word_select.h"
#include "hangman.h"
#include "game.h"
#include <gtk/gtk.h>

void difficult_ch(GtkToggleButton *button)
{
    if (gtk_toggle_button_get_active(button))
    {
        const char *diffname;
        diffname = gtk_button_get_label(GTK_BUTTON(button));
        printf("Difficult: %d\n", difficult);
        if (!strcmp(diffname, "Peaceful"))
            difficult = 0;
        else if (!strcmp(diffname, "Easy"))
            difficult = 1;
        else if (!strcmp(diffname, "Medium"))
            difficult = 2;
        else if (!strcmp(diffname, "Hard"))
            difficult = 3;
    }
}

int startGame()
{
    gtk_widget_hide(difficultWindow);
    gtk_widget_hide(msgWindow);

    int gamesWin = 0, gamesLose = 0;
    int gameRes;
    char *wordOfTheGame;
    if (!(wordOfTheGame = WordSelect(difficult)))
        return 0;
    gtk_label_set_text(hiddenWordLabel, wordOfTheGame);

    gtk_widget_show(gameWindow);
    return 0;
}

int game()
{
    int gamesWin = 0, gamesLose = 0;
    char prompt = 'y';
    while (prompt != 'n')
    {
        int gameRes, difficult = -1;
        char *wordOfTheGame;
        while (difficult < 0 || difficult > 3)
        {
            printf("1 - Peaceful\n");
            printf("2 - Easy\n");
            printf("3 - Medium\n");
            printf("4 - Hard\n");
            printf("0 - Exit from the game\n");
            printf("\nSelect menu number: ");
            difficult = getche() - '0';
            if (difficult < 0 || difficult > 3)
            {
                printf("\nYou should enter [0..3] symbols only.");
                getch();
            }
        }
        system("clear");
        if (!(wordOfTheGame = WordSelect(difficult)))
            return 0;
        printf("Word of the game: %s.\n", wordOfTheGame);
        gameRes = Hangman(wordOfTheGame);
        if (gameRes)
            gamesWin++;
        else
            gamesLose++;
        printf("Win: %d\tLose: %d\n", gamesWin, gamesLose);
        printf("Another try? [y/n] ");
        prompt = getche();
        if (prompt == 'y')
            system("clear");
    }
    printf("\n");
    
    return 0;
}
