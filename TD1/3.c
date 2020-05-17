#include <uvsqgraphics.h>

void affiche_efface()
{
POINT p1,p2;
int i;

for(i=0;;i++)
{
p1=wait_clic();
draw_fill_circle(p1,25,red);
draw_fill_circle(p2,25,noir);
p2=wait_clic();
draw_fill_circle(p1,25,noir);
draw_fill_circle(p2,25,rouge);
}

}

int main()
{
init_graphics(600,600);

affiche_efface();

wait_escape(0);
exit(0);
}


