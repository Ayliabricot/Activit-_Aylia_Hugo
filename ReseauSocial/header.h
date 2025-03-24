#ifndef RESEAU
#define RESEAU

typedef struct {
	int identifiant;
	char pseudo[20];
	Utilisateur* premier_ami;
	Publication* premier_post;
}Utilisateur;

typedef struct {
	char texte[1000];
}Publication;

#endif
