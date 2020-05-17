#include <uvsqgraphics.h>
#include <math.h>
void ecran()
{

init_graphics(900,600);

POINT p1,p2;

p1.x=0; p1.y=200;
p2.x=900; p2.y=200;

draw_line(p1,p2,blanc);

}

void afficher_cadran()
{

POINT p1,p2;

p1.x=453; p1.y=93;
draw_circle(p1,90,white);

draw_fill_circle(p1,3,white);

p1.x=450; p1.y=100;
for(int i=1;i<=12;i++)
{

p2.x = p1.x + cosf((-3*M_PI/2)-i*(M_PI/6))*80; p2.y = p1.y + sinf((-3*M_PI/2)-i*(M_PI/6))*80;
aff_int(i,10,p2,blanc);

}
}

void afficher_aiguille(int h,int m,int s)
{
POINT p1,p2;

//heure


p1.x=450; p1.y=93;
p2.x = p1.x + cosf((-3*M_PI/2)-h*(M_PI/6))*50;
p2.y= p1.y + sinf((-3*M_PI/2)-h*(M_PI/6))*50;

draw_line(p1,p2,blanc);

p2.x = p1.x + cosf((-3*M_PI/2)-(h-1)*(M_PI/6))*50;
p2.y= p1.y + sinf((-3*M_PI/2)-(h-1)*(M_PI/6))*50;

draw_line(p1,p2,noir);

//minute


p1.x=450; p1.y=93;
p2.x = p1.x + cosf((-3*M_PI/2)-(2*M_PI/60)*m)*60;
p2.y= p1.y + sinf((-3*M_PI/2)-(2*M_PI/60)*m)*60;

draw_line(p1,p2,blanc);

p2.x = p1.x + cosf((-3*M_PI/2)-(2*M_PI/60)*(m-1))*60;
p2.y= p1.y + sinf((-3*M_PI/2)-(2*M_PI/60)*(m-1))*60;

draw_line(p1,p2,noir);

//seconde


p1.x=450; p1.y=93;
p2.x = p1.x + cosf((-3*M_PI/2)-(2*M_PI/60)*s)*80;
p2.y= p1.y + sinf((-3*M_PI/2)-(2*M_PI/60)*s)*80;

draw_line(p1,p2,blanc);

p2.x = p1.x + cosf((-3*M_PI/2)-(2*M_PI/60)*(s-1))*80;
p2.y= p1.y + sinf((-3*M_PI/2)-(2*M_PI/60)*(s-1))*80;

draw_line(p1,p2,noir);

}

void afficher1()
{
draw_line(T[0],T[1],noir);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],noir);
draw_line(T[6],T[7],noir);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],noir);
draw_line(T[12],T[13],noir);
}

void afficher2()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],noir);
draw_line(T[8],T[9],noir);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],red);
}

void afficher3()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],noir);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],noir);
}

void afficher4()
{
draw_line(T[0],T[1],noir);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],red);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],noir);
draw_line(T[12],T[13],noir);
}

void afficher5()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],noir);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],red);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],noir);
}

void afficher6()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],noir);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],red);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],red);
}

void afficher7()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],noir);
draw_line(T[6],T[7],noir);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],noir);
draw_line(T[12],T[13],noir);
}

void afficher8()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],red);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],red);
}

void afficher9()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],red);
draw_line(T[6],T[7],red);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],noir);
}

void afficher0()
{
draw_line(T[0],T[1],red);
draw_line(T[2],T[3],red);
draw_line(T[4],T[5],noir);
draw_line(T[6],T[7],red);
draw_line(T[8],T[9],red);
draw_line(T[10],T[11],red);
draw_line(T[12],T[13],red);
}

void afficher_dizaine_heure(int h)
{

POINT T[14];
	T[0].x=200;T[0].y=460;
	T[1].x=240;T[1].y=460;
	T[2].x=250;T[2].y=450;
	T[3].x=250;T[3].y=410;
	T[4].x=240;T[4].y=400;
	T[5].x=200;T[5].y=400;
	T[6].x=190;T[6].y=410;
	T[7].x=190;T[7].y=450;
	T[8].x=250;T[8].y=390;
	T[9].x=250;T[9].y=350;
	T[10].x=240;T[10].y=340;
	T[11].x=200;T[11].y=340;
	T[12].x=190;T[12].y=350;
	T[13].x=190;T[13].y=390;

if(h<10)
{
afficher0();
}

else if(h>=10 && h<20)
{
afficher1();
}

else
{
afficher2();
}

}

void afficher_unite_heure(int h)
{
	
POINT T[14];
	T[0].x=200+70;T[0].y=460;
	T[1].x=240+70;T[1].y=460;
	T[2].x=250+70;T[2].y=450;
	T[3].x=250+70;T[3].y=410;
	T[4].x=240+70;T[4].y=400;
	T[5].x=200+70;T[5].y=400;
	T[6].x=190+70;T[6].y=410;
	T[7].x=190+70;T[7].y=450;
	T[8].x=250+70;T[8].y=390;
	T[9].x=250+70;T[9].y=350;
	T[10].x=240+70;T[10].y=340;
	T[11].x=200+70;T[11].y=340;
	T[12].x=190+70;T[12].y=350;
	T[13].x=190+70;T[13].y=390;


if(h==0 || h==10 || h==20)
{
afficher0();
}

else if(h==1 || h==11 || h==21)
{
afficher1();
}

else if(h==2 || h==12 || h==22)
{
afficher2();
}

else if(h==3 || h==13 || h==23)
{
afficher3();
}

else if(h==4 || h==14 || h==24)
{
afficher4();
}

else if(h==5 || h==15)
{
afficher5();
}

else if(h==6 || h==16)
{
afficher6();
}

else if(h==7 || h==17)
{
afficher7();
}

else if(h==9 || h==19)
{
afficher9();
}

else if(h==8 || h==18)
{
afficher8();
}
}

void afficher_dizaine_minute(int m)
{
POINT T[14];
	T[0].x=200+190;T[0].y=460;
	T[1].x=240+190;T[1].y=460;
	T[2].x=250+190;T[2].y=450;
	T[3].x=250+190;T[3].y=410;
	T[4].x=240+190;T[4].y=400;
	T[5].x=200+190;T[5].y=400;
	T[6].x=190+190;T[6].y=410;
	T[7].x=190+190;T[7].y=450;
	T[8].x=250+190;T[8].y=390;
	T[9].x=250+190;T[9].y=350;
	T[10].x=240+190;T[10].y=340;
	T[11].x=200+190;T[11].y=340;
	T[12].x=190+190;T[12].y=350;
	T[13].x=190+190;T[13].y=390;

if(m<10)
{
afficher0();
}

else if(m>=10 && m<20)
{
afficher1();
}

else if(m>=20 && m<30)
{
afficher2();
}

else if(m>=30 && m<40)
{
afficher3();
}

else if(m>=40 && m<50)
{
afficher4();
}

else if(m>=50 && m<=59)
{
afficher5();
}

}

void afficher_unite_minute(int m)
{

POINT T[14];
	T[0].x=200+260;T[0].y=460;
	T[1].x=240+260;T[1].y=460;
	T[2].x=250+260;T[2].y=450;
	T[3].x=250+260;T[3].y=410;
	T[4].x=240+260;T[4].y=400;
	T[5].x=200+260;T[5].y=400;
	T[6].x=190+260;T[6].y=410;
	T[7].x=190+260;T[7].y=450;
	T[8].x=250+260;T[8].y=390;
	T[9].x=250+260;T[9].y=350;
	T[10].x=240+260;T[10].y=340;
	T[11].x=200+260;T[11].y=340;
	T[12].x=190+260;T[12].y=350;
	T[13].x=190+260;T[13].y=390;


if(m==0 || m==10 || m==20 || m==30 || m==40 || m==50)
{
afficher0();
}

else if(m==1 || m==11 || m==21 || m==31 || m==41 || m==51)
{
afficher1();
}

else if(m==2 || m==12 || m==22 || m==32 || m==42 || m==52)
{
afficher2();
}

else if(m==3 || m==13 || m==23 || m==33 || m==43 || m==53)
{
afficher3();
}

else if(m==4 || m==14 || m==24 || m==34 || m==44 || m==54)
{
afficher4();
}

else if(m==5 || m==15 || m==25 || m==35 || m==45 || m==55)
{
afficher5();
}

else if(m==6 || m==16 || m==26 || m==36 || m==46 || m==56)
{
afficher6();
}

else if(m==7 || m==17 || m==27 || m==37 || m==47 || m==57)
{
afficher7();
}

else if(m==8 || m==18 || m==28 || m==38 || m==48 || m==58)
{
afficher8();
}

else if(m==9 || m==19 || m==29 || m==39 || m==49 || m==59)
{
afficher9();
}

}


void afficher_dizaine_seconde(int s)
{


POINT T[14];
	T[0].x=200+380;T[0].y=460;
	T[1].x=240+380;T[1].y=460;
	T[2].x=250+380;T[2].y=450;
	T[3].x=250+380;T[3].y=410;
	T[4].x=240+380;T[4].y=400;
	T[5].x=200+380;T[5].y=400;
	T[6].x=190+380;T[6].y=410;
	T[7].x=190+380;T[7].y=450;
	T[8].x=250+380;T[8].y=390;
	T[9].x=250+380;T[9].y=350;
	T[10].x=240+380;T[10].y=340;
	T[11].x=200+380;T[11].y=340;
	T[12].x=190+380;T[12].y=350;
	T[13].x=190+380;T[13].y=390;

if(s<10)
{
afficher0();
}

else if(s>=10 && s<20)
{
afficher1();
}

else if(s>=20 && s<30)
{
afficher2();

}

else if(s>=30 && s<40)
{
afficher3();
}

else if(s>=40 && s<50)
{
afficher4();
}

else if(s>=50 && s<=59)
{
afficher5();
}

}

void afficher_unite_seconde(int s)
{
	
POINT T[14];
	T[0].x=630+20;T[0].y=460;
	T[1].x=670+20;T[1].y=460;
	T[2].x=680+20;T[2].y=450;
	T[3].x=680+20;T[3].y=410;
	T[4].x=670+20;T[4].y=400;
	T[5].x=630+20;T[5].y=400;
	T[6].x=620+20;T[6].y=410;
	T[7].x=620+20;T[7].y=450;
	T[8].x=680+20;T[8].y=390;
	T[9].x=680+20;T[9].y=350;
	T[10].x=670+20;T[10].y=340;
	T[11].x=630+20;T[11].y=340;
	T[12].x=620+20;T[12].y=350;
	T[13].x=620+20;T[13].y=390;

if(s==0 || s==10 || s==20 || s==30 || s==40 || s==50)
{
afficher0();
}

else if(s==1 || s==11 || s==21 || s==31 || s==41 || s==51)
{
afficher1();
}

else if(s==2 || s==12 || s==22 || s==32 || s==42 || s==52)
{
afficher2();
}

else if(s==3 || s==13 || s==23 || s==33 || s==43 || s==53)
{
afficher3();
}

else if(s==4 || s==14 || s==24 || s==34 || s==44 || s==54)
{
afficher4();
}

else if(s==5 || s==15 || s==25 || s==35 || s==45 || s==55)
{
afficher5();
}

else if(s==6 || s==16 || s==26 || s==36 || s==46 || s==56)
{
afficher6();
}

else if(s==7 || s==17 || s==27 || s==37 || s==47 || s==57)
{
afficher7();
}

else if(s==8 || s==18 || s==28 || s==38 || s==48 || s==58)
{
afficher8();
}

else if(s==9 || s==19 || s==29 || s==39 || s==49 || s==59)
{
afficher9();
}
	
}

void afficher_bouton()
{
POINT p1,p2;

p1.x=50; p1.y=400;
p2.x=100; p2.y=350;
draw_fill_rectangle(p1,p2,red);
}

int main()
{
ecran();
afficher_cadran();
afficher_bouton();
int h,m,s;
while(1)
{
h=heure(); m=minute(); s=seconde();

afficher_dizaine_seconde(s);
afficher_dizaine_heure(h);
afficher_unite_heure(h);
afficher_dizaine_minute(m);
afficher_unite_minute(m);
afficher_unite_seconde(s);
afficher_aiguille(h,m,s);
}

wait_escape(0);
exit(0);	
}
