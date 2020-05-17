#include <uvsqgraphics.h>

void carre()
{
POINT p,p1,p2,p3;


p.x=0;
p.y=0;
p1.x=p.x + 50;
p1.y=p.y + 50;
draw_rectangle(p,p1,blanc);


p2.x=p.x;
p2.y=p.y;
p3.x=p.x + 50;
p3.y=p.y + 50;
draw_line(p2,p3,blanc);


p2.x=p.x;
p2.y=p.y + 50;
p3.x=p.x + 50;
p3.y=p.y;
draw_line(p2,p3,blanc);
}

int main()
{
init_graphics(600,600);

carre();



wait_escape(0);
exit(0);
}
