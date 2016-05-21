#include <stdio.h>
#include <gtk/gtk.h>
#include "interface.h"

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

    hiddenWordLabel = GTK_LABEL(gtk_builder_get_object(builder, "hiddenWordLabel"));
    gameMsg = GTK_LABEL(gtk_builder_get_object(builder, "gameMsg"));
    winAmount = GTK_LABEL(gtk_builder_get_object(builder, "winAmount"));
    loseAmount = GTK_LABEL(gtk_builder_get_object(builder, "loseAmount"));

    gtk_builder_connect_signals (builder, NULL);
    g_object_unref( G_OBJECT( builder ) );
    gtk_widget_show( difficultWindow );
    gtk_main();

    return 0;
}
