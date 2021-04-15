#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int Cantidad_notas;                                        //lA CANTIDAD DE NOTAS A TRATAR
	printf("Inserte cantidad de notas a evaluar:\n");
	scanf("%d", &Cantidad_notas);
	
	if((Cantidad_notas>0)&&(Cantidad_notas<101)){             //INSERTAR NOTAS
		int i=0;
		int suma=0;
	    int Vector_Notas[Cantidad_notas];
		printf("Inserte Notas:\n");
        do{
			scanf("%d",&Vector_Notas[i]);
        	suma=suma+Vector_Notas[i];
        	i++;
        	fflush( stdin );
		}while(i<=(Cantidad_notas-1));
        
		for(i=0;i<Cantidad_notas;i++){                                //NOTAS INGRESADAS
        	printf("Nota %d es: %d\n",i,Vector_Notas[i]);
		}
		
		
		printf("Suma: %d\n",suma);

		float media_aritmetica;
		media_aritmetica=suma/(double)Cantidad_notas;                //MEDIA ARITMETICA
		printf("La media aritmética es: %f\n",media_aritmetica);
		
		
		i=0;
		float aux;                                                   //(Xi+media)^2
		float aux2 = 0;                                             //Sumatoria -> (Xi+media)^2
		while(i<Cantidad_notas){
			aux=(Vector_Notas[i]-media_aritmetica);
			aux=pow(aux,2);
			aux2=aux2+aux;
			i++;			
		}
		double varianza;
		varianza=aux2/Cantidad_notas;                               //VARIANZA
		printf("La varianza es: %lf\n",varianza);
		double desviacion_estandar=sqrtf(varianza);                        //DESVIACION ESTANDAR
		printf("La desviacion estandar es: %lf\n",desviacion_estandar);
		
		i=0;
		int j;
		int contador=0;                                          
		int Vector_contador[(Cantidad_notas-1)];                     
		do{
			j=0;
			while(j<Cantidad_notas){
				if(Vector_Notas[i]==Vector_Notas[j]){
					contador++;                          //CANTIDAD DE VECES QUE SE REPITE UNA NOTA
					j++;
				}else{
					j++;
				}
			}
			Vector_contador[i]=contador;                          //SE DEFINE QUÉ NOTA FUE LA QUE SE REPITIÓ
			contador=0;
			i++;
		}while(i<=(Cantidad_notas-1));
		
/*		for(i=0;i<Cantidad_notas;i++){
        	printf("Cantidad de Notas %d es: %d\n",Vector_Notas[i],Vector_contador[i]);       //TODO BIEN
		}
*/		
	
		i=0;
		j=i+1;
		int Vector_modas[(Cantidad_notas-1)];
		int k=0;
		Vector_modas[k]=Vector_Notas[i];
		int m1, m2;
		
		while(j<=(Cantidad_notas-1)){
			if(Vector_contador[i]>Vector_contador[j]){             //QUE PASA SI CANTIDAD DE NOTAS DE LA IZQUIERA ES MAYOR A LA DE LA DERECHA
				j++;
			}else if(Vector_contador[i]<Vector_contador[j]){             //QUE PASA SI CANTIDAD DE NOTAS DE LA DERECHA ES MAYOR A LA DE LA IZQUIERDA
				k=0;
				Vector_modas[k]=Vector_Notas[j];
				i=j;
				j++;
			}else if(Vector_contador[i]==Vector_contador[j]){            //QUE PASA SI AMBAS NOTAS TIENEN LA MISMA CANTIDAD
				if(Vector_Notas[i]==Vector_Notas[j]){
					j++;
				}else{
					if(k==0){
						k++;
						Vector_modas[k]=Vector_Notas[j];
						j++;
					}else{
						m1=0;
						m2=0;
						for(m1=0;m1<=k;m1++){
							if(Vector_modas[m1]==Vector_Notas[j]){
							    m2=1;                                         //aux2=1 -> Moda ya está incluída
					    	}
						}
						if(m2==0){
							k++;
							Vector_modas[k]=Vector_Notas[j];
				     	}   
				    	j++;
			    	}
		    	}	
	        }	    
    	}
        
		do{
        	printf("La moda es: %d\n",Vector_modas[k]);
         	k--;
    	}while(k>=0);

	}else{
		printf("Cantidad de notas fuera del rango.\n");
	}
    return 0;
}
