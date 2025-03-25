#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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

	printf("\nVeuillez saisir votre commentaire : ");
	getchar();
	fgets(post, sizeof(post), stdin);

	strcpy_s(nouvellePublication->texte, 1000, post);
	nouvellePublication->publication_suivante = NULL;

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
		printf("\n%s n'a pas d'amis.\n\n",utilisateur->pseudo);
		return;
	}
	printf("\n->Amis de %s:\n", utilisateur->pseudo);
	Utilisateur** listeAmis = utilisateur->amis;
	for (int n = 0; n < utilisateur->nbAmis; n++) {
		printf("-%s\n", listeAmis[n]->pseudo);
	}
	printf("\n");
}

void chainePost(Utilisateur* user,Publication* newPost) {
	if (!user) {
		printf("Erreur allocation");
		return;
	}
	
	if (!newPost) {
		printf("Erreur allocation");
		return;
	}

	newPost->publication_suivante = user->premier_post;
	user->premier_post = newPost;
	
	return;
}

void afficherPost(Utilisateur* user) {
	if (!user) {
		printf("Erreur allocation");
		return;
	}
	if (user->premier_post == NULL) {
		printf("\n%s n'a rien publie.\n\n",user->pseudo);
		return;
	}
	int n = 1;
	Publication* post = user->premier_post;
	printf("\n->Publications de %s:\n\n", user->pseudo);
	while (post) {
		printf("%d - %s\n", n,post->texte);
		post = post->publication_suivante;
		n++;
	}
}

void libererMemoireUtilisateurs(Utilisateur** utilisateur) {
	if ((*utilisateur)->utilisateur_suivant != NULL) {
		libererMemoireUtilisateurs(&(*utilisateur)->utilisateur_suivant);
	}
	libererMemoirePosts((*utilisateur)->premier_post);
	free(utilisateur);
	utilisateur = NULL;
}

void libererMemoirePosts(Publication* post) {
	if (post->publication_suivante != NULL) {
		libererMemoirePosts(post->publication_suivante);
	}
	free(post);
	post = NULL;
}