#include <gtk/gtk.h>

//Callback function
static void hello( GtkWidget *widget, gpointer data )
{
	g_print ("Hello World \n");
}

static gboolen delete_event( GtkWidget *widget,
							 GdkEvent *event,
							 gpointer data )
{
	g_print ("Hello World \n");

	return TRUE;
}

static void destroy( GtkWidget *widget,
					 gpointer data )
{
	gtk_main_quit();
}

int main ( int argc, char *argv[] )
{
	//storage type for widgets
	GtkWidget *window;
	GtkWidget *button;

	//arguments are prsed and returned to the app
	gtk_init (&argc, &argv);

	//create new window
	window = gtk_window_new( GTK_WINDOW_TOPLEVEL);

	/* Trigered by a "delete-event" given by the window manager (close option),
	 * in this case we call the delete_event () function as defined.
	 * The data passed is NULL and is ignored in the function */
	g_signal_connect (window, "delete-event", G_CALLBACK (delete_event), NULL);

	/* "destroy event -> signal handler, occurs when we call "gtk_widget_destroy()
	 * on the window, or if the "delete-event" callback returns false */
	g_signal_connect (window, "destroy", G_CALLBACK (destroy), NULL);

	//sets border width
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);

	//Creates button with label "Hello World"
	button = gtk_button_new_with_label ("Hello World");

	//When button receives "clicked" signal, calls hello()
	g_signal_connect (button, "clocked", G_CALLBACK (hello), NULL);

	//This will cause the window to be destroyed by calling gtk_widget_destroy(window)
	g_signal_connect_swapped (button, "clocked", G_CALLBACK (gtk_widget_destroy), window);

	//packs the button into the window (a gtk container)
	gtk_container_add (GTK_CONTAINER (window), button);

	//display the new widget
	gtk_widget_show (button);

	//display the window
	gtk_widget_show (window);

	/* GTK aplicatiosn must have gtk_main. Things ends up in here and waits
	 * for an evvent (key, mouse, penguin) */
	gtk_main ();

	return 0;
}
