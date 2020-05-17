#include "uvsqgraphics.h"



POINT init_balle(int x, int y)
{
	POINT p;
	p.x = x;
	p.y = y;
		
		return p;
}


int trop_haut(POINT p, int r)
{
		if(p.y < 900 - r)
		{
			return 1;
	    }
	    else 
	    {
				return 0;
		}
}

POINT deplace_balle(POINT p, int dx, int dy)
{
		
		
		p.x = p.x + dx;
		p.y = p.y + dy;

		return p;
		
		
		
}


int trop_bas(POINT p, int r)
{
		if(p.y < r)
		{
			return 1;
	    }
	    else 
	    {
				return 0;
		}
}

int trop_droite(POINT p, int r)
{
		if(p.x > 900 - r)
		{
			return 1;
	    }
	    else 
	    {
				return 0;
		}
}

int trop_gauche(POINT p, int r)
{
		if(p.x < r)
		{
			return 1;
	    }
	    else 
	    {
				return 0;
		}
}

void init_raquette(POINT ra, POINT rb)
{
		ra.x = 400; ra.y = 100;
		rb.x = 500; rb.y = 120;
		draw_fill_rectangle(ra,rb,bleu);
		
}

int deplace_raquette(POINT g, POINT d)
{
	
	
}

int main()
{
init_graphics(900,900);
POINT ra; POINT rb;
init_raquette(ra,rb);
POINT nouveau; POINT p;
p = init_balle(300,400);
nouveau = p; int dexh = 2; 
int deyh = 1;

COULEUR c = red;


while(1)
	{
		p = deplace_balle(p,deyh,dexh);
		if( trop_haut(p,25) == 0)
		 {
			dexh = -alea_int(2);;
			c = green;
		 }
		 if( trop_bas(p,25) == 1)
		 {
			dexh = alea_int(2);
			c = purple;
		 }
		if( trop_droite(p,25) == 1)
		 {
			deyh = -alea_int(2);;
			c= yellow;
		 }
		 if( trop_gauche(p,25) == 1)
		 {
			deyh = alea_int(2);;
			c= bleu;
		 }
		 
		 
		
		draw_fill_circle(p,25,c);
		affiche_all();
		nouveau = p;
		draw_fill_circle(nouveau,25,black);
		affiche_auto_off();
		 
		 
		
		
	}
		 
	
	
wait_escape();
exit(0);
}
