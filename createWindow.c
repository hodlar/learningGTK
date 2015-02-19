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
	gtk_widget_show (window);

	gtk_main ();

	return 0;
}
