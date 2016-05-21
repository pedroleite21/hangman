#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <gtk/gtk.h>
#include "word_select.h"
#include "hangman.h"

#define UI_FILE "../res/interface.glade"

GtkBuilder *builder;
GtkWidget *difficultWindow, *gameWindow, *msgWindow;
GtkRadioButton *difficult0, *difficult1, *difficult2, *difficult3;
GtkButton *startButton, *exitButton;

int main(int argc, char *argv[])
{
    GError *error = NULL;

    gtk_init( &argc, &argv );
    builder = gtk_builder_new();
    if( ! gtk_builder_add_from_file( builder, UI_FILE, &error ) )
    {
        g_warning( "%s", error->message );
        g_free( error );
        return( 1 );
    }

    difficultWindow = GTK_WIDGET(gtk_builder_get_object(builder, "difficultWindow"));
    gameWindow = GTK_WIDGET(gtk_builder_get_object(builder, "gameWindow"));
    msgWindow = GTK_WIDGET(gtk_builder_get_object(builder, "msgWindow"));
    difficult0 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "difficult0"));
    difficult1 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "difficult1"));
    difficult2 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "difficult2"));
    difficult3 = GTK_RADIO_BUTTON(gtk_builder_get_object(builder, "difficult3"));
    startButton = GTK_BUTTON(gtk_builder_get_object(builder, "startButton"));
    exitButton = GTK_BUTTON(gtk_builder_get_object(builder, "exitButton"));

    gtk_builder_connect_signals (builder, NULL);
    g_object_unref( G_OBJECT( builder ) );
    gtk_widget_show( difficultWindow );
    gtk_widget_show( gameWindow );
    gtk_widget_show( msgWindow );
    gtk_main();

    return 0;

    int gamesWin = 0, gamesLose = 0;
    char prompt = 'y';
    while (prompt != 'n')
    {
        int gameRes, difficult = -1;
        char *wordOfTheGame;
        while (difficult < 0 || difficult > 4)
        {
            printf("1 - Peaceful\n");
            printf("2 - Easy\n");
            printf("3 - Medium\n");
            printf("4 - Hard\n");
            printf("0 - Exit from the game\n");
            printf("\nSelect menu number: ");
            difficult = getche() - '0';
            if (difficult == 0)
                return 0;
            if (difficult < 0 || difficult > 4)
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

void difficult_ch(GtkToggleButton *button)
{
    printf("FIX IT!\n");
}
