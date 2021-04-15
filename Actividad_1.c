#include <stdio.h>
#include <string.h>

int main(){
    char cad[50];
    char car;
    int i;
    int contador=0;
    
    
    printf("Inserte cadena de caracteres:\n");
    scanf("%s", &cad);
    
    printf("Inserte caracter a contar:\n");
    scanf("%s", &car);
    
    for(i=0;i<50;i++){
        if(cad[i]==car){
            contador++;
        }
    }
    printf("La cantidad de letras %c presentes en el arreglo ingresado es de: %d\n",car,contador);
    return 0;
}
