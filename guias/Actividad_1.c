#include <stdio.h>
int main() {   
    int CLA; //clave del trabajador
    int CAT; //categoría del empleado
    int ANT; //antigu¨edad del trabajador
    int RES = 0; //condiciones

    printf("Clave del trabajador: ");  
    scanf("%d",&CLA);

    printf("Categoria del empleado: ");  
    scanf("%d",&CAT);

    printf("Antiguedad del trabajador: ");  
    scanf("%d",&ANT);

    if ((CAT > 2) && (CAT < 5) && (ANT > 5))
    {
        // Cumple las condiciones
        RES = 1;
    }else if((CAT == 2) && (ANT > 7)){
        // Cumple las condiciones
        RES = 1;
    }
    
    if(RES == 1){
        printf("El empleado clave %d cumple las condiciones", CLA);
    }else{
        printf("El empleado clave %d no Cumple las condiciones", CLA);
    }
    
    return 0;
}
