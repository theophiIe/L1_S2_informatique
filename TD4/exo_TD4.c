#include <uvsqgraphics.h>

int Vies=3;

int SCORE=0;

int Longueur=900;

int Largeur=600;

#define PERDU 3

 

struct Raquette

{

POINT p1,p2;

COULEUR coul; 

};

 

typedef struct Raquette RAQUETTE;

 

struct balle

{

POINT centre,centre2,centre3;

int rayon;

COULEUR coul;

int dx, dy;

};

 

typedef struct balle BALLE;

 

BALLE init_balle()

{

BALLE B;

B.centre.x=450;B.centre.y=300;
B.centre2.x=400;B.centre2.y=280;
B.centre3.x=350;B.centre3.y=260;
B.rayon=25;

B.coul=bleu;

B.dx=2;B.dy=3;

return B;

}

 

BALLE deplace_balle(BALLE B)

{

B.centre.x=B.centre.x+B.dx;

B.centre.y=B.centre.y+B.dy;

B.centre2.x=B.centre2.x+B.dx;

B.centre2.y=B.centre2.y+B.dy;

B.centre3.x=B.centre3.x+B.dx;

B.centre3.y=B.centre3.y+B.dy;

return B;

}

 

BALLE efface_balle(BALLE B )

{

draw_fill_circle(B.centre,B.rayon,noir);

return B;

}

 

BALLE affiche_balle(BALLE B)

{

draw_fill_circle(B.centre,B.rayon,B.coul);

return B;

}



BALLE efface_balle2(BALLE B )

{

draw_fill_circle(B.centre2,B.rayon,noir);

return B;

}

 

BALLE affiche_balle2(BALLE B)

{

draw_fill_circle(B.centre2,B.rayon,B.coul);

return B;

}


BALLE efface_balle3(BALLE B )

{

draw_fill_circle(B.centre3,B.rayon,noir);

return B;

}

 

BALLE affiche_balle3(BALLE B)

{

draw_fill_circle(B.centre3,B.rayon,B.coul);

return B;

}


BALLE rebond_balle(BALLE B,int a,int Max)

{

if((B.centre.x-B.rayon)<=0||(B.centre.x+B.rayon)>=900)

B.dx=-B.dx;

else if((B.centre.y+B.rayon)>=Max||a==1)

B.dy=-B.dy;

else

{

B.dx=B.dx;B.dy=B.dy;

}

return B;

}

 

int choc(BALLE B,RAQUETTE R)

{

if((B.centre.y-B.rayon)<= R.p2.y&&(B.centre.x+B.rayon)>=R.p1.x&&B.centre.x-B.rayon<=R.p2.x)

return 1;

else

return 0;

}

 

void efface_Raquette(RAQUETTE ancienne)

{

draw_fill_rectangle(ancienne.p1,ancienne.p2,noir);

}

 

void affiche_Raquette(RAQUETTE R)

{

draw_fill_rectangle(R.p1,R.p2,R.coul);

}

 

RAQUETTE deplace_Raquette(RAQUETTE R, int dx)

{

R.p1.x=R.p1.x+dx;

R.p2.x=R.p2.x+dx;

return R;

}

 

RAQUETTE deplace_Raquette2(RAQUETTE R, POINT P)

{

int Test,test1;

Test=R.p1.x+P.x;test1=R.p2.x+P.x;

if(Test<=0 || test1 >=900)

{

return R;

}

else

{

R.p1.x=R.p1.x+P.x*2;

R.p2.x=R.p2.x+P.x*2;

return R;

}

}

 

int perdre(BALLE B)

{

if((B.centre.y-B.rayon)<=0)

return PERDU;

else

return 1;

}

 

void affiche(int Vies, int Scores)

{

POINT p1,p2,p3,p4;

p1.x=0;p1.y=599;

p2.x=0;p2.y=586;

p3.x=p1.x+50;p3.y=p1.y;

p4.x=p2.x+55;p4.y=p2.y;

aff_pol("Vies :",15,p1,orange);

aff_pol("Score :",15,p2,orange);

aff_int(Vies,15,p3,orange);

aff_int(Scores,15,p4,orange);

}

 

int ajoute_vie(int combo) 

{

if(combo==10)

{Vies=Vies+1;

combo=0;

return combo;}

else

{Vies=Vies;

return combo;}

}

 

int accelere_balle(BALLE B)// option 3,augmente la vitesse a chaque rebond

{ 

B.dx=B.dx*1.25;

return B.dx;

}

 

RAQUETTE retrecir_raquette(RAQUETTE R) 

{

if(distance(R.p1,R.p2)>0&&R.p1.x<R.p2.x)

{

R.p1.x=R.p1.x+2;

return R;

}

else

return R;

}

 

BALLE retrecir_BALLE(BALLE B) // option 6

{

if(B.rayon>0)

{

B.rayon=B.rayon-1;

return B;

}

else

return B;

}

 

int descendre_plafond(int Max) 

{

 

Max=Max-5;

return Max;

}

int main()

{

init_graphics(Longueur,Largeur);

BALLE Balle,Balle2;

RAQUETTE R,R1;

POINT P;

int MAX=Largeur;

int c=0; 

R.p1.x=0;R.p1.y=0;

R.p2.x=75;R.p2.y=10;

R.coul=orange;

int a=0; // pour fonction choc

//int dx=2;

 

/*for(i=0;i<100;i++)

{

R1=deplace_Raquette(R,dx);

affiche_auto_off();

fill_screen(noir);

efface_Raquette(R);

affiche_Raquette(R1);

attendre(10);

affiche_all();

R=R1;

} */

while(Vies>0)

{

Balle=init_balle();

affiche_Raquette(R);

affiche_balle(Balle);

while((Balle.centre.y-Balle.rayon)>0) 

{

P=get_arrow();

 

R1=deplace_Raquette2(R,P);

Balle2=deplace_balle(Balle); 

affiche_auto_off(); 

fill_screen(noir);

affiche(Vies, SCORE);

efface_balle(Balle);

affiche_balle(Balle2);

attendre(5); 

efface_Raquette(R);

affiche_Raquette(R1);

affiche_all(); 

a=choc(Balle2,R1);

if(a==1)

{

SCORE=SCORE+1;

c++;

c=ajoute_vie(c);

Balle2.dx=accelere_balle(Balle2); 

R1=retrecir_raquette(R1);

Balle2=retrecir_BALLE(Balle2);

MAX=descendre_plafond(MAX);

if(SCORE>=20)
{

efface_balle2(Balle);

affiche_balle2(Balle2);

attendre(5); 

efface_balle3(Balle);

affiche_balle3(Balle2);

attendre(5); 

}
}

else

{

SCORE=SCORE;

Balle2.dx=Balle2.dx;

}

Balle=rebond_balle(Balle2,a,MAX);// test pour savoir si la balle rebondit sur les murs

if(perdre(Balle)==PERDU)

{

Vies=Vies-1;

SCORE=0;

 

}

else

{

Balle.centre.x=Balle2.centre.x;Balle.centre.y=Balle2.centre.y; // enregistre pos de la raquette et de la balle

R=R1;

}

}

}

wait_escape();

exit(0);

}
