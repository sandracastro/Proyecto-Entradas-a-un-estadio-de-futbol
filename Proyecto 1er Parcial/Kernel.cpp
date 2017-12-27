#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>


//ESTRUCTURAS

struct Localidad
{
	char nombreLocalidad[10];
	int capacidad;	
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
    int segundo;
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



main()
{
	
}
