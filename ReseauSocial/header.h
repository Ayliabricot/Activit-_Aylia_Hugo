#ifndef RESEAU
#define RESEAU

typedef struct {
	int id;
	char pseudo[20];
	Utilisateur* premier_ami;
	Publication* premier_post;
}Utilisateur;

typedef struct {
	char texte[1000];
}Publication;

Utilisateur** creer_liste_utilisateurs(void);
Utilisateur* creer_utilisateur(int id);

#endif
