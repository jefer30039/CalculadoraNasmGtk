#include <gtk/gtk.h>

extern void suma(GtkWidget *widget, gpointer data);
extern void resta(GtkWidget *widget, gpointer data);
extern void multiplicacion(GtkWidget *widget, gpointer data);
extern void division(GtkWidget *widget, gpointer data);
extern void porcentaje(GtkWidget *widget, gpointer data);


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
    gtk_window_set_default_size(GTK_WINDOW(window), 170, 180);

    grid = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(window), grid);

    label = gtk_label_new("Result");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

    button = gtk_button_new_with_label("AC"); // Clear
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("<"); // Backspace
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

    button = gtk_button_new_with_label("%"); // Porcentage
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);

    button = gtk_button_new_with_label("÷"); // Division
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 1, 1, 1);

    button = gtk_button_new_with_label("x"); // Multiplicacion
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 2, 1, 1);

    button = gtk_button_new_with_label("-"); // Resta
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);

    button = gtk_button_new_with_label("+"); // Suma
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 4, 1, 1);

    button = gtk_button_new_with_label("="); // Igual
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 5, 1, 1);

    button = gtk_button_new_with_label("."); // Punto
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 5, 1, 1);

    //for para crear los botones de los numeros (menos el 0)
    for (int i = 1; i < 10; i++) {
        button = gtk_button_new_with_label(g_strdup_printf("%d", i));
        g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
        gtk_grid_attach(GTK_GRID(grid), button, (i - 1) % 3, 4 - (i - 1) / 3, 1, 1);
    }

    button = gtk_button_new_with_label("0");
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 2, 1);

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