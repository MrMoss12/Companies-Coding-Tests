#include <stdio.h>
#include <string.h>

// Función para encontrar la distancia máxima al más cercano
int maxDistToClosest(int* seats, int seatsSize) {
    int maxDist = 0;
    int lastPerson = -1;
    
    // Primera pasada para calcular las distancias máximas
    for (int i = 0; i < seatsSize; i++) {
        if (seats[i] == 1) {
            if (lastPerson == -1) {
                // Distancia desde el principio hasta el primer `1`
                maxDist = i;
            } else {
                // Distancia entre dos `1`s consecutivos
                maxDist = (i - lastPerson) / 2 > maxDist ? (i - lastPerson) / 2 : maxDist;
            }
            lastPerson = i;
        }
    }
    
    // Distancia desde el último `1` hasta el final
    if (seats[seatsSize - 1] == 0) {
        maxDist = (seatsSize - 1 - lastPerson) > maxDist ? (seatsSize - 1 - lastPerson) : maxDist;
    }
    
    return maxDist;
}

int main() {
    char seatsStr[20001];
    scanf("%s", seatsStr); // Leer la cadena de asientos desde el input estándar
    
    int seatsSize = strlen(seatsStr);
    int seats[seatsSize];
    
    // Convertir la cadena de caracteres a un arreglo de enteros
    for (int i = 0; i < seatsSize; i++) {
        seats[i] = seatsStr[i] - '0';
    }
    
    int maxDistance = maxDistToClosest(seats, seatsSize);
    printf("%d\n", maxDistance); // Imprimir la distancia máxima
    
    return 0;
}
