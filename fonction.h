#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

    #define TAILLE_BLOC         34 // Taille d'un bloc (carré) en pixels
    #define NB_BLOCS_LARGEUR    32
    #define NB_BLOCS_HAUTEUR    24
    #define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR

    //constante du reseaux
    #define GLIDE_DELAY          5000;
    #define SWITCH_ENTRY_AGE    60;
    #define SWITCH_CRON_DELAY   1000;
    #define ARP_ENTRY_AGE       60;
    #define ROUTER_CRON_DELAY   1000;

    #define IP4_RETRY_DELAY     2*GLIDE_DELAY+1000;
    #define IP4_RETRY_MAX       4;

    #define ROUTE_HIGHLIGHT_DELAY   5000;

    #define ETHERNET_BROADCAST  'ff:ff:ff:ff:ff:ff';

    //Variable Reseaux




    //

    enum {VIDE, NOEUD, ROUTER, LIENS, LIENS_UN, VOYANT_VERT, VOYANT_ROUGE, PARQUET, TABLE_ROUTEUR, TABLE_NOEUD, COMMUTATEUR};

    void editeur(SDL_Surface* ecran);

    void ecrireTexte(SDL_Surface* screen, int x, int y, TTF_Font* font, SDL_Surface* textSurface);

    void pause();

#endif // FONCTION_H_INCLUDED

