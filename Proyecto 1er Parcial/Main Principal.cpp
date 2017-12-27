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
#include <ctime>
#include <stdlib.h>
#include "colores.h"
#include "imagen.h"
#define N 30

// ATRBUTOS PROPIOS DEL PROGRAMA


//ESTRUCTURAS
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

struct Entrada
{
    //Cliente cliente;
    Estadio estadio;
    Tiempo tiempo;
    float costo;
};

struct Cliente
{
	Entrada entrada[N];
	long int CI[10];
	long int Celular[10];
    char Nombre[30];
    int Codigo;
    float total;
    long int cedula;
};




//FIN ESTRUCTURAS


// LISTAS DOBLES
struct Nodo
{
    bool disponibilidad;
    int codigoCliente;
	int asiento;
    struct Nodo *siguienteDireccion;
    struct Nodo *anterior;
    long int cedula;
};
typedef struct Nodo *Lista;




// Declaración de los prototipos 
void gotoxy(int ,int );
void portada();
void menu_seleccion(const char *[], int, const char *[], int, const char *[], int , int []);



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

	Lista auxiliarLista = new Nodo();
	Lista auxiliarLista2 = lista;
	
	auxiliarLista->asiento = asiento;
	auxiliarLista->disponibilidad = true;


	if(lista==NULL)
	{		
        Lista punteroAuxiliar=new(struct Nodo);
        punteroAuxiliar->asiento=asiento;
        punteroAuxiliar->disponibilidad = true;
        punteroAuxiliar->siguienteDireccion=punteroAuxiliar->anterior=NULL;
        lista=punteroAuxiliar;
        //printf("\n\nNumero ingresado: %d\n\n", asiento);
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
        //printf("\n\nNumero ingresado: %d\n\n", asiento);
	}
    
}

void imprimirLista( Lista lista)
{
	Lista auxiliarLista = new Nodo();
	auxiliarLista = lista;
	/*
	while(lista && lista->anterior)
	{
		printf(" %d", auxiliarLista->asiento);
		lista = lista->anterior;
	}
	printf(" %d", auxiliarLista->asiento);
	*/
	
	
	printf("\n\n");
	while (auxiliarLista != NULL && auxiliarLista != NULL)
	{
		printf(" %d", auxiliarLista->asiento);	
		auxiliarLista = auxiliarLista->siguienteDireccion;
	}
}

void imprimirEntradasDisponibles( Lista lista)
{
	Lista auxiliarLista = new Nodo();
	auxiliarLista = lista;
	/*
	while(lista && lista->anterior)
	{
		printf(" %d", auxiliarLista->asiento);
		lista = lista->anterior;
	}
	printf(" %d", auxiliarLista->asiento);
	*/
	
	while (auxiliarLista != NULL && auxiliarLista != NULL)
	{
		if(auxiliarLista->disponibilidad == true)
		{
			printf(" %d", auxiliarLista->asiento);	
		}
		
		auxiliarLista = auxiliarLista->siguienteDireccion;
	}
}

void generarLocalidades(Lista &lista, int limite)
{
	int i;
	Lista aux;
	aux = lista;
	/*
	while(lista && lista->siguienteDireccion)
	{
		//printf(" %d", auxiliarLista->asiento);
		lista = lista->siguienteDireccion;
	}
	*/
	for(i=1; i<=limite; i++)
	{
		ingresarAlFinal(lista, i);
	}
	//printf("\n");
	//imprimirLista(lista);
	/*
	while(aux!= NULL)
	{
		printf("%d ", aux->asiento);
		aux = aux->siguienteDireccion;
	}
	*/
}

bool disponibilidadAsiento(Lista lista, int asiento)
{
	Lista auxiliarLista = new Nodo();
	auxiliarLista = lista;
	int contador=0;
	while (auxiliarLista != NULL && auxiliarLista != NULL)
	{
		if(auxiliarLista->disponibilidad == true && auxiliarLista->asiento == asiento)
		{
			contador++;
		}
		
		auxiliarLista = auxiliarLista->siguienteDireccion;
	}
	if(contador == 0) return false;
	else return true;
	
}

int contarAsientosDisponibles(Lista lista)
{
	Lista auxiliarLista = new Nodo();
	auxiliarLista = lista;
	int contador=0;
	
	printf("\n\n");
	while (auxiliarLista != NULL && auxiliarLista != NULL)
	{
		if(auxiliarLista->disponibilidad == true)
		{
			contador++;
		}	
		auxiliarLista = auxiliarLista->siguienteDireccion;
	}
	return contador;
}

long int convertirCedula(long int cedula[])
{
	long int ced=0;
	
	for(int i=0;i<10; i++)
	{
		ced = (ced*10)+cedula[i]; 
	}
	return ced;
}

long int soloNumeros(long int a)
{
	char caracter;
	int i=0;

	fflush(stdin);
	caracter=getch();
	while(caracter!=13)
	{
		fflush(stdin);
		if(caracter!=8)//borrar
		{
			if((caracter>=48)&&(caracter<=57))//entre 0 y 9
			{
				if(caracter!=13)//enter
				{
					printf("%c",caracter);
					fflush(stdin);
					a=(a*10)+(caracter-48);
					i++;
				}
			}
		}
		else
		{
			if(i>0)
			{
				printf("\b \b");//mueve el cursor a la izquierda
				a=(a/10);
				i--;
			}
		}
		caracter=getch();
	}
	return a;
}

void validarCedula(long int data[])
 {
 	long int ci=0;
 	long int A[5];
 	int i,cociente,CEDULA[10],RES[10],sumar,DS,validar, op=0;
 	
	do
	{
		printf("\nIngrese n%cmero de c%cdula:\t",163,130);
		ci=soloNumeros(ci);



		if((ci==0000000000)||(ci==1010101010)||(ci==1111111116))
		{
			op==0;
			printf("\n\tUMERO DE CEDULA NO VALIDO\n");
		}
		else
		{
			for(i=9;i>=0;i--)
			{
				cociente=(ci)/10;
				CEDULA[i]=(ci)%10;
				ci=cociente;
			}
			
			for(i=0; i<9; i+=2)
			{
				RES[i]=CEDULA[i] * 2;
				if(RES[i]>9)
				{
					RES[i]=RES[i] - 9;
				}
			}
			
			for(i=1;i<9;i+=2)
			{
				RES[i]=CEDULA[i];
			}
			
			sumar=0;
			for(i=0;i<9;i++)
			{
				sumar=sumar+RES[i];
			}
			
			DS=((sumar/10)+1)*10;
			validar=DS-sumar;
			
			if(validar==10)
			{
				validar=0;
			}
			
			if(validar==CEDULA[9])
			{
				op=1;
			}
			else
			{
				op=0;
			}
			
			if(op==0)
			{
				printf("\n\tNUMERO DE CEDULA NO VALIDO\n");
			}
				
		}
	}while(op==0);
		for(i=0; i<10; i++)
	    {
	    	data[i]=CEDULA[i];
		}
 }

char *soloLetras(char A[])
{
	char letra;
	int i=0,l=0;
	fflush(stdin);
	letra=getch();
	while(letra!=13 && i<50)
	{
		fflush(stdin);
		if(letra!=8)
			{
				if((letra>=65 && letra<=90)||(letra>=97 && letra<=122)||(letra==32))
				{
					if(letra!=13)
					{
						printf("%c",letra);
						fflush(stdin);
						A[i]=letra;
						i++;
					}
				}
			}
			else
			{
				l=strlen(A);
				if(l>0)
				{
					printf("\b \b");//mueve el cursor a la izquierda
					A[l-1]='\0';
					i--;
				}
			}
			letra=getch();
	}
	A[i]='\0';
	
	return A;
}

void validarNombre(char A[])
 {
	 	printf("\nIngrese su Nombre:\t\t");
		A=soloLetras(A);
 }

void validarCelular(long int N_telefono[])
 {
 	long int n_celular=0;
 	int i,coc,Celular[10],op=0;
 	do
 	{
 		op=0;
 		n_celular=0;
 		printf("\nIngrese n%cmero de celular:\t",163);
	 	n_celular=soloNumeros(n_celular);
	 	for(i=9;i>=0;i--)
	 	{
	 		coc=n_celular/10;
	 		Celular[i]=n_celular%10;
	 		n_celular=coc;
		 }
		 if(Celular[0]==0 && Celular[1]==9)
		 {
		 	op=1;
		 }
		 else
		 {
		 	op=0;
		 	printf("\n\tNumero de celular invalido");
		 }
		for(i=0;i<10;i++)
		{
			N_telefono[i]=Celular[i];
		}
	 }while(op==0);

 }

void ingresoDatos(Cliente t[], int x, Lista &General, Lista &Palco, Lista &Tribuna)
{
	//Lista
	Lista auxiliarLista = new Nodo();
	
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal = *localtime(&now);
	//Cursor
	int ejeX=1;
	bool repetirMove=true;
	int tecla2=0;
	//Generales
	int a=0,val_ci=0,i,j,k;
	long int ci[10];
	long int entradasRequeridas;
	int numeroAsiento=0;
	float totalPago=0;
	
	system("cls");
	
	do
	{
		system("cls");
		printf("\nLocalidades Disponibles");
		printf("\n\tHora Local\t%d : %d : %d", nowLocal.tm_hour, nowLocal.tm_min, nowLocal.tm_sec);
		printf("\n\nGenerales:\n\t");
		imprimirEntradasDisponibles(General);
		printf("\n\nPalcos:\n\t");
		imprimirEntradasDisponibles(Palco);
		printf("\n\nTribunas:\n\t");
		imprimirEntradasDisponibles(Tribuna);
		
		
		if(ejeX ==1)
		{
			color(7,3);
			gotoxy(30, 20);
			printf("GENERAL");
			color(15,0);
			gotoxy(70, 20);
			printf("PALCO");
			gotoxy(100, 20);
			printf("TRIBUNA");
		}
		
		if(ejeX ==2)
		{
			gotoxy(30, 20);
			printf("GENERAL");
			color(7,3);
			gotoxy(70, 20);
			printf("PALCO");
			color(15,0);
			gotoxy(100, 20);
			printf("TRIBUNA");
		}
		
		if(ejeX ==3)
		{
			gotoxy(30, 20);
			printf("GENERAL");
			gotoxy(70, 20);
			printf("PALCO");
			color(7,3);
			gotoxy(100, 20);
			printf("TRIBUNA");
			color(15,0);
		}
		
		
		
		do											// Metodo para que me permita ingresar solo las flechas o ENTER
		{
			fflush(stdin);
			tecla2=getch();
		}while( (tecla2!=77)&&(tecla2!=75)&&(tecla2!=13) );
		
		switch(tecla2)
		{
			case 75:								//Izquierda
			{
				ejeX--;
				if(ejeX<1)
				{
					ejeX = 3;
				}
				break;
			}
			
			case 77:
			{
				ejeX++;
				if(ejeX>3)
				{
					ejeX = 1;
				}
				break;
			}
			
			case 13:
			{
				repetirMove = false;
				break;
			}		
		}
		
	}while(repetirMove);
	
	if(ejeX == 1)
	{
		if(contarAsientosDisponibles(General)>0)
		{
			system("cls");
			printf("\n\n\t\t\t\t\tIngreso de Datos\n");
			validarCedula( t[x].CI);
			t[x].Codigo = x;
			validarNombre(t[x].Nombre);
			validarCelular(t[x].Celular);

			do
			{
				system("cls");
				printf("\nLocalidades Disponibles");
				printf("\n\nGenerales:\n\t");
				imprimirEntradasDisponibles(General);
	
				printf("\nNumero de Entradas a comprar:\t");
				k=0;
				entradasRequeridas = soloNumeros(k);
				//printf("\n%d", entradasRequeridas);
				if((entradasRequeridas > contarAsientosDisponibles(General) || entradasRequeridas < 1))
					printf("\n\nNumero de entradas no validas");
				
			}while(entradasRequeridas > contarAsientosDisponibles(General) || entradasRequeridas < 1);
			//entradasRequeridas = soloNumeros(entradasRequeridas);
			//printf("\nEntradas Disponibles:\t%d", contarAsientosDisponibles(General));
			for(j=1; j<=entradasRequeridas; j++)
			{
				auxiliarLista = General;
				do
				{
					printf("\nIngrese el numero de Asiento:\t");
					k=0;
					numeroAsiento = soloNumeros(k);
					if((disponibilidadAsiento(General, numeroAsiento)== false))
						printf("\n\tAsiento no disponible");
					//auxiliarLista = auxiliarLista->siguienteDireccion;
				}while(disponibilidadAsiento(General, numeroAsiento)== false);
				//printf("\n%d", numeroAsiento);
				
				while (auxiliarLista != NULL && auxiliarLista != NULL)
				{
					if(auxiliarLista->disponibilidad == true && auxiliarLista->asiento == numeroAsiento)
					{
						auxiliarLista->disponibilidad = false;
						auxiliarLista->codigoCliente = x;
						auxiliarLista->cedula = convertirCedula(t[x].CI);
						//printf("\n\nCedula convertida: %d",auxiliarLista->cedula );
						//getch();
	
						t[x].entrada[j].tiempo.fReservacion.dia= nowLocal.tm_mday;
						t[x].entrada[j].tiempo.fReservacion.mes= nowLocal.tm_mon;
						t[x].entrada[j].tiempo.fReservacion.anio= nowLocal.tm_year;
						
						t[x].entrada[j].tiempo.hReservacion.hora= nowLocal.tm_hour;
						t[x].entrada[j].tiempo.hReservacion.minuto= nowLocal.tm_min;
						t[x].entrada[j].costo = 5;				
					}
					
					auxiliarLista = auxiliarLista->siguienteDireccion;
				}
			}
			/*
			for(int y=0; y<N; y+++)
			{
				totalPago = totalPago + t[x].entrada[y].costo;
			}
			t[x].total = total;*/
			/*
			printf("\n");
			imprimirEntradasDisponibles(General);
			printf("\n\tHora Local\t%d : %d ", t[x].entrada[2].tiempo.hReservacion.hora, t[x].entrada[2].tiempo.hReservacion.minuto);
			*/
				
		}
		else
		{
			printf("\n\t\tENTRADAS AGOTADAS PARA ESTA LOCALIDAD");
			getch();
		}

	}
	
	
	
	if(ejeX == 2)
	{
		
		if(contarAsientosDisponibles(Palco)>0)
		{
			system("cls");
			printf("\n\n\t\t\t\t\tIngreso de Datos\n");
			validarCedula( t[x].CI);
			t[x].Codigo = x;
			validarNombre(t[x].Nombre);
			validarCelular(t[x].Celular);
			
			
			
			do
			{
				system("cls");
				printf("\nLocalidades Disponibles");
				printf("\n\nPalcos:\n\t");
				imprimirEntradasDisponibles(Palco);
				printf("\nNumero de Entradas a comprar:\t");
				k=0;
				entradasRequeridas = soloNumeros(k);
				//printf("\n%d", entradasRequeridas);
				if((entradasRequeridas > contarAsientosDisponibles(Palco) || entradasRequeridas < 1))
					printf("\n\nNumero de entradas no validas");
			}while(entradasRequeridas > contarAsientosDisponibles(Palco) || entradasRequeridas < 1);
			//entradasRequeridas = soloNumeros(entradasRequeridas);
			//printf("\nEntradas Disponibles:\t%d", contarAsientosDisponibles(General));
			for(j=1; j<=entradasRequeridas; j++)
			{
				auxiliarLista = Palco;
				do
				{
					printf("\nIngrese el numero de Asiento:\t");
					k=0;
					numeroAsiento = soloNumeros(k);
					if((disponibilidadAsiento(Palco, numeroAsiento)== false))
						printf("\n\tAsiento no disponible");
				}while(disponibilidadAsiento(Palco, numeroAsiento)== false);
				
				while (auxiliarLista != NULL && auxiliarLista != NULL)
				{
					if(auxiliarLista->disponibilidad == true && auxiliarLista->asiento == numeroAsiento)
					{
						auxiliarLista->disponibilidad = false;
						auxiliarLista->codigoCliente = x;
						auxiliarLista->cedula = convertirCedula(t[x].CI);
						
						t[x].entrada[j].tiempo.fReservacion.dia= nowLocal.tm_mday;
						t[x].entrada[j].tiempo.fReservacion.mes= nowLocal.tm_mon;
						t[x].entrada[j].tiempo.fReservacion.anio= nowLocal.tm_year;
						
						t[x].entrada[j].tiempo.hReservacion.hora= nowLocal.tm_hour;
						t[x].entrada[j].tiempo.hReservacion.minuto= nowLocal.tm_min;
						
					}
					
					auxiliarLista = auxiliarLista->siguienteDireccion;
				}	
			}
			//printf("\n");
			//imprimirEntradasDisponibles(Palco);
		
			
		}
		else
		{
			printf("\n\t\tENTRADAS AGOTADAS PARA ESTA LOCALIDAD");
			getch();
		}
	
	}
	
	
	if(ejeX == 3)
	{
		
		if(contarAsientosDisponibles(Tribuna)>0)
		{
			system("cls");
			printf("\n\n\t\t\t\t\tIngreso de Datos\n");
			validarCedula( t[x].CI);
			t[x].Codigo = x;
			validarNombre(t[x].Nombre);
			validarCelular(t[x].Celular);
		
			do
			{
				system("cls");
				printf("\nLocalidades Disponibles");
				printf("\n\nTribunas:\n\t");
				imprimirEntradasDisponibles(Tribuna);
				printf("\nNumero de Entradas a comprar:\t");
				k=0;
				entradasRequeridas = soloNumeros(k);
				//printf("\n%d", entradasRequeridas);
				if((entradasRequeridas > contarAsientosDisponibles(Tribuna) || entradasRequeridas < 1))
					printf("\n\nNumero de entradas no validas");
			}while(entradasRequeridas > contarAsientosDisponibles(Tribuna) || entradasRequeridas < 1);
			//entradasRequeridas = soloNumeros(entradasRequeridas);
			//printf("\nEntradas Disponibles:\t%d", contarAsientosDisponibles(General));
			for(j=1; j<=entradasRequeridas; j++)
			{
				auxiliarLista = Tribuna;
				do
				{
					printf("\nIngrese el numero de Asiento:\t");
					k=0;
					numeroAsiento = soloNumeros(k);
					if((disponibilidadAsiento(Tribuna, numeroAsiento)== false))
						printf("\n\tAsiento no disponible");
					//auxiliarLista = auxiliarLista->siguienteDireccion;
				}while(disponibilidadAsiento(Tribuna, numeroAsiento)== false);
				//printf("\n%d", numeroAsiento);
				
				while (auxiliarLista != NULL && auxiliarLista != NULL)
				{
					if(auxiliarLista->disponibilidad == true && auxiliarLista->asiento == numeroAsiento)
					{
						auxiliarLista->disponibilidad = false;
						auxiliarLista->codigoCliente = x;
						auxiliarLista->cedula = convertirCedula(t[x].CI);
						
						t[x].entrada[j].tiempo.fReservacion.dia= nowLocal.tm_mday;
						t[x].entrada[j].tiempo.fReservacion.mes= nowLocal.tm_mon;
						t[x].entrada[j].tiempo.fReservacion.anio= nowLocal.tm_year;
						
						t[x].entrada[j].tiempo.hReservacion.hora= nowLocal.tm_hour;
						t[x].entrada[j].tiempo.hReservacion.minuto= nowLocal.tm_min;
					}
					
					auxiliarLista = auxiliarLista->siguienteDireccion;
				}
			}
			/*printf("\n");
			imprimirEntradasDisponibles(Tribuna);
			printf("\n\tHora Local\t%d : %d ", t[x].entrada[2].tiempo.hReservacion.hora, t[x].entrada[2].tiempo.hReservacion.minuto);*/
			
		}
		else
		{
			printf("\n\t\tENTRADAS AGOTADAS PARA ESTA LOCALIDAD");
			getch();
		}
	}

	for(int y=0; y<N; y++)						// cALCULA EL MONTO FINAL A PAGAR
	{
		totalPago = totalPago + t[x].entrada[y].costo;
	}
	t[x].total = totalPago;
	
 }
void imagen()
{

    hConWnd = GetConsoleWndHandle();
    if (hConWnd)
    {
        // select a bitmap file you have or use one of the files in the Windows folder
        // filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
        BCX_Bitmap("LOGO.bmp",hConWnd,123,230,65,0,0);
        //system("pause>nul");
        Sleep(3000);
        //getchar();
    }
    system("cls");

}
bool informarAsientosDisponibles( Lista General,  Lista Palco, Lista Tribuna, Lista General2,  Lista Palco2, Lista Tribuna2, int selector)
{
	printf("\n\n Asientos Disponibles");
	int contador=0;
	
	if(selector == 0)
	{
		printf("\tGeneral:\t%d\t$5", contarAsientosDisponibles(General));
		printf("\tPalco:\t\t%d\t$15", contarAsientosDisponibles(Palco));
		printf("\tTribuna:\t%d\t$10", contarAsientosDisponibles(Tribuna));
		
		contador = contador + contarAsientosDisponibles(General);
		contador = contador + contarAsientosDisponibles(Palco);
		contador = contador + contarAsientosDisponibles(Tribuna);
	}
	else
	{
		printf("\tGeneral:\t%d\t$5", contarAsientosDisponibles(General2));
		printf("\tPalco:\t\t%d\t$15", contarAsientosDisponibles(Palco2));
		printf("\tTribuna:\t%d\t$10", contarAsientosDisponibles(Tribuna2));
		
		contador = contador + contarAsientosDisponibles(General2);
		contador = contador + contarAsientosDisponibles(Palco2);
		contador = contador + contarAsientosDisponibles(Tribuna2);
	}
	
	if(contador == 0)
	{
		printf("\n\n\t\t\tENTRADAS AGOTADAS");
		return false;
	}
	else
	{
		return true;
	}
}
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

void llenarDatosEstadio(Estadio &estadio, int capacidad, char nombreEstadio[], Lista &General,  Lista &Palco, Lista &Tribuna)
{
	
	estadio.capacidadTotal = capacidad;
	strcpy(estadio.nombre, nombreEstadio);
	fflush(stdin);
	estadio.general.capacidad = (capacidad / 3);	
	estadio.palco.capacidad = (capacidad / 3);
	estadio.tribuna.capacidad = (capacidad / 3);
	
	generarLocalidades(General, estadio.general.capacidad);
	generarLocalidades(Palco, estadio.palco.capacidad);
	generarLocalidades(Tribuna, estadio.tribuna.capacidad);
	/*
	imprimirLista(General);
	imprimirLista(Palco);
	imprimirLista(Tribuna);*/
}

void imprimirArchivo(Lista General,  Lista Palco, Lista Tribuna, Lista General2,  Lista Palco2, Lista Tribuna2, Cliente cliente)
{

	int i=0;
	char buffer[80]={0};
	Lista auxiliarLista1 = new Nodo();
	Lista auxiliarLista2 = new Nodo();
	Lista auxiliarLista3 = new Nodo();
	Lista auxiliarLista4 = new Nodo();
	Lista auxiliarLista5 = new Nodo();
	Lista auxiliarLista6 = new Nodo();
	
	auxiliarLista1 = General;
	auxiliarLista2 = Palco;
	auxiliarLista3 = Tribuna;
	auxiliarLista4 = General2;
	auxiliarLista5 = Palco2;
	auxiliarLista6 = Tribuna2;

	printf("\n\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	printf("\n\t\t\t\t\t\tESTRUCTURA DE DATOS 2479");
	printf("\n\t\t\t\t      SISTEMA DE VENTAS PARA UN ESTADIO DE FUTBOL");
	printf("\n\n\t\tAutores:\t Bryan Tualle  y  Sandra Castro");
	printf("\n\t\tFecha:\t\t 2017/11/21");
	printf("\n\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta");
	printf("\n\t\tCarrera:\t Ing. Sistemas e informatica");
	/*
	while(lista && lista->anterior)
	{
		printf(" %d", auxiliarLista->asiento);
		lista = lista->anterior;
	}
	printf(" %d", auxiliarLista->asiento);
	*/
	
	auxiliarLista1 = General;
	auxiliarLista2 = Palco;
	auxiliarLista3 = Tribuna;
	auxiliarLista4 = General2;
	auxiliarLista5 = Palco2;
	auxiliarLista6 = Tribuna2;
	
	printf("\n%s con Cedula %d adquirio las entradas", cliente.Nombre, cliente.cedula);
	printf("\n\nGeneral:");
	while (auxiliarLista1 != NULL && auxiliarLista1 )
	{
		if(auxiliarLista1->cedula == cliente.cedula )
			printf("\nAsiento:\t %d", auxiliarLista1->asiento);	
		auxiliarLista1 = auxiliarLista1->siguienteDireccion;
	}
	printf("\n\nPalco:");
	while (auxiliarLista2 != NULL && auxiliarLista2->cedula == cliente.cedula )
	{
		printf("\nAsiento:\t %d", auxiliarLista2->asiento);	
		auxiliarLista2 = auxiliarLista2->siguienteDireccion;
	}
	printf("\n\nTribuna:");
	while (auxiliarLista3 != NULL && auxiliarLista3->cedula == cliente.cedula )
	{
		printf("\nAsiento:\t %d", auxiliarLista3->asiento);	
		auxiliarLista3 = auxiliarLista3->siguienteDireccion;
	}
		printf("\n\nGeneral:");
	while (auxiliarLista4 != NULL && auxiliarLista4->cedula == cliente.cedula )
	{
		printf("\nAsiento:\t %d", auxiliarLista4->asiento);	
		auxiliarLista4 = auxiliarLista4->siguienteDireccion;
	}
	printf("\n\nPalco:");
	while (auxiliarLista5 != NULL && auxiliarLista5->cedula == cliente.cedula )
	{
		printf("\nAsiento:\t %d", auxiliarLista5->asiento);	
		auxiliarLista5 = auxiliarLista5->siguienteDireccion;
	}
	printf("\n\nTribuna:");
	while (auxiliarLista6 != NULL && auxiliarLista6->cedula == cliente.cedula )
	{
		printf("\nAsiento:\t %d", auxiliarLista6->asiento);	
		auxiliarLista6 = auxiliarLista6->siguienteDireccion;
	}
	
	
	///////////////////////////////////////DATO UNICO/////////////////////////////////////////
	FILE *archivo_unico=NULL;
	sprintf(buffer,"C:/Users/BRYAN TUALLE/Documents/GitHub/Proyecto-Entradas-a-un-estadio-de-futbol/archivo.txt");
	archivo_unico=fopen(buffer,"w");
	fprintf(archivo_unico,"\n\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	fprintf(archivo_unico,"\n\t\t\t\t\t\tESTRUCTURA DE DATOS 2479");
	fprintf(archivo_unico,"\n\t\t\t\t      SISTEMA DE VENTAS PARA UN ESTADIO DE FUTBOL");
	fprintf(archivo_unico,"\n\n\t\tAutores:\t Bryan Tualle  y  Sandra Castro");
	fprintf(archivo_unico,"\n\t\tFecha:\t\t 2017/11/21");
	fprintf(archivo_unico,"\n\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta");
	fprintf(archivo_unico,"\n\t\tCarrera:\t Ing. Sistemas e informatica");
	
	fprintf(archivo_unico,"\n%s con Cedula %d adquirio las entradas", cliente.Nombre, cliente.cedula);
	fprintf(archivo_unico,"\n\nGeneral:");
	while (auxiliarLista1 != NULL && auxiliarLista1->cedula == cliente.cedula )
	{
		fprintf(archivo_unico,"\nAsiento:\t %d", auxiliarLista1->asiento);	
		auxiliarLista1 = auxiliarLista1->siguienteDireccion;
	}
	fprintf(archivo_unico,"\n\nPalco:");
	while (auxiliarLista2 != NULL && auxiliarLista2->cedula == cliente.cedula )
	{
		fprintf(archivo_unico,"\nAsiento:\t %d", auxiliarLista2->asiento);	
		auxiliarLista2 = auxiliarLista2->siguienteDireccion;
	}
	fprintf(archivo_unico,"\n\nTribuna:");
	while (auxiliarLista3 != NULL && auxiliarLista3->cedula == cliente.cedula )
	{
		fprintf(archivo_unico,"\nAsiento:\t %d", auxiliarLista3->asiento);	
		auxiliarLista3 = auxiliarLista3->siguienteDireccion;
	}
		fprintf(archivo_unico,"\n\nGeneral:");
	while (auxiliarLista4 != NULL && auxiliarLista4->cedula == cliente.cedula )
	{
		fprintf(archivo_unico,"\nAsiento:\t %d", auxiliarLista4->asiento);	
		auxiliarLista4 = auxiliarLista4->siguienteDireccion;
	}
	fprintf(archivo_unico,"\n\nPalco:");
	while (auxiliarLista5 != NULL && auxiliarLista5->cedula == cliente.cedula )
	{
		fprintf(archivo_unico,"\nAsiento:\t %d", auxiliarLista5->asiento);	
		auxiliarLista5 = auxiliarLista5->siguienteDireccion;
	}
	fprintf(archivo_unico,"\n\nTribuna:");
	while (auxiliarLista6 != NULL && auxiliarLista6->cedula == cliente.cedula )
	{
		fprintf(archivo_unico,"\nAsiento:\t %d", auxiliarLista6->asiento);	
		auxiliarLista6 = auxiliarLista6->siguienteDireccion;
	}
	
	fclose(archivo_unico);

	//LLAMO A LOS JAR DE JAVA
	system("start QR.jar ");
	system("start D:/GENERADORPDF.jar");
	getch();

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

void gotoxy(int x,int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
 }

/////////////////////////////////////
void menuSeleccion(const char *opciones[], int numeroOpciones, const char *partidos[], int numeroPartidos, const char *subOpciones[], int numeroSubOpciones, int coordenada[])
{
	
	Tiempo fechasPartidos[2];
	Estadio estadio[2];
	Cliente cliente[N];
	
	Lista General1 = new Nodo();
	Lista Palco1 = new Nodo();
	Lista Tribuna1 = new Nodo();
	General1 = Palco1 = Tribuna1 = NULL;
	int contadorPartido1=0, contadorPartido2=0;
	
	Lista General2 = new Nodo();
	Lista Palco2 = new Nodo();
	Lista Tribuna2 = new Nodo();
	General2 = Palco2 = Tribuna2 = NULL;
	
	bool repite = true, aux = true;
	int tecla=0,x=1,x1=10,i, selec=1,opcion=0;
	
	int tecla2=0, moveX=1;
	bool repetirMove = true;
	
	long int cedulaBuscar[10], u[10];
	long int cedulaBuscar2;
	
	llenarDatosEstadio(estadio[0], N , "Estadio de Sangolqui", General1, Palco1, Tribuna1);				//Inserto la informacion del estadio y partidos
	estadio[0].capacidadTotal = N;
	llenarDatosPartidos(fechasPartidos);
	llenarDatosEstadio(estadio[1], N , "Estadio de Sangolqui", General2, Palco2, Tribuna2);				//Inserto la informacion del estadio y partidos
	estadio[0].capacidadTotal = N;

	//generarLocalidades()
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
									
									
									
									if(informarAsientosDisponibles(General1, Palco1, Tribuna1, General2, Palco2, Tribuna2, selec - 1) == true)
									{
										//printf("\n\nAsientos Disponibles ");
										
										do
										{
											system("cls");
											informacionParido(partidos, selec-1, fechasPartidos);
											informarAsientosDisponibles(General1, Palco1, Tribuna1, General2, Palco2, Tribuna2, selec - 1);
											
											
											if(moveX ==1)
											{
												color(7,3);
												gotoxy(30, 20);
												printf("COMPRAR");
												color(15,0);
												gotoxy(80, 20);
												printf("CANCELAR");
												
											}
											else
											{
												gotoxy(30, 20);
												printf("COMPRAR");
												color(7,3);
												gotoxy(80, 20);
												printf("CANCELAR");
												color(15,0);
											}
											
											
											
											do											// Metodo para que me permita ingresar solo las flechas o ENTER
											{
												fflush(stdin);
												tecla2=getch();
											}while( (tecla2!=77)&&(tecla2!=75)&&(tecla2!=13) );
											
											switch(tecla2)
											{
												case 75:								//Izquierda
												{
													moveX--;
													if(moveX<1)
													{
														moveX = 2;
													}
													repetirMove = true;
													break;
												}
												
												case 77:
												{
													moveX++;
													if(moveX>2)
													{
														moveX = 1;
													}
													repetirMove = true;
													break;
												}
												
												case 13:
												{
													
													if((selec - 1) ==0 && (moveX-1)==0)
													{
														
														ingresoDatos(cliente, contadorPartido1 , General1, Palco1, Tribuna1);
														contadorPartido1++;
													}
													else
													{
														if((selec - 1) ==1 && (moveX-1)==0)
														ingresoDatos(cliente, contadorPartido2, General2, Palco2, Tribuna2);
														contadorPartido2++;
													}
													
													
													repetirMove = false;
													break;
												}		
											}
											
										}while(repetirMove);
										
										
									}
									else
									{
										printf("\n\nEntradas Agotadas");
										getch();
									}
									
									
									

									
									aux=false;
									repite=true;
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
									printf("AYUDA");
									color(15,0);
								}
								else
								{
									printf("AYUDA");
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
									
									int x;
									for(;;)
								    {
										x=getch();
							        	if(x==59)
							        	{
								        	system("C:\\Users\\BRYAN TUALLE\\Desktop\\Extras\\Ayuda.chm");
										}
									}
									
									aux=false;
									repite=true;
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
									
									system("cls");
									printf("\nIngrese el numero de la cedula a buscar:");
									
									
									validarCedula(cedulaBuscar);
									cedulaBuscar2 = convertirCedula(u);
									int auxcont=0;
									int auxbusqueda=0;
									do
									{
										if(cliente[auxcont].cedula == cedulaBuscar2) auxbusqueda =auxcont;
										auxcont++;
									}while(cliente[auxcont].cedula != cedulaBuscar2);
									imprimirArchivo( General1, Palco1, Tribuna1, General2,  Palco2, Tribuna2, cliente[auxbusqueda]);
									getch();
									aux=false;
									repite=true;
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
									
									
									if(informarAsientosDisponibles(General1, Palco1, Tribuna1, General2, Palco2, Tribuna2, selec - 1) == true)
									{
										//printf("\n\nAsientos Disponibles ");
										
										do
										{
											system("cls");
											informacionParido(partidos, selec-1, fechasPartidos);
											informarAsientosDisponibles(General1, Palco1, Tribuna1, General2, Palco2, Tribuna2, selec - 1);
											
											
											if(moveX ==1)
											{
												color(7,3);
												gotoxy(30, 20);
												printf("COMPRAR");
												color(15,0);
												gotoxy(80, 20);
												printf("CANCELAR");
												
											}
											else
											{
												gotoxy(30, 20);
												printf("COMPRAR");
												color(7,3);
												gotoxy(80, 20);
												printf("CANCELAR");
												color(15,0);
											}
											
											
											
											do											// Metodo para que me permita ingresar solo las flechas o ENTER
											{
												fflush(stdin);
												tecla2=getch();
											}while( (tecla2!=77)&&(tecla2!=75)&&(tecla2!=13) );
											
											switch(tecla2)
											{
												case 75:								//Izquierda
												{
													moveX--;
													if(moveX<1)
													{
														moveX = 2;
													}
													repetirMove = true;
													break;
												}
												
												case 77:
												{
													moveX++;
													if(moveX>2)
													{
														moveX = 1;
													}
													repetirMove = true;
													break;
												}
												
												case 13:
												{
													
													if((selec - 1) ==0 && (moveX-1)==0)
													{
														
														ingresoDatos(cliente, contadorPartido1 , General1, Palco1, Tribuna1);
														contadorPartido1++;
													}
													else
													{
														if((selec - 1) ==1 && (moveX-1)==0)
														ingresoDatos(cliente, contadorPartido2, General2, Palco2, Tribuna2);
														contadorPartido2++;
													}
													
													
													repetirMove = false;
													break;
												}		
											}
											
										}while(repetirMove);
										
										
									}
									else
									{
										printf("\n\nEntradas Agotadas");
										getch();
									}

									//informacionParido(partidos, selec-1, fechasPartidos);
									
									aux=false;
									repite=true;
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
									printf("AYUDA");
									color(15,0);
								}
								else
								{
									printf("AYUDA");
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
									
									int x;
									for(;;)
								    {
										x=getch();
							        	if(x==59)
							        	{
								        	system("C:\\Users\\BRYAN TUALLE\\Desktop\\Extras\\Ayuda.chm");
										}
									}

									
									aux=false;
									repite=true;
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
									
									int x;
									for(;;)
								    {
										x=getch();
							        	if(x==59)
							        	{
								        	system("C:\\Users\\BRYAN TUALLE\\Desktop\\Extras\\Ayuda.chm");
										}
									}
									
									aux=false;
									repite=true;
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
								int x;
								for(;;)
							    {
									x=getch();
						        	if(x==59)
						        	{
							        	system("C:\\Users\\Public\\Documents\\ExtrasAyuda\\Ayuda.chm");
									}
								}
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
									
									
									if(informarAsientosDisponibles(General1, Palco1, Tribuna1, General2, Palco2, Tribuna2, selec - 1) == true)
									{
										//printf("\n\nAsientos Disponibles ");
										
										do
										{
											system("cls");
											informacionParido(partidos, selec-1, fechasPartidos);
											informarAsientosDisponibles(General1, Palco1, Tribuna1, General2, Palco2, Tribuna2, selec - 1);
											
											
											if(moveX ==1)
											{
												color(7,3);
												gotoxy(30, 20);
												printf("COMPRAR");
												color(15,0);
												gotoxy(80, 20);
												printf("CANCELAR");
												
											}
											else
											{
												gotoxy(30, 20);
												printf("COMPRAR");
												color(7,3);
												gotoxy(80, 20);
												printf("CANCELAR");
												color(15,0);
											}
											
											
											
											do											// Metodo para que me permita ingresar solo las flechas o ENTER
											{
												fflush(stdin);
												tecla2=getch();
											}while( (tecla2!=77)&&(tecla2!=75)&&(tecla2!=13) );
											
											switch(tecla2)
											{
												case 75:								//Izquierda
												{
													moveX--;
													if(moveX<1)
													{
														moveX = 2;
													}
													repetirMove = true;
													break;
												}
												
												case 77:
												{
													moveX++;
													if(moveX>2)
													{
														moveX = 1;
													}
													repetirMove = true;
													break;
												}
												
												case 13:
												{
													
													if((selec - 1) ==0 && (moveX-1)==0)
													{
														
														ingresoDatos(cliente, contadorPartido1 , General1, Palco1, Tribuna1);
														contadorPartido1++;
													}
													else
													{
														if((selec - 1) ==1 && (moveX-1)==0)
														ingresoDatos(cliente, contadorPartido2, General2, Palco2, Tribuna2);
														contadorPartido2++;
													}
													
													
													repetirMove = false;
													break;
												}		
											}
											
										}while(repetirMove);
										
										
									}
									else
									{
										printf("\n\nEntradas Agotadas");
										getch();
									}
									
									
									

									
									aux=false;
									repite=true;
									break;
									
									
									informacionParido(partidos, selec-1, fechasPartidos);
									

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
									printf("AYUDA");
									color(15,0);
								}
								else
								{
									printf("AYUDA");
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
									
									int x;
									for(;;)
								    {
										x=getch();
							        	if(x==59)
							        	{
								        	system("C:\\Users\\BRYAN TUALLE\\Desktop\\Extras\\Ayuda.chm");
										}
									}
									
									aux=false;
									repite=true;
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
								
								
								int x;
								for(;;)
							    {
									x=getch();
						        	if(x==59)
						        	{
							        	system("C:\\Users\\Public\\Documents\\ExtrasAyuda\\Ayuda.chm");
									}
								}
								
								printf("\t\t\t\t GRACIAS");
								imagen();
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
	const char *opciones[]={"  Venta de Entradas   ", "Modificacion Asiento  ", "  Ayuda de Ventas       ", "  Consulta de Entradas  ","   Salir del Sistema   "};
	const char *partidos[]={"  Clan Juvenil VS El Nacional  ", "  IDV VS U. Catolica           "};
	const char *subOpciones[]={"  CEDULA  "};
	
	int numeroOpciones = 5;
	int numeroPartidos = 2;
	int numeroSubOpciones = 1;
	int coordenada[2];
	/*
	Lista lista = new Nodo();
	lista = NULL;
	generarLocalidades(lista, 10);
	getch();*/
	color(15,0);
	menuSeleccion(opciones,numeroOpciones, partidos, numeroPartidos, subOpciones, numeroSubOpciones, coordenada );
	
	
	
}
