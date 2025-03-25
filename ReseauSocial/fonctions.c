#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Utilisateur** creer_liste_utilisateurs(void) {
	Utilisateur** liste = malloc(sizeof(Utilisateur));
	*liste = NULL;

	return liste;
}

Utilisateur* creer_utilisateur(int id) {
	char pseudo[20];

	printf("\nVeuillez saisir votre pseudo (espaces non-autorises) : ");
	scanf_s("%s", &pseudo, 20);

	Utilisateur* utilisateur = malloc(sizeof(Utilisateur));
	utilisateur->nbAmis = 0;
	utilisateur->id = id;
	strcpy_s(utilisateur->pseudo, 20, pseudo);
	utilisateur->utilisateur_suivant = NULL;
	utilisateur->amis = NULL;
	utilisateur->premier_post = NULL;

	printf("\n");

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

void ajouter_utilisateur(Utilisateur** liste, Utilisateur* nouveau) {
	if (*liste == NULL) {
		*liste = nouveau;
		return;
	}
	else {
		ajouter_utilisateur(&(*liste)->utilisateur_suivant, nouveau);
	}
}

void afficherUtilisateur(Utilisateur* user) {
	printf("\nListe des utilisateurs :\n");
	if (user==NULL) {
		printf("Erreur allocation");
		return;
	}
	while (user != NULL) {
		printf("%d - %s\n", user->id, user->pseudo);
		user = user->utilisateur_suivant;
	}
}