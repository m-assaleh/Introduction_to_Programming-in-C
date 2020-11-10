#include <stdio.h>
#include <stdlib.h>
#include "input.h" // Hier binden wir die Bibliothek ein


int fibonacci(int number) {

    int f;

    if (number == 1 || 2) { f = 1; }
    
    else 
    {    f = fibonacci(number-1) + fibonacci(number-2); 
    
    return f;
  }
}

int main(){
    int n = lese_int(); // Hier rufen wir die Funktion lese_int auf.
    int f = fibonacci(n);
    printf("Fib(%d) = %d\n" , n, f); 

    return 0; //Beende das Programm ohne Fehlermeldung
}
