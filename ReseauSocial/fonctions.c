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
	utilisateur->amis = malloc(sizeof(Utilisateur*));
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
	printf("\n->Liste des utilisateurs :\n");
	if (user==NULL) {
		printf("Erreur allocation");
		return;
	}
	while (user != NULL) {
		printf("%d - %s\n", user->id, user->pseudo);
		user = user->utilisateur_suivant;
	}
	printf("\n");
}

Utilisateur* trouverUtilisateur(int id, Utilisateur* user) {
	if (!user) {
		printf("Erreur allocation");
		return 0;
	}
	while (user->id != id) {
		user = user->utilisateur_suivant;
	}
	return user;
}

void afficherAmis(Utilisateur* utilisateur) {
	if (utilisateur->nbAmis == 0) {
		printf("\nCette personne n'a pas d'amis.\n\n");
		return;
	}
	printf("\n->Amis de %s:\n", utilisateur->pseudo);
	Utilisateur** listeAmis = utilisateur->amis;
	for (int n = 0; n < utilisateur->nbAmis; n++) {
		printf("-%s\n", listeAmis[n]->pseudo);
	}
	printf("\n");
}

Publication* chainePost(int id, Utilisateur* premier, char post[1000]) {
	if (!premier) {
		printf("Erreur allocation");
		return;
	}
	Utilisateur* user = trouverUtilisateur(id, premier);
	if (!user) {
		printf("Erreur allocation");
		return;
	}
	Publication* newPost = malloc(sizeof(Publication));
	if (!newPost) {
		printf("Erreur allocation");
		return;
	}
	strcpy_s(user->premier_post, 1000, post);
	newPost->publication_suivante = user->premier_post;
	user->premier_post = newPost;

	return newPost;
}

void affciherPost(Utilisateur* user) {
	if (!user) {
		printf("Erreur allocation");
		return;
	}
	Publication* post = user->premier_post;
	printf("publication de %s:\n", user->pseudo);
	while (post) {
		printf("%s", post->texte);
		post = post->publication_suivante;

	}
}