#include <iostream>

class NodoCola
{

	public:
		int numero;
		//int identificador;
		NodoCola *siguiente;
		/*
		NodoCola(int x)
		{
			numero = x;
			siguiente = NULL;
		}	
		*/
		NodoCola(int);
};

NodoCola::NodoCola(int x)
{
	numero = x;
	siguiente = NULL;
}

