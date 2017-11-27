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
void menu_seleccion(const char *[], int, const char *[], int, const char *[], int , int []);



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

void menuSeleccion(const char *opciones[], int numeroOpciones, const char *partidos[], int numeroPartidos, const char *subOpciones[], int numeroSubOpciones, int coordenada[])
{
	bool repite = true, aux = true;
	int tecla=0,x=1,x1=10,i, selec=1,opcion=0;
	
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
				color(7,16);
				printf("%s",opciones[i]);	
				color(15,0);
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
			
			case 72:												//arriba
			{
				
					if(x==1)
					{
						do
						{
						
							for(i=0;i<numeroPartidos;i++)		//Imprime los partidos a jugarse
							{
								gotoxy(6,13+i);
								
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",partidos[i]);
									color(15,0);
								}
								else
								{
									printf("%s",partidos[i]);	
								}	
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroPartidos;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroPartidos)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}
						
						}while(aux);
					}
					
					///////////////////////////////////////////////////////////////////////////
					if(x==2)
					{
						do
						{
							
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(28,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==3)
					{
						
						do
						{
							
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(50,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

							
						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==4)
					{
						do
						{
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(72,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

							
						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==5)
					{
						/*
						system("cls");
						coordenada[0]=0;
						coordenada[1]=0;
						printf("SALIENDO");
						Sleep(175);printf(" . ");Sleep(175);printf(" . ");Sleep(175);printf(" . ");
						repite=false;
						*/
					}


				break;
			}
			
			case 80:			//abajo
			{
				
					if(x==1)
					{
						do
						{
							
							for(i=0;i<numeroPartidos;i++)		//Imprime los partidos a jugarse
							{
								gotoxy(6,13+i);
								
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",partidos[i]);
									color(15,0);
								}
								else
								{
									printf("%s",partidos[i]);	
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroPartidos;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroPartidos)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}
						
						}while(aux);
					}
					
					///////////////////////////////////////////////////////////////////////////
					if(x==2)
					{
						do
						{
							
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(28,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==3)
					{
						
						do
						{
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(50,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

							
						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==4)
					{
						do
						{
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(72,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

							
						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==5)
					{
							if(tecla==13)
							{
								/*
								system("cls");
								coordenada[0]=0;
								coordenada[1]=0;
								gotoxy(3,2);
								printf("%s",opciones);
								gotoxy(45+x,2);
								printf("-");
								gotoxy(27,10);
								printf("SALIENDO");
								Sleep(175);printf(" . ");Sleep(175);printf(" . ");Sleep(175);printf(" . ");
								repite=false;
								*/
							}
							
					}
				break;
			}
			
			case 13:			//enter
			{
				
				
				
					if(x==1)
					{
						do
						{
							
							for(i=0;i<numeroPartidos;i++)		//Imprime los partidos a jugarse
							{
								gotoxy(6,13+i);
								
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",partidos[i]);
									color(15,0);
								}
								else
								{
									printf("%s",partidos[i]);	
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroPartidos;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroPartidos)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}
						
						}while(aux);
					}
					
					///////////////////////////////////////////////////////////////////////////
					if(x==2)
					{
						do
						{
							
							
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(28,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==3)
					{
						
						do
						{
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(50,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									color(3,10);
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

							
						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==4)
					{
						do
						{
							for(i=0;i<numeroSubOpciones;i++)		//Imprime las subOpciones
							{
								gotoxy(72,13+i);
								if( (i+1) == selec)
								{
									color(3,10);
									printf("%s",subOpciones[i]);
									color(15,0);
								}
								else
								{
									printf("%s",subOpciones[i]);
								}
								
							}
							
							do
							{
								fflush(stdin);
								opcion=getch();
							}while((opcion!=72)&&(opcion!=80)&&(opcion!=13)&&(opcion!=75)&&(opcion!=77));
							
							switch(opcion)
							{
								case 75:
								{
									aux=false;
									break;
								}
								case 77:
								{
									aux=false;
									break;
								}
								case 72:
								{
									selec--;
									if(selec<1)
									{
										selec = numeroSubOpciones;
									}
									aux=true;
									break;
								}
								case 80:
								{
									selec++;
									if(selec > numeroSubOpciones)
								 	{
										selec=1;
									}
									aux=true;
									break;
								}
								case 13:
								{
									coordenada[0]= x;					//Indica el numero de Opcion
									coordenada[1]= selec;				//Indica el numero de SubOpcion
									
									aux=false;
									repite=false;
									break;
								}
								
							}

							
						}while(aux);
					}
					///////////////////////////////////////////////////////////////////////////
					if(x==5)
					{
							if(tecla==13)
							{
								system("cls");
								coordenada[0]=0;
								coordenada[1]=0;
								printf("\t\t\t\t GRACIAS");
								Sleep(175);printf(" . ");Sleep(175);printf(" . ");Sleep(175);printf(" . ");
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
	const char *opciones[]={"  Venta de Entradas   ", "Modificacion Entradas  ", "  Eliminacion de Ventas ", "  Consulta de Entradas  ","   Salir del Sistema   "};
	const char *partidos[]={"  Clan Juvenil VS El Nacional  ", "  IDV VS Emelec                "};
	const char *subOpciones[]={"  CEDULA  "};
	
	int numeroOpciones = 5;
	int numeroPartidos = 2;
	int numeroSubOpciones = 1;
	int coordenada[2];
	
	
	color(15,0);
	menuSeleccion(opciones,numeroOpciones, partidos, numeroPartidos, subOpciones, numeroSubOpciones, coordenada );
	
	
	
}
