#include <uvsqgraphics.h>

void affiche_une_allumette(POINT p)
{

POINT p1;

	p1.x=p.x;
	p1.y=p.y+100;
	draw_line(p,p1,burlywood);

}


void efface_une_allumette(POINT p)
{

POINT p1;

	p1.x=p.x;
	p1.y=p.y+100;
	draw_line(p,p1,noir);

}

void affiche_allumette(int N)
{

POINT p;
int i;

for(i=0;i<N;i++)
{

	p.x=20+20*i;
	p.y=200;	
	affiche_une_allumette(p);

}
}	

void affiche_123()
{

POINT p,P,p1;

	p.x=20;
	p.y=20;
	P.x=p.x+50;
	P.y=p.y+50;
	draw_rectangle(p,P,blanc);

	p1.x=45;
	p1.y=45;
	draw_fill_circle(p1,2,blanc);

	p.x=80;
	p.y=20;
	P.x=p.x+50;
	P.y=p.y+50;
	draw_rectangle(p,P,blanc);

	p1.x=115;
	p1.y=35;
	draw_fill_circle(p1,2,blanc);
	
	p1.x=95;
	p1.y=55;
	draw_fill_circle(p1,2,blanc);

	p.x=140;
	p.y=20;	
	P.x=p.x+50;
	P.y=p.y+50;
	draw_rectangle(p,P,blanc);

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


int c;
c=0;

int get_valeur()
{

POINT p,P;
int x;
x=0;

p=wait_clic();
c=c+1;

if(c%2==1)
{

	P.x=120; P.y=468;
	draw_fill_circle(P,6,blue);

	P.x=120; P.y=448;
	draw_fill_circle(P,6,noir);

}

else
{

	P.x=120; P.y=448;
	draw_fill_circle(P,6,red);


	P.x=120; P.y=468;
	draw_fill_circle(P,6,noir);

}

if(p.x>20 && p.x<70 && p.y<70 && p.y>20)
{

x=1;
return x;

}

else if(p.x>80 && p.x<130 && p.y<70 && p.y>20)
{

x=2;
return x;

}

else if(p.x>140 && p.x<190 && p.y<70 && p.y>20)
{

x=3;
return x;

}

return x;

}

int a;
a=0;

void jouer_humain()
{

int i,x,g;


POINT p,p1,z,z1;

x=get_valeur();	
a=a+x;

if(x==0)
{

	jouer_humain();

}

else
{

for(i=0;i<a;i++)
{

	p.x=20+20*i;
	p.y=200;	

efface_une_allumette(p);

}

a=i;

}

	z.x=280;	z.y=355;
	z1.x=320;	z1.y=335;

	draw_fill_rectangle(z,z1,noir);

	p1.x = 285; 
	p1.y = 360;
	g=23-a;
	aff_int(g,20,p1,rouge);

if(g<=0)
{
	
	draw_fill_rectangle(z,z1,noir);	
	aff_int(0,20,p1,rouge);

}

if(a>=23 && c%2==0)
{

    char *Menu = "FIN DE PARTIE";
    p1.x = 330; 
    p1.y = 580;
    aff_pol(Menu,35,p1,white);
 
    char *win1 = "VICTOIRE J1";
    p1.x = 330; 
    p1.y = 480;
    aff_pol(win1,30,p1,jaune);
}

else if(a>=23 && c%2==1)
{   
	char *Menu = "FIN DE PARTIE";
    p1.x = 330; 
    p1.y = 580;
    aff_pol(Menu,35,p1,white); 
    
	char *win2 = "VICTOIRE J2";
    p1.x = 330; 
    p1.y = 480;
    aff_pol(win2,30,p1,jaune);
    
wait_escape(0);
exit(0);	

}

else
{
	
jouer_humain();

}
}

void jouer()
{
	
jouer_humain();

}

void interface()
{
	
POINT p1;

    char *Menu = "JEU DE NIM";
    p1.x = 30; 
    p1.y = 580;
    aff_pol(Menu,35,p1,white);

    char *Menu1 = "JEU DE NIM";
    p1.x = 29; 
    p1.y = 579;
    aff_pol(Menu1,35,p1,gris);
    
    char *J1 = "JOUEUR 1";
    p1.x = 30; 
    p1.y = 480;
    aff_pol(J1,15,p1,blue);
    
    char *J2 = "JOUEUR 2";
    p1.x = 30; 
    p1.y = 460;
    aff_pol(J2,15,p1,red);

    char *allumette = "NOMBRE D'ALLUMETTES:";
    p1.x = 25; 
    p1.y = 360;
    aff_pol(allumette,20,p1,white);
  
}

int main()
{
	
init_graphics(600,600);
interface();
affiche_allumette(23);
affiche_123();
dessine_123different(3);
jouer();
wait_escape(0);
exit(0);
	
}

