#include <uvsqgraphics.h>

void efface_affiche(POINT ancien, POINT nouveau)
{
affiche_auto_off();
draw_fill_circle(ancien,25,noir);
draw_fill_circle(nouveau,25,red);
affiche_all();
}

int main()
{
init_graphics(900,600);

POINT p,p1;
int i;
p.x=50; p.y=50;

wait_clic();

for(i=0;i<200;i++)
{
attendre(10);	
efface_affiche(p1,p);
p1.x=p.x; p1.y=p.y;
p.x=p.x+2; p.y=p.y+3;
}


wait_escape(0);
exit(0);
}

