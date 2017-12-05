//Devoir #1 pour le cour INF145 fait par William Gauvin-Joyal (GAUW23019407)du pour le 6 octobre 2015
//Le but : Réalisation du jeu ''le compte est bon'' 
//L'ordinateur génère une cible grace à des chiffres formé aléatoirement dans un nombre précis d'opérations permis
//L'utilisateur peut seulement utiliser les nombres générés aléatoirement pour réussir à atteindre la cible 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "expression.h"
#include "module_utilitaire.h"
#include "op_bits.h"
#include <time.h>

//Definition  MIN pour la generation des nombres
#define min 1

//Sous-programme principal pour generer une cible que l'ordinateur doit atteindre 
int cible_generee(int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis); 

//Sous-programme secondaire pour prendre aléatoirement 1 seul nombre parmis les six chiffres donnés
int choisir_nb_alea(int nb1, int nb2, int nb3, int nb4, int nb5, int nb6); 

//Sous-programme secondaire pour verifier le 2e choix de chiffre
int verif_et_choix_nb_alea(int nb1, int nb2,int  nb3, int nb4, int nb5, int nb6, int cible);

//Sous-programme principal où l'utilisateur va jouer au jeu et faire ses operations mathematiques
int resultat_utilisateur(int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, int cible, unsigned int nb_choisis);

//Sous-programme secondaire où l'on verifie que l'utilisateur entre est correct mathematiquement et entre dans les paramètres demandés 
int resultat_valide(int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis); 

//Sous-programme qui incrémente l'ordre pour les bits dans le ''nb_choisis'' pour ne pas les reprendre 
int incremente_ordre(int ordre);

//Sous-programme qui choisi un operateur au hasard (+,-,/,*)
char generer_operateur(int operateur_random);

//Sous-programme qui calcul mathematiquement deux chiffres avec un operateur entre ceux-ci
int resultat_operation(int cible, int deuxieme_nb_choisi, char operateur);

//Sous-programme qui valide la division (si celle-ci est faisable donc sans reste)
int division_faisable(int cible,int deuxieme_nb_choisi);

//Sous-programme qui demande un choix d'opérateur et un deuxième nombre a l'utilisateur
int resultat_calcul_operateur(int resultat, int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis, int ordre);

//Sous-programme qui valide si le nombre entré par l'utilisateur est valide et existe dans la liste 
int boucle_validation_nombre(int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, int resultat);

//Sous-programme qui demande à l'utilisateur s'il veut rejouer sinon il ferme le programme 
int fin_programme(char fin_prog);

//Sous-programme qui ajsute le booléen pour vérifier si les nombres ont déjà été choisis ou non
//deux sous-programme non utilisé (et expliquer le pourquoi à la fin en entête de ceux-ci
int ajuster_booléen (int nombre, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis);
int ajuster_booléen_suite(int nombre, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis);

int main(void) {
	int nb_operations; //nombre d'opération requis pour atteindre la cible 
	int nb1;// nombre choisi aléatoire 
	int nb2;// nombre choisi aléatoire 
	int nb3;// nombre choisi aléatoire 
	int nb4;// nombre choisi aléatoire 
	int nb5;// nombre choisi aléatoire 
	int nb6;// nombre choisi aléatoire 
	unsigned int nb_choisis=0; //nombre choisi pour verifier si les chiffres sont déjà utilisés (avec ses bites)
	char fin_prog = 'o'; //Booléen pour la fermeture du programme par l'utilisateur
	int cible; //cible généré par le jeu et que l'utilisateur doit atteindre
	int resultat;

	srand(time(NULL));

	while (fin_prog != 'n') {
		//initialisation de la fonction expression
		initialiser_expression();

		//Fonction qui gégère les six chiffres aléatoires avec le nombre d'opérations nécessaire
		 nb1 = alea(min, 10);
		 nb2 = alea(min, 10);
		 nb3 = alea(min, 10);
		 nb4 = alea(min, 10);
		 nb5 = alea(min, 10);
		 nb6 = alea(min, 10);
		 nb_operations = alea(min, 6);
		 //nb_operations = 1;
		//Généré la valeur cible avec l'expression mathématique utilisé
		 cible = cible_generee( nb_operations,nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis);
	
		//Effectuer un tour avec l'utilisateur
		resultat = resultat_utilisateur(nb_operations, nb1, nb2, nb3, nb4, nb5, nb6, cible, nb_choisis);

		
		//Demande à l'utilisateur s'il veut rejouer ou non
		fin_prog = fin_programme(fin_prog);
		
		}
	
	//message de fin de programme
	printf("\nMerci d'avoir jouer!");

	return EXIT_SUCCESS;
}
//Sous-programme qui demande si l'utilisateur veut rejouer sinon il ferme le programme
//Paramètre : charactère 
//retour : charactère
//spécification : Les deux seuls caractères acceptés sont o ou n
int fin_programme(char fin_prog){
	
	//Affichage du message et prise de la variable
	printf("\nVoulez-vous rejouer?");
	scanf("%c",&fin_prog);

		//Boucle : Si l'utilisateur donne autre chose que 'o' ou 'n' à la question s'il veut rejouer, on lui redemande 
		while (fin_prog != 'o' && fin_prog != 'n') {
			printf("\nVoulez-vous rejouer?");
			scanf("%c",&fin_prog);
			fflush(stdin);
		}
return fin_prog;
}
/*
Sous-programme PRINCIPAL pour généré une cible aléatoire avec sa solution mathématique
Paramètre : des entiers (nombre d'opération et 6 chiffres) et un unsigned
Retour : Retourne la cible que l'utilisateur doit atteindre
*/
int cible_generee(int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis) {
	int cible; // pour arriver a la cible
	int deuxieme_nb_choisi; // deuxieme nombre choisi avec sa verification
	int compteur=0; //Pour continuer la boucle jusqu'a ce que le nombre d'opérations a été atteint
	int resultat; //resultat de l'opération 
	int ordre=0; //ordre des chiffres mis a 0 pour commencer au debut 
	char operateur; //Variable pour le choix de l'opérateur
	int operateur_random; // variable temporaire pour choisir un operateur aleatoirement

	nb_choisis = 0; //set les bits a 0

	//choisis un des 6 nombre aléatoirement
	cible = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6); 

	//ajuste le booléen du nombre choisi
	//nb_choisis = ajuster_booléen (cible, nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis);

	
	//choisis un deuxième nombre parmis les 6 aléatoirement
	deuxieme_nb_choisi = verif_et_choix_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6, cible );
	/****************************************************************************************************************
	deuxieme_nb_choisi = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6);

	nb_choisis = ajuster_booléen (deuxieme_nb_choisi,nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis);

	 deuxieme_nb_choisi = ajuster_booléen_suite(deuxieme_nb_choisi, nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis);
	**************************DEVRAIT EMPECHER LE CHOIX DU MÊME CHIFFRE D'ÊTRE REPRIS*********************************/
	 
	 //Boucle qui compte le nombre d'opération, l'ordinateur doit avoir le nombre d'équation mathématique requis 
	while (compteur < nb_operations) {
		//choisis un chiffre au hasard entre 1 et 4 pour les 4 operateurs existant
		operateur_random = alea(min, 4);

		//Sous-programme qui choisis l'operateur 
		operateur = generer_operateur(operateur_random);

		//effectue l'équation mathematique demander avec les deux chiffres choisis aléatoirement avec l'operateur choisis
		resultat = resultat_operation(cible,deuxieme_nb_choisi,operateur);

		//Si la division n'est pas valide on redemande un operateur
		if(resultat == -1){
			//choisis un chiffre au hasard entre 1 et 3 pour ainsi enlevé la division qui n'est pas faisable car si le programme rentre dans cette boucle, 
			//la divison a déjà été prise et elle n'est pas conforme
			//spécification : le 4 est omis car le 4 est la division mais elle est invalide
			operateur_random = alea(min, 3);

			//choisis l'opérateur 
			operateur = generer_operateur(operateur_random);

			//effectue l'équation mathematique demander avec les deux chiffres choisis aléatoirement avec l'opérateur choisis
			resultat = resultat_operation(cible,deuxieme_nb_choisi,operateur);	
			}

		//si le résultat est bon, donc la division valide car c'est le seul operateur avec un probleme 
		if (resultat != -1) {
			/*---------------*****************************************---------------------
			mettre cible,deuxieme nombre choisi et l'opérateur dans le module expression donné
			  ---------------*****************************************---------------------*/
			//met le premier chiffre dans le module expression pour pouvoir l'afficher par la suite
			ajouter_nombre(cible);

			//met l'operateur dans le module expression pour pouvoir l'afficher par la suite
			ajouter_operateur(operateur);

			//met le premier chiffre dans le module expression pour pouvoir l'afficher par la suite
			ajouter_nombre(deuxieme_nb_choisi);

			//metre le égal
			ajouter_operateur(EGAL);

			//ajouter le resultat
			ajouter_nombre(resultat);

			//saut de ligne pour avoir un meilleur affichage
			ajouter_saut_ligne();
			/*
			--------------*****************************************--------------------------
			*/
			//redemande un autre chiffre pour continuer les opérations tant et aussi longtemps qu'il reste des operations à faire pour terminer l'autre boucle
			//mais il ne doit pas demander un autre chiffre si on est dans le dernier tour de boucle
			if(compteur < nb_operations){
				//choix d'un autre nombre pour continuer les opérations
				deuxieme_nb_choisi = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6);

				//***********************met le bit a 1 pour les autres nombres choisi***************************************************
				
				//nb_choisis = ajuster_booléen (deuxieme_nb_choisi,nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis);

				//deuxieme_nb_choisi = ajuster_booléen_suite(deuxieme_nb_choisi, nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis);
		//**************************DEVRAIT EMPECHER LE CHOIX DU MÊME CHIFFRE D'ÊTRE REPRIS********************************
			}

			//la cible devient le résultat pour continuer les opérations dans le prochain tour de boucle
			cible = resultat;

			//incrémente le compteur si le résultat est valide
			compteur++;
		}	
	}
	return cible;
}
/*sous-programme SECONDAIRE pour choisir aléatoirement un nombre dans les 6 chiffres déjà générés
Paramètre : 6 entiers générés aléatoirement 
Retour : un entier choisi aléatoirement 
*/
int choisir_nb_alea(int nb1, int nb2, int nb3, int nb4, int nb5, int nb6) {
	
	int aleatoire; // chiffre generer aleatoire pour pour choisir le nombre voulu
	int chiffre_choisi; // apres l'aléatoire, un chiffre est choisi

	//choisi un nombre aleatoire entre 1 et 6 pour choisir un des nombres
	aleatoire = alea(min, 6);

	//fait le choix de quel nombre est associé à quel chiffre 
	//switch case utilisé pour faire un choix entre les 6 variables en utilisant un autre chiffre aléatoirement choisi
	switch (aleatoire) {
	case 1: chiffre_choisi = nb1; break;
	case 2: chiffre_choisi = nb2; break;
	case 3: chiffre_choisi = nb3; break;
	case 4: chiffre_choisi = nb4; break;
	case 5: chiffre_choisi = nb5; break;
	case 6: chiffre_choisi = nb6; break;
	}

	return chiffre_choisi;
}

/*Sous-programme SECONDAIRE qui choisi le deuxieme nombre aléatoirement 
Paramètre : 6 entiers générés aléatoirement avec la cible 
Retour : un entier différent de la cible
Spécification : La cible à cet étape est l'un des 6 entiers générés aléatoirement
*/
int verif_et_choix_nb_alea(int nb1, int nb2, int  nb3, int nb4, int nb5, int nb6, int cible) {

	int cible_2; //deuxieme chiffre choisi aléatoirement
	
	cible_2 = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6); //appel de la fonction pour choisir aleatoirement un nombre

	while (cible == cible_2) {      //boucle de verification que les nombres ne sont pas identique

		cible_2 = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6);
	}

	return cible_2;
}

/* sous-programme PRINCIPAL pour qu'un utilisateur joue au jeu et il choisi ses opérations avec les chiffres avec lesquels il fait ses opérations
Paramètre : 8 entiers (6 chiffres générés aléatoirement avec le nombre d'opérations et la cible) avec un unsigned
Retour : il nous retourne le résultat obtenu par l'utilisateur
Spécification : C'est ici que l'utilisateur joue au jeu et qu'il y a des interactions avec l'utilisateur
*/
int resultat_utilisateur(int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, int cible, unsigned int nb_choisis) {
	
	int resultat=0; // si le resultat est -1 le jeu s'arrete, on initialise à 0 pour entrer dans la premiere boucle de jeu

	//Boucle pour jouer avec les regles du jeu et l'utilisateur qui joue
	while (resultat != cible && resultat != -1) {
		//les trois printf sont là pour afficher les regles du jeu avec les nombres, cibles, nombres d'operations permises
		printf("\n Voici les règles du jeu :\n 1) Vous devez atteindre le chiffre cible avec le nombre de coup minimale obligatoire\n 2) Vous devez utiliser les chiffres fournis qu'une SEULE fois avec les opérations de bases ('+','-','*','/') pour atteindre la cible\n 3) Pour annuler un tour faite -1 \n 4) Pour quitter, appuyer sur n");
		printf("\n\n Voici la cible a atteindre : %d \n Voici le nombre d'operation obligatoire : %d", cible, nb_operations);
		printf("\nVoici vos nombres :\n     %d     %d\n     %d     %d\n     %d     %d", nb1, nb2, nb3, nb4, nb5, nb6);

		//sous-programme qui valide les opérations faite par l'utilisateur
		resultat = resultat_valide( nb_operations, nb1,nb2, nb3, nb4, nb5, nb6, nb_choisis);

		//s'il a reussi a atteindre la cible
		if (resultat == cible) 
		printf("\nBRAVO!! Vous avez réussi!\n\n");

		// si le résultat n'a pas été atteint et que ce n'est pas -1
		else if (resultat != cible && resultat != -1)
		printf("\nCe n'est pas le bon résultat!\n\n\n\n");
	}
	// affiche l'expression de l'ordinateur
	afficher_expression();

	return resultat;
}

/*Sous-programme SECONDAIRE qui valide le resultat que l'utilisateur fait
Paramètre : 7 entiers (6 chiffres générés aléatoirement avec le nombre d'opérations) avec un unsigned
Retour : le resultat
*/

int resultat_valide(int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis) {
	int resultat; //resultat de l'operation et le premier chiffre choisi
	int ordre=0; //l'ordre des bites du nombre choisis
	
	nb_choisis = 0; // fixe a 0
	
		//L'utilisateur entre le premier chiffre et saisi de variable
		printf("\nEntrer votre chiffre : ");
		scanf("%d",&resultat);
		fflush(stdin);
		
		
		//Sous-programme qui valide si le chiffre entré par l'utilisateur existe dans la liste
		resultat = boucle_validation_nombre(nb1, nb2, nb3, nb4, nb5, nb6, resultat);
		
		
		//appel de sous-programme pour faire les équations mathématiques
			resultat = resultat_calcul_operateur(resultat, nb_operations, nb1, nb2, nb3, nb4, nb5, nb6, nb_choisis,ordre);

		return resultat;
}
/*
Sous-programme qui valide un nombre dans une liste si ce dernier existe dans la liste 
Paramètre : 7 entiers (6 chiffres générés aléatoirement avec le nombre d'opérations et le résultat)
Retour : le résultat (le chiffre saisi par l'utilisateur)
Spécification : Le résultat peut entré dans ce sous-programme mais pourrait ne pas entré dans la boucle si ce dernier est déjà valide
*/
int boucle_validation_nombre(int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, int resultat){
	
	if(resultat != -1){
	//Boucle qui verifie si le nombre existe dans la liste sinon il redemande un choix de nombre à l'utilisateur
		while (resultat != nb1 && resultat != nb2 && resultat != nb3 && resultat != nb4 && resultat != nb5 && resultat != nb6){
			//Demande d'entrer un chiffre et saisi de variable
			printf("\nEntrer un chiffre valide! : ");
			scanf("%d", &resultat);
			fflush(stdin);
		}
	}
	return resultat;
}

/*
Sous-programme qui calcule deux nombres choisis par l'utilisateur avec un opérateur choisis aussi par l'utilisateur 
Paramètre : 8 entiers (6 chiffres générés aléatoirement avec le nombre d'opérations et le résultat) avec un unsigned
Retour : retourne le résultat
*/
int resultat_calcul_operateur(int resultat, int nb_operations, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis, int ordre){
	int i=0; //compteur
	char operateur_choisi; //choix de l'opérateur
	int deuxieme_nombre=0; // deuxieme nombre choisis par l'utilisateur

	//Boucle de calcul avec itérateur pour compter le nombre d'opérations et si le résultat est différent de -1 pour rester dans la boucle car c'est une condition de sortie
	while(i < nb_operations && resultat != -1){
		printf("\nChoisir un opérateur valide (+,-,*,/) :");
		scanf("%c",&operateur_choisi);
		fflush(stdin);

		//si l'opérateur est différent de -1 et égal au opérateur
		if (operateur_choisi != '42' || operateur_choisi != '43'||operateur_choisi != '45' || operateur_choisi != '47'){
			printf("\nChoisir un deuxieme nombre : ");
			scanf("%d",&deuxieme_nombre);
			fflush(stdin);
			//Sous-programme qui verifie si le chiffre est dans la liste ou non
			deuxieme_nombre = boucle_validation_nombre( nb1, nb2, nb3, nb4, nb5, nb6, deuxieme_nombre);

			//si le deuxieme nombre n'est pas -1 donc le tour n'a pas été annulé
			if(deuxieme_nombre != -1){
				nb_choisis = set_bit(nb_choisis,ordre);
				//calcul du resultat avec le bon opérateur et le deuxieme nombre
				resultat = resultat_operation(resultat, deuxieme_nombre,operateur_choisi);
				printf("Voici votre resultat : %d", resultat);
			}
			//si le deuxième nombre choisis est -1, on annule le tour
			else if (deuxieme_nombre == -1){
				//mettre le resultat a -1 pour qu'il annule le tour
				resultat = -1;
			}
			//incremente le compteur
			i++;
		}
		//si l'operateur est -1 on annule le tour
		else if (operateur_choisi == '42' || operateur_choisi == '43'||operateur_choisi == '45' || operateur_choisi == '47')
			resultat = -1;
	}

	return resultat;
}



//Sous-programme qui incrémente l'ordre pour bien placé les nombres dans les bits
int incremente_ordre(int ordre){
	ordre = ordre +1;

	return ordre;
}

/*Sous-programme qui choisis un opérateur au hasard
Paramètre : un entier
Retour : un caractère
Spécification : un nombre choisis aléatoirement comblé a un switch case donne un caractère en sorti
*/
char generer_operateur(int operateur_random){
	int operateur_choisi;//conserve l'operateur choisis pour le ramener dans le main
	
	//switch case est utiliser pour associer un mot a un caractère
	switch(operateur_random){
		case 1 : operateur_choisi = '+'; break;
		case 2 : operateur_choisi = '-'; break;
		case 3 : operateur_choisi = '*'; break;
		case 4 : operateur_choisi = '/'; break;
	}
return operateur_choisi;
}

/*Sous-programme qui calcul l'équation mathématique de deux chiffres avec un operateur choisis aléatoirement
Paramètre : 2 entiers et 1 caractère
Retour : le résultat calculé avec l'opérateur 
Spécification : associe un caractère a un symbole mathématique dans une équation avec 2 autre variables dans l'ordre désiré
*/
int resultat_operation(int cible, int deuxieme_nb_choisi,char operateur){
	int resultat; //resultat de l'équation
	
	//si l'operateur est +, on fait une addition
	if(operateur == '+')
		resultat = cible + deuxieme_nb_choisi;

	//si l'operateur est -, on fait une soustraction
	else if(operateur == '-')
		resultat = cible - deuxieme_nb_choisi;
	
	//si l'operateur est *, on fait une muliplication
	else if(operateur == '*')
		resultat = cible * deuxieme_nb_choisi;

	//si l'operateur est /, on fait une division
	else if(operateur == '/'){
		resultat = division_faisable(cible, deuxieme_nb_choisi);
	}
	return resultat;

}

/*Sous-programme qui verifie si la division est faisable sinon il faut choisir un autre opérateur
Paramètre : 2 entiers
Retour : validation (ici un entier et en plus est le résultat de la divison)
Spécification : retourne le résultat de la division si celle ci est faisable sinon le sous-programme retourne -1
*/
int division_faisable(int cible,int deuxieme_nb_choisi){
	int validation; //variable pour savoir si la division a un reste entier

	//avoir un reste entier ou non
	validation = cible % deuxieme_nb_choisi;

	//si la division n'est pas valide, on renvoie -1 pour redemander un auter operateur
	if (validation != 0)
		validation = -1;

	//si la division est valide, on fait la divison
	else if (validation == 0)
		validation = cible / deuxieme_nb_choisi;

return validation;
}

/*
Les deux sous-programme suivant devrait être pour la validation des nombres pour savoir si ceux-ci ont déjà été pris par l'ordinateur et l'utilisateur
Mais je ne peux les utiliser car ils ne répondent pas au attente.
Leur fonctionnement devrait être le suivant en pseudo-code : 
	Choisi un nombre aléatoire (nb1 à nb6) ''choisir_nb_alea ();''
		si le bit(get_bit) à la position de choisir_nb_alea () == 0 
			nb_choisis = set_bit( nb_choisis, ordre(du chiffre aléatoire);
		sinon 
		rechoisis un autre nombre aléatoire ''choisir_nb_alea ();''

Ce qui devrait empecher l'ordinateur de prendre une variable deux fois dans la même équation 

Pour l'utilisateur le code serait identique sauf qu'il ne prendrait pas une variable aléatoirement mais celle fournis par l'utilisateur 

L'usage de tableau ou de pointeur aurait été une manière de résoudre le problème que j'avais avec les compétences que j'ai en ce moment et les notions apprises
mais sinon je ne suis pas en mesure de résoudre ce problème 

*/
int ajuster_booléen (int nombre, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis){

	int i=0; //valeur booléenne
	int ordre=0;

while ( i==0){
	if (nombre == nb1)
		ordre=0;
	else if (nombre == nb2)
		ordre=1;
	else if (nombre == nb3)
		ordre=2;
	else if (nombre == nb4)
		ordre=3;
	else if (nombre == nb5)
		ordre=4;
	else if (nombre == nb6)
		ordre=5;

	
		if(get_bit(nb_choisis,ordre)==0){
			nb_choisis = set_bit(nb_choisis,ordre);
			i = 1;
		}
		else
			nombre = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6);
	}

return nb_choisis;

}

int ajuster_booléen_suite(int nombre, int nb1, int nb2, int nb3, int nb4, int nb5, int nb6, unsigned int nb_choisis){

	int i=0; //valeur booléenne
	int ordre=0;

while ( i==0){
	if (nombre == nb1)
		ordre=0;
	else if (nombre == nb2)
		ordre=1;
	else if (nombre == nb3)
		ordre=2;
	else if (nombre == nb4)
		ordre=3;
	else if (nombre == nb5)
		ordre=4;
	else if (nombre == nb6)
		ordre=5;

	
		if(get_bit(nb_choisis,ordre)==0){
			nb_choisis = set_bit(nb_choisis,ordre);
			i = 1;
		}
		else
			nombre = choisir_nb_alea(nb1, nb2, nb3, nb4, nb5, nb6);
	}

return nombre;

}