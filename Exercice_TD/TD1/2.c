#include <uvsqgraphics.h>

void triangle()
{
POINT p1,p2,p3;

p1.x=0;
p1.y=0;
p2.x=250;
p2.y=0;
p3.x=225;
p3.y=250;

draw_fill_triangle(p1,p2,p3,vert);

}

void triangle2()
{
POINT p1,p2,p3;

p1=wait_clic();
p2=wait_clic();
p3=wait_clic();

draw_fill_triangle(p1,p2,p3,blanc);

}
int main()
{
init_graphics(600,600);

triangle();
int i;
for(i=0;i<10;i++)
{
triangle2();
}

wait_escape(0);
exit(0);
}

