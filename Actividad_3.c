#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
/* funcion para obtener numeros random */ 
int * getRandom() { 
  static int r[255];
  int i;
 
  srand( (unsigned)time( NULL ) ); 
    for ( i = 0; i < 256; ++i) { 
    r[i] = rand() % (255 + 1 - 0) + 0 ; //se limita al intervalo 0-255
    printf( "r[%d] = %d\n", i, r[i]);
  }
 
  return r; 
}
/* funcion para transformar a binario */  
int * bin(unsigned n){
    static int b[8];
    int limit = 128; //debido a que el intervalo esta limitado a 255, 128 es el bit mayor
    int c = 0;
    for ( c = 0; c < 8; ++c){ 
        if ((n > 1) && (n >= limit)){
            n = (n - limit);
            b[c] = 1;
        }else if((n == 1) && (c == 7)){
            b[c] = 1;
        }else{
            b[c] = 0;
        }
        limit = (limit / 2);
        printf( "%d", b[c]);
    }
    printf("\n");
    for ( c = 0; c < 8; ++c){ 
        printf( "%d ", b[c]);
    }
    printf("\n");
    return b;
}

int main (){
    int x;
    int *ran = getRandom();

    for ( x = 0; x < 256; x++){
        int *p;
        int i;
        printf( "----------------------\n");
        printf( "Decimal ingresado: %d\n", *(ran + x));
        p = bin(*(ran + x));
        int c = 0;
        for ( i = 7; i >= 0; i-- ){
            if(*(p + i) == 1){
                printf( "Led %d: ON\n", c); 
            }else{
                printf( "Led %d: OFF\n", c);
            }
            c++;
        }
    }
    return 0;
} 
