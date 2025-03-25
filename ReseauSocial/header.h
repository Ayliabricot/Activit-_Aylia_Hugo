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
}Publication;

Utilisateur** creer_liste_utilisateurs(void);
Utilisateur* creer_utilisateur(int id);
Publication* creerPublication(void);
void ajouter_utilisateur(Utilisateur** liste, Utilisateur* nouveau);
void afficherUtilisateur(Utilisateur* user);
Utilisateur* trouverUtilisateur(int id, Utilisateur* user);
void afficherAmis(Utilisateur* utilisateur);

#endif
