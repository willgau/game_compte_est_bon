#include <stdlib.h> //rand

//G�n�re un entier entre min et max
int alea(int min,int max)
{
	//Strat�gie, on utilise le g�n�rateur de C qui retourne une valeur en 1 et RANDMAX
	return rand() % (max - min + 1) + min;
}
