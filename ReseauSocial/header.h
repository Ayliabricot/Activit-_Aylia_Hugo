#ifndef RESEAU
#define RESEAU

typedef struct {
	int id;
	int nbAmis;
	char pseudo[20];
	struct Utilisateur* utilisateur_suivant;
	struct Utilisateur** amis;
	struct Publication* premier_post;

}Utilisateur;

typedef struct {
	char texte[1000];
	struct Publication* publication_suivante;
}Publication;

Utilisateur** creer_liste_utilisateurs(void);
Utilisateur* creer_utilisateur(int id);
Publication* creerPublication(void);
void ajouter_utilisateur(Utilisateur** liste, Utilisateur* nouveau);
void afficherUtilisateur(Utilisateur* user);

#endif
