#include <stdio.h>
int main() {   
    int S; //Nu´mero de sonidos emitidos por la chicharra
    int FA; //Fahrenheit
    int CEL; //Celsius

    printf("Ingrese nu´mero de sonidos emitidos por la chicharra: ");  
    scanf("%d", &S);

    FA = S/4+40;
    CEL = (FA-32) * 5/9;

    printf("Grados de la chicharra: %d °C", CEL);
    
    return 0;
}
