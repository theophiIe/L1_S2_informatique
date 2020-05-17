#include <uvsqgraphics.h>

COULEUR T[256][256];

void remplir_rouge_bleu()
{
int i,j;

for(i=0;i<256;i++)
{
for(j=0;j<256;j++)
{
T[i][j]=couleur_RGB(i,0,j);
}
}
}

void affiche_2D()
{
POINT p,p1;
int i,j;

for(i=0;i<256;i++)
{
for(j=0;j<256;j++)
{

p.x=2*i; p.y=2*j;
p1.x=2+2*i; p1.y=2+2*j;

draw_fill_rectangle(p,p1,T[i][j]);
}
}
}
int main()
{
init_graphics(512,512);

remplir_rouge_bleu();
affiche_2D();

wait_escape(0);
exit(0);	
}
