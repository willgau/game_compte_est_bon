#include <stdlib.h> //rand

//Génère un entier entre min et max
int alea(int min,int max)
{
	//Stratégie, on utilise le générateur de C qui retourne une valeur en 1 et RANDMAX
	return rand() % (max - min + 1) + min;
}
