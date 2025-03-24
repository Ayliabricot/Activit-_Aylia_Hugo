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

	printf("\nVeuillez saisir votre pseudo : ");
	scanf_s("%s", &pseudo, sizeof(pseudo));

	Utilisateur* utilisateur = malloc(sizeof(Utilisateur));
	utilisateur->id = id;
	strcpy_s(utilisateur->pseudo, 20, pseudo);
	utilisateur->premier_ami = NULL;
	utilisateur->premier_post = NULL;

	return utilisateur;
}