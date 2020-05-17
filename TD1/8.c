#include <uvsqgraphics.h>

POINT init_balle(int x, int y)
{

POINT p;
p.x=x;
p.y=y;

return p;

}

int trop_haut(POINT p, int r)
{

if(p.y<800-r)
{
	return 1;
}

else
{
	return 0;
}

}

POINT deplace_balle(POINT p,int dx, int dy)
{

p.x=p.x+dx;
p.y=p.y+dy;

return p;

}

int trop_bas(POINT p, int r)
{

if(p.y+r<0)
{
	return 1;
}

else
{
	return 0;
}

}

int trop_a_droite(POINT p, int r)
{

if(p.x+r<0)
{
	return 1;
}

else
{
	return 0;
}

}

int trop_a_gauche(POINT p, int r)
{

if(p.x<800+r)
{
	return 1;
}

else
{
	return 0;
}

}


int main()
{
init_graphics(800,800);

POINT p;
POINT nouveau;

p=init_balle(500,400);
nouveau=p;
int dexh=1;
int aaa=1;
while(1)
{
	
p=deplace_balle(p,aaa,dexh);

if(trop_haut(p,25)==0)
{
	dexh = -1;

}

else if(trop_bas(p,25)==1)
{
	dexh = 1;
}
if(trop_a_gauche(p,25)==0)
{
	 aaa= -1;

}

else if(trop_a_droite(p,25)==1)
{
	aaa = 1;
}

draw_fill_circle(p,25,red);
affiche_all();
nouveau=p;
draw_fill_circle(nouveau,25,noir);
affiche_auto_off();

}

wait_escape(0);
exit(0);
}


