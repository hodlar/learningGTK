#include <gtk/gtk.h>

//Callback functionin improved (with data)
static void callback( GtkWidget *widget, gpointer data )
{
	g_print ("Hello - %s was pressed  \n", (gchar *) data);
}


/* In case of returning FALSE, this will call the destroy function =0
 * so, this is usefull for the "sure you want to exit?" dialogs (= */
static gboolean delete_event( GtkWidget *widget,
							 GdkEvent *event,
							 gpointer data )
{
	gtk_main_quit();
	return FALSE;
}

int main ( int argc, char *argv[] )
{
	//storage type for widgets
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box1;

	//arguments are prsed and returned to the app
	gtk_init (&argc, &argv);

	//create new window
	window = gtk_window_new( GTK_WINDOW_TOPLEVEL);

	//This just sets the title
	gtk_window_set_title (GTK_WINDOW (window), "Titulo (=");

	/* Trigered by a "delete-event" given by the window manager (close option),
	 * in this case we call the delete_event () function as defined.
	 * The data passed is NULL and is ignored in the function */
	g_signal_connect (window, "delete-event", G_CALLBACK (delete_event), NULL);

	//sets border width
	gtk_container_set_border_width (GTK_CONTAINER (window), 15);

	//Create a box to "pack" widgets
	box1 = gtk_hbox_new (FALSE, 0);

	//put the box into the main window
	gtk_container_add (GTK_CONTAINER (window), box1);

	//Creates button with label "Hello World", and allocates in memory
	button = gtk_button_new_with_label ("Button 1");

	//When button receives "clicked" signal, calls hello()
	g_signal_connect (button, "clicked", G_CALLBACK (callback), "button 1");

	//Pack this button into the invisible box
	gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

	//This tells GTK that the button is ready to be showed (=
	gtk_widget_show (button);

	//Creates button with label "Hello World", and allocates in memory
	button = gtk_button_new_with_label ("Button 2");

	//When button receives "clicked" signal, calls hello()
	g_signal_connect (button, "clicked", G_CALLBACK (callback), "button 2");

	//Pack this button into the invisible box
	gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

	//Showing all the stuff...
	gtk_widget_show (button);

	gtk_widget_show (box1);

	gtk_widget_show (window);

	/* GTK aplicatiosn must have gtk_main. Things ends up in here and waits
	 * for an evvent (key, mouse, penguin) */
	gtk_main ();

	return 0;
}
