#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"
//#include "NodoCola.h"

class Cola
{
	protected:
		
		class NodoCola
		{
		
			public:
				int numero;
				int identificador;
				NodoCola *siguiente;
				/*
				NodoCola(int x)
				{
					numero = x;
					siguiente = NULL;
				}	*/
				NodoCola(int x, int iden)
				{
					numero = x;
					identificador = iden;
					siguiente = NULL;
				}	
				//NodoCola(int);
		};
			
		NodoCola *frente;
		NodoCola *final;
		
	public:
		Cola();
	   	void insertar(int , int);
	    //int quitar();
	    //void borrarCola();
	    //int frenteCola();
	    int colaVacia();
	    void imprimirDatos();
	    void Pop();
	    int finalCola();
	    int Buscar(int);
	    ~Cola();
};

Cola::Cola()
{
	frente = final = NULL;
}

Cola::~Cola()
{
    //borrarCola ();
}
/*
void Cola :: borrarCola()
{
    for (; frente != NULL;)
    {
        NodoCola* a;
        a = frente;
        frente = frente -> siguiente;
        delete a;
    }
    final = NULL;
}
*/

int Cola :: colaVacia()
{
	if(frente == NULL)
	{
		return true;	
	}
	else
	{
		return false;
	}
}


void Cola :: insertar(int elemento, int ident)
{
    NodoCola* nuevo = new NodoCola (elemento,ident);
    
    //printf("\nNumero: %d",nuevo->numero);
    if (colaVacia())
    {
        frente = nuevo;
        final = frente;
    }
    else
    {
        final->siguiente = nuevo;
        final = nuevo;
    }
    //final = nuevo;
    //printf("\nfrente: %d",frente->numero);
    //printf("\nfinal: %d",final->numero);
    //printf("\nidentificador: %d",final->identificador);
    
}

/*
void Cola :: quitar()
{
    if (colaVacia())
    {
    	printf("\n\n\tCola vacía, no se puede extraer");
    	return 0;
	}
	else
	{
		//printf("\n\n\tCola vacía, no se puede extraer");
		int aux = frente -> numero;
	    NodoCola* a = frente;
	    frente = frente -> siguiente;
	    delete a;
	    return aux;
	}
}
*/
/*
int Cola :: frenteCola()
{
    if (colaVacia())
    {
    	printf("\n\n\tCola vacía");
	}
	
    return frente->numero;
}
*/

int Cola :: finalCola()
{
    if (colaVacia())
    {
    	printf("\n\n\tCola vacía");
	}
	else
	{
		return final->numero;	
	}

}


void Cola::imprimirDatos()
{
	NodoCola *actual = new NodoCola(0,0);
	actual = frente;

	if (frente != NULL)
	{
		while (actual != NULL)
		{
			printf("\n%d", actual->numero);
			actual = actual->siguiente;
		}
		printf("\n\n");
	}
	else
	{
		printf("\nLa cola está vacia");
	}
}
/*
void Cola::imprimirTabla()
{
	NodoCola *actual = new NodoCola(0);
	actual = frente;

	if (frente != NULL)
	{
		while (actual != NULL)
		{
			printf("\n%d", actual->numero);
			actual = actual->siguiente;
		}
		printf("\n\n");
	}
	else
	{
		printf("\nLa cola está vacia");
	}
}

*/

int Cola::Buscar(int dato)
{
	NodoCola *actual = new NodoCola(0,0);
	actual = frente;

	bool helper = false;
	int aux;
	int ret;

	if (frente != NULL)
	{
		while (actual != NULL && helper != true)
		{
			if (actual->identificador == dato)
			{
				ret = actual->numero;
				helper = true;
				aux = 1;
			}
			else
			{
				aux = 0;
				actual = actual->siguiente;
			}
		}
		if (aux == 0)
		{
			//cout << "El dato NO se encuentra en la cola.\n";
			helper = false;
		}
	}
	else
	{
		//printf("\nLa cola está vacia");
	}
	return(ret);
}


void Cola::Pop()
{
	//FIFO: First in First out
	NodoCola *actual = new NodoCola(0,0);
	actual = frente;

	if (frente != NULL)
	{
		if (actual == frente)
		{
			frente = frente->siguiente;
		}
	}
	else
	{
		printf("\nLa cola está vacia");
	}
}


