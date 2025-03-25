#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	int nbUtilisateurs=0;
	int choix = 1;
	int id=1;
	int idAmi;
	Utilisateur** liste = creer_liste_utilisateurs();
	
	while (choix != 6) {
		printf("---Laureenstagram---\n\n1- Nouvel utilisateur\n2- Nouvel ami\n3- Afficher la liste des utilisateurs\n4- Afficher une liste d'amis\n5- Afficher une liste de posts\n6- Quitter\n\nVotre choix : ");
		scanf_s("%d", &choix);

		if (choix == 1) {
			nbUtilisateurs++;
			ajouter_utilisateur(liste,creer_utilisateur(nbUtilisateurs));
		} 
		else if (choix == 2) {
			printf("\nVeuillez saisir votre id : ");
			scanf_s("%d",&id);
			printf("\nVeuillez saisir l'id de votre nouvel ami : ");
			scanf_s("%d", &idAmi);

			trouverUtilisateur(id, *liste)->amis = realloc(trouverUtilisateur(id, *liste)->amis, (trouverUtilisateur(id, *liste)->nbAmis+1) * sizeof(Utilisateur*));
			trouverUtilisateur(id, *liste)->amis[trouverUtilisateur(id, *liste)->nbAmis] = trouverUtilisateur(idAmi, *liste);
			trouverUtilisateur(id, *liste)->nbAmis++;
		}
		else if (choix == 3) {
			afficherUtilisateur(*liste);
		}
		else if (choix == 4) {
			printf("\nVeuillez saisir l'id de la personne dont vous voulez afficher les amis : ");
			scanf_s("%d", &id);
			afficherAmis(trouverUtilisateur(id, *liste));
		}
	}
	
	printf("\nVous avez quitte.\n");

	return 0;
}