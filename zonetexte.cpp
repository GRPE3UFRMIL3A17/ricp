/*
zonetexte.c
Par Rayman3640 et Troumad
Rôle : permettre au créateur de simuler des zones de texte avec la SDL
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "zonetexte.h"

void lireDonneeZoneTexte(SDL_Surface *surface, TTF_Font *police, char *chaineEntree, char *introductionInitiale, char *texteDePreremplissage, unsigned long nombreDeCaracteresMaximal)
{
	int continuer = 1, majuscule = 0;
	SDL_Surface *texte, *barre = NULL;
	SDL_Color noir = {0,0,0,0}; // 4ème champ inutilisé, mais présent tout de même : évite un warning.
	SDL_Color blanc = {255,255,255,0}; // 4ème champ inutilisé, mais présent tout de même : évite un warning.
	SDL_Rect positionTexte;
	unsigned long positionCaractere = 0;
	SDL_Event event;
    SDL_Rect bas_blanc;


    SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,0,0,0));
	texte = TTF_RenderUTF8_Solid(police,introductionInitiale,blanc);
	positionTexte.x = 0;
	positionTexte.y = 0;
	SDL_BlitSurface(texte,NULL,surface,&positionTexte);
	positionTexte.y = texte->h +10;
	bas_blanc.y=positionTexte.y-5;
	bas_blanc.h=480-bas_blanc.y;
	bas_blanc.x=0;
	bas_blanc.w=640;

	SDL_FillRect(surface,&bas_blanc,65535);

	barre = SDL_LoadBMP("curseur.bmp");
	detecterErreurs(surface,barre,police,chaineEntree,texteDePreremplissage,nombreDeCaracteresMaximal);
	//strcpy(introduction,introductionInitiale);
	strcpy(chaineEntree,texteDePreremplissage);
	positionCaractere = strlen(chaineEntree);
	//SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,255,255,0));
	SDL_EnableKeyRepeat(100,100);
	SDL_Flip(surface);
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				lireCaractereZoneTexte(event,&majuscule,chaineEntree,&positionCaractere,&continuer,nombreDeCaracteresMaximal);
				break;
		}
		texte = TTF_RenderUTF8_Solid(police,chaineEntree,noir);
		SDL_BlitSurface(texte,NULL,surface,&positionTexte);
		blitterCurseur(&positionTexte,police,chaineEntree,surface,barre, positionCaractere);
		SDL_Flip(surface);
    	SDL_FillRect(surface,&bas_blanc,65535);
		//SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,255,255,0));
	}
	SDL_FreeSurface(texte);
	SDL_FreeSurface(barre);

}

void detecterErreurs(SDL_Surface *surface, SDL_Surface *barre, TTF_Font *police, char *chaineEntree, char *texteDePreremplissage, unsigned long nombreDeCaracteresMaximal)
{
	if(surface == NULL)
	{
		fprintf(stderr,"Le pointeur sur surface vaut NULL, donc le texte ne peut pas être affiché à l'écran.\n");
		exit(EXIT_FAILURE);
	}
	if(barre == NULL)
	{
		fprintf(stderr,"Erreur lors de l'ouverture de l'image Curseur.png: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if(police == NULL)
	{
		fprintf(stderr,"Le pointeur sur police vaut NULL, donc aucune police ne peut être ouverte.\n");
		exit(EXIT_FAILURE);
	}
	if(chaineEntree == NULL)
	{
		fprintf(stderr,"La chaîne entrée vaut NULL, donc l'utilisateur ne peut rentrer aucune chaîne.\n");
		exit(EXIT_FAILURE);
	}
	if(nombreDeCaracteresMaximal < 1)
	{
		fprintf(stderr,"La taille maximale est nulle, donc l'utilisateur ne peut entrer aucune chaîne.\n");
		exit(EXIT_FAILURE);
	}
	if(texteDePreremplissage != NULL && strlen(texteDePreremplissage) > nombreDeCaracteresMaximal)
	{
		fprintf(stderr,"Le nombre de caractères du texte de préremplissage est supérieur au nombre de caractères maximal.\n");
		exit(EXIT_FAILURE);
	}

}

void blitterCurseur(SDL_Rect *positionTexte, TTF_Font *police, char *chaineEntree, SDL_Surface *surface, SDL_Surface *barre, unsigned long positionCaractere)
{
	int longueurSurfaceTexte = 0, longueurSurfaceTexte2 = 0, longueurSurfaceTexte3 = 0, largeurSurfaceTexte = 0;
	SDL_Rect positionBarre;
	if(strlen(chaineEntree) > 0)
	{
		positionBarre.x = positionTexte->x;
		if(TTF_SizeUTF8(police,chaineEntree,&longueurSurfaceTexte2,&largeurSurfaceTexte) == 0)
		{
			if(TTF_SizeUTF8(police,&chaineEntree[positionCaractere],&longueurSurfaceTexte3,&largeurSurfaceTexte) == 0)
			{
				longueurSurfaceTexte = longueurSurfaceTexte2 - longueurSurfaceTexte3;
			}
			positionBarre.x += longueurSurfaceTexte;
		}
		positionBarre.y = positionTexte->y;
		SDL_BlitSurface(barre,NULL,surface,&positionBarre);
	}

}

void lireCaractereZoneTexte(SDL_Event event, int *majuscule, char *chaine, unsigned long *positionCaractere, int *continuer, unsigned long nombreDeCaracteresMaximal)
{
	char caractereEntre = 0;
	int lettreEntree = 0, diminuerPositionCaractere = 1;
	unsigned long i = 0;
	if(event.key.keysym.mod & KMOD_SHIFT)
	{
		*majuscule = 1;
	}
	else
	{
		*majuscule = 0;
	}
	if (event.key.keysym.mod & KMOD_CAPS)
	 *majuscule=!*majuscule;
	switch(event.key.keysym.sym)
	{
		case SDLK_LEFT:
			if(*positionCaractere > 0)
				*positionCaractere -= 1;
			break;
		case SDLK_RIGHT:
			if(*positionCaractere < strlen(chaine))
				*positionCaractere += 1;
			break;
		case SDLK_BACKSPACE:
			//if(*positionCaractere > 0)
			{
			    if (*positionCaractere==0)
			    {
			        diminuerPositionCaractere = 0;
			        i=0;
			    }
			    else i=*positionCaractere-1;
				while( i < strlen(chaine))
				{
					chaine[i] = chaine[i+1];
                    i++;
				}
				if(diminuerPositionCaractere)
					*positionCaractere-=1;
				else
					*positionCaractere=0;
			}
			break;
		case SDLK_ESCAPE:
			*continuer = 0;
			break;
		case SDLK_RETURN:
			*continuer = 0;
			break;
		default:
			break;
	}
	detecterLettre(event,&lettreEntree,&caractereEntre,majuscule);
	if(lettreEntree == 1 && strlen(chaine) <= nombreDeCaracteresMaximal)
	{
		insererCaractereDansChaine(*positionCaractere,chaine,caractereEntre);
		*positionCaractere += 1;
	}
}

void detecterLettre(SDL_Event event, int *lettreEntree, char *caractereEntre, int *majuscule)
{
	long i = 0;
	for(i = 0; i < 26; i++) //Lettres sans accents minuscules et majuscules
	{
		if(event.key.keysym.sym == SDLK_a + i)
		{
			entrerLettre(lettreEntree,65 + i,caractereEntre);
			if(!(*majuscule))
			{
				*caractereEntre += 32;
			}
			break;
		}
	}
	for(i = 0; i < 27; i++)
	{
		if(event.key.keysym.sym == SDLK_AMPERSAND + i)
		{
			entrerLettre(lettreEntree,38 + i,caractereEntre);
		}
	}
	for(i = 0; i < 5; i++)
	{
		if(event.key.keysym.sym == SDLK_SPACE + i)
		{
			entrerLettre(lettreEntree,32 + i,caractereEntre);
		}
	}
	switch(event.key.keysym.sym) //Caractères spéciaux
	{
		case SDLK_BACKSLASH:
			entrerLettre(lettreEntree,92,caractereEntre);
			break;
		default:
			break;
	}
	for(i = 0; i < 10; i++)
	{
		if(event.key.keysym.sym == SDLK_KP0 + i) //Nombres du pavé numérique
		{
			entrerLettre(lettreEntree,'0' + i,caractereEntre);
		}
	}

}

void entrerLettre(int *lettreEntree, unsigned long numeroCaractere, char *caractere)
{
	if(!(*lettreEntree))
	{
		*lettreEntree = 1;
		*caractere = numeroCaractere;
	}
}

void insererCaractereDansChaine(unsigned long positionCaractere, char *chaine, char caractereAInserer)
{
	char * chaine2;

	chaine2=(char *)malloc(strlen(chaine)+2); // insertion au début d'une chaîne aussi grande que souhaitée
	strcpy(chaine2,&chaine[positionCaractere]);
	chaine[positionCaractere] = caractereAInserer;
	strcpy(&chaine[positionCaractere+1],chaine2);
}
