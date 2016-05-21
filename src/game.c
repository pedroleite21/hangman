#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "word_select.h"
#include "hangman.h"
#include "interface.h"
#include "game.h"

int difficult = 0, gamesWin = 0, gamesLose = 0;

void difficult_ch(GtkToggleButton *button)
{
    if (gtk_toggle_button_get_active(button))
    {
        const char *diffname;
        diffname = gtk_button_get_label(GTK_BUTTON(button));
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

    if (!(wordOfTheGame = WordSelect(difficult)))
        return 0;
    printf("Word: %s\n", wordOfTheGame);

    for (int k = 0; k < alphabetSize; k++)
        usedSymbols[k] = '-';

    for (wordSize = 0; wordOfTheGame[wordSize] != '\0'; wordSize++);

    hiddenWord = (char*)malloc(wordSize*sizeof(char));
    for (i = 0; i < wordSize; i++)
        hiddenWord[i] = '-';
    hiddenWord[i] = '\0';

    gtk_label_set_text(hiddenWordLabel, hiddenWord);
    gtk_widget_show(gameWindow);

    return 0;
}

/* int game()
{
    char prompt = 'y';
    while (prompt != 'n')
    {
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
} */
