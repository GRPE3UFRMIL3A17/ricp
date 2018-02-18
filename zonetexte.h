#ifndef ZONETEXTE_H_INCLUDED
#define ZONETEXTE_H_INCLUDED

    #include <SDL/SDL.h>
    void lireDonneeZoneTexte(SDL_Surface *surface, TTF_Font *police, char *chaineEntree, char *introductionInitiale, char *texteDePreremplissage, unsigned long nombreDeCaracteresMaximal);
    void detecterErreurs(SDL_Surface *surface, SDL_Surface *barre, TTF_Font *police, char *chaineEntree, char *texteDePreremplissage, unsigned long nombreDeCaracteresMaximal);
    void lireCaractereZoneTexte(SDL_Event event, int *majuscule, char *chaine, unsigned long *positionCaractere, int *continuer, unsigned long nombreDeCaracteresMaximal);
    void entrerLettre(int *lettreEntree, unsigned long numeroCaractere, char *caractere);
    void insererCaractereDansChaine(unsigned long positionCaractere, char *chaine, char caractereAInserer);
    void blitterCurseur(SDL_Rect *positionTexte, TTF_Font *police, char *chaineEntree, SDL_Surface *surface, SDL_Surface *barre, unsigned long positionCaractere);
    void detecterLettre(SDL_Event event, int *lettreEntree, char *caractereEntre, int *majuscule);


#endif // ZONETEXTE_H_INCLUDED
