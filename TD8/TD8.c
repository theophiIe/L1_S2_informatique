#include <uvsqgraphics.h>
#include <math.h>
#define LARGEUR 8
#define LARGEUR 8
int c [8][12];
int i,j;

void plateau()
{
POINT p1,p2;

for(int n=0;n<=9;n++)
{
	p1.x=50*n; p1.y=50;
	p2.x=50*n; p2.y=650;

		draw_line(p1,p2,blanc);
}

for(int n=0;n<=13;n++)
{
	p1.x=50; p1.y=50*n;
	p2.x=450; p2.y=50*n;

		draw_line(p1,p2,blanc);
}}

void initialiser(int i, int j)
{
for(i=0;i<8;i++)
{

	for(j=0;j<12;j++)
	{
		c[i][j]=alea_int(4);
}}}


void cercle(int i, int j)
{
POINT centre;
COULEUR coul=blanc;
for(i=0;i<8;i++)
{
	for(j=0;j<12;j++)
	{
		centre.x=(50*i)+75;
		centre.y=(50*j)+75;
		if(c[i][j]==0) coul=bleu;
		if(c[i][j]==1) coul=rouge;
		if(c[i][j]==2) coul=jaune;
		if(c[i][j]==3) coul=vert;
		draw_fill_circle(centre,20,coul);
}}}



int main()
{
init_graphics(500,700);

plateau();
initialiser(i,j);
cercle(i,j);

wait_escape(0);
exit(0);

}

