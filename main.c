#include <gtk/gtk.h>

typedef struct {
    int a;
    int b;
} SumData;

static void sum(GtkWidget *widget, gpointer data) {
    SumData *sum_data = (SumData *) data;
    g_print("Sum: %d\n", sum_data->a + sum_data->b);
}

static void say_hello(GtkWidget *widget, gpointer data) {
    g_print("Hello, World!\n");
}

static void activate(GtkApplication *application, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *label;

    window = gtk_application_window_new(application);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    label = gtk_label_new("Calculadora");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    button = gtk_button_new_with_label("AC");
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("7");
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);


    gtk_window_present(GTK_WINDOW(window));


}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}