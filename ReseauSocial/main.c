#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	int nbUtilisateurs=0;
	int choix = 1;
	Utilisateur** liste = creer_liste_utilisateurs();

	while (choix != 6) {
		printf("---Laureenstagram---\n\n1- Nouvel utilisateur\n2- Nouvel ami\n3- Afficher la liste des utilisateurs\n4- Afficher une liste d'amis\n5- Afficher une liste de posts\n6- Quitter\n\nVotre choix :");
		scanf_s("%d", &choix);

		if (choix == 1) {
			nbUtilisateurs++;
			ajouter_utilisateur(*liste, creer_utilisateur(nbUtilisateurs));
		}
	}
	Publication* post = creerPublication();
	printf("%s", post->texte);

	Utilisateur* utilisateur = creer_utilisateur(1);

	
	afficherUtilisateur(utilisateur);
	return 0;
}