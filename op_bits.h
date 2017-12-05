/**********************************************************/
/*   le groupe d'info du SEG	présente					*/
/**********************************************************/

/* Ce module offre les  actions les plus standard sur les bits
	d'un entier positif 
*/ 

/*  Un entier sur nos petites machines ont une représentation
	à 4 bytes(32 bits) au début du vingt et unième siècle 
*/

/* L'ordre des bits dans un entier selon la tradition 
  commence à 0 , ordre du bit le moins significatif  jusqu'au nombre
  total de bits -1
  Avec 32 bits, l'ordre peut varier de 0 à 31  inclusivement
*/
/*
Le module offre de : 
afficher les bits d'un entier avec la fonction  voir_bits(nombre)
obtenir la valeur d'un bit  avec la fonction  get_bit(nombre, ordre)
mettre un bit à 1 dans un entier avec la fonction  set_bit(nombre, ordre)
mettre un bit à 0 dans un entier avec la fonction  clear_bit(nombre, ordre)
inverser un bit dans un entier avec la fonction  flip_bit(nombre, ordre)

*/

/**********************************************************/

#ifndef  MODULE_OP_BITS
#define  MODULE_OP_BITS

/**********************************************************/

/*****************************************************/
/*		CONSTANTE					*/
/*****************************************************/
/*  On aura un symbole pour le nombre de bits dans un entier 
	sur la plateforme de travail.
*/
#define INT_BIT	 (sizeof(int) * 8)

/* l'intervalle d'ordre acceptable ira donc de 0 à  INT_BIT-1 */
/*****************************************************/

/*****************************************************/
/*****************************************************/


/***************** VOIR_BITS ****************************/
/* 
	Affiche les bits du nombre reçu à l'écran.        
	PARAMETRE : nombre , un entier non signé		
	RETOUR : rien								
	SPECIFICATIONS :								
	Les bits sont affichés du plus significatif au moins significatif
	Peu importe en fait le signe du paramètre effectif
*/

void voir_bits(	unsigned int nombre);
/**********************************************************/

/******************* GET_BIT **********************/
/* 
	donne la valeur du  bit d'ordre spécifié.		
	PARAMETRES : nombre , un entier non signé						
	          ordre , spécifie le bit voulu dans nombre. 
	RETOUR : 0 ou 1 								
	SPECIFICATIONS :							
	Si ordre n'est pas dans l'intervalle correct, 
	alors la fonction retourne 0.	
*/

int get_bit(unsigned int nombre, int ordre);
/**********************************************************/

/*********************** SET_BIT **************************/
/* 
	donne la valeur du nombre avec le bit d'ordre spécifié mis à 1 
    PARAMETRES : nombre , un entier quelconque					
              ordre , spécifie le bit mis à 1 dans nombre. 
	RETOUR : la valeur obtenue du paramètre avec ce bit à 1								
	SPECIFICATIONS :								
	Si ordre n'est pas dans l'intervalle correct, 
	la	fonction retourne la valeur reçue.	
*/

unsigned int set_bit(unsigned int nombre, int ordre);
/**********************************************************/

/****************** CLEAR_BIT **************************/
/* 
	donne la valeur du nombre  avec le bit d'ordre spécifié mis à 0 
	PARAMETRES : nombre , un entier quelconque						
	            ordre , spécifie le bit mis à 0 dans nombre. 
	RETOUR : la valeur obtenue du paramètre avec ce bit à 0						
	SPECIFICATIONS :								
	Si ordre n'est pas dans l'intervalle correct, 
	alors la fonction retourne la valeur reçue.
*/

unsigned int clear_bit(unsigned int  nombre, int ordre);
/**********************************************************/

/******************** FLIP_BIT *************************/
/* 
	donne la valeur du nombre reçu  avec le bit inversé 
	d'ordre spécifié
	Entrée : nombre : un entier positif					
	          ordre : spécifie le bit  à inverser dans nombre. 
	RETOUR : la valeur obtenue du paramètre avec ce bit inversé					
	SPECIFICATIONS :							
	Si ordre n'est pas dans l'intervalle correct, 
	alors la fonction retourne la valeur reçue.	
*/
unsigned int flip_bit(unsigned int  nombre, int ordre);
/**********************************************************/

#endif
/**********************************************************/

