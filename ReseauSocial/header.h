#ifndef RESEAU
#define RESEAU

typedef struct {
	int id;
	char pseudo[20];
	struct Utilisateur* premier_ami;
	struct Publication* premier_post;
}Utilisateur;

typedef struct {
	char texte[1000];
}Publication;

Utilisateur** creer_liste_utilisateurs(void);
Utilisateur* creer_utilisateur(int id);
Publication* creerPublication();

#endif
