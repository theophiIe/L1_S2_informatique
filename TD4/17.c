#include <uvsqgraphics.h>

struct balle 
	{
		
	POINT centre;
	
	int rayon;
	
	COULEUR coul;
	
	int dx, dy;
	
	};

typedef struct balle BALLE;

BALLE init_balle()
{

BALLE B;

B.centre.x=50;	B.centre.y=250;

B.rayon=10;

B.coul=vert;

B.dx=2;	B.dy=3;

return B;

}

void efface_balle(BALLE B)
{
draw_fill_circle(B.centre,B.rayon,noir);
}

void affiche_balle(BALLE B)
{
draw_fill_circle(B.centre,B.rayon,B.coul);
}

BALLE deplace_balle(BALLE B)
{

B.centre.x = B.centre.x + B.dx;
B.centre.y = B.centre.y + B.dy;

return B;
}

BALLE rebond_balle(BALLE B)
{

if((B.centre.x>800)||(B.centre.x<20))
{

B.dx = -B.dx;

}
else if ((B.centre.y>600)||(B.centre.y<20))
{
	
B.dy = -B.dy;	

}
else 
{

B.dx=B.dx;B.dy=B.dy;

}
return B;
}

int main()
{
init_graphics(800,600);
BALLE B;
B=init_balle();
for(int i = 1; i<8000;i++)
{

B=rebond_balle(B);
B=deplace_balle(B);
affiche_balle(B);
attendre(4);
efface_balle(B);

}

wait_escape(0);
exit(0);	
}

