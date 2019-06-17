#include <uvsqgraphics.h>

COULEUR T[256][256][256];

void remplir_aleatoir()
{
int i,j,k;

for(i=0;i<256;i++)
{
for(j=0;j<256;j++)
{
for(k=0;k<256;k++)
{	
T[i][j][k]=couleur_RGB(i,j,k);
}}}
}

void affiche_2D()
{
POINT p,p1;
int i,j,k;


for(k=0;k<256;k++)
{

i=alea_int(256);
j=alea_int(256);

p.x=2*i; p.y=2*j;
p1.x=2+2*i; p1.y=2+2*j;

draw_fill_rectangle(p,p1,T[i][j][k]);
}
}



int main()
{
init_graphics(512,512);

remplir_aleatoir();
affiche_2D();

wait_escape(0);
exit(0);	
}
