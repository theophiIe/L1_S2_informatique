#include "uvsqgraphics.h" 
// leger probleme, le premier element mangé n'apparait jamais ou alors il ne suit pas la tete du serpent
// a tester: ajout elem
int score=0;
int compteur=0; // pour le combo manger 3 meme elem d'affiles
int s=0;

// Définition des différentes formes
#define VIDE 0
#define CERCLE 100
#define CARRE 101
#define CROIX 102
// Définition des types
struct elem 
{
int i,j; // position sur le quadrillage de l’élément
int forme; // vaut VIDE, CERCLE, CARRE ou CROIX
COULEUR coul; // vaut bleu, rouge, jaune ou vert
};

struct serpent 
{
int longueur; // nombre d’éléments dans le corps du serpent // utilité dans le programme ?
struct elem A[200]; // les éléments constitutifs du serpent
int dx; 
int dy; // dx et dy stocke la direction dans laquelle va le serpent,un seul suffit
};

typedef struct elem ELEMENT;
typedef struct serpent SERPENT;

void init_jeu(struct elem J[40][60])
{
	int i,j; // compteur parcours du tableau
	int a,b; // comtpeur pour la couleur et la forme
	COULEUR coul[4]; // tableau de couleurs pour uen choisir une au hasard
	coul[0]=rouge;coul[1]=jaune;coul[2]=bleu;coul[3]=vert;
	for(i=0;i<40;i++)
	{
		for(j=0;j<60;j++)
		{
			a=alea_int(4);
			J[i][j].coul=coul[a]; // définit une couleur aleatoire pour une case
			
			do{
				b=alea_int(103);
			}while(b!=0 && b!=100 && b!=101 && b!=102); // définit une forme aleatoire pour une case
			J[i][j].forme=b;
				
		}
	}
}

struct serpent init_serpent() // la tete est-elle dans le tableau ??????
{
struct serpent S;
int a;
S.longueur=1; // c'est la tete
S.A[0].i=alea_int(40); // il peut apparaitre sur une case avec forme
S.A[0].j=alea_int(60);
S.A[0].coul=blanc;
S.A[0].forme=CERCLE;
S.dx=0;S.dy=0; // déplacement de base, le serpent attend l'appui sur une touche directionnelle



for(a=1;a<200;a++)
{// on cree un corps de serpent sur le plateau totalement vide,il suffira de le remplir apres
	S.A[a].forme=VIDE;
	S.A[a].coul=noir;
}
return S;
}

void affiche_jeu(struct elem J[40][60])
{

	
	int i,j; // compteur parcourir le tableau
	POINT p1,p2,p3,p4;
	p1.x=0;p1.y=0;
	p2.x=p1.x;p2.y=600; // ligne verticale
	
	p3.x=0;p3.y=0;
	p4.x=400;p4.y=p3.y; // ligne horizontale
	// dessine le quadrillage
	while(p1.x<400)
	{
		draw_line(p1,p2,blanc);
		p1.x=p1.x+10;
		p2.x=p1.x;
	}
	
	while(p3.y<=600)
	{
		draw_line(p3,p4,blanc);
		p3.y=p3.y+10;
		p4.y=p3.y;
	}
	// dessine les formes dans les cases
	for(i=0;i<40;i++)
	{
		for(j=0;j<60;j++)
		{
			if(J[i][j].forme==VIDE)
			{
			p1.x=i*10;p1.y=j*10; // point en bas a gauche
			p2.x=i*10;p2.y=j*10; // point en haut a droite
			draw_fill_rectangle(p1,p2,noir);
			}
			else if(J[i][j].forme==CERCLE)
			{
				p1.x=i*10+5;p1.y=j*10+5;
				draw_fill_circle(p1,3,J[i][j].coul);
			}
			else if(J[i][j].forme==CARRE)
			{
				p1.x=i*10+2;p1.y=j*10+2; // point en bas a gauche
				p2.x=i*10+8;p2.y=j*10+8; // point en haut a droite
				draw_fill_rectangle(p1,p2,J[i][j].coul);
			}
			else if(J[i][j].forme==CROIX)
			{
				p1.x=i*10;p1.y=j*10; // point en bas a gauche
				p2.x=i*10+10;p2.y=j*10; // point en bas a droite
				p3.x=i*10;p3.y=j*10+10; // point en haut a gauche
				p4.x=i*10+10;p4.y=j*10+10; // point en haut a droite
				
				draw_line(p1,p4,J[i][j].coul);
				draw_line(p2,p3,J[i][j].coul);
			}
		}
	}
}

  void affiche_serpent(struct serpent S) // // la derniere case ne s'efface pas
{ 
	int a;
	POINT p1,p2,p3,p4;
	// on efface l'ancienne position
	if(S.longueur==1) // le serpent n'a rien mangé,il n'y a que la tete dans le corps
	{
		p1.x=(S.A[0].i-S.dx)*10+5;p1.y=(S.A[0].j-S.dy)*10+5;
		draw_fill_circle(p1,3,noir);
	}
	else if(S.longueur==2)
	{
		p1.x=(S.A[0].i-S.dx)*10+5;p1.y=(S.A[0].j-S.dy)*10+5;
		draw_fill_circle(p1,3,noir);
	}
	else
	{
		
		
	for(a=0;a<=S.longueur;a++) // le corps contient autre chose que la tete 
	{
			if(S.A[a].forme==VIDE)
			;
			else if(S.A[a].forme==CERCLE)
			{
				p1.x=(S.A[a+1].i)*10+5;p1.y=(S.A[a+1].j)*10+5;
				draw_fill_circle(p1,3,noir);
			}
			else if(S.A[a].forme==CARRE)
			{
				p1.x=(S.A[a+1].i)*10+2;p1.y=(S.A[a+1].j)*10+2; // point en bas a gauche
				p2.x=(S.A[a+1].i)*10+8;p2.y=(S.A[a+1].j)*10+8; // point en haut a droite
				draw_fill_rectangle(p1,p2,noir);
			}
			else if(S.A[a].forme==CROIX)
			{
				p1.x=(S.A[a+1].i)*10;p1.y=(S.A[a+1].j)*10; // point en bas a gauche
				p2.x=(S.A[a+1].i)*10+10;p2.y=(S.A[a+1].j)*10; // point en bas a droite
				p3.x=(S.A[a+1].i)*10;p3.y=(S.A[a+1].j)*10+10; // point en haut a gauche
				p4.x=(S.A[a+1].i)*10+10;p4.y=(S.A[a+1].j)*10+10; // point en haut a droite
				
				draw_line(p1,p4,noir);
				draw_line(p2,p3,noir);
			}
	}
	}
	
	// on affiche la nouvelle position
	if(S.longueur==1) // le serpent n'a rien mangé,il n'y a que la tete dans le corps
	{
		p1.x=(S.A[0].i)*10+5;p1.y=(S.A[0].j)*10+5;
		draw_fill_circle(p1,3,S.A[0].coul);
	}
	
	else if(S.longueur==2)
	{
		for(a=0;a<S.longueur;a++)
	{
			if(S.A[a].forme==VIDE)
			;
			else if(S.A[a].forme==CERCLE)
			{
				p1.x=(S.A[a].i)*10+5;p1.y=(S.A[a].j)*10+5;
				draw_fill_circle(p1,3,S.A[a].coul);
			}
			else if(S.A[a].forme==CARRE)
			{
				p1.x=(S.A[a].i)*10+2;p1.y=(S.A[a].j)*10+2; // point en bas a gauche
				p2.x=(S.A[a].i)*10+8;p2.y=(S.A[a].j)*10+8; // point en haut a droite
				draw_fill_rectangle(p1,p2,S.A[a].coul);
			}
			else if(S.A[a].forme==CROIX)
			{
				p1.x=(S.A[a].i)*10;p1.y=(S.A[a].j)*10; // point en bas a gauche
				p2.x=(S.A[a].i)*10+10;p2.y=(S.A[a].j)*10; // point en bas a droite
				p3.x=(S.A[a].i)*10;p3.y=(S.A[a].j)*10+10; // point en haut a gauche
				p4.x=(S.A[a].i)*10+10;p4.y=(S.A[a].j)*10+10; // point en haut a droite
				
				draw_line(p1,p4,S.A[a].coul);
				draw_line(p2,p3,S.A[a].coul);
			}
	}
	}
	
	else
	{
	for(a=0;a<S.longueur-1;a++)
	{
			if(S.A[a].forme==VIDE)
			;
			else if(S.A[a].forme==CERCLE)
			{
				p1.x=(S.A[a].i)*10+5;p1.y=(S.A[a].j)*10+5;
				draw_fill_circle(p1,3,S.A[a].coul);
			}
			else if(S.A[a].forme==CARRE)
			{
				p1.x=(S.A[a].i)*10+2;p1.y=(S.A[a].j)*10+2; // point en bas a gauche
				p2.x=(S.A[a].i)*10+8;p2.y=(S.A[a].j)*10+8; // point en haut a droite
				draw_fill_rectangle(p1,p2,S.A[a].coul);
			}
			else if(S.A[a].forme==CROIX)
			{
				p1.x=(S.A[a].i)*10;p1.y=(S.A[a].j)*10; // point en bas a gauche
				p2.x=(S.A[a].i)*10+10;p2.y=(S.A[a].j)*10; // point en bas a droite
				p3.x=(S.A[a].i)*10;p3.y=(S.A[a].j)*10+10; // point en haut a gauche
				p4.x=(S.A[a].i)*10+10;p4.y=(S.A[a].j)*10+10; // point en haut a droite
				
				draw_line(p1,p4,S.A[a].coul);
				draw_line(p2,p3,S.A[a].coul);
			}
	}
	}
}

struct serpent deplace_serpent(struct serpent S, POINT p) // les conditions permettent de savoir dans quelle direction le serpent va
{ // les deplacements sont unidirectionnelle (pas de diagonale possible) 
 // les conditions et utilisation de S.dx & S.dy sont la car p=get_arrow() donne une valeur incoherente (pas adapte a la taille de notre jeu)
	int a;
			
			
		// on déplace tout le corps
		for(a=S.longueur-1;a>0;a--) 
		{
			S.A[a].i=S.A[a-1].i; // prend la position de la forme devant lui dans le tableau
			S.A[a].j=S.A[a-1].j;
		}
		
	// on effectue le deplacement
	if(S.A[0].i+p.x>S.A[0].i) // on verifie la tete car le reste du corps est oblige de suivre le parcours de la tete
		{
			S.dx=1;S.dy=0; // cette ligne sauvegarde le déplacement
		S.A[0].i=(S.A[0].i)+S.dx; // déplace les formes selon le déplacement du serpent
		S.A[0].j=(S.A[0].j);
		}
		
	else if(S.A[0].i+p.x<S.A[0].i)
		{
			S.dx=-1;S.dy=0;
		S.A[0].i=(S.A[0].i)+S.dx; 
		S.A[0].j=(S.A[0].j);
		}
		
	else if(S.A[0].j+p.y<S.A[0].j)
		{
			S.dx=0;S.dy=-1;
		S.A[0].i=(S.A[0].i); 
		S.A[0].j=(S.A[0].j)+S.dy;
		}
	else if(S.A[0].j+p.y>S.A[0].j)
		{
			S.dx=0;S.dy=1;
		S.A[0].i=(S.A[0].i); 
		S.A[0].j=(S.A[0].j)+S.dy;
		}
		
	else
		{
			S.dx=S.dx;S.dy=S.dy; // permet le deplacement continu du serpent meme lorsque le joueur n'utilise pas get_arrow
		S.A[0].i=(S.A[0].i)+S.dx;
		S.A[0].j=(S.A[0].j)+S.dy;
		}
		// A partir de la, A[0] a sa nouvelle position

	return S;
}

struct serpent manger_element(struct serpent S, struct elem J[40][60]) 
{// l'element est toujours ajouter au debut du corps donc en A[1] puisque A[0] est la tete
	int a;
	COULEUR TMPC;
	int TMPF;
	TMPF=VIDE; TMPC=noir;
	
	if(J[S.A[0].i][S.A[0].j].forme!=VIDE && (S.dx!=0 || S.dy!=0)) // on verifie que le serpent se deplace et que la tete est sur une forme
	{
		S.longueur=S.longueur+1; // est réutilise dans deplace_serpent
		
	// on ajoute l'element sur lequel on passe
	if(S.longueur-1==1) // il n'y a que la tete,le serpent s'apprete a manger son premier element
	{
	S.A[1].forme=J[S.A[0].i][S.A[0].j].forme;
	S.A[1].coul=J[S.A[0].i][S.A[0].j].coul;
	
	}
	else
	{
	// les elements sont decales de 1 pour laisse la case 1 libre
	for(a=S.longueur-1;a>1;a--) // on s'arrete a 1 car 1 est une case libre et 0 et la tete
	{
	S.A[a].forme=S.A[a-1].forme;
	S.A[a].coul=S.A[a-1].coul;
	} // la case 1 est "vide"
	
	S.A[1].forme=J[S.A[0].i][S.A[0].j].forme;
	S.A[1].coul=J[S.A[0].i][S.A[0].j].coul;
	}
	
	J[S.A[0].i][S.A[0].j].forme=VIDE;
	J[S.A[0].i][S.A[0].j].coul=noir;
	}
	//else si le plateau est vide et que la tete est sur son corps alors il le mange et score augmente +1 et si 3 d'affile +100
	else if(J[S.A[0].i][S.A[0].j].forme==VIDE && J[S.A[0].i][S.A[0].j].coul==noir && (S.dx!=0 || S.dy!=0))
	{
		for(a=1;a<S.longueur;a++)
		{
			if(S.A[0].i==S.A[a].i && S.A[0].j==S.A[a].j) // on verifie que la tete est sur une partie du corps
			{
				if(S.A[a].coul== TMPC && S.A[a].forme==TMPF)
				{compteur=compteur+1;}
				else
				{compteur=0;}
				
				TMPC=S.A[a].coul; TMPF=S.A[a].forme;
				S.A[a].coul=noir;S.A[a].forme=VIDE;
				
				if(compteur==2)
				{score=score+100;compteur=0;}
				else
				{score=score+1;}}
		}
	}
	

	return S;
}

struct serpent retrecir_serpent( struct serpent S)
{
	int a; // compteur pouur parcourir le serpent
	int i; // compteur pour faire les modif
	COULEUR TMPC=noir;
	int TMPF=VIDE;
	
	// on verifie si trois elements sont les memes
	if(S.longueur>=4)
	{
	for(a=1;a<S.longueur-3;a++) // -3 car à 198, 198+2=200 n'existe pas dans le serpent
	{
		if(S.A[a+1].forme == S.A[a].forme && S.A[a+1].coul == S.A[a].coul) // on vérifie la case suivante si faux inutile de poursuivre
		{
			if(S.A[a+2].forme == S.A[a].forme && S.A[a+2].coul == S.A[a].coul) // si vrai, 3 éléments sont alignés
			{
				for(i=a;i<a+3;i++)
				{// on fait disparaitre les 3 éléments identiques
					S.A[i].forme=VIDE;
					S.A[i].coul=noir;}
					TMPC=S.A[a].coul;TMPF=S.A[a].forme;
					while(S.A[a].coul==noir && S.A[a].forme==VIDE)
					{
				for(i=a;i<S.longueur-1;i++)
				{// on comble le trou apparu suite a la disparition des éléments
					S.A[i].forme=S.A[i+1].forme;
					S.A[i].coul=S.A[i+1].coul;
					S.A[S.longueur-1].forme=TMPF;
					S.A[S.longueur-1].coul=TMPC;}
					S.longueur=S.longueur-1;
					}
			}
		}
		
	}
	
	}
	return S;
}

void ajoute_element(struct elem J[40][60]) //il faut tester la fonction mais flemme, on ne voit rien 
{ // toutes les dix secondes et si la case est vide et s'il n'y a pas la tete,on ajoute un element
	int i,j;
	int a,b;
	COULEUR coul[4]; 
	coul[0]=rouge;coul[1]=jaune;coul[2]=bleu;coul[3]=vert;
	s=chrono_lap();
	if(s==10)
	{
		
		do{ // choisit une case vide aleatoirement
			i=alea_int(40);
			j=alea_int(60);
		}while(J[i][j].forme!=VIDE && J[i][j].coul!=noir);
		//on choisit aleatoirement une forme a mettre
		
		a=alea_int(4);
		J[i][j].coul=coul[a]; // définit une couleur aleatoire pour une case
			
		do{
			b=alea_int(103);
		}while(b!=0 && b!=100 && b!=101 && b!=102); // définit une forme aleatoire pour une case
		J[i][j].forme=b;
		chrono_start();
	}
}

void affiche_score()
{
	POINT p1,p2,p3;
	p1.x=180;p1.y=620;
	aff_pol("score:",12,p1,orange);
	p2.x=220;p2.y=620;
	p3.x=400;p3.y=605;
	draw_fill_rectangle(p2,p3,noir);
	aff_int(score,12,p2,orange);
}

int perdre(struct serpent S,struct elem J[40][60] )
{// un peu rapide,il faut etre assez reactif pour aller plus vite que le test condition if
	if(S.A[0].i>=40 || S.A[0].j>=60 || S.A[0].i<0 || S.A[0].j<0) 
	return 1; // 1 le jeu s'arrete
	else if(J[S.A[0].i][S.A[0].j].forme==CERCLE && J[S.A[0].i][S.A[0].j].coul==rouge && (S.dx!=0 || S.dy !=0))
	return 1;
	else if(J[S.A[0].i][S.A[0].j].forme==CARRE && J[S.A[0].i][S.A[0].j].coul==bleu && (S.dx!=0 || S.dy !=0))
	return 1;
	else if(J[S.A[0].i][S.A[0].j].forme==CROIX && J[S.A[0].i][S.A[0].j].coul==jaune && (S.dx!=0 || S.dy !=0))
	return 1;
	else
	return 2; // valeur aléatoire par defaut, 0 etant deja pris pour une forme.2 le jeu continue 
}
int main()
{
struct elem J[40][60]; // plateau
struct serpent S;
POINT p;
int perdu=0;

init_graphics(400,630);
init_jeu(J);
S = init_serpent();
chrono_start();

while (perdu!=1) // condition stop : s'il mange la mauvaise forme ou si la tete touche le bord de l'ecran 
{
p = get_arrow();
ajoute_element(J);

S = deplace_serpent(S,p);
//perdu=perdre(S,J);
S=manger_element(S,J); // rajouter le code pour manger le corps
S=retrecir_serpent(S);


affiche_jeu(J);
affiche_serpent(S);
affiche_score();



}
wait_escape();
exit(0);
} 
