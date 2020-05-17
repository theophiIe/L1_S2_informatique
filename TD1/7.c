#include <uvsqgraphics.h>

void efface_affiche(POINT ancien, POINT nouveau)
{

draw_fill_circle(ancien,25,noir);
nouveau=ancien;

draw_fill_circle(nouveau,25,red);
affiche_all();
affiche_auto_off();
ancien=nouveau;
draw_fill_circle(ancien,25,noir);

}

POINT deplace_balle(POINT ancien,int dx, int dy)
{

ancien.x=ancien.x+dx;
ancien.y=ancien.y+dy;

return ancien;

}

POINT init_balle(int x, int y)
{

POINT p;
p.x=x;
p.y=y;

return p;

}

int main()
{
init_graphics(900,900);

POINT ancien;
POINT nouveau;

ancien=init_balle(500,400);
nouveau=ancien;

int i;

for(i=0;i<1000;i++)
{

ancien=deplace_balle(ancien,1,1);
draw_fill_circle(ancien,25,red);
affiche_all();
nouveau=ancien;
draw_fill_circle(nouveau,25,noir);
affiche_auto_off();

}

wait_escape(0);
exit(0);
}
