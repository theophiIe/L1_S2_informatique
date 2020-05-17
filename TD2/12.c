#include <uvsqgraphics.h>

COULEUR T[256];

void remplir_gris()
{
int i;

for(i=0;i<256;i++)
{
T[i]=couleur_RGB(i,i,i);
}
}

void affiche_horizontal()
{

int i;

for(i=0;i<256;i++)
{

POINT p,p1;

p.x=0; p.y=2*i;
p1.x=512; p1.y=2+2*i;

draw_fill_rectangle(p,p1,T[i]);
}
}


int main()
{
init_graphics(512,512);
remplir_gris();
affiche_horizontal();

wait_escape(0);
exit(0);	
}
