#include <gtk/gtk.h>
#include <string.h>

extern int calcularSuma(int operando1, int operando2);
extern int calcularResta(int operando1, int operando2);
extern int calcularMultiplicacion(int operando1, int operando2);
extern int calcularDivision(int operando1, int operando2);
//extern void calcularPorcentaje(int operando1, int operando2);

char input[100];
int numero = 0;
int posicion_input = 0;
int operando1 = 0;
int operando2 = 0;
int operacion = 0;
int resultado = 0;

//funcion para limpiar la entrada
static void limpiarEntrada (GtkWidget *widget, gpointer data) {
    for (int i = 0; i < 100; i++) {
        input[i] = '\0';
    }
    posicion_input = 0;
}

static void say_hello (GtkWidget *widget, gpointer data) {
    g_print("Hello World\n");
}
static void suma (GtkWidget *widget, gpointer data) {
    g_print("+\n");
    numero = atoi(input);
    operando1 = numero;
    limpiarEntrada(widget, data);
    operacion = 1;
}
static void resta (GtkWidget *widget, gpointer data) {
    g_print("-\n");
    numero = atoi(input);
    operando1 = numero;
    limpiarEntrada(widget, data);
    operacion = 2;
}static void multiplicacion (GtkWidget *widget, gpointer data) {
    g_print("x\n");
    numero = atoi(input);
    operando1 = numero;
    limpiarEntrada(widget, data);
    operacion = 3;

}static void division (GtkWidget *widget, gpointer data) {
    g_print("÷\n");
    numero = atoi(input);
    operando1 = numero;
    limpiarEntrada(widget, data);
    operacion = 4;
}static void porcentaje (GtkWidget *widget, gpointer data) {
    g_print("porcetaje\n");
    operando1 = numero;
    numero = 0;
    operacion = 5;
}static void ac (GtkWidget *widget, gpointer data) {
    limpiarEntrada(widget, data);
    g_print("\n");
}
static void igual(GtkWidget *widget, gpointer data) {
    g_print("=\n");
    operando2 = numero;
    switch (operacion){
        case 1:
            resultado = calcularSuma(operando1, operando2);
            g_print("Resultado: %d\n", resultado);
            break;
        case 2:
            resultado = calcularResta(operando1, operando2);
            g_print("Resultado: %d\n", resultado);
            break;
        case 3:
            resultado = calcularMultiplicacion(operando1, operando2);
            g_print("Resultado: %d\n", resultado);
            break;
        case 4:
            resultado = calcularDivision(operando1, operando2);
            g_print("Resultado: %d\n", resultado);
            break;
        case 5:
            //calcularPorcentaje(operando1, operando2);
            break;
        default:
            break;
    }
}

//funcion para guardar los numeros
static void mostrarNum (GtkWidget *widget, gpointer data) {
    numero = atoi(input);
    g_print("%d\n", numero);
}

static void saveNumber(GtkWidget *widget, gpointer data) {
    switch (GPOINTER_TO_INT(data))
    {
    case 0:
        input[posicion_input] = '0';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 1:
        input[posicion_input] = '1';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 2:
        input[posicion_input] = '2';
        posicion_input++;
        mostrarNum(widget, data);  
        break;
    case 3:
        input[posicion_input] = '3';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 4:
        input[posicion_input] = '4';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 5:
        input[posicion_input] = '5';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 6:
        input[posicion_input] = '6';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 7:
        input[posicion_input] = '7';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 8:
        input[posicion_input] = '8';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    case 9:
        input[posicion_input] = '9';
        posicion_input++;
        mostrarNum(widget, data);
        break;
    default:
        break;
    }
}

static void punto (GtkWidget *widget, gpointer data) {
    g_print(".\n");
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
    g_signal_connect(button, "clicked", G_CALLBACK(ac), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("<"); // Backspace
    g_signal_connect(button, "clicked", G_CALLBACK(say_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

    button = gtk_button_new_with_label("%"); // Porcentage
    g_signal_connect(button, "clicked", G_CALLBACK(porcentaje), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);

    button = gtk_button_new_with_label("÷"); // Division
    g_signal_connect(button, "clicked", G_CALLBACK(division), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 1, 1, 1);

    button = gtk_button_new_with_label("x"); // Multiplicacion
    g_signal_connect(button, "clicked", G_CALLBACK(multiplicacion), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 2, 1, 1);

    button = gtk_button_new_with_label("-"); // Resta
    g_signal_connect(button, "clicked", G_CALLBACK(resta), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 3, 1, 1);

    button = gtk_button_new_with_label("+"); // Suma
    g_signal_connect(button, "clicked", G_CALLBACK(suma), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 4, 1, 1);

    button = gtk_button_new_with_label("="); // Igual
    g_signal_connect(button, "clicked", G_CALLBACK(igual), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 3, 5, 1, 1);

    //for para crear los botones de los numeros (menos el 0)
    for (int i = 1; i < 10; i++) {
        button = gtk_button_new_with_label(g_strdup_printf("%d", i));
        g_signal_connect(button, "clicked", G_CALLBACK(saveNumber), GINT_TO_POINTER(i));
        gtk_grid_attach(GTK_GRID(grid), button, (i - 1) % 3, 4 - (i - 1) / 3, 1, 1);
    }

    button = gtk_button_new_with_label("0");
    g_signal_connect(button, "clicked", G_CALLBACK(saveNumber), GINT_TO_POINTER(0));
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 3, 1);

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