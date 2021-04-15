#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double * getrandom(){
	static double r[24];
	int i;
	
	double random_value;

    srand ( time ( NULL));

    for(i=0;i<24;i++){
    	r[i] = ((double)rand()/RAND_MAX*2.0-1.0)*40;//float in range -1 to 1
        printf ( "%f\n", r[i]);
	}
    return r;
	} 

int main(){
	double *TEM;
	int i;
	double suma = 0;
	double TEM_PROMEDIO;
	double TEM_MAYOR=-40;
	double TEM_MENOR=40;
	int TEM_MENOR_h;
	int TEM_MAYOR_h;
	
	TEM = getrandom();
	
	for(i=0; i<24; i++){
		printf("Temperatura Nª%d: %fºC\n",(i+1),*(TEM+i));
		suma=suma+TEM[i];
		if(TEM[i]<TEM_MENOR){
			TEM_MENOR=TEM[i];
			TEM_MENOR_h=i+1;
		}
		if(TEM[i]>TEM_MAYOR){
			TEM_MAYOR=TEM[i];
			TEM_MAYOR_h=i+1;
		}
	}
	TEM_PROMEDIO=suma/i;
	printf("La temperatura promedio fue de: %lfºC\nLa temperatura mayor fue de: %lfºC a las %dhrs\nLa temperatura menor fue de: %lfºC a las %dhrs",TEM_PROMEDIO,TEM_MAYOR,TEM_MAYOR_h,TEM_MENOR,TEM_MENOR_h);
}
