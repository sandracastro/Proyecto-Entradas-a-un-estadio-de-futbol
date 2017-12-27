#include "Cola.h"

/*
										UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
												IMPLEMENTACION DE COLAS
				
				Autores: 				Bryan Tualle y	Sandra Castro
				Fecha de Creación:		21/11/2017
				Fecha de modificacion:	22/11/2017
				Docente: 				Ing. Edgar Fernando Solis Acosta
				Carrera: 				Ing. Sistemas e Informática
*/
void portada()
{
	printf("\n\t\t\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE");
	printf("\n\t\t\t\t\t\tESTRUCTURA DE DATOS 2479");
	printf("\n\t\t\t\t\t\t IMPLEMENTACION DE COLAS");
	printf("\n\n\t\tAutores:\t Bryan Tualle  y  Sandra Castro");
	printf("\n\t\tFecha:\t\t 2017/12/17");
	printf("\n\t\tProfesor:\t Ing. Edgar Fernando Solis Acosta");
	printf("\n\t\tCarrera:\t Ing. Sistemas e informatica");
}

int aleatorio()
{
	int num=1;
	
	num = 1 + (rand()%10);
	return num;
}

int maximoPareja(int x, int y)
{
	if(x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void imprimirTabla(Cola colaCliente, Cola colaTLlegada, Cola colaTEspera, Cola colaTDescanzo, Cola colaTServicio,
					  Cola colaTSalida, Cola colaTEntreLlegadas, int limite)
{
	int i;
	
	for(i=0; i<=limite; i++)
	{
		if(i==0)
		{
			printf("\n  Cliente         T. LLegada \t    T. Espera \tT. Descanzo \tT. Servicio \tT. Salida \tT. Entre LLegada");
		}
		else
		{
			printf("\n     %d \t\t\t%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d", colaCliente.Buscar(i), colaTLlegada.Buscar(i), colaTEspera.Buscar(i),
			colaTDescanzo.Buscar(i), colaTServicio.Buscar(i),colaTSalida.Buscar(i), colaTEntreLlegadas.Buscar(i));
		}
		
	}
}

void cola(int limite)
{
	int i;
    Cola colaCliente;
    Cola colaTLlegada;
    Cola colaTEspera;
    Cola colaTDescanzo;
    Cola colaTServicio;
    Cola colaTSalida;
    Cola colaTEntreLlegadas;
/*
	//Generar el numero del cliente
	for(i=1; i<=limite; i++)
	{
		colaCliente.insertar(i,i);
	}
	
	//Generar el tiempo de llegada
	for(i=1; i<=limite; i++)
	{
		if(i==1)
			colaTLlegada.insertar(aleatorio(),i);
		else
			colaTLlegada.insertar(aleatorio() + colaTLlegada.finalCola(), i);
	}
	
	//Generar el tiempo de servicio
	for(i=1; i<=limite; i++)
	{
		colaTServicio.insertar(aleatorio(), i);
	}
	
	//Generar el tiempo de salida
	
	for(i=1; i<=limite; i++)
	{
		colaTSalida.insertar( colaTLlegada.Buscar(i) + colaTEspera.Buscar(i) + colaTServicio.Buscar(i),i);
	}
	
	
	for(i=1; i<=limite; i++)
	{
		
		if(i==1)
		{
			colaTDescanzo.insertar(0,i);	
		}
		else
		{
			colaTDescanzo.insertar(maximoPareja(colaTLlegada.Buscar(i), colaTSalida.Buscar(i-1)) - colaTSalida.Buscar(i-1),i);
			printf("\n%d) Descanzo: ( %d , %d) - %d",i, maximoPareja(colaTLlegada.Buscar(i), colaTSalida.Buscar(i-1)) - colaTSalida.Buscar(i-1));
		}
	}
	
	for(i=1; i<=limite; i++)
	{
		if(i==1)
		{
			colaTEspera.insertar(0,i);	
		}
		else
		{
			colaTEspera.insertar(maximoPareja(colaTLlegada.Buscar(i), colaTSalida.Buscar(i-1)) - colaTLlegada.Buscar(i),i);
			printf("\n%d) Espera: ( %d , %d) - %d",i, maximoPareja(colaTLlegada.Buscar(i), colaTSalida.Buscar(i-1)) - colaTLlegada.Buscar(i));
		}
		
	}
	

	//Generar el tiempo entre llegadas
	for(i=1; i<=limite; i++)
	{
		//colaTEntreLlegadas.insertar(0,0);
		if(i==1)
		{
			colaTEntreLlegadas.insertar(colaTLlegada.Buscar(i), 1);	
		}
		else
		{
			colaTEntreLlegadas.insertar(colaTLlegada.Buscar(i) - colaTLlegada.Buscar(i-1),i);
		}
	}
	*/
	
	for(i=1; i<=limite; i++)
	{
		//colaTEntreLlegadas.insertar(0,0);
		if(i==1)
		{
			colaCliente.insertar(i,i);
			colaTLlegada.insertar(aleatorio(),i);
			colaTEspera.insertar(0,i);
			colaTDescanzo.insertar(0,i);
			colaTServicio.insertar(aleatorio(), i);	
			colaTSalida.insertar( colaTLlegada.Buscar(i) + colaTEspera.Buscar(i) + colaTServicio.Buscar(i),i);
			colaTEntreLlegadas.insertar(colaTLlegada.Buscar(i), i);	
			
		}
		else
		{
			colaCliente.insertar(i,i);
			colaTLlegada.insertar(aleatorio() + colaTLlegada.finalCola(), i);
			colaTEspera.insertar(maximoPareja(colaTLlegada.Buscar(i), colaTSalida.Buscar(i-1)) - colaTLlegada.Buscar(i),i);
			colaTDescanzo.insertar(maximoPareja(colaTLlegada.Buscar(i), colaTSalida.Buscar(i-1)) - colaTSalida.Buscar(i-1),i);
			colaTServicio.insertar(aleatorio(), i);
			colaTSalida.insertar( colaTLlegada.Buscar(i) + colaTEspera.Buscar(i) + colaTServicio.Buscar(i),i);
			colaTEntreLlegadas.insertar(colaTLlegada.Buscar(i) - colaTLlegada.Buscar(i-1),i);
		}
	}
	
	
	
	imprimirTabla(colaCliente, colaTLlegada, colaTEspera, colaTDescanzo, colaTServicio, colaTSalida, colaTEntreLlegadas, limite);
}

main()
{
	int cantidad;

	do
	{
		system("cls");
		portada();
		printf("\n\n\nIngrese la cantidad de clientes:\t");
		scanf("%d", &cantidad);
	}while(cantidad<=0);
	
	cola(cantidad);

}

