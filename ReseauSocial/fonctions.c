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