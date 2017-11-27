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
//#include <graphics.h>
#include <stdlib.h>
#include "colores.h"

// ATRBUTOS PROPIOS DEL PROGRAMA


//ESTRUCTURAS

struct Localidad
{
	//char nombreLocalidad[10];
	int capacidad;	
	int asiento;
};

struct Estadio
{
    char nombre[20];
	int capacidadTotal;
	Localidad general, palco, tribuna;
};


struct Cliente
{
	long int CI[10];
	long int numTelefono[10];
    char Nombre[30];
};


struct Hora
{
    int hora;
    int minuto;
};

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Tiempo
{
    Fecha fReservacion;
    Fecha fPartido;
    Hora hReservacion;
    Hora hPpartido;
};


struct Entrada
{
    Cliente cliente;
    Estadio estadio;
    Tiempo tiempo;
    float costo;
};
//FIN ESTRUCTURAS


// LISTAS DOBLES
struct Nodo
{
    int asiento;
    bool disponibilidad;
    struct Nodo *siguienteDireccion;
    struct Nodo *anterior;
};
typedef struct Nodo *Lista;



//


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

void llenarDatosEstadio(Estadio &estadio, int capacidad, char nombreEstadio[])
{
	
	estadio.capacidadTotal = capacidad;
	strcpy(estadio.nombre, nombreEstadio);
	fflush(stdin);
	estadio.general.capacidad = (capacidad / 3);	
	estadio.palco.capacidad = (capacidad / 3);
	estadio.tribuna.capacidad = (capacidad / 3);
}

void llenarDatosPartidos(Tiempo fechasPartidos[])
{
	
	fechasPartidos[0].fPartido.anio = 2017;
	fechasPartidos[0].fPartido.mes  = 12;
	fechasPartidos[0].fPartido.dia  = 03;
	fechasPartidos[0].hPpartido.hora= 15;
	fechasPartidos[0].hPpartido.minuto= 30;
	
	fechasPartidos[1].fPartido.anio = 2017;
	fechasPartidos[1].fPartido.mes  = 12;
	fechasPartidos[1].fPartido.dia  = 10;
	fechasPartidos[1].hPpartido.hora= 12;
	fechasPartidos[1].hPpartido.minuto= 00;
	
}

void informacionParido(const char *partidos[], int numeroPartido, Tiempo fechasPartidos[])
{
	system("cls");
	printf("\n\t\t\t\t\tCAMPENOATO ECUATORIANO DE FÚTBOL");
	printf("\n\n\t\t\t\t\t\tESTADIO RUMIÑAHUI");
	printf("\n\n\t\t\t\t\t\t    FECHA #%d", (21+numeroPartido));
	printf("\n\t\t\t\t\t     %s", partidos[numeroPartido]);
	if(fechasPartidos[numeroPartido].hPpartido.minuto == 0)
	{
		printf("\n\n\t\t\t\t\t\t%d/%d/%d\t%d:0%d", fechasPartidos[numeroPartido].fPartido.dia, fechasPartidos[numeroPartido].fPartido.mes, fechasPartidos[numeroPartido].fPartido.anio, 
		fechasPartidos[numeroPartido].hPpartido.hora, fechasPartidos[numeroPartido].hPpartido.minuto);	
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t%d/%d/%d\t%d:%d", fechasPartidos[numeroPartido].fPartido.dia, fechasPartidos[numeroPartido].fPartido.mes, fechasPartidos[numeroPartido].fPartido.anio, 
		fechasPartidos[numeroPartido].hPpartido.hora, fechasPartidos[numeroPartido].hPpartido.minuto);
	}

}

void llenarEstadio(Estadio estadio)
{
	
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

//----- Funciones con Listas Dobles

void ingresarAlFinal(Lista &lista, int asiento)
{
	/*
	Lista punteroAuxiliar1,punteroAuxiliar2;
	
    punteroAuxiliar1=new(struct Nodo);
    punteroAuxiliar1->asiento=asiento;
    punteroAuxiliar1->disponibilidad = true;
    */
    
/*
	Lista auxiliarLista = new Nodo();
	Lista auxiliarLista2 = lista;
	
	auxiliarLista->asiento = asiento;
	auxiliarLista->disponibilidad = true;
	
	if (lista == NULL)
	{
		auxiliarLista->siguienteDireccion =  NULL;
		auxiliarLista->anterior = NULL;
		lista = auxiliarLista;
	}
	else
	{
		auxiliarLista->siguienteDireccion = auxiliarLista2->siguienteDireccion;
		auxiliarLista->anterior = auxiliarLista2;
		auxiliarLista2->siguienteDireccion = auxiliarLista;
		auxiliarLista2->siguienteDireccion->anterior = auxiliarLista;
		lista = auxiliarLista2;
		
	}
*/

	if(lista==NULL)
	{		
        Lista punteroAuxiliar=new(struct Nodo);
        punteroAuxiliar->asiento=asiento;
        punteroAuxiliar->disponibilidad = true;
        punteroAuxiliar->siguienteDireccion=punteroAuxiliar->anterior=NULL;
        lista=punteroAuxiliar;
        printf("\n\nNumero ingresado: %d\n\n", asiento);
	}
	else
	{
		
		Lista punteroAuxiliar1,punteroAuxiliar2;
        punteroAuxiliar1=new(struct Nodo);
        punteroAuxiliar1->asiento=asiento;
        punteroAuxiliar1->disponibilidad = true;
        punteroAuxiliar2=lista;
        while(punteroAuxiliar2->siguienteDireccion!=NULL)
		{
            punteroAuxiliar2=punteroAuxiliar2->siguienteDireccion;
        }
        punteroAuxiliar1->siguienteDireccion=punteroAuxiliar2->siguienteDireccion;
        punteroAuxiliar2->siguienteDireccion=punteroAuxiliar1;
        punteroAuxiliar1->anterior=punteroAuxiliar2;
        printf("\n\nNumero ingresado: %d\n\n", asiento);
	}

    /*
    
    if(lista!=NULL)
	{
        Lista punteroAuxiliar1, punteroAuxiliar2;
        //punteroAuxiliar1=new (struct Nodo);
        //punteroAuxiliar2=new (struct Nodo);
        punteroAuxiliar1->asiento =asiento;
        punteroAuxiliar1->disponibilidad = true;
        
		punteroAuxiliar2=lista;
        
        while(punteroAuxiliar2->siguienteDireccion!=NULL)
		{
            punteroAuxiliar2 = punteroAuxiliar2->siguienteDireccion;
        }
        punteroAuxiliar1->siguienteDireccion=punteroAuxiliar2->siguienteDireccion;
        punteroAuxiliar2->siguienteDireccion=punteroAuxiliar1;
        punteroAuxiliar1->anterior=punteroAuxiliar2;
        printf("\n\nDato ingresado!\n\n");
    }else
	{
        if(lista==NULL)
		{
	        Lista punteroAuxiliar=new(struct Nodo);
	        punteroAuxiliar->asiento=asiento;
	        punteroAuxiliar->disponibilidad = true;
	        punteroAuxiliar->siguienteDireccion=punteroAuxiliar->anterior=NULL;
	        lista=punteroAuxiliar;
	        //printf("\n\nPrimer numero ingresado!\n\n");
    	}
    }
    
    */
}

void imprimirLista( Lista lista)
{
	Lista auxiliarLista = lista;
	
	while (auxiliarLista != NULL)
	{
		printf(" %d", auxiliarLista->asiento);	
		auxiliarLista = auxiliarLista->siguienteDireccion;
	}
	
}

void generarLocalidades(Lista &lista, int limite)
{
	int i;
	Lista aux;
	aux = lista;
	
	for(i=1; i<=limite; i++)
	{
		ingresarAlFinal(lista, i);
	}
	printf("\n");
	imprimirLista(lista);
	/*
	while(aux!= NULL)
	{
		printf("%d ", aux->asiento);
		aux = aux->siguienteDireccion;
	}
	*/
}



/////////////////////////////////////
void menuSeleccion(const char *opciones[], int numeroOpciones, const char *partidos[], int numeroPartidos, const char *subOpciones[], int numeroSubOpciones, int coordenada[])
{
	
	Tiempo fechasPartidos[2];
	Estadio estadio;
	
	
	bool repite = true, aux = true;
	int tecla=0,x=1,x1=10,i, selec=1,opcion=0;
	
	
	llenarDatosEstadio(estadio, 190 , "Estadio de Sangolqui");				//Inserto la informacion del estadio y partidos
	estadio.capacidadTotal = 90;
	llenarDatosPartidos(fechasPartidos);
	/*
	for(int j=0; j<2; j++)
	{
		printf("\n %d/%d/%d ", fechasPartidos[j].fPartido.anio, fechasPartidos[j].fPartido.mes, fechasPartidos[j].fPartido.dia );	
	}
	
	printf("\n%s", estadio.nombre);
	printf("\n%d", estadio.general.capacidad);
	
	getch();
	*/
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
									
									informacionParido(partidos, selec-1, fechasPartidos);
									
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
									
									informacionParido(partidos, selec-1, fechasPartidos);
									
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
									
									informacionParido(partidos, selec-1, fechasPartidos);
									
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
									
									printf("\n\nHola Opcion 2");
									
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
	const char *opciones[]={"  Venta de Entradas   ", "Modificacion Asiento  ", "  Eliminacion de Ventas ", "  Consulta de Entradas  ","   Salir del Sistema   "};
	const char *partidos[]={"  Clan Juvenil VS El Nacional  ", "  IDV VS U. Catolica           "};
	const char *subOpciones[]={"  CEDULA  "};
	
	int numeroOpciones = 5;
	int numeroPartidos = 2;
	int numeroSubOpciones = 1;
	int coordenada[2];
	
	Lista lista = new Nodo();
	
	generarLocalidades(lista, 10);
	getch();
	color(15,0);
	//menuSeleccion(opciones,numeroOpciones, partidos, numeroPartidos, subOpciones, numeroSubOpciones, coordenada );
	
	
	
}
