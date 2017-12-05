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

//MAximum de caract�res possibles pour une expression (1 chiffre == 1 caract�re)
#define MAX_CAR 256

//Les op�rateurs possibles dans une expression
#define ADDITION '+'
#define SOUSTRACTION '-'
#define MULT '*'
#define DIVISION '/'
#define EGAL '='

//Prototype

//Remet l'expression dans son �tat initial (vide)
void initialiser_expression();

//Ajoute le nombre re�u � l'expression + un espace
void ajouter_nombre(int nombre);

//Ajoute l'op�rateur re�u � l'expression + un espace
void ajouter_operateur(char operateur);

//Ajoute un saut de ligne � l'expresssion
void ajouter_saut_ligne();

//Affiche l'expression � la position courante du curseur en mode console
void afficher_expression();