#include<stdio.h>
#include <windows.h>

int color(int b, int f);

int color(int b, int f){
	HANDLE  hConsole;
	WORD    ForeColor = 0;
	WORD    BackColor;
	WORD    wAttributesOld;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

  // **  Open the current console input buffer.
  // **  Abrir la consola actual memoria intermedia de entrada.
  if( ( hConsole = CreateFile("CONOUT$", GENERIC_WRITE | GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,
                     0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L) )
                 == (HANDLE) -1 ) {
      printf("\nError: Unable to open console.\n");
      return( -1 );
  }

  // **  Get and Save information on the console screen buffer.
  // **  Obtener y guardar información sobre la pantalla de la consola de amortiguación.
	GetConsoleScreenBufferInfo( hConsole, &csbi );
	wAttributesOld = csbi.wAttributes;

	BackColor = b;
	ForeColor= f;
	SetConsoleTextAttribute( hConsole, (WORD) ( (BackColor << 4) | ForeColor) );
	return 0;
}