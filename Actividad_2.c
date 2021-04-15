#include <stdio.h>
#include <string.h>

int main(){
    char cad[50];
    int i;
    int j;
    int n=0;
    int mult;
    
    printf("Ingrese cadena:\n");
    scanf("%s",&cad);
    printf("Cadena es: %s\n",cad);
    
    for(i=0;i<50;i++){
        if(i==n){
            mult=cad[i]-48;
            n=n+2;
        }else{
            j=0;
            do{
                printf("%c",cad[i]);
                j++;
            }while(j<mult);
        }
    }
        printf("\n");
    return 0;
}
