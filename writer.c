#include <gtk/gtk.h>

static void cb_button (GtkWidget *widget, gpointer data) {
  g_print ("Hello World\n");
}

int main (int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *button;

  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW(window), "Hello World");
  gtk_widget_set_size_request (window, 250, 80);
  gtk_container_set_border_width (GTK_CONTAINER(window), 10);
  
  button = gtk_button_new_with_label ("Hello World");
  gtk_container_add (GTK_CONTAINER(window), button);

  g_signal_connect (G_OBJECT(window),
		    "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect (G_OBJECT(button),
		    "clicked", G_CALLBACK(cb_button), NULL);

  gtk_widget_show_all (window);
  gtk_main ();

  return 0;
}
