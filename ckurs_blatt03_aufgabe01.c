#include <stdio.h>

int main() {
    int breite = 6;
    int hoehe = 3;

    for (int i = 0; i < breite+2; i++) {
        printf("A");
    }

    printf("\n");

    for (int i = 0; i < hoehe; i++) {
        printf("A");
        for (int i = 0; i < breite; ++i) {
            printf("B");
        }
    printf("A\n");
    }

    for (int i = 0; i < breite+2; ++i) {
        printf("A");
    }
    return 0;
}
