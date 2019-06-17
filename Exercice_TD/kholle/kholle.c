#include <uvsqgraphics.h>
#define N 100

void init_croissant(int T[])
{

for(int i=0; i<N; i++)
{	
	T[i]=i+1;
}
}

void init_decroissant(int T[])
{

for(int i=0; i<N; i++)
{
	T[i]=100-i;
}
}

void init_alea(int T[])
{

for(int i=0; i<N; i++)
{
		T[i]=alea_int(N);
}
}



void affiche(int T[])
{
fill_screen(black);
POINT p1,p2;

p1.x=5;		p1.y=50;
p2.x=10;

for(int i=0; i<N; i++)
{

	p2.y=T[i]+50;
	draw_fill_rectangle(p1,p2,gold);
	
	p1.x=p1.x+8;		p2.x=p2.x+8;
}
}

void echange(int T[], int i, int j)
{
int tmp;
  tmp = T[i];
  T[i] = T[j];
  T[j] = tmp;
}

void TriInsertion(int T[])
{
	
int TC, i, p, tmp;

for (TC = 0; TC < N-1; TC++)
{
	tmp = T[TC+1];
	p = 0;
	
while( T[p] < tmp)
{
	p = p + 1;
}

for (i = TC; i >= p; i--)
{
	T[i+1] = T[i];
}
	T[p] = tmp;
	attendre(100);
	affiche(T);
}
}




int Recherche_ind_min(int T[],int d)
{
int indmin;
int i;
indmin = d;

for(i=d;i<N;i++)
{

if (T[i] < T[indmin])
{
	indmin = i;
}
}

return indmin;
}

void TriSelection(int T[])
{
	
int TC, indmin;

for (TC = 0; TC < N-1; TC++)
{
indmin = Recherche_ind_min(T,TC);
echange(T,TC,indmin);
attendre(100);
affiche(T);
}

}



void Bulles(int T[])
{

int TC,i;

for(TC=1;TC<N;TC++)
{

for(i=N-1;i>=TC;i--)
{
if (T[i-1] > T[i])
{echange(T,i,i-1);}
}
attendre(100);
affiche(T);
}

}




int main() 
{
init_graphics(810,400);
chrono_start();
int T[N];

init_alea(T);
affiche(T);
//Bulles(T);
//TriSelection(T);
TriInsertion(T);
float a;

a=chrono_lap();
POINT p1;
p1.x=100;	p1.y=350;
aff_int(a*1000,50,p1,gold);
wait_escape();
exit(0);
}

