#include <stdio.h>
#include "funciones.h"

int main() {
    char clientes[5][2][40] = {
        {"Juan", "1789654123"},
        {"", ""},
        {"", ""},
        {"", ""},
        {"", ""}
    };

    char habitaciones[9][3][40] = {
        {"1", "simple", "Dan_Carlton"},
        {"2", "doble", "Dan_Carlton"},
        {"3", "triple", "Dan_Carlton"},
        {"4", "simple", "Swissotel"},
        {"5", "doble", "Swissotel"},
        {"6", "triple", "Swissotel"},
        {"7", "simple", "Sheraton"},
        {"8", "doble", "Sheraton"},
        {"9", "triple", "Sheraton"}
    };

    double precios[9] = {90, 120, 160, 65, 100, 140, 85, 110, 150};

    int reservas[10][4] = {
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0},
        {-1, -1, -1, 0}
    };

    int opcion, numHabitacion, numReserva;
    do {
        printf("\nEscoja una opcion:\n1. Buscar Habitacion\n2. Realizar reserva\n3. Ver reservas\n4. Pagar Reserva\n>> ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("1. Por tamaño\n2. Por Hotel\n>> ");
                scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                        buscarPorTamano(&numHabitacion, habitaciones, precios);
                        break;
                    case 2:
                        buscarHotel(&numHabitacion, habitaciones, precios);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                realizarReserva(numHabitacion, habitaciones, clientes, reservas);
                break;
            case 3:
                buscarReservaPorCedula(&numReserva, clientes, reservas);
                imprimirReserva(numReserva, reservas, habitaciones, precios, clientes);
                break;
            case 4:
                buscarReservaPorCedula(&numReserva, clientes, reservas);
                pagarReserva(numReserva,reservas,habitaciones,precios);
                break;
            default:
                break;

        }
        printf("Desea elegir otra opcion\n1.Si\n2.No\n>>");
        scanf("%d", &opcion);
    } while (opcion == 1);

    return 0;
}
