#include <uvsqgraphics.h>

POINT init_balle(int x, int y)
{

POINT p;
p.x=x;
p.y=y;

return p;

}

POINT deplace_balle(POINT p,int dx, int dy)
{

p.x=p.x+dx;


p.y=p.y+dy;

return p;

}



int main()
{
init_graphics(900,900);

POINT p;
POINT nouveau;

p=init_balle(500,400);
nouveau=p;
int dexh=2;

while(1)
{
	
p=deplace_balle(p,0,dexh);

draw_fill_circle(p,25,red);
affiche_all();
nouveau=p;
draw_fill_circle(nouveau,25,noir);
affiche_auto_off();

}

wait_escape(0);
exit(0);
}



