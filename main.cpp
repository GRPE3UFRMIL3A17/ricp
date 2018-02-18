#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "fonction.h"
#include "zonetexte.h"


int main(int argc, char *argv[]){


    //SDL_Delay(6000);

// Le pointeur qui va stocker la surface de l'�cran , message
    SDL_Surface *ecran = NULL, *menu= NULL, *texteAffiche = NULL;
    //variable position
    SDL_Rect positionMenu, position;
    SDL_Event event;
    /* Chargement de la police */
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    char texte[20] = "";
    char chaine[100] = "";
    int continuer = 1;

// Chargement de la vid�o, de l'audio et du timer
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) == -1)
	{
		fprintf(stderr,"Erreur lors de l'initialisation de la SDL : %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
//Init ecriture
	if(TTF_Init() == -1)
	{
		fprintf(stderr,"Erreur lors de l'initialisation de SDL_TTF : %s\n",TTF_GetError());
		exit(EXIT_FAILURE);
	}


// Chargement de l'ic�ne AVANT SDL_SetVideoMode */
    SDL_WM_SetIcon(SDL_LoadBMP("pc.bmp"), NULL);

    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    //Label ou nom de la fenetre
    SDL_WM_SetCaption("Projet Simulateur Reseaux", NULL);
/* Chargement de la police */
    police=TTF_OpenFont("timesbd.ttf", 14);
	if(police == NULL)
	{
		fprintf(stderr,"Erreur police : %s",TTF_GetError());
		exit(EXIT_FAILURE);
	}
    lireDonneeZoneTexte(ecran,police,chaine,"Projet Simulateur Reseaux","Le Site du Zer0",99);

    positionMenu.x = 0;
    positionMenu.y = 0;

    editeur(ecran);

        while(continuer!=0){
            if( (event.type) && (event.key.keysym.sym == SDLK_ESCAPE) ){
                continuer=0;
            }
            else if( (event.type) && (event.type== SDL_QUIT) ){
                continuer=0;
            }
            else{
                continuer = 1;

                sprintf(texte, chaine);
                texteAffiche= TTF_RenderText_Solid(police, texte, couleurNoire);

                SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
                //position texte
                position.x = 1 * TAILLE_BLOC;
                position.y = 1 * TAILLE_BLOC;

                SDL_BlitSurface(texteAffiche, NULL, ecran, &position);



                SDL_Flip(ecran);

                SDL_WaitEvent(&event);

            }
        }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texteAffiche);
    SDL_FreeSurface(menu);
    SDL_FreeSurface(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}
