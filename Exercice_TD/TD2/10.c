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

int main()
{
init_graphics(512,512);

remplir_gris();


wait_escape(0);
exit(0);	
}

