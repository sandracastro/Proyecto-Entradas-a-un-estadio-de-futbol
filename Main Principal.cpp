/*
										UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
								Sistema para Ventas de entradas de un estadio de Fútbol
				
				Autores: 				Bryan Tualle y	Sandra Castro
				Fecha de Creación:		21/11/2017
				Fecha de modificacion:	22/11/2017
				Docente: 				Ing. Edgar Fernando Solis Acosta
				Carrera: 				Ing. Sistemas e Informática
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>
#include "colores.h"

// ATRBUTOS PROPIOS DEL PROGRAMA

	// Declaración de los prototipos 
void gotoxy(int ,int );
void portada();
void menu_seleccion(const char *[], int );



// DESARROLLO DE LOS MÉTODOS DEL PROGRAMA
void portada()
{
	printf("\n\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	printf("\n\t\t\t\t\t\tESTRUCTURA DE DATOS 2479");
	printf("\n\t\t\t\t      SISTEMA DE VENTAS PARA UN ESTADIO DE FUTBOL");
	printf("\n\n\t\tAutores:\t Bryan Tualle  y  Sandra Castro");
	printf("\n\t\tFecha:\t\t 2017/11/21");
	printf("\n\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta");
	printf("\n\t\tCarrera:\t Ing. Sistemas e informatica");

}

void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void menu_seleccion(const char *opciones[], int numeroOpciones)
{
	bool repite=true;
	int tecla=0,x=1,x1=10,i;
	
	do
	{
		
		system("cls");
		color(15,3);
		portada();
		color(15,0);

		for(i=0; i<numeroOpciones; i++)
		{
			gotoxy(5+(22*i), 12);
			if( (10+(22*i)) == x1)
			{
				color(5,10);
				printf("%s",opciones[i]);	
				color(15,0);
			}
			else
			{
				printf("%s",opciones[i]);	
			}
		}
		
		// 77 Derecha	75 IZQUIERDA	72 ARRIBA	80 ABAJO	13 ENTER
		
		do											// Metodo para que me permita ingresar solo las flechas o ENTER
		{
			fflush(stdin);
			tecla=getch();
		}while( (tecla!=72)&&(tecla!=80)&&(tecla!=77)&&(tecla!=75)&&(tecla!=13) );
		
		switch(tecla)
		{
			case 77:												//derecha
			{
				x++;
				x1=x1+22;
				if(x>numeroOpciones)
			 	{
					x=1;
				}
				if(x1>100)
				{
					x1=10;
				}
				break;
			}
			
			case 75:												//izquierda
			{
				x--;
				x1=x1-22;
				if(x<1)
				{
					x=numeroOpciones;
				}
				if(x1<2)
				{
					x1=x1+110;
				}
				break;
			}
			
			case 72:			//arriba
			{

				break;
			}
			
			case 80:			//abajo
			{

				break;
			}
			case 13:			//enter
			{
				
				///////////////////////////////////////////////////////////////////////////
				if(x==1)
				{

				}
				///////////////////////////////////////////////////////////////////////////
				if(x==2)
				{
					
				}
				///////////////////////////////////////////////////////////////////////////
				if(x==3)
				{
				
				}
				///////////////////////////////////////////////////////////////////////////
				if(x==4)
				{
					
				}
				///////////////////////////////////////////////////////////////////////////
				if(x==5)
				{
					if(tecla==13)
					{
						system("cls");

						printf("SALIENDO");
						Sleep(150);printf(" . ");
						Sleep(150);printf(" . ");
						Sleep(150);printf(" . ");
						repite=false;
					}

				}
				
				break;
			}
		}
	}while(repite);

}



main()
{
	const char *opciones[]={"  Venta de Boletos  ", "  Modificacion de Boletos  ", "  Eliminacion de Venta ", "  Consulta de Boletos  ","   Salir del Sistema   "};
	int numeroOpciones=5;
	
	color(15,0);
	menu_seleccion(opciones,numeroOpciones);
	
	
	
}
