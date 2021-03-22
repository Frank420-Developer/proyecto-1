#include<conio.h>
#include<stdio.h>
#include<windows.h>
#define perfume 2
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
char op='s';
char pro[10];
int OP,contra,venta,OP2;
int i;
int contador = 0;
float precio, sum;
//Funciones utilizadas
void menu(void);
void entradas(void);
void guardarVisitas(void);
void leerVisitas(void);
void leerGanancia(void);
void guardarGanancia(void);
float calculaUtilidades(void);
void ventaProducto(void);
float mensualidad(void);


FILE *fana;
FILE *frodrigo;
FILE *fraul;
FILE *fGanancia;
FILE *fUtilidades;
FILE *fRegistro;

int visitasAna, visitasRodrigo, visitasRaul;
float utilidadesMes;
char cad[10]; 

typedef struct{
		char nombre[15];
		int contra;
		}Usuario;


main(){
	    	  
 	  Usuario ana, raul, rodrigo;
 	  //ana.nombre = "Ana";
 	  ana.contra = 123456;
 	  //rodrigo.nombre = "Rodrigo";
 	  rodrigo.contra = 2468;
 	  //raul.nombre = "Raul";
 	  raul.contra = 654321;
 	  
 	  leerVisitas();
 	  leerGanancia();
 	  
	      system("color 4b");
printf("\t\t\t\t\t PERFUMERIA");
printf("\n///////  /////////   //////////  ////////////// ////////////  /////    /////   ////////////");
printf("\n///      //    ///   ///    ///     ///////     //////        /////    /////   ////");
printf("\n///      //    ///   ///    ///     ///////     //////        /////    /////   ////");
printf("\n/////    /////////   //////////     ///////     //////        //////////////   ///////");
printf("\n///      //     ///  ///    ///     ///////     //////        /////    /////   ////");
printf("\n///      //      /// ///    ///  ////////////// ////////////  /////    /////   ////////////");
printf("\n\n");        
      system("PAUSE");
      system("cls");
      while(op=='s')
      {
      system("color 2f");
      do{
 	 			printf("\n1.Arturo \n2.Daniel \n3.Francisco ");
 	 			printf("\nInicio de sesion:");
 	 			fflush(stdin);
 	 			scanf("%i", & OP);
 	 			system("cls");
        }while(OP < 1 || OP >3);
      switch(OP)
      {
                 case 1:
                      {
   	 				   do
                      {                     
                      printf("\nIngrese su clave de seguridad: ");
                      fflush(stdin);
                      scanf("%i", & contra);
                      if(contra == ana.contra)
                      {
					   			system("cls");
                                printf("\n'ACEPTADA' \n");                      }
                      else
                      {
                          system("cls");
                          printf("\nClave incorrecta \n");
                      }
                       
                      }
                      while(contra != ana.contra);
                      visitasAna++;
					  menu();
            
						break;
						}
                          
                 case 2:
                      do
                      {                     
                      printf("\nIngrese su clave de seguridad: ");
                      fflush(stdin);
                      scanf("%i", & contra);
                      if(contra == rodrigo.contra)
                      {
					   			system("cls");
                                printf("\n'ACEPTADA' \n");                 
                      }
                      else
                      {
                          system("cls");
                          printf("\nClave incorrecta");
                      }
                       
                      }
                      while(contra != rodrigo.contra);
                      visitasRodrigo++;
                      menu();
                          break;
                 case 3:
                      do
                      {                     
                      printf("\nIngrese su clave de seguridad: ");
                      fflush(stdin);
                      scanf("%i", & contra);
                      if(contra == raul.contra)
                      {
					   			system("cls");
                                printf("\n'ACEPTADA' \n");                 
                      }
                      else
                      {
                          system("cls");
                          printf("\nClave incorrecta");
                      }
                       
                      }
                      while(contra != raul.contra);
                      visitasRaul++;
                      menu();
                      
                      
                          break;
                 default:
                         break;
      }
										  
	  guardarVisitas();
	  printf("\n Desea realizar otra accion nuevamente?   s=si   n=no");
	  scanf("%c",&op);
	  op=getch();
	  system("cls");
	  }
}


void menu(void){
do{
   	 system("cls");
   	 printf("\n1 Venta de producto \n2 Registo de productos \n3 Ganancia total del mes \n4 Chequeo de entradas mensuales\n ");
   	 printf("\nSeleccione su opcion deseada:");
		fflush(stdin);
   	 scanf("%i", & OP2);
}while(OP2 < 1 || OP2 > 4);

                      switch( OP2)
                      {
                       case 1:
					   		  ventaProducto();
							   break;
							
						
                         case 2:    
								calculaUtilidades();
                              break;
								
						case 3:
							    mensualidad();
							   break;             
						case 4:
							   entradas();
							   break;
                                                 
                         default:
                              break;
                       
                     
						
}
}

void entradas(void){
	 
	 printf("\nVisitas de Arturo: %i", visitasAna);
	 printf("\nVisitas de Daniel: %i", visitasRodrigo);
	 printf("\nVisitas de Francisco: %i", visitasRaul);
	 
}

void leerVisitas(void){
	 fana = fopen("UAna.txt", "r+");
	 frodrigo = fopen("URodrigo.txt", "r+");
	 fraul = fopen("URaul.txt", "r+");
	 
	 visitasAna =  atoi(fgets(cad, 10, fana));
	 visitasRodrigo =  atoi(fgets(cad, 10, frodrigo));
	 visitasRaul =  atoi(fgets(cad, 10, fraul));
	 
	 fclose(fana);
	 fclose(frodrigo);
	 fclose(fraul);
}

void guardarVisitas(void){
	 fana = fopen("UAna.txt", "w");
      frodrigo = fopen("URodrigo.txt", "w");
      fraul = fopen("URaul.txt", "w");
      
	  fprintf(fana, "%i", visitasAna);
	  fprintf(frodrigo, "%i", visitasRodrigo);
	  fprintf(fraul, "%i", visitasRaul); 
	  
	  fclose(fana);
	  fclose(frodrigo);
	  fclose(fraul);
}
void leerGanancia(void){
	 fUtilidades = fopen("Gananciamensual.txt", "r+");
	 utilidadesMes =  atof(fgets(cad, 10, fUtilidades));
	 fclose(fUtilidades);
}

void guardarGanancia(void){
	 fUtilidades=fopen("Gananciamensual.txt","w");
	 fprintf(fUtilidades, "%.2f", utilidadesMes);
	 fclose(fUtilidades);
}

void ventaProducto(void){
	 printf("\n cuantos productos vendera?");
	 scanf("%i",&venta);
	 for(i=0;i<=venta-1;i++){
	 						 printf("\n ingrese el tipo de producto %i:",i+1);
	 						 scanf("%s",&pro[i]);
	 						 printf("\n ingrese el precio del producto %i:$",i+1);
	 						 scanf("%f",&precio);
	 						 sum=sum+precio;
							  }		
							  printf("El precio total a pagar es de:$%.2f",sum);
							  utilidadesMes = utilidadesMes + sum;
							  guardarGanancia();
}

float mensualidad(void){
	  printf("\nLas utilidades totales del mes son: %.2f", utilidadesMes);
}

float calculaUtilidades(void){
	  char cad[10];
	  float inventario;
	  
	fRegistro = fopen("Registro.txt", "a");
	//inventario =  atof(fgets(cad, 10, fGanancia));
	struct inventario {
char nombre[20];
unsigned int precio;
unsigned int existencias;
};

struct inventario accede[perfume];

int i;
printf("\n¿Cuantos productos ingresara? ");
scanf("%i", & i);
for ( contador = 0; contador < i; contador++ ) {
printf("Introduzca el nombre del producto %i: ", contador + 1);
scanf("%s", &accede[contador].nombre );
printf("Introduzca el precio del producto %s: ", accede[contador].nombre );
scanf("%i" , &accede[contador].precio );
printf("Introduzca el numero de existencias de %s: ", accede[contador].nombre );
scanf("%i", &accede[contador].existencias );
printf("\n");

fprintf(fRegistro,"\nNombre: %s \nPrecio: %i\nExistencias: %i\n" , accede[contador].nombre, accede[contador].precio,
accede[contador].existencias);

/*
ofstream archivo;
archivo.open("Registro.txt");
 archivo << "Nombre del producto: " << accede[contador].nombre << endl;
 archivo << "Precio: " << accede[contador].precio << endl;
 archivo << "Existencias: " << accede[contador].existencias << endl;
 system("pause>>null");
*/

}




//fprintf(fGanancia,"\nNombre: %s \nPrecio: %i\nExistencias: %i\n" , accede[contador].nombre, accede[contador].precio,
//accede[contador].existencias);


//return 0;
//return inventario;
fclose(fRegistro);
}
