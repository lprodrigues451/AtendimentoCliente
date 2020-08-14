#include<stdio.h>
#include<glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>
#define SPEED 40.0      

float i=0.0;    
float m=0.0;
float m2 = 0.0;    
float n=0.0;    
float o=0.0;   
float c=0.0;   

int light=1;      
int dia=1;        
int plane=0;    
int comet=0;    
const double PI=3.141592654;
float angulo = 0, a=0 ; 


void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void draw_object()
{
int l;
if(dia==1)
{
	
//céu
glColor3f(0.00392, 0.4706, 0.90980 );
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();

//montanha
glColor3f(0.25,0.18,0.16);
glBegin(GL_TRIANGLES);
glVertex2f(600,450);
glVertex2f(650,500);
glVertex2f(700,450);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(700,520);
glVertex2f(800,400);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(750,515);
glVertex2f(850,350);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(800,510);
glVertex2f(900,400);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(800,505);
glVertex2f(950,390);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(880,520);
glVertex2f(1000,370);
glEnd();

//sol
	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(38,650,l);
}


//selva
glColor3f(0.0,0.88,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

//Rio
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(250,350);
glVertex2f(250,375);
glVertex2f(500,400);
glVertex2f(750,410);
glVertex2f(1100,420);
glVertex2f(1100,420);
glVertex2f(2250,410);
glVertex2f(0,405);
glVertex2f(0,390);
glVertex2f(0,375);
glVertex2f(0,350);
glVertex2f(0,320);
glVertex2f(0,300);
glVertex2f(0,295);
glVertex2f(0,290);
glVertex2f(0,285);
glVertex2f(0,280);
glVertex2f(0,280);
glVertex2f(0,280);
glVertex2f(0,290);
glVertex2f(0,300);
glVertex2f(0,310);
glEnd();


//casa
glBegin(GL_QUADS);
glColor3f(0.44314 , 0.38431 , 0.37255); 
glVertex2f(900,250);
glVertex2f(900,380);
glVertex2f(1050,380);
glVertex2f(1050,250);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.46 , 0.13 , 0.07); // Telhado
glVertex2f(900,380);
glVertex2f(975,430);
glVertex2f(1050,380);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.31 , 0.18 , 0.09); // porta
glVertex2f(915,250);
glVertex2f(915,300);
glVertex2f(950,300);
glVertex2f(950,250);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.24314 , 0.28431 , 0.27255 ); // janela
glVertex2f(1000,300);
glVertex2f(1000,340);
glVertex2f(1040,340);
glVertex2f(1040,300);
glEnd();


//luz do poste
glColor3f(0.0,0.88,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(143,315);
glVertex2f(90,160);
glVertex2f(200,160);
glEnable(GL_BLEND);
glEnd();

//poste 1
glColor3f(0.0,0.2,0.5);
glBegin(GL_POLYGON);
glVertex2f(140,155);
glVertex2f(140,295); // Altura
glVertex2f(150,295); // Altura
glVertex2f(150,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(130,295);
glVertex2f(130,330); // Altura
glVertex2f(160,330); // Altura
glVertex2f(160,295);
glEnd();

//poste 2
glColor3f(0.0,0.2,0.5);
glBegin(GL_POLYGON);
glVertex2f(740,155);
glVertex2f(740,295); // Altura
glVertex2f(750,295); // Altura
glVertex2f(750,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(730,295);
glVertex2f(730,330); // Altura
glVertex2f(760,330); // Altura
glVertex2f(760,295);
glEnd();

//Nuvem 1

	for(l=0;l<=8;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(78+m2,650,l);

	}


	for(l=0;l<=13;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(90+m2,650,l);
		draw_circle(95+m2,650,l);
	}

	for(l=0;l<=8;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(110+m2,650,l);
	}

//Nuvem 2

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(0+m,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(40+m,625,l);
		draw_circle(65+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(105+m,625,l);
	}
//nuvem 3

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(260+m,590,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(300+m,590,l);
		draw_circle(325+m,590,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(365+m,590,l);
	}
	
	


}


else
{
	

//céu
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,450);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,450);
glEnd();


//estrela 1
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(385,558);
glVertex2f(380,550);
glVertex2f(390,550);
glVertex2f(385,545);
glVertex2f(380,555);
glVertex2f(390,555);
glEnd();

//estrela 2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(555,635);
glVertex2f(550,625);
glVertex2f(560,625);
glVertex2f(555,620);
glVertex2f(550,630);
glVertex2f(560,630);
glEnd();

//estrela 3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(935,645);
glVertex2f(930,635);
glVertex2f(940,635);
glVertex2f(935,630);
glVertex2f(930,640);
glVertex2f(940,640);
glEnd();

//estrela 4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,630);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,615);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();

//estrela 5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,630);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,615);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

//Lua 
int l;
	for(l=0;l<=35;l++)
{
		glColor3f(1.0,1.0,1.0);
		draw_circle(38,650,l);
}

//montanha
glColor3f(0.25,0.18,0.16);
glBegin(GL_TRIANGLES);
glVertex2f(600,450);
glVertex2f(650,500);
glVertex2f(700,450);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(700,520);
glVertex2f(800,400);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(750,515);
glVertex2f(850,350);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(800,510);
glVertex2f(900,400);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(800,505);
glVertex2f(950,390);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(600,430);
glVertex2f(880,520);
glVertex2f(1000,370);
glEnd();

//Selva
glColor3f(0.0,0.58,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,450);
glVertex2f(1100,450);
glVertex2f(1100,160);
glEnd();

//Rio
glColor3f(0.0,0.59,1.0);
glBegin(GL_POLYGON);
glVertex2f(250,350);
glVertex2f(250,375);
glVertex2f(500,400);
glVertex2f(750,410);
glVertex2f(1100,420);
glVertex2f(1100,420);
glVertex2f(2250,410);
glVertex2f(0,405);
glVertex2f(0,390);
glVertex2f(0,375);
glVertex2f(0,350);
glVertex2f(0,320);
glVertex2f(0,300);
glVertex2f(0,295);
glVertex2f(0,290);
glVertex2f(0,285);
glVertex2f(0,280);
glVertex2f(0,280);
glVertex2f(0,280);
glVertex2f(0,290);
glVertex2f(0,300);
glVertex2f(0,310);
glEnd();

//ponte
glBegin(GL_QUADS);
glColor3f(0.44314 , 0.38431 , 0.37255); 

//casa
glBegin(GL_QUADS);
glColor3f(0.44314 , 0.38431 , 0.37255); 
glVertex2f(900,250);
glVertex2f(900,380);
glVertex2f(1050,380);
glVertex2f(1050,250);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.46 , 0.13 , 0.07); // Telhado
glVertex2f(900,380);
glVertex2f(975,430);
glVertex2f(1050,380);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.31 , 0.18 , 0.09); // porta
glVertex2f(915,250);
glVertex2f(915,300);
glVertex2f(950,300);
glVertex2f(950,250);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.83529,  0.80392,  0.55686 ); // janela
glVertex2f(1000,300);
glVertex2f(1000,340);
glVertex2f(1040,340);
glVertex2f(1040,300);
glEnd();


//luz do poste 1
glColor4f(0.0,0.88,0.0,0.5);
glBegin(GL_TRIANGLES);
glVertex2f(144,315);
glVertex2f(70,160);
glVertex2f(230,160);
glEnable(GL_BLEND);
glEnd();

//poste 1
glColor3f(0.0,0.2,0.5);
glBegin(GL_POLYGON);
glVertex2f(140,155);
glVertex2f(140,295); // Altura
glVertex2f(150,295); // Altura
glVertex2f(150,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(130,295);
glVertex2f(130,330); // Altura
glVertex2f(160,330); // Altura
glVertex2f(160,295);
glEnd();

//luz do poste 2
glColor3f(0.0,0.88,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(744,315);
glVertex2f(670,160);
glVertex2f(830,160);
glEnd();

//poste 2
glColor3f(0.0,0.2,0.5);
glBegin(GL_POLYGON);
glVertex2f(740,155);
glVertex2f(740,295); // Altura
glVertex2f(750,295); // Altura
glVertex2f(750,155);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(730,295);
glVertex2f(730,330); // Altura
glVertex2f(760,330); // Altura
glVertex2f(760,295);
glEnd();


}

//rua de casa 
glColor3f(0.71,0.50,0.22);
glBegin(GL_POLYGON);
glVertex2f(915,250);
glVertex2f(850,90);
glVertex2f(930,90);
glVertex2f(950,250);

glEnd();

//rua
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,0);
glEnd();

//faixa de asfalto 
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,80); //cima
glVertex2f(0,90); //baixo
glVertex2f(1100,90);
glVertex2f(1100,80);
glEnd();


//arvore1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(250,280);
glVertex2f(250,350); // Altura
glVertex2f(270,350); // Altura
glVertex2f(270,280);
glEnd();



	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(250,340,l);
		draw_circle(270,340,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(260,365,l);
	}
	
//arvore2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(350,280);
glVertex2f(350,350); // Altura
glVertex2f(370,350); // Altura
glVertex2f(370,280);
glEnd();



	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(350,340,l);
		draw_circle(370,340,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(360,365,l);
	}
	
//arvore3
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(430,280);
glVertex2f(430,350); // Altura
glVertex2f(450,350); // Altura
glVertex2f(450,280);
glEnd();



	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(430,340,l);
		draw_circle(450,340,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(440,365,l);
	}


//carro 2
glColor3f(0.0,1.0,1.2);
glBegin(GL_POLYGON);
glVertex2f(1050-i,125);
glVertex2f(900-i,125);
glVertex2f(895-i,190);
glVertex2f(1050-i,190);
glEnd();

glColor3f(0.0,1.0,1.2);
glBegin(GL_POLYGON);
glVertex2f(1050-i,125);
glVertex2f(950-i,125);
glVertex2f(950-i,250);
glVertex2f(1050-i,250);
glEnd();



for(l=0;l<20;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(1030-i,125,l);
	draw_circle(930-i,125,l);
   }



//carro 1 
glColor3f(0.0,1.0,0.2);
glBegin(GL_POLYGON);
glVertex2f(45+i,50);
glVertex2f(45+i,125);
glVertex2f(65+i,200);
glVertex2f(165+i,200);
glVertex2f(190+i,125);
glVertex2f(240+i,115);
glVertex2f(230+i,50);
glEnd();



for(l=0;l<20;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(75+i,50,l);
	draw_circle(175+i,50,l);
   }

glFlush();
}



void idle()

{


if(light==0)
 {
	 i=i;
	 ++m;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=SPEED/25;
     m+=0.200;
     m2 = m/10;
	n-=2;
	 o+=0.2;
	c+=2;
	
	if(i>1630)
	 i=0.0;
if(m>50000)
	 m=0.0;
 }

glutPostRedisplay();

}


void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
exit(0);
}


void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {

case 'd':
	case 'D':
		dia=1;
		break;

	case 'n':
case 'N':
		dia=0;
		break;

    };

}

void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		comet=1;
		 c=0.0;
	 }
	break;
	}
}





void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
 glEnable(GL_BLEND);
 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glFlush();
}


int main(int argc,char** argv)
{
int c_menu;

	printf("Pressionar a tecla d para fica de dia \n");
	printf("Pressionar a tecla n para fica de noite \n");


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000.0,600.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("PROJETO FINAL");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	
	myinit();

	c_menu=glutCreateMenu(main_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
	
	
}

