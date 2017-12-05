/* Ce module offre la possibilité de construire une expression arithmétique
   avec des nombres et des opérateurs.  Aucune validation sur les valeurs reçues.

   On peut voir cela comme un assemblage de nombre et de caractères
*/ 

/*
Le module offre de : 
initialiser l'expression
afficher l'expression (en mode console)
ajouter un nombre à l'expression avec la procedure ajouter_nombre(int nombre)
ajouter un opérateur avec la procédure ajouter_operateur (char operateur)
*/

/*STRATÉGIE : on utilise untableau de caractères static pour conserver l'expression.*/
#include <stdlib.h> //NULL
#include <stdio.h> //printf
#include <string.h> //strcat
#include "expression.h"

//Sert à itoa
#define BASE 10

//à ajouter après un ajout
#define ESPACE " "

//saut de ligne en C
#define SAUT_LIGNE "\n"

//La chaîne qui contrient l'expression
static char expression[MAX_CAR];

//Remet l'expression dans son état initial (vide)
void initialiser_expression()
{	
		expression[0] = NULL;
}

//Ajoute le nombre reçu à l'expression + un espace
void ajouter_nombre(int nombre)
{
	//Pour convertir le nombre en string
	char str_tmp[MAX_CAR];
	strcat(expression, itoa(nombre, str_tmp, BASE));
	strcat(expression, ESPACE);

}


//fonction locale 
char* car2str(char * str, char operateur)
{
	switch (operateur)
	{
	    case ADDITION : str = "+";break;
		case SOUSTRACTION : str = "-";break;
		case MULT : str = "*";break;
		case DIVISION : str = "/";break;
		case EGAL : str = "=";



	}
	return str;
}

//Ajouter un saut de ligne à l'expression
void ajouter_saut_ligne()
{
	strcat(expression,SAUT_LIGNE);
}

//Ajoute l'opérateur reçu à l'expression + un espace
void ajouter_operateur(char operateur)
{
	//Pour convertir le caractère en string
	char str_tmp[MAX_CAR];
	strcat(expression, car2str(str_tmp, operateur));
	strcat(expression, ESPACE);
}

//Affiche l'expression à la position courante du curseur en mode console
void afficher_expression()
{

	printf(expression);
}