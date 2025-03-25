#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

int main() {
	int nbUtilisateurs=0;
	int choix = 1;
	int id=1;
	int idAmi;
	Utilisateur** liste = creer_liste_utilisateurs();
	
	while (choix != 7) {
		printf("---Laureenstagram---\n\n1- Nouvel utilisateur\n2- Nouvel ami\n3- Nouveau post\n4- Afficher la liste des utilisateurs\n5- Afficher une liste d'amis\n6- Afficher une liste de posts\n7- Quitter\n\nVotre choix : ");
		scanf_s("%d", &choix);

		if (choix == 1) {
			system("cls");
			nbUtilisateurs++;
			ajouter_utilisateur(liste,creer_utilisateur(nbUtilisateurs));
		} 
		else if (choix == 2) {
			system("cls");
			afficherUtilisateur(*liste);
			printf("Veuillez saisir votre id : ");
			scanf_s("%d",&id);
			printf("\nVeuillez saisir l'id de votre nouvel ami : ");
			scanf_s("%d", &idAmi);

			trouverUtilisateur(id, *liste)->amis = realloc(trouverUtilisateur(id, *liste)->amis, (trouverUtilisateur(id, *liste)->nbAmis+1) * sizeof(Utilisateur*));
			trouverUtilisateur(id, *liste)->amis[trouverUtilisateur(id, *liste)->nbAmis] = trouverUtilisateur(idAmi, *liste);
			trouverUtilisateur(id, *liste)->nbAmis++;
		}
		else if (choix == 3) {
			system("cls");
			afficherUtilisateur(*liste);
			printf("Veuillez saisir votre id : ");
			scanf_s("%d", &id);

			chainePost(trouverUtilisateur(id, *liste), creerPublication());
		}
		else if (choix == 4) {
			system("cls");
			afficherUtilisateur(*liste);
			getchar();
			getchar();
		}
		else if (choix == 5) {
			system("cls");
			afficherUtilisateur(*liste);
			printf("Veuillez saisir l'id de la personne dont vous voulez afficher les amis : ");
			scanf_s("%d", &id);
			afficherAmis(trouverUtilisateur(id, *liste));
			getchar();
			getchar();
		}
		else if (choix == 6) {
			system("cls");
			afficherUtilisateur(*liste);
			printf("Veuillez saisir l'id de la personne dont vous voulez afficher les publications : ");
			scanf_s("%d", &id);

			afficherPost(trouverUtilisateur(id, *liste));
			getchar();
			getchar();
		}
		system("cls");
	}
	
	printf("\nVous avez quitte.\n");

	libererMemoireUtilisateurs(liste);
	free(liste);
	liste = NULL;

	return 0;
}