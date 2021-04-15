#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   FILE * fp;
   char data[100000];

   fp = fopen ("data2.txt", "r");
   fscanf( fp, " %[^\n]",&data);
   printf("Informacion Ingresada:\n%s\n",data);
   fclose(fp);
 
   int i;
   
   for(i=0;i<100;i++){
       if(data[i]=='7'){
           if(data[i+1]=='E'){
               if(data[i+2]=='B'){
                   if(data[i+3]=='3'){
                        printf("\nRouter 1:\n");
                        printf("Temperatura Ambiente: %c%c\n",data[i+19],data[i+20]);
                    }else{
                        printf("\nRouter 2:\n");
                        printf("Humedad: %c%c%c\n",data[i+19],data[i+20],data[i+21]);
                    }
                   printf("Trama: ");
               }
           }
           
       }
       printf("%c",data[i]);
   }

   return(0);
}
