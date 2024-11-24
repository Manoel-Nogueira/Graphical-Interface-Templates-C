/**
 * @author Manoel Nogueira Melo Filho
*/

#include <gtk/gtk.h>

static void activate (GtkApplication* app, gpointer user_data){

  // Cria uma nova janela  
  GtkWidget *window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  // Cria um label com o texto desejado
  GtkWidget *label = gtk_label_new("Hello World!");
    
  // Adiciona o label à janela
  gtk_container_add(GTK_CONTAINER(window), label);

  // Exibe todos os widgets na janela
  gtk_widget_show_all (window);

}

int main (int argc, char **argv){

  GtkApplication *app;
  int status;

  // Cria uma nova aplicação GTK
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);

  // Conecta o sinal "activate" à função on_activate
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  // Executa a aplicação e obtém o status de término
  status = g_application_run (G_APPLICATION (app), argc, argv);

  // Libera recursos associados à aplicação
  g_object_unref (app);

  return status;
  
}
