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

//MAximum de caractères possibles pour une expression (1 chiffre == 1 caractère)
#define MAX_CAR 256

//Les opérateurs possibles dans une expression
#define ADDITION '+'
#define SOUSTRACTION '-'
#define MULT '*'
#define DIVISION '/'
#define EGAL '='

//Prototype

//Remet l'expression dans son état initial (vide)
void initialiser_expression();

//Ajoute le nombre reçu à l'expression + un espace
void ajouter_nombre(int nombre);

//Ajoute l'opérateur reçu à l'expression + un espace
void ajouter_operateur(char operateur);

//Ajoute un saut de ligne à l'expresssion
void ajouter_saut_ligne();

//Affiche l'expression à la position courante du curseur en mode console
void afficher_expression();