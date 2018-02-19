#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

    #define TAILLE_BLOC         34 // Taille d'un bloc (carré) en pixels
    #define NB_BLOCS_LARGEUR    32
    #define NB_BLOCS_HAUTEUR    24
    #define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR

    //Variable Reseaux

    typedef struct Noeud Noeud;
    struct Noeud
    {
        char addresseIP[20]="";
        char addresseMac[20]="";

    };

    //

    enum {VIDE, NOEUD, NOEUD1, NOEUD2, NOEUD3, NOEUD4, ROUTER, LIENS, LIENS_UN, VOYANT_VERT, VOYANT_ROUGE, PARQUET, TABLE_ROUTEUR, TABLE_NOEUD, COMMUTATEUR};

    void editeur(SDL_Surface* ecran);

    void ecrireTexte(SDL_Surface* screen, int x, int y, TTF_Font* font, SDL_Surface* textSurface);

    void pause();

#endif // FONCTION_H_INCLUDED

