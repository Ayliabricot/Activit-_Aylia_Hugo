#include "header.h"
#include <stdio.h>
#include <stdlib.h>


Publication* creerPublication() {
	Publication* nouvellePublication = malloc(sizeof(Publication));
	if (!nouvellePublication) {
		printf("erreur allocation");
		return 0;
	}
	char post[1000];
	printf("que voulez vous partager ?");
	fgets(post, sizeof(post), stdin);
	strcpy_s(nouvellePublication->texte, 1000, post);
	return nouvellePublication;
}

Utilisateur** creer_liste_utilisateurs(void) {
	Utilisateur** liste = malloc(sizeof(Utilisateur*));
	*liste = NULL;

	return liste;
}

Utilisateur* creer_utilisateur(int id) {
	char pseudo[20];

	printf("\nVeuillez saisir votre pseudo (espaces non-autorisés) : ");
	scanf_s("%s", &pseudo, sizeof(pseudo));

	Utilisateur* utilisateur = malloc(sizeof(Utilisateur));
	utilisateur->id = id;
	strcpy_s(utilisateur->pseudo, 20, pseudo);
	utilisateur->premier_ami = NULL;
	utilisateur->premier_post = NULL;

	return utilisateur;
}