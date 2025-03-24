#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Utilisateur** creer_liste_utilisateurs(void) {
	Utilisateur** liste = malloc(sizeof(Utilisateur*));
	*liste = NULL;

	return liste;
}

Utilisateur* creer_utilisateur(int id) {
	char pseudo[20];

	printf("\nVeuillez saisir votre pseudo (espaces non-autorises) : ");
	scanf_s("%s", &pseudo, sizeof(pseudo));

	Utilisateur* utilisateur = malloc(sizeof(Utilisateur));
	utilisateur->id = id;
	strcpy_s(utilisateur->pseudo, 20, pseudo);
	utilisateur->utilisateur_suivant = NULL;
	utilisateur->ami_suivant = NULL;
	utilisateur->premier_post = NULL;

	return utilisateur;
}

Publication* creerPublication(void) {
	char post[1000];

	Publication* nouvellePublication = malloc(sizeof(Publication));

	if (!nouvellePublication) {
		printf("Erreur allocation");
		return 0;
	}

	printf("Veuillez saisir votre commentaire : ");
	fgets(post, sizeof(post), stdin);
	strcpy_s(nouvellePublication->texte, 1000, post);

	return nouvellePublication;
}

void afficherUtilisateur(Utilisateur* user) {
	if (!user) {
		printf("Erreur allocation");
		return 0;
	}
	while (user!=NULL) {
		printf("%d - %s", user->id, user->pseudo);
		user = user->utilisateur_suivant;
	}
}