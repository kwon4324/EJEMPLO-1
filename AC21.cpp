#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

void playWelcomeSound() {
    // Reproduce un sonido de bienvenida (solo en Windows)
    Beep(523, 300);  // Do (C5)
    Sleep(100);
    Beep(659, 300);  // Mi (E5)
    Sleep(100);
    Beep(784, 300);  // Sol (G5)
    Sleep(100);
    Beep(1047, 500); // Do agudo (C6)
}

void mostrarPortada() {
    system("cls"); // Limpiar pantalla
    system("color 0B"); // Fondo negro, texto cian claro
    
    cout << "\n";
    cout << "  " << char(201);
    for(int i = 0; i < 78; i++) cout << char(205);
    cout << char(187) << "\n";
    
    cout << "  " << char(186) << setw(39) << "FES ACATLAN" << setw(40) << char(186) << "\n";
    cout << "  " << char(186) << setw(50) << "UNIVERSIDAD NACIONAL AUTONOMA DE MEXICO" << setw(29) << char(186) << "\n";
    cout << "  " << char(186) << setw(48) << "MATEMATICAS APLICADAS Y COMPUTACION" << setw(31) << char(186) << "\n";
    
    cout << "  " << char(204);
    for(int i = 0; i < 78; i++) cout << char(205);
    cout << char(185) << "\n";
    
    cout << "  " << char(186) << string(78, ' ') << char(186) << "\n";
    cout << "  " << char(186) << setw(50) << "PROGRAMACION ORIENTADA A OBJETOS" << setw(29) << char(186) << "\n";
    cout << "  " << char(186) << setw(39) << "UNIDAD 1" << setw(40) << char(186) << "\n";
    cout << "  " << char(186) << setw(41) << "PRACTICA 1" << setw(38) << char(186) << "\n";
    cout << "  " << char(186) << string(78, ' ') << char(186) << "\n";
    
    cout << "  " << char(204);
    for(int i = 0; i < 78; i++) cout << char(205);
    cout << char(185) << "\n";
    
    cout << "  " << char(186) << setw(48) << "PROFESORA: ESLAVA GARCIA GEORGINA" << setw(31) << char(186) << "\n";
    cout << "  " << char(186) << string(78, ' ') << char(186) << "\n";
    cout << "  " << char(186) << setw(44) << "INTEGRANTES DEL EQUIPO:" << setw(35) << char(186) << "\n";
    cout << "  " << char(186) << string(78, ' ') << char(186) << "\n";

    cout << "  " << char(186) << "    * LOPEZ CHAVEZ FABIAN URIEL - 424117210" << setw(36) << char(186) << "\n";
    cout << "  " << char(186) << "    * REYES GONZALEZ DIEGO DE JESUS - 424135339" << setw(32) << char(186) << "\n";
    cout << "  " << char(186) << string(78, ' ') << char(186) << "\n";
    
    cout << "  " << char(204);
    for(int i = 0; i < 78; i++) cout << char(205);
    cout << char(185) << "\n";
    
    cout << "  " << char(186) << setw(41) << "GRUPO: 1301" << setw(38) << char(186) << "\n";
    cout << "  " << char(186) << setw(45) << "TERCER SEMESTRE" << setw(34) << char(186) << "\n";
    cout << "  " << char(186) << setw(43) << "TURNO: MATUTINO" << setw(36) << char(186) << "\n";
    cout << "  " << char(186) << setw(41) << "AGOSTO 2025" << setw(38) << char(186) << "\n";
    
    cout << "  " << char(200);
    for(int i = 0; i < 78; i++) cout << char(205);
    cout << char(188) << "\n";
    

    // Reproducir sonido
    playWelcomeSound();
    
    cout << " \n\n BIENVENIDO AL REGISTRO DE CLIENTES...\n\n";
    getch();
}

// =============== AGENDA DE CONTACTOS DE CLIENTES ===============
// (Sin modificar estructura, sin acentos, con mensaje de vacío)

#include <stdio.h>
#include <string.h>

enum opciones {
    almacenar = 1,
    listar,
    buscar,
    borrar,
    modificar,
    salir
};

class Cliente {
private:
    char numCuenta[80];
    char nombre[80];
    char direccion[80];
    char telefono[80];

public:
    Cliente() {
        strcpy(numCuenta, "");
        strcpy(nombre, "");
        strcpy(direccion, "");
        strcpy(telefono, "");
    }

    void leeCliente() {
        cout << "\nNumero de cuenta: ";
        fflush(stdin);
        fgets(numCuenta, 80, stdin);
        numCuenta[strcspn(numCuenta, "\n")] = 0;

        cout << "\nNombre del cliente: ";
        fflush(stdin);
        fgets(nombre, 80, stdin);
        nombre[strcspn(nombre, "\n")] = 0;

        cout << "\nDireccion: ";
        fflush(stdin);
        fgets(direccion, 80, stdin);
        direccion[strcspn(direccion, "\n")] = 0;

        cout << "\nTelefono: ";
        fflush(stdin);
        fgets(telefono, 80, stdin);
        telefono[strcspn(telefono, "\n")] = 0;
    }

    void imprimeCliente() {
        cout << "\nNumero de cuenta: " << numCuenta;
        cout << "\nNombre: " << nombre;
        cout << "\nDireccion: " << direccion;
        cout << "\nTelefono: " << telefono << endl;
    }

    void guardar() {
        FILE *f;
        f = fopen("agendaClientes.txt", "a");
        if (f == NULL) {
            cout << "\nError en apertura de archivo";
            getch();
            return;
        }

        leeCliente();

        fprintf(f, "\n%s", numCuenta);
        fprintf(f, "\n%s", nombre);
        fprintf(f, "\n%s", direccion);
        fprintf(f, "\n%s", telefono);

        fclose(f);
        cout << "\nCliente guardado con exito.";
        getch();
    }

    void listarClientes() {
        FILE *list;
        list = fopen("agendaClientes.txt", "r");
        if (list == NULL) {
            cout << "\nAgenda de clientes vacia, favor de ingresar el contacto del primer cliente";
            getch();
            return;
        }

        // Verificar si el archivo está vacío
        fseek(list, 0, SEEK_END);
        long tam = ftell(list);
        if (tam == 0) {
            fclose(list);
            cout << "\nAgenda de clientes vacia, favor de ingresar el contacto del primer cliente";
            getch();
            return;
        }

        rewind(list);
        cout << "\n--- LISTADO DE CLIENTES ---\n";

        while (!feof(list)) {
            if (fscanf(list, "\n%79[^\n]", numCuenta) != 1) break;
            if (fscanf(list, "\n%79[^\n]", nombre) != 1) break;
            if (fscanf(list, "\n%79[^\n]", direccion) != 1) break;
            if (fscanf(list, "\n%79[^\n]", telefono) != 1) break;

            imprimeCliente();
        }

        fclose(list);
        getch();
    }

    void buscarCliente() {
        char num[80];
        int centinela = 0;

        FILE *buscar;
        buscar = fopen("agendaClientes.txt", "r");
        if (buscar == NULL) {
            cout << "\nAgenda de clientes vacia, favor de ingresar el contacto del primer cliente";
            getch();
            return;
        }

        cout << "\nDar el numero de cuenta a buscar: ";
        fflush(stdin);
        fgets(num, 80, stdin);
        num[strcspn(num, "\n")] = 0;

        while (!feof(buscar)) {
            if (fscanf(buscar, "\n%79[^\n]", numCuenta) != 1) break;
            if (fscanf(buscar, "\n%79[^\n]", nombre) != 1) break;
            if (fscanf(buscar, "\n%79[^\n]", direccion) != 1) break;
            if (fscanf(buscar, "\n%79[^\n]", telefono) != 1) break;

            if (strcmp(numCuenta, num) == 0) {
                cout << "\nCliente encontrado:\n";
                imprimeCliente();
                getch();
                centinela = 1;
            }
        }

        if (centinela == 0) {
            cout << "\nCliente no encontrado.";
            getch();
        }

        fclose(buscar);
    }

    void borrarCliente() {
        char num[80];
        int centinela = 0;
        FILE *borrar, *aux;

        borrar = fopen("agendaClientes.txt", "r");
        if (borrar == NULL) {
            cout << "\nAgenda de clientes vacia, favor de ingresar el contacto del primer cliente";
            getch();
            return;
        }

        aux = fopen("borrame.txt", "w");
        if (aux == NULL) {
            cout << "\nError de escritura de archivo temporal";
            getch();
            return;
        }

        cout << "\nDar el numero de cuenta del cliente a borrar: ";
        fflush(stdin);
        fgets(num, 80, stdin);
        num[strcspn(num, "\n")] = 0;

        while (!feof(borrar)) {
            if (fscanf(borrar, "\n%79[^\n]", numCuenta) != 1) break;
            if (fscanf(borrar, "\n%79[^\n]", nombre) != 1) break;
            if (fscanf(borrar, "\n%79[^\n]", direccion) != 1) break;
            if (fscanf(borrar, "\n%79[^\n]", telefono) != 1) break;

            if (strcmp(numCuenta, num) == 0) {
                cout << "\nCliente eliminado:\n";
                imprimeCliente();
                getch();
                centinela = 1;
            } else {
                fprintf(aux, "\n%s", numCuenta);
                fprintf(aux, "\n%s", nombre);
                fprintf(aux, "\n%s", direccion);
                fprintf(aux, "\n%s", telefono);
            }
        }

        if (centinela == 0) {
            cout << "\nCliente no encontrado.";
            getch();
        }

        fclose(borrar);
        fclose(aux);
        remove("agendaClientes.txt");
        rename("borrame.txt", "agendaClientes.txt");
    }

    void modificar() {
        char num[80];
        int centinela = 0;
        FILE *modi, *aux;

        modi = fopen("agendaClientes.txt", "r");
        if (modi == NULL) {
            cout << "\nAgenda de clientes vacia, favor de ingresar el contacto del primer cliente";
            getch();
            return;
        }

        aux = fopen("borrame.txt", "w");
        if (aux == NULL) {
            cout << "\nError de escritura de archivo temporal";
            getch();
            return;
        }

        cout << "\nDar el numero de cuenta del cliente a modificar: ";
        fflush(stdin);
        fgets(num, 80, stdin);
        num[strcspn(num, "\n")] = 0;

        while (!feof(modi)) {
            if (fscanf(modi, "\n%79[^\n]", numCuenta) != 1) break;
            if (fscanf(modi, "\n%79[^\n]", nombre) != 1) break;
            if (fscanf(modi, "\n%79[^\n]", direccion) != 1) break;
            if (fscanf(modi, "\n%79[^\n]", telefono) != 1) break;

            if (strcmp(numCuenta, num) == 0) {
                cout << "\nCliente encontrado:\n";
                imprimeCliente();

                int opcimodi;
                do {
                    cout << "\n--- MODIFICAR ---\n";
                    cout << "1. Modificar numero de cuenta\n";
                    cout << "2. Modificar nombre\n";
                    cout << "3. Modificar direccion\n";
                    cout << "4. Modificar telefono\n";
                    cout << "5. Salir de modificar\n";
                    cout << "Elija opcion: ";
                    cin >> opcimodi;

                    switch (opcimodi) {
                        case 1:
                            cout << "\nNuevo numero de cuenta: ";
                            fflush(stdin);
                            fgets(numCuenta, 80, stdin);
                            numCuenta[strcspn(numCuenta, "\n")] = 0;
                            break;

                        case 2:
                            cout << "\nNuevo nombre: ";
                            fflush(stdin);
                            fgets(nombre, 80, stdin);
                            nombre[strcspn(nombre, "\n")] = 0;
                            break;

                        case 3:
                            cout << "\nNueva direccion: ";
                            fflush(stdin);
                            fgets(direccion, 80, stdin);
                            direccion[strcspn(direccion, "\n")] = 0;
                            break;

                        case 4:
                            cout << "\nNuevo telefono: ";
                            fflush(stdin);
                            fgets(telefono, 80, stdin);
                            telefono[strcspn(telefono, "\n")] = 0;
                            break;

                        case 5:
                            cout << "\nSaliendo de modificar...";
                            getch();
                            break;

                        default:
                            cout << "\nOpcion no valida.";
                            getch();
                    }
                } while (opcimodi != 5);

                centinela = 1;
            }

            fprintf(aux, "\n%s", numCuenta);
            fprintf(aux, "\n%s", nombre);
            fprintf(aux, "\n%s", direccion);
            fprintf(aux, "\n%s", telefono);
        }

        if (centinela == 0) {
            cout << "\nCliente no encontrado.";
            getch();
        }

        fclose(modi);
        fclose(aux);
        remove("agendaClientes.txt");
        rename("borrame.txt", "agendaClientes.txt");
    }
};

int main() {
    // Mostrar portada con sonido
    mostrarPortada();

    // Iniciar la agenda después de la portada
    int opci;
    Cliente cliente1;

    do {
        cout << "\n--- AGENDA DE CONTACTOS DE CLIENTES ---\n";
        cout << "1. Guardar cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Buscar cliente\n";
        cout << "4. Borrar cliente\n";
        cout << "5. Modificar cliente\n";
        cout << "6. Salir\n";
        cout << "Elija opcion: ";
        cin >> opci;

        switch (opci) {
            case almacenar:
                cliente1.guardar();
                break;

            case listar:
                cliente1.listarClientes();
                break;

            case buscar:
                cliente1.buscarCliente();
                break;

            case borrar:
                cliente1.borrarCliente();
                break;

            case modificar:
                cliente1.modificar();
                break;

            case salir:
                cout << "\nFin de Ejecucion\n";
                break;

            default:
                cout << "\nOpcion incorrecta\n";
                getch();
        }
    } while (opci != salir);

    return 0;
}
