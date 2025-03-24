#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	Publication* post = creerPublication();
	printf("%s", post->texte);

	Utilisateur* utilisateur = creer_utilisateur(1);
	printf("%d - %s", utilisateur->id, utilisateur->pseudo);
	return 0;
}