#include "uvsqgraphics.h"
#define LARGEUR 8
#define HAUTEUR 12

COULEUR B[LARGEUR][HAUTEUR];
int score=0;

COULEUR couleur_aleatoire() // fonction pour choisir une couleur aléatoire
{
	COULEUR C[4];
	int i;
	COULEUR c;
	C[0]=jaune;C[1]=rouge;C[2]=bleu;C[3]=vert;
	
	i=alea_int(4);
	c=C[i];
	return c;
}

void init_boules() // mets des couleurs aléatoire dans le tableau
{
	int i,j;
	
	for(i=0;i<LARGEUR;i++)
	{
		for(j=0;j<HAUTEUR;j++)
		{
			B[i][j]=couleur_aleatoire();
		}
	}
}

void affiche_quadrillage()
{
	POINT p1,p2,p3,p4;
	p1.x=0;p1.y=0;
	p2.x=p1.x;p2.y=HAUTEUR*50; // ligne verticale
	
	p3.x=0;p3.y=0;
	p4.x=HAUTEUR*50;p4.y=p3.y; // ligne horizontale
	
	while(p1.x<LARGEUR*50)
	{
		draw_line(p1,p2,blanc);
		p1.x=p1.x+50;
		p2.x=p1.x;
	}
	
	while(p3.y<=HAUTEUR*50)
	{
		draw_line(p3,p4,blanc);
		p3.y=p3.y+50;
		p4.y=p3.y;
	}
	
}

void affiche_boules()
{
	int i,j;
	POINT centre;
	for(i=0;i<LARGEUR;i++)
	{
		for(j=0;j<HAUTEUR;j++)
		{
		centre.x=i*50+25;;centre.y=j*50+25;
		draw_fill_circle(centre,20,B[i][j]);
		}
	}
}

void affiche_score(int coup)
{
	int i,j;
	int compteur=0;
	POINT p1,p2,p3;
	
	p1.x=235;p1.y=630;
	
	p2.x=230;p2.y=610;
	p3.x=400;p3.y=650;
	
	for(i=0;i<LARGEUR;i++)
	{
		for(j=0;j<HAUTEUR;j++)
		{
			if(B[i][j]==noir)
			compteur=compteur+1;
		}}
		if(compteur==LARGEUR*HAUTEUR)
		score=score+200;
		else
		score=score+coup*(coup-1);
		
	draw_fill_rectangle(p2,p3,noir); // technique pour effacer le résultat precedent
	aff_int(score,15,p1,orange);
}

int mettre_a_noir(COULEUR coul, int i, int j) // optimisation -> faire une récursivité
{
	int ligne,colonne;
	int score=0;
	POINT centre;
	if(coul==noir) // vérifie les cases autour et les mets en noir si OK
	return 0;
	if(B[i-1][j]==coul)
	{ // a gauche de la case cliquee
	B[i-1][j]=noir;score++;}
	if(B[i+1][j]==coul) // a droite
	{
	B[i+1][j]=noir;score++;}
	if(B[i][j-1]==coul)
	{ // en bas
	B[i][j-1]=noir;score++;}
	if(B[i][j+1]==coul)
	{ // en haut
	B[i][j+1]=noir;score++;}
	
	B[i][j]=noir;
	score++;
	
		for(ligne=i-1;ligne<=(i+1);ligne++) // colorie les ensembles si ne dépasse pas du jeu
		{
			for(colonne=j-1;colonne<=(j+1);colonne++)
			{
				if(ligne >=0 && colonne>=0 &&  ligne< LARGEUR && colonne< HAUTEUR) // condition de non débordement
				{
				centre.x=ligne*50+25;
				centre.y=colonne*50+25;
				draw_fill_circle(centre,20,B[ligne][colonne]);
				}
			}
			
		}
		return score;
}



void descendre_colonne(int j) //tasse les boules vers le bas
{
	int compteur,a;
	POINT centre;
	COULEUR TMP; // variable temporaire qui stocke la couleur de notre case clic
	for(compteur=0;compteur<HAUTEUR;compteur++) // cherche a partir de quelle ligne il y a une boule noire
		{	
		if(j-1>=0 && j+1<LARGEUR && compteur+1<HAUTEUR) // cas ou le clic est au centre du plateau
		{
			
		for(a=j-1;a<=j+1;a++) // vérifie les cases alentour en y
		{
			if(B[a][compteur]==noir)
			{
				if(B[a][compteur+1]==noir && compteur+2<HAUTEUR && B[a][compteur+2]!=noir)
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+2]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+2]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+125;
				draw_fill_circle(centre,20,B[a][compteur+2]);	
				}
				else if(B[a][compteur+2]==noir&& B[a][compteur+1]==noir && compteur+3<HAUTEUR)
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+3]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+3]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+175;
				draw_fill_circle(centre,20,B[a][compteur+3]);
				}
				else
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+1]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+1]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+75;
				draw_fill_circle(centre,20,B[a][compteur+1]);
				}
			}
			}
							
		}
		else if(j-1<0 && j+1<LARGEUR && compteur+1<HAUTEUR) // cas ou on est sur le bord gauche
		{
			for(a=j;a<j+2;a++)
			{
			if(B[a][compteur]==noir)
			{
				if(B[a][compteur+1]==noir && compteur+2<HAUTEUR && B[a][compteur+2]!=noir) // OK
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+2]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+2]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+125;
				draw_fill_circle(centre,20,B[a][compteur+2]);	
				}
				else if(B[a][compteur+2]==noir&& B[a][compteur+1]==noir && compteur+3<HAUTEUR)
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+3]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+3]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+175;
				draw_fill_circle(centre,20,B[a][compteur+3]);
				}
				else
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+1]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+1]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+75;
				draw_fill_circle(centre,20,B[a][compteur+1]);
				}
			}
			}
		}
		else if(j-1>=0 && j+1>=LARGEUR && compteur+1<HAUTEUR)// bord droit
		{
			for(a=j-1;a<j+1;a++)
{
			if(B[a][compteur]==noir)
			{
				if(B[a][compteur+1]==noir && compteur+2<HAUTEUR && B[a][compteur+2]!=noir) 
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+2]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+2]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+125;
				draw_fill_circle(centre,20,B[a][compteur+2]);	
				}
				else if(B[a][compteur+2]==noir && B[a][compteur+1]==noir && compteur+3<HAUTEUR)
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+3]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+3]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+175;
				draw_fill_circle(centre,20,B[a][compteur+3]);
				}
				else
				{
				TMP=B[a][compteur];
				B[a][compteur]=B[a][compteur+1]; // { permet le switch entre case cliquée et case au dessus
				B[a][compteur+1]=TMP;
				centre.x=a*50+25;centre.y=compteur*50+25; // effectue visuellement les changement
				draw_fill_circle(centre,20,B[a][compteur]);
				centre.x=a*50+25;centre.y=compteur*50+75;
				draw_fill_circle(centre,20,B[a][compteur+1]);
				}
			}
			}
		}
}
}

void deplacement_droite()// mets une colonne noir tout a gauche
{
	int i,j,a,b; // a sert a parcourir une deuxieme fois la colonne noire
	POINT centre;
	COULEUR TMP; // stock temporairement la colonne i-1
	int vide=0;
	for(i=0;i<LARGEUR;i++)
	{
		vide=0;
	for(j=0;j<HAUTEUR;j++)
	{
		if(B[i][j]==noir) // compte le nombre de boules noires sur une colonne
		vide=vide+1;
		if(vide==HAUTEUR) // OK change la couleur de la colonne
		{
			for(b=i;b>=0;b--) // boucle pour décaler la colonne noir jusqu'a gauche
			{
				for(a=0;a<HAUTEUR;a++)
				{ // inverse 2 colonnes
					if(b-1>=0) // évite le débordement sur le bord gauche
					{
						TMP=B[b][a]; // stocke la couleur noire de la colonne à déplacer
						B[b][a]=B[b-1][a]; // prend la couleur de la colonne d'avant
						B[b-1][a]=TMP; // la colonne d'avant prend la couleur noir
						centre.x=b*50+25;centre.y=a*50+25; // effectue visuellement le changmeent
						draw_fill_circle(centre,20,B[b][a]);
						centre.x=b*50-25;centre.y=a*50+25;
						draw_fill_circle(centre,20,B[b-1][a]);
					}	
				}
			}	
		}	
	}
}

}

void gestion_clic() // effectue les deplacements,modifie le score 
{
	
	int abs,ord; // int i,j de la fonction mettre_a_noir...
	POINT p;
	int boules=0;
	p=wait_clic();
	abs=p.x/50;
	ord=p.y/50;
	
	boules=mettre_a_noir(B[abs][ord],abs,ord);
	descendre_colonne(abs);
	deplacement_droite();
	affiche_score(boules); 
	
	
}

void affiche()
{
	POINT p;
	p.x=180;p.y=630;
	
	init_boules();
	aff_pol("score :",15,p,orange);
	affiche_quadrillage();
	affiche_boules();
}

int gagner()
{
	int i,j,G;
	G=0;
	for(i=0;i<LARGEUR;i++) // compte le nombre de cases noires dans le tableau
	{
		for(j=0;j<HAUTEUR;j++)
		{
			if(B[i][j]==noir)
			G++;
		}
	}
	
	return G;
}

int main()
{
	init_graphics(400,650);
	int G_P=0;
	
	affiche();
	
	while(G_P!=(LARGEUR*HAUTEUR)) // toute les cases doivent etre noires
	{
		gestion_clic();
		G_P=gagner();
	}
	
	wait_escape();
	exit(0);
}
