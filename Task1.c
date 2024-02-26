#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Motor {
    int cod;
    char* denumire;
    int nrPiese;
    float* preturi;
};

// Funcție pentru citirea unui obiect de tipul Motor de la tastatură
struct Motor citeste_motor() {
    struct Motor motor;

    printf("Introduceti codul motorului: ");
    scanf("%d", &motor.cod);

    printf("Introduceti denumirea motorului: ");
    motor.denumire = (char*)malloc(100 * sizeof(char));
    scanf("%s", motor.denumire);

    printf("Introduceti numarul de piese: ");
    scanf("%d", &motor.nrPiese);

    motor.preturi = (float*)malloc(motor.nrPiese * sizeof(float));
    printf("Introduceti preturile pieselor:\n");
    for (int i = 0; i < motor.nrPiese; i++) {
        printf("Pretul piesei %d: ", i + 1);
        scanf("%f", &motor.preturi[i]);
    }

    return motor;
}

// Funcție pentru calcularea mediei prețurilor pieselor de pe un motor
float calculeaza_medie_preturi(struct Motor motor) {
    float suma = 0;
    for (int i = 0; i < motor.nrPiese; i++) {
        suma += motor.preturi[i];
    }
    return suma / motor.nrPiese;
}

// Funcție pentru modificarea numărului de piese de pe un motor
void modifica_nr_piese(struct Motor* motor, int nou_nr_piese) {
    motor->nrPiese = nou_nr_piese;
    motor->preturi = (float*)realloc(motor->preturi, nou_nr_piese * sizeof(float));
}

// Funcție pentru afișarea informațiilor despre un motor
void afiseaza_motor(struct Motor motor) {
    printf("Cod: %d\n", motor.cod);
    printf("Denumire: %s\n", motor.denumire);
    printf("Numar piese: %d\n", motor.nrPiese);
    printf("Preturi piese:\n");
    for (int i = 0; i < motor.nrPiese; i++) {
        printf("Piesa %d: %.2f\n", i + 1, motor.preturi[i]);
    }
}

int main() {
    struct Motor motor = citeste_motor();
    printf("Media preturilor pieselor de pe motor este: %.2f\n", calculeaza_medie_preturi(motor));

    // Modificăm numărul de piese de pe motor
    modifica_nr_piese(&motor, 6);

    printf("Dupa modificare:\n");
    afiseaza_motor(motor);

    // Eliberăm memoria alocată dinamic
    free(motor.denumire);
    free(motor.preturi);

    return 0;
}