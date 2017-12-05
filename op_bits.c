/*****************************************************/
/* PAR     : H.Saulnier et F.Henri							*/
/*****************************************************/

/* implémentation des fonctions offertes dans op_bits.h*/
/* toutes sont simples et basées sur les bitwise operators du C */

#include "op_bits.h"

#include <stdio.h>
#include <stdlib.h>


/*****************************************************/
/*		DEFINITIONS DES FONCTIONS				*/
/*****************************************************/
/*****************************************************/

void voir_bits(unsigned int nombre){	
	int i;
	// boucle d'affichage de chaque bit obtenu de get_bit
	for(i = INT_BIT - 1; i > -1; i-=1)
		printf("%d", get_bit(nombre,i));
}

/*****************************************************/
int get_bit(unsigned int nombre, int ordre){
	// un bitwise and avec un train de bit n'ayant qu'un 1
	// judicieusement placé
	return (nombre & (1<<ordre)) != 0;
}

/*****************************************************/
unsigned int set_bit(unsigned int nombre, int ordre){
	// un bitwise or avec un train de bit n'ayant qu'un 1
	// judicieusement placé
	 return nombre | (1 << ordre);
}

/*****************************************************/
unsigned int clear_bit(unsigned int nombre, int ordre){
	// un bitwise and avec un train de bits que de 1 avec un 
	// seul  0 judicieusement placé
	return nombre & ~(1<<ordre);
}

/*****************************************************/
unsigned int flip_bit(unsigned int nombre, int ordre){
	// s'il est à 1, on clear sinon on set
	if (get_bit(nombre, ordre))
		return clear_bit(nombre, ordre);
	else
		return set_bit(nombre, ordre);
}

/*****************************************************/
/*****************************************************/

