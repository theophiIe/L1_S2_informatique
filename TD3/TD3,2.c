#include <uvsqgraphics.h>


void dessine_123different(int a)
{

POINT p,P,p1;

int i;

for(i=0;i<a;i++)
{

	p.x=20;
	p.y=20;
	P.x=p.x+50;
	P.y=p.y+50;
	draw_rectangle(p,P,blanc);

	p1.x=45;
	p1.y=45;
	draw_fill_circle(p1,2,blanc);

	p.x=p.x+60*i;
	p.y=p.y;
	P.x=P.x+60*i;
	P.y=P.y;
	draw_rectangle(p,P,blanc);


	
if(a==2)
{
	p1.x=115;
	p1.y=35;
	draw_fill_circle(p1,6,blanc);
	
	p1.x=95;
	p1.y=55;
	draw_fill_circle(p1,6,blanc);
}
if(a==3)
{
	p1.x=115;
	p1.y=35;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=95;
	p1.y=55;
	draw_fill_circle(p1,2,blanc);
	p1.x=165;
	p1.y=45;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=177;
	p1.y=35;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=153;
	p1.y=55;
	draw_fill_circle(p1,2,blanc);
}
}

if(a==4)
{

	p1.x=115;
	p1.y=35;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=95;
	p1.y=55;
	draw_fill_circle(p1,2,blanc);
	p1.x=165;
	p1.y=45;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=177;
	p1.y=35;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=153;
	p1.y=55;
	draw_fill_circle(p1,2,blanc);
	

	p1.x=208;
	p1.y=30;
	draw_fill_circle(p1,2,blanc);

	p1.x=240;
	p1.y=30;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=240;
	p1.y=60;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=208;
	p1.y=60;
	draw_fill_circle(p1,2,blanc);
}
}










int main()
{
	
init_graphics(600,600);
dessine_123different(4);

wait_escape(0);
exit(0);
	
}

