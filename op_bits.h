/**********************************************************/
/*   le groupe d'info du SEG	pr�sente					*/
/**********************************************************/

/* Ce module offre les  actions les plus standard sur les bits
	d'un entier positif 
*/ 

/*  Un entier sur nos petites machines ont une repr�sentation
	� 4 bytes(32 bits) au d�but du vingt et uni�me si�cle 
*/

/* L'ordre des bits dans un entier selon la tradition 
  commence � 0 , ordre du bit le moins significatif  jusqu'au nombre
  total de bits -1
  Avec 32 bits, l'ordre peut varier de 0 � 31  inclusivement
*/
/*
Le module offre de : 
afficher les bits d'un entier avec la fonction  voir_bits(nombre)
obtenir la valeur d'un bit  avec la fonction  get_bit(nombre, ordre)
mettre un bit � 1 dans un entier avec la fonction  set_bit(nombre, ordre)
mettre un bit � 0 dans un entier avec la fonction  clear_bit(nombre, ordre)
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

/* l'intervalle d'ordre acceptable ira donc de 0 �  INT_BIT-1 */
/*****************************************************/

/*****************************************************/
/*****************************************************/


/***************** VOIR_BITS ****************************/
/* 
	Affiche les bits du nombre re�u � l'�cran.        
	PARAMETRE : nombre , un entier non sign�		
	RETOUR : rien								
	SPECIFICATIONS :								
	Les bits sont affich�s du plus significatif au moins significatif
	Peu importe en fait le signe du param�tre effectif
*/

void voir_bits(	unsigned int nombre);
/**********************************************************/

/******************* GET_BIT **********************/
/* 
	donne la valeur du  bit d'ordre sp�cifi�.		
	PARAMETRES : nombre , un entier non sign�						
	          ordre , sp�cifie le bit voulu dans nombre. 
	RETOUR : 0 ou 1 								
	SPECIFICATIONS :							
	Si ordre n'est pas dans l'intervalle correct, 
	alors la fonction retourne 0.	
*/

int get_bit(unsigned int nombre, int ordre);
/**********************************************************/

/*********************** SET_BIT **************************/
/* 
	donne la valeur du nombre avec le bit d'ordre sp�cifi� mis � 1 
    PARAMETRES : nombre , un entier quelconque					
              ordre , sp�cifie le bit mis � 1 dans nombre. 
	RETOUR : la valeur obtenue du param�tre avec ce bit � 1								
	SPECIFICATIONS :								
	Si ordre n'est pas dans l'intervalle correct, 
	la	fonction retourne la valeur re�ue.	
*/

unsigned int set_bit(unsigned int nombre, int ordre);
/**********************************************************/

/****************** CLEAR_BIT **************************/
/* 
	donne la valeur du nombre  avec le bit d'ordre sp�cifi� mis � 0 
	PARAMETRES : nombre , un entier quelconque						
	            ordre , sp�cifie le bit mis � 0 dans nombre. 
	RETOUR : la valeur obtenue du param�tre avec ce bit � 0						
	SPECIFICATIONS :								
	Si ordre n'est pas dans l'intervalle correct, 
	alors la fonction retourne la valeur re�ue.
*/

unsigned int clear_bit(unsigned int  nombre, int ordre);
/**********************************************************/

/******************** FLIP_BIT *************************/
/* 
	donne la valeur du nombre re�u  avec le bit invers� 
	d'ordre sp�cifi�
	Entr�e : nombre : un entier positif					
	          ordre : sp�cifie le bit  � inverser dans nombre. 
	RETOUR : la valeur obtenue du param�tre avec ce bit invers�					
	SPECIFICATIONS :							
	Si ordre n'est pas dans l'intervalle correct, 
	alors la fonction retourne la valeur re�ue.	
*/
unsigned int flip_bit(unsigned int  nombre, int ordre);
/**********************************************************/

#endif
/**********************************************************/

