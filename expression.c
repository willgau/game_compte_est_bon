/* Ce module offre la possibilit� de construire une expression arithm�tique
   avec des nombres et des op�rateurs.  Aucune validation sur les valeurs re�ues.

   On peut voir cela comme un assemblage de nombre et de caract�res
*/ 

/*
Le module offre de : 
initialiser l'expression
afficher l'expression (en mode console)
ajouter un nombre � l'expression avec la procedure ajouter_nombre(int nombre)
ajouter un op�rateur avec la proc�dure ajouter_operateur (char operateur)
*/

/*STRAT�GIE : on utilise untableau de caract�res static pour conserver l'expression.*/
#include <stdlib.h> //NULL
#include <stdio.h> //printf
#include <string.h> //strcat
#include "expression.h"

//Sert � itoa
#define BASE 10

//� ajouter apr�s un ajout
#define ESPACE " "

//saut de ligne en C
#define SAUT_LIGNE "\n"

//La cha�ne qui contrient l'expression
static char expression[MAX_CAR];

//Remet l'expression dans son �tat initial (vide)
void initialiser_expression()
{	
		expression[0] = NULL;
}

//Ajoute le nombre re�u � l'expression + un espace
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

//Ajouter un saut de ligne � l'expression
void ajouter_saut_ligne()
{
	strcat(expression,SAUT_LIGNE);
}

//Ajoute l'op�rateur re�u � l'expression + un espace
void ajouter_operateur(char operateur)
{
	//Pour convertir le caract�re en string
	char str_tmp[MAX_CAR];
	strcat(expression, car2str(str_tmp, operateur));
	strcat(expression, ESPACE);
}

//Affiche l'expression � la position courante du curseur en mode console
void afficher_expression()
{

	printf(expression);
}