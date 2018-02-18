#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "fonction.h"


void editeur(SDL_Surface* ecran){

    SDL_Surface *img_rouge = NULL, *img_bleu = NULL, *rougebmp = NULL, *img_vert = NULL;
    SDL_Surface *vertbmp = NULL, *table_noeud= NULL, *table_routeur = NULL, *creationPaquet = NULL;
    SDL_Surface *elementImg = NULL, *img_router = NULL, *img_noeud = NULL;
    SDL_Surface *img_lien2 = NULL, *img_lien1 = NULL, *img_commut= NULL;

    SDL_Rect posElement;

    int i = 0, j = 0;
    int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR ] = {0};

     // Chargement des sprites (décors, personnage...)
    img_bleu = SDL_LoadBMP("bleu.bmp");
    img_vert = SDL_LoadBMP("vert.bmp");
    img_rouge = SDL_LoadBMP("rouge.bmp");
    img_router = SDL_LoadBMP("router.bmp");
    img_lien1 = SDL_LoadBMP("lien1.bmp");
    img_lien2 = SDL_LoadBMP("lien2.bmp");
    img_noeud = SDL_LoadBMP("pc.bmp");
    img_commut = SDL_LoadBMP("commutateur.bmp");
    rougebmp = SDL_LoadBMP("rouge.bmp");
    vertbmp = SDL_LoadBMP("vert.bmp");
    table_noeud = SDL_LoadBMP("table_noeud.bmp");
    creationPaquet = SDL_LoadBMP("creationPaquet.bmp");
    table_routeur = SDL_LoadBMP("table_routeur.bmp");

//PERMET DE POSITIONNER LES ELEMENTS SUR A CARTE HORZON(G ou D)|VERTI(H ou B)
    //HAUT
    carte[12][6]=NOEUD;
    carte[12][7]=VOYANT_VERT;
    carte[12][8]=LIENS_UN;
    carte[12][9]=VOYANT_VERT;
    carte[12][10]=LIENS_UN;
    carte[12][11]=VOYANT_VERT;
    //CENTRE

    carte[12][12]=COMMUTATEUR;

    //BAS
    carte[12][13]=VOYANT_VERT;
    carte[12][14]=LIENS_UN;
    carte[12][15]=VOYANT_VERT;
    carte[12][16]=LIENS_UN;
    carte[12][17]=VOYANT_VERT;
    carte[12][18]=NOEUD;

    //GAUCHE
    carte[6][12]=NOEUD;
    carte[7][12]=VOYANT_VERT;
    carte[8][12]=LIENS;
    carte[9][12]=VOYANT_VERT;
    carte[10][12]=LIENS;
    carte[11][12]=VOYANT_VERT;
    //carte[5][7]=VOYANT_VERT;

    //DROITE
    carte[13][12]=VOYANT_VERT;
    carte[14][12]=LIENS;
    carte[15][12]=VOYANT_VERT;
    carte[16][12]=ROUTER;
    carte[17][12]=VOYANT_VERT;

    carte[18][12]=LIENS;
    carte[19][12]=VOYANT_VERT;
    carte[20][12]=COMMUTATEUR;
    carte[21][12]=VOYANT_VERT;
    carte[22][12]=LIENS;
    carte[23][12]=VOYANT_VERT;
    carte[24][12]=NOEUD;
    //
    carte[0][19]=PARQUET;
    carte[20][0]=TABLE_ROUTEUR;

    carte[0][8]=TABLE_NOEUD;
    carte[9][1]=TABLE_NOEUD;
    carte[9][19]=TABLE_NOEUD;
    carte[25][10]=TABLE_NOEUD;

    // Effacement de l'écran
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        // Activation de la répétition des touches
    SDL_EnableKeyRepeat(100, 100);


    for (i = 0 ; i < NB_BLOCS_LARGEUR ; i++){
        for (j = 0 ; j < NB_BLOCS_HAUTEUR ; j++){
            posElement.x = i * TAILLE_BLOC;
            posElement.y = j * TAILLE_BLOC;

            switch(carte[i][j]){
                    case VIDE:

                    break;
                    case COMMUTATEUR:
                        SDL_BlitSurface(img_commut, NULL, ecran, &posElement);
                    break;
                    case NOEUD:
                        SDL_BlitSurface(img_noeud, NULL, ecran, &posElement);
                    break;
                    case ROUTER:
                        SDL_BlitSurface(img_router, NULL, ecran, &posElement);
                    break;
                    case LIENS:
                        SDL_BlitSurface(img_lien2, NULL, ecran, &posElement);
                    break;
                    case LIENS_UN:
                        SDL_BlitSurface(img_lien1, NULL, ecran, &posElement);
                    break;
                    case VOYANT_VERT:
                        SDL_BlitSurface(vertbmp, NULL, ecran, &posElement);
                    break;
                    case VOYANT_ROUGE:
                        SDL_BlitSurface(rougebmp, NULL, ecran, &posElement);
                    break;
                    case PARQUET:
                        SDL_BlitSurface(creationPaquet, NULL, ecran, &posElement);
                    break;
                    case TABLE_ROUTEUR:
                        SDL_BlitSurface(table_routeur, NULL, ecran, &posElement);
                    break;
                    case TABLE_NOEUD:
                        SDL_BlitSurface(table_noeud, NULL, ecran, &posElement);
                    break;
                }

            }
    }

        // Mise à jour de l'écran
        SDL_Flip(ecran);
// Désactivation de la répétition des touches (remise à 0)
    SDL_EnableKeyRepeat(0, 0);
// Libération des surfaces chargées
    SDL_FreeSurface(img_rouge);
    SDL_FreeSurface(img_bleu);
    SDL_FreeSurface(img_vert);
    SDL_FreeSurface(elementImg);
    SDL_FreeSurface(img_router);
    SDL_FreeSurface(img_noeud);
    SDL_FreeSurface(rougebmp);
    SDL_FreeSurface(vertbmp);
    SDL_FreeSurface(creationPaquet);
    SDL_FreeSurface(table_noeud);
    SDL_FreeSurface(table_routeur);
    SDL_FreeSurface(img_lien2);
    SDL_FreeSurface(img_lien1);
    SDL_FreeSurface(img_commut);

}


void pause(){
    int continuer = 1;
    SDL_Event event;
    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
        }
    }
}


void ecrireTexte(SDL_Surface* screen, int x, int y, TTF_Font* font, SDL_Surface* textSurface){

   SDL_Rect textLocation = { x, y, 0, 0 };

   SDL_BlitSurface(textSurface, NULL, screen, &textLocation);

    //SDL_Flip(screen);

    TTF_CloseFont(font);

   SDL_FreeSurface(textSurface);
   SDL_FreeSurface(screen);

   //pause();
}
