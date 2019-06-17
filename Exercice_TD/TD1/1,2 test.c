#include <uvsqgraphics.h>


void carre_de_base()
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

void carre()
{

POINT p,p1,p2,p3;

int a, b, d, longueur;
longueur=50;
	
	printf("nombre de colone\n");
	scanf("%d",&a);
	printf("nombre de ligne\n");
	scanf("%d",&b);

	int i,j;

//boucle pour les colones

	for(i=0;i<a;i++)
	{
		
			p.x=longueur*i;
			p.y=-50+longueur;
			p1.x=p.x + longueur;
			p1.y=p.y + longueur;
			draw_rectangle(p,p1,blanc);


			p2.x=p.x;
			p2.y=p.y;
			p3.x=p.x + longueur;
			p3.y=p.y + longueur;
			draw_line(p2,p3,blanc);


			p2.x=p.x;
			p2.y=p.y + longueur;
			p3.x=p.x + longueur;
			p3.y=p.y;
			draw_line(p2,p3,blanc);	
			
	}

//boucle pour les lignes
		
	i=0;
	
	for(j=0;j<b;j++)
	{
		i=i+1;
		p.x=-50+longueur;
		p.y=longueur*j;
		p1.x=p.x + longueur;
		p1.y=p.y + longueur;
		draw_rectangle(p,p1,blanc);


		p2.x=p.x;
		p2.y=p.y;
		p3.x=p.x + longueur;
		p3.y=p.y + longueur;
		draw_line(p2,p3,blanc);


		p2.x=p.x;
		p2.y=p.y + longueur;
		p3.x=p.x + longueur;
		p3.y=p.y;
		draw_line(p2,p3,blanc);	
		
		
			for (d=1;d<a;d++)
			{
				p.x=longueur*d;
				p.y=longueur*i-50;
				p1.x=p.x + longueur;
				p1.y=p.y + longueur;
				draw_rectangle(p,p1,blanc);


				p2.x=p.x;
				p2.y=p.y;
				p3.x=p.x + longueur;
				p3.y=p.y + longueur;
				draw_line(p2,p3,blanc);


				p2.x=p.x;
				p2.y=p.y + longueur;
				p3.x=p.x + longueur;
				p3.y=p.y;
				draw_line(p2,p3,blanc);	
			}
	}
carre_de_base();
}
int main()
{
init_graphics(900,900);

carre();

wait_escape(0);
exit(0);
}

