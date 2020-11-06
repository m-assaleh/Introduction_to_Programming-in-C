#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int nummer = 105; // Die probierten Werte
    printf("Ist %d eine Primzahl?\n", nummer);
    // 1 ist keine Primzahl
    if (nummer == 1) { printf("nein\n");
        return 0;
    }

    for (int i = 2; i <= sqrt(nummer); i++)
        if (nummer % i == 0) {
            printf("Nein\n");
            return 0;
        }
    printf("Ja\n");
    return 0;

}