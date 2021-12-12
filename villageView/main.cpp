#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

float _run = 0.0;
float _run1 = 0.0;
float _run2 = 0.0;
float _run3 = 0.0;
float _rain = 0.0;
float _nt = 0.0;
float _ang_tri = 0.0;
float _ang_tri_r = 0.0;
float _ang_tri_y = 0.0;
float _move1=0.0;
char text[] = "SCHOOL";


bool onOff;
bool frd = false;
bool bck = false;


bool bonOff;
bool bfrd = false;
bool bbck = false;


bool rainday = false;
bool night = false;



void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(1.0,0.0,0.0);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, st[i]);

    }
}

void c(float r)
{
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
}
void BC(float r)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
}
void cl(float r)
{
    glBegin(GL_LINE_LOOP);
    glColor3ub(225, 19, 14);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();

}
void wheel(float r)
{

    glBegin(GL_POLYGON);
    glColor3ub(44, 42, 45);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
}

void cloud()
{
    glPushMatrix();
    glTranslatef(_run3, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(200, 800, 0);
    c(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180, 750, 0);
    glBegin(GL_POLYGON);
    c(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250, 800, 0);
    c(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(230, 750, 0);
    c(50);
    glPopMatrix();

//cloud 2
    glPushMatrix();
    glTranslatef(350, 100, 0);

    glPushMatrix();
    glTranslatef(200, 800, 0);
    c(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(180, 750, 0);
    c(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(250, 800, 0);
    c(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(230, 750, 0);
    c(50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(300, 800, 0);
    c(40);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(290, 760, 0);
    c(40);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();


}
void circule(float r)
{

    glBegin(GL_LINE_LOOP);
    glColor3ub(225, 19, 14);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
}

void birdOne()
{
    glPushMatrix();
    glTranslatef(_run2, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(167, 805, 0);
    BC(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(193, 808, 0);
    glBegin(GL_POLYGON);
    glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = (r-24) * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(195, 810, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();


    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(200,800);
    glVertex2i(200,813);
    glVertex2i(215,805);
    glEnd();

    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(117,810);
    glVertex2i(120,825);
    glVertex2i(148,805);
    glEnd();

    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(155,840);
    glVertex2i(185,840);
    glVertex2i(170,815);
    glEnd();



    glPopMatrix();

}
void birdTwo()
{
    glPushMatrix();
    glTranslatef(_move1, 0.0, 0.0);

    glPushMatrix();
    glTranslatef(85, 785, 0);
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=20;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(103, 788, 0);
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 0.5f, 0.0f);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = (r-24) * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(105, 790, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();


    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(110,780);
    glVertex2i(110,793);
    glVertex2i(125,795);
    glEnd();

    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(27,790);
    glVertex2i(30,805);
    glVertex2i(68,785);
    glEnd();

    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(65,820);
    glVertex2i(95,820);
    glVertex2i(80,795);
    glEnd();



    glPopMatrix();

}

void hill()
{
    glColor3ub(34, 177, 76);
    glBegin(GL_QUADS);
    glVertex2i(0,550);
    glVertex2i(0,560);
    glVertex2i(100,650);
    glVertex2i(200,550);
    glEnd();

    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(400,550);
    glVertex2i(500,650);
    glVertex2i(600,550);
    glEnd();


//hill
    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(100,550);
    glVertex2i(300,650);
    glVertex2i(500,550);
    glEnd();


    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(600,550);
    glVertex2i(700,650);
    glVertex2i(800,550);
    glEnd();


//hill
    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(800,550);
    glVertex2i(1000,650);
    glVertex2i(1000,550);
    glEnd();

    glColor3ub(34, 177, 76);
    glBegin(GL_TRIANGLES);
    glVertex2i(700,550);
    glVertex2i(900,650);
    glVertex2i(1000,550);
    glEnd();
}
void moon()
{
    glPushMatrix();
    glTranslatef(165, 890, 0);
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=50;
        float x = (r-24) * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();



}
void sun()
{
    glPushMatrix();
    glTranslatef(165, 890, 0);
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=50;
        float x = (r-24) * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();



}


void house()
{
    glPushMatrix();
    glTranslatef(-10, 70, 0.0);

    glColor3ub(182, 163, 240);
    glBegin(GL_POLYGON);
    glVertex2i(85,310);
    glVertex2i(85,350);
    glVertex2i(130,350);
    glVertex2i(130,310);
    glEnd();

    glColor3ub(240, 242, 242);
    glBegin(GL_POLYGON);
    glVertex2i(100,310);
    glVertex2i(100,338);
    glVertex2i(115,338);
    glVertex2i(115,310);
    glEnd();

    glColor3ub(55, 161, 163);
    glBegin(GL_TRIANGLES);
    glVertex2i(80,350);
    glVertex2i(107,380);
    glVertex2i(135,350);
    glEnd();

    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(80,310);
    glVertex2i(80,300);
    glVertex2i(135,300);
    glVertex2i(135,310);
    glEnd();
    glPopMatrix();


    //small home2
    glPushMatrix();
    glTranslatef(60, 70, 0.0);

    glColor3ub(182, 163, 240);
    glBegin(GL_POLYGON);
    glVertex2i(85,310);
    glVertex2i(85,350);
    glVertex2i(130,350);
    glVertex2i(130,310);
    glEnd();

    glColor3ub(240, 242, 242);
    glBegin(GL_POLYGON);
    glVertex2i(100,310);
    glVertex2i(100,338);
    glVertex2i(115,338);
    glVertex2i(115,310);
    glEnd();

    glColor3ub(55, 161, 163);
    glBegin(GL_TRIANGLES);
    glVertex2i(80,350);
    glVertex2i(107,380);
    glVertex2i(135,350);
    glEnd();

    glColor3f(0.850, 0.490, 0.756);
    glBegin(GL_QUADS);
    glVertex2i(80,310);
    glVertex2i(80,300);
    glVertex2i(135,300);
    glVertex2i(135,310);
    glEnd();
    glPopMatrix();

}
void school()
{
    glPushMatrix();
    glTranslatef(0, 50, 0);

	glColor3ub(173, 151, 9);   //BODY
    glBegin(GL_QUADS);
    glVertex2i(575, 350);
    glVertex2i(575, 425);
	glVertex2i(825, 425);
	glVertex2i(825, 350);
	glEnd();

	glColor3ub(77, 77, 219);   //ROOF
    glBegin(GL_QUADS);
    glVertex2i(550, 425);
    glVertex2i(600, 460);
	glVertex2i(800, 460);
	glVertex2i(850, 425);
	glEnd();

	glColor3ub(139, 137, 143);    //STAIR
    glBegin(GL_QUADS);
    glVertex2i(565, 340);
    glVertex2i(565, 350);
	glVertex2i(835, 350);
	glVertex2i(835, 340);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);   //DOOR
    glBegin(GL_QUADS);
    glVertex2i(690, 350);
    glVertex2i(690, 400);
	glVertex2i(710, 400);
	glVertex2i(710, 350);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);  //Left Windows
    glBegin(GL_QUADS);
    glVertex2i(595, 375);
    glVertex2i(595, 400);
	glVertex2i(615, 400);
	glVertex2i(615, 375);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(635, 375);
    glVertex2i(635, 400);
	glVertex2i(655, 400);
	glVertex2i(655, 375);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);  //Right Windows
    glBegin(GL_QUADS);
    glVertex2i(805, 375);
    glVertex2i(805, 400);
	glVertex2i(785, 400);
	glVertex2i(785, 375);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(765, 400);
	glVertex2i(745, 400);
	glVertex2i(745, 375);
	glVertex2i(765, 375);
	glEnd();

    glPopMatrix();


}
void flag()
{
    glPushMatrix();
    glTranslatef(0, 40, 0);

    glColor3ub(156, 143, 6);    //STAIR
    glBegin(GL_QUADS);
    glVertex2i(475, 340);
    glVertex2i(475, 350);
	glVertex2i(490, 350);
	glVertex2i(490, 340);
	glEnd();

    glColor3ub(106, 107, 108);    //STAND
    glBegin(GL_QUADS);
    glVertex2i(480, 350);
    glVertex2i(480, 425);
	glVertex2i(485, 425);
	glVertex2i(485, 350);
	glEnd();

	glColor3ub(9, 107, 4);    //QUAD
    glBegin(GL_QUADS);
    glVertex2i(485, 390);
    glVertex2i(485, 425);
	glVertex2i(550, 425);
	glVertex2i(550, 390);
	glEnd();

    //Circle
    glPushMatrix();
    //glScalef(0.5, 0.5, 0.5);
    glTranslatef(516, 407, 0);


    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
   glEnd();
   glPopMatrix();
   glPopMatrix();

   glPopMatrix();

}
void treesOneN()
{

    glPushMatrix();
    glTranslatef(650, 40, 0);

    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);


    glPushMatrix();



    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();





    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);





    glPushMatrix();



    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();





    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);





    glPushMatrix();



    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();



    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
    glVertex2i(203, 425);
    glVertex2i(203, 380);
    glEnd();




    glPopMatrix();




    glPopMatrix();

}
void treesTwoN()
{

    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(1400, 500, 0);



    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();



    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();




    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();



    glPopMatrix();




///tree 9



    glPushMatrix();



    glTranslatef(780, 415, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();



    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();



    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();



    glPopMatrix();


}

void treesOneS()
{







    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(250, 50, 0);






    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);







    glPushMatrix();





    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();







    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);







    glPushMatrix();





    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();







    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);







    glPushMatrix();





    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();








    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
    glVertex2i(203, 425);
    glVertex2i(203, 380);
    glEnd();



    glPopMatrix();



///circle tree 6 near tree





    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(50, 34, 0);






    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(200, 450, 0);







    glPushMatrix();





    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();







    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(210, 438, 0);







    glPushMatrix();





    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();







    glPushMatrix();
// glScalef(0.5, 0.5, 0.5);
    glTranslatef(190, 438, 0);







    glPushMatrix();





    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 0.5);
    for(int i=0; i<200; i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=15;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y );
    }
    glEnd();
    glPopMatrix();
    glPopMatrix();








    glColor3f(0.39, 0.26, 0.12);
    glBegin(GL_QUADS);
    glVertex2i(198, 380);
    glVertex2i(198, 425);
    glVertex2i(203, 425);
    glVertex2i(203, 380);
    glEnd();
    glPopMatrix();





}
void treesTwoS()
{



    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(-400, 500, 0);





    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();





    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();






    glColor3f(0.39, 0.26, 0.12);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();





    glPopMatrix();






///tree 4





    glPushMatrix();
    glScalef(0.50, 0.50, 0.25);
    glTranslatef(250, 600, 0);





    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();





    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();





    glColor3f(0.39, 0.26, 0.12);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();





    glPopMatrix();





///tree 5





    glPushMatrix();





    glTranslatef(0, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();





    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();





    glColor3f(0.39, 0.26, 0.12);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();





    glPopMatrix();






///tree 7





    glPushMatrix();





    glTranslatef(-50, 400, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();





    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();





    glColor3f(0.4, 0, 0.5);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();





    glPopMatrix();






///tree 8





    glPushMatrix();





    glTranslatef(80, 420, 0);
    glScalef(0.25, 0.25, 0.25);
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 340);
    glVertex2i(492, 440);
    glVertex2i(540, 340);
    glEnd();





    glColor3f(0, 0.8, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2i(445, 360);
    glVertex2i(492, 460);
    glVertex2i(540, 360);
    glEnd();





    glColor3f(0.39, 0.26, 0.12);
    glBegin(GL_QUADS);
    glVertex2i(497, 340);
    glVertex2i(486, 340);
    glVertex2i(486, 250);
    glVertex2i(497, 250);
    glEnd();





    glPopMatrix();








}


//___________________________________________________

void road()
{

    glColor3ub(64,64,64);
    glBegin(GL_QUADS);
    glVertex2i(0,330);
    glVertex2i(1000,330);
    glVertex2i(1000,270);
    glVertex2i(0,270);
    glEnd();

    glColor3ub(64,64,64);
	glBegin(GL_QUADS);
	glVertex2i(690,390);
	glVertex2i(710,390);
	glVertex2i(710,320);
	glVertex2i(690,320);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(690,320);
	glVertex2i(710,320);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(690,310);
	glVertex2i(710,310);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(690,290);
	glVertex2i(710,290);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(690,280);
	glVertex2i(710,280);
	glEnd();

    glLineWidth(1.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    float j;
    for(j=0; j<=1000; j+=40)
    {
        glVertex2i(10+j,300);
        glVertex2i(30+j,300);

    }
    glEnd();


}
//____________________________________________Cars___________________________________

//_________________________Red Car_________________________

void redCar()
{
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.0f, 0.0f);

        glVertex2i(250, 310);
        glVertex2i(250, 350);
        glVertex2i(260, 350);
        glVertex2i(270, 400);
        glVertex2i(315, 400);
        glVertex2i(330, 350);
        glVertex2i(340, 350);
        glVertex2i(350, 310);
        glEnd();

         glBegin(GL_QUADS);
        glColor3ub(0,0,0);

        glVertex2i(275, 395);
        glVertex2i(290, 395);
        glVertex2i(290, 345);
        glVertex2i(265, 345);

        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(0,0,0);

        glVertex2i(295, 395);
        glVertex2i(310, 395);
        glVertex2i(320, 345);
        glVertex2i(295, 345);

        glEnd();


        glPushMatrix();
        glTranslatef(280, 310, 0);

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        for(int i=0; i<200; i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

        glPopMatrix();



         glPushMatrix();
        glTranslatef(320, 310, 0);

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        for(int i=0; i<200; i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

    glPopMatrix();

}

//__________________________Yellow Car____________________

void yellowCar()
{
        glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 0.0f);

        glVertex2i(750, 290);
        glVertex2i(760, 330);
        glVertex2i(775, 330);
        glVertex2i(785, 380);
        glVertex2i(785, 380);
        glVertex2i(830, 380);
        glVertex2i(840, 330);
        glVertex2i(850, 330);
        glVertex2i(850, 290);

        glEnd();


         glBegin(GL_QUADS);
        glColor3ub(0,0,0);

        glVertex2i(790, 375);
        glVertex2i(804, 375);
        glVertex2i(804, 325);
        glVertex2i(775, 325);

        glEnd();

         glBegin(GL_QUADS);
        glColor3ub(0,0,0);

        glVertex2i(808, 375);
        glVertex2i(825, 375);
        glVertex2i(833, 325);
        glVertex2i(808, 325);

        glEnd();




        glPushMatrix();
        glTranslatef(780, 290, 0);

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        for(int i=0; i<200; i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

        glPopMatrix();



         glPushMatrix();
        glTranslatef(820, 290, 0);

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        for(int i=0; i<200; i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
        glEnd();

        glPopMatrix();

}

//_____________________________________________________

void railLine()
{
    glColor3ub(150, 150, 144);
	glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(0,205);
    glVertex2i(1000,205);
    glVertex2i(1000,180);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,202);
    glVertex2i(1000,202);
    glVertex2i(1000,205);
    glVertex2i(0,205);

    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(0,180);
    glVertex2i(1000,180);
    glVertex2i(1000,184);
    glVertex2i(0,184);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    float j;
    for(j=0;j<=1000;j+=20) //rail line
   {
        glVertex2i(10+j,180);
        glVertex2i(15+j,205);

    }
    glEnd();

}
void railBody()
{
    glPushMatrix();
    glTranslatef(_ang_tri, 0.0, 0.0);

    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(75, 0, 0);

    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


   glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();



    glPushMatrix();
    glTranslatef(-75, 0, 0);

    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


    glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(150, 0, 0);

    glColor3f(0.192, 0.576, 0.705);
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(170, 200);
	glVertex2i(170, 250);
	glVertex2i(100, 250);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(110, 225);
    glVertex2i(120, 225);
	glVertex2i(120, 240);
	glVertex2i(110, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(130, 225);
    glVertex2i(140, 225);
	glVertex2i(140, 240);
	glVertex2i(130, 240);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(150, 225);
    glVertex2i(160, 225);
	glVertex2i(160, 240);
	glVertex2i(150, 240);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(100, 210);
    glVertex2i(170, 210);
	glVertex2i(170, 215);
	glVertex2i(100, 215);
	glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(170, 200);
    glVertex2i(176, 210);
	glVertex2i(176, 260);
	glVertex2i(170, 250);
	glEnd();


	glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(101, 250);
    glVertex2i(170, 250);
	glVertex2i(176, 260);
	glVertex2i(105, 260);
	glEnd();

	glPushMatrix();
    glTranslatef(115, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
   glPopMatrix();


   glPushMatrix();
    glTranslatef(155, 192, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(109, 109, 115);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(322, 245);
    glVertex2i(330, 245);
	glVertex2i(330, 232);
	glVertex2i(322, 232);
	glEnd();

	glColor3f(0.325, 0.101, 0.619);
	glBegin(GL_QUADS);
    glVertex2i(310, 253);
    glVertex2i(300, 253);
	glVertex2i(300, 258);
	glVertex2i(310, 258);
	glEnd();

	glPushMatrix();
    glTranslatef(303, 267, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(293, 270, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(283, 272, 0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.709, 0.701, 0.717);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPopMatrix();

}
//_____________________________________________River_____________________________

void river()
{

    glColor3ub(152, 222, 245);
    glBegin(GL_QUADS);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, -200);
    glVertex2i(0, -200);
    glEnd();
}
//___________________________________________Boats________________________________

void boatOne()
{

    glBegin(GL_QUADS);
    glColor3ub(0,0,139);
    glVertex2i(100, 70);
    glVertex2i(150, 70);
    glVertex2i(150, 35);
    glVertex2i(100, 35);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,0,127);
    glVertex2i(75, 35);
    glVertex2i(175, 35);
    glVertex2i(150, -5);
    glVertex2i(100, -5);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(180, 70);
    glVertex2i(180, 130);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(150, 35);
    glVertex2i(180, 100);

    glEnd();

}

void boatTwo()
{

    glBegin(GL_QUADS);
    glColor3ub(0,128,128);
    glVertex2i(250, 70);
    glVertex2i(300, 70);
    glVertex2i(300, 35);
    glVertex2i(250, 35);
    glEnd();


    glBegin(GL_QUADS);
     glColor3ub(184,134,11);
    glVertex2i(225, 35);
    glVertex2i(325, 35);
    glVertex2i(300, -5);
    glVertex2i(250, -5);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(330, 70);
    glVertex2i(330, 130);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(300, 35);
    glVertex2i(330, 100);

    glEnd();
}

void boatThree()
{

    glBegin(GL_QUADS);
    glColor3ub(255,20,147);
    glVertex2i(750, 20);
    glVertex2i(800, 20);
    glVertex2i(800, -25);
    glVertex2i(750, -25);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(128,0,128);
    glVertex2i(725, -25);
    glVertex2i(825, -25);
    glVertex2i(800, -65);
    glVertex2i(750, -65);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(800, 20);
    glVertex2i(820, -70);
    glEnd();
}

void boatFour()
{
    glBegin(GL_QUADS);
    glColor3ub	(0,0,255);
    glVertex2i(450, -65);
    glVertex2i(500, -65);
    glVertex2i(500, -105);
    glVertex2i(450, -105);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,0,0);
    glVertex2i(425, -105);
    glVertex2i(525, -105);
    glVertex2i(500, -145);
    glVertex2i(450, -145);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(450, -65);
    glVertex2i(430, -160);
    glEnd();
}


//____________________________________________

void redCarForward(int value)
{

    if(frd)
    {

        _ang_tri_r += 0.1f;

        if (_ang_tri_r > 1000)
        {
            _ang_tri_r -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, redCarForward, 0);
    }
}

void redCarBackward(int value)
{
    if(bck)
    {

        _ang_tri_r -= 0.1f;

        if (_ang_tri_r < -350)
        {
            _ang_tri_r = 1100;
        }
        glutPostRedisplay();
        glutTimerFunc(25, redCarBackward, 0);
    }
}


//___________________________________________________


void yellowCarForward(int value)
{

    if(frd)
    {

        _ang_tri_y += 0.1f;

        if (_ang_tri_y > 200)
        {
            _ang_tri_y -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, yellowCarForward, 0);
    }
}

void yellowCarBackward(int value)
{
    if(bck)
    {

        _ang_tri_y -= 0.1f;

        if (_ang_tri_y < -1350)
        {
            _ang_tri_y = 200;
        }
        glutPostRedisplay();
        glutTimerFunc(25, yellowCarBackward, 0);
    }
}

//_____________________________________________

void init(){

	glClearColor(0.0,0.5,0.8,1.0);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,-200.0,1000.0);

}



void display(){
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
	glColor3ub(0.0, 128, 0.0);
	glVertex2i(0,550);
	glVertex2i(1000,550);
	glVertex2i(1000,0);
	glVertex2i(0,0);
	glEnd();


	school();

    treesTwoN();
    treesOneN();

    treesOneS();
    treesTwoS();


//hill

    hill();
    //sun
    sun();

//birds
    birdOne();
    birdTwo();
///Cloud

    cloud();
//end of cloud



//road

    road();




//rail line
    railLine();




    //small home
    house();


///Making of Rail Body

    railBody();

///End of Making of Rail Body


///flag
    flag();


//________________________________________________



 //_________River_______
    river();
    //_________Road________
    road();
    //_________Boats_______
    boatOne();
    boatTwo();

    glPushMatrix();
    glTranslatef(-_run, 0.0f, 0.0f);
    boatThree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_run, 0.0f, 0.0f);
    boatFour();
    glPopMatrix();

    //_________Cars________


    glPushMatrix();
    glTranslatef(_ang_tri_r, 0.0f, 0.0f);
    redCar();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_ang_tri_y, 0.0f, 0.0f);
    yellowCar();
    glPopMatrix();

//______________________________________________________________



//text school
    glColor3f(1.0, 1.0, 1.0);    //QUAD
    glBegin(GL_QUADS);
    glVertex2i(675, 495);
    glVertex2i(725, 495);
	glVertex2i(725, 475);
	glVertex2i(675, 475);
	glEnd();


    glPushMatrix();
    glTranslatef(680, 478, 0);
    Sprint(1.0,0,text);
    glPopMatrix();
// end of text


    glFlush();
	glutSwapBuffers();
}



void railForward(int value){

if(frd){

    _ang_tri += 2.2f;

    if (_ang_tri > 1000) {
		_ang_tri -= 1400;
	}

	glutPostRedisplay();
	glutTimerFunc(25, railForward, 0);
}
}



void birdForward(int value)
{

    if(bfrd)
    {

        _move1 += 2.2f;

        if (_move1 > 1000)
        {
            _move1 -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, birdForward, 0);
    }
}

void birdBackward(int value)
{
    if(bbck)
    {

        _move1 -= 2.2f;

        if (_move1 < -350)
        {
            _move1 = 1100;
        }
        glutPostRedisplay();
        glutTimerFunc(25, birdBackward, 0);
    }
}


void railBackward(int value){
if(bck){

    _ang_tri -= 2.2f;

     if (_ang_tri < -350) {
		_ang_tri = 1100;
	}
	glutPostRedisplay();
	glutTimerFunc(25, railBackward, 0);
}
}


void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=200;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+20,y+20);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}

void Night(int value){

if(night){


    moon();
    glClearColor(0.0,0.0,0.0,0.0);
	glutPostRedisplay();
    glutTimerFunc(5, Night, 0);
    glFlush();

}
}

void myKeyboard(unsigned char key, int x, int y){
	switch (key)
	{
	    case 'a':
        frd = false;
        bck = true;
        redCarBackward(_ang_tri_r);
        break;

    case 'b':
        frd = true;
        bck = false;
        redCarForward(_ang_tri_r);
        break;

    case 'c':
        frd = false;
        bck = true;
        yellowCarBackward(_ang_tri_y);
        break;

    case 'd':
        frd = true;
        bck = false;
        yellowCarForward(_ang_tri_y);
        break;

    case 'e':
        frd = true;
        bck = true;
        redCarForward(_ang_tri_r);
        yellowCarBackward(_ang_tri_y);
        break;

    case 's':
        frd = false;
        bck = false;
        break;





	case 'f':
        frd = false;
	    bck = true;
	    railBackward(_ang_tri);
	break;

	case 'g':
	     frd = true;
	     bck = false;
         railForward(_ang_tri);
	    break;


    case 'h':
        rainday = true;
        Rain(_rain);
        sndPlaySound("River.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
        break;

    case 'i':
        rainday = false;
		sndPlaySound(NULL,SND_ASYNC);
        break;

    case 'j':
        bfrd = false;
        bbck = true;
        birdBackward(_move1);
        break;

    case 'k':
        bfrd = true;
        bbck = false;
        birdForward(_move1);
        break;

    case 'l':
        bfrd = false;
        bbck = false;
        break;


    case 'm':
        night = true;
        Night(_nt);
        break;

    case 'n':
        night = false;
        glClearColor(0.0,0.5,0.8,1.0);
        break;

    case 27:     // ESC key
        exit(0);
        break;

	default:
	break;
	}
}


//_______________________________________________

void update(int value) {

	_run += 1.0f;
	if (_run > 1000)
    {
        _run -= 1700;
    }

    _run1 += 1.0f;
	if (_run1 > 1000)
    {
        _run1 -= 1300;
    }

    _run2 += 2.0f;
    if (_run2 > 1000)
    {
        _run2 -= 1300;
    }
    _run3 += 0.6f;
    if (_run3 > 1000)
    {
        _run3 -= 1700;
    }
    if(bonOff)
    {
        _move1 += 2.5f;
        if (_move1 > 1000)
        {
            _move1 = 1300;
        }
    }

    if(onOff){
	_ang_tri += 2.5f;
	if (_ang_tri > 1000){
		_ang_tri = 1300;
	}
	 }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}

//_______________________________________________________

int main(int argc,char **argv)
{
    cout << endl << "*********** Natural View Of A Village ********************" << endl << endl;

    cout << "Press A : To Backward the Red Car" << endl << endl;
    cout << "Press B : To Forward the Red Car" << endl << endl;
    cout << "Press C : To Backward the Yellow Car" << endl << endl;
    cout << "Press D : To Forward the Yellow Car " << endl << endl;


    cout << "Press E : For Backward and Forward both for Red and Yellow Car" << endl << endl;

    cout << "Press F : To Backward the Train" << endl << endl;
    cout << "Press G : To Forward the Train" << endl << endl;
    cout << "Press H :  For Rain" << endl << endl;

    cout << "Press I : For Sunny " << endl << endl;
    cout << "Press J : For Bird Backward" << endl << endl;

     cout << "Press K : For Bird Forward " << endl << endl;
    cout <<  "Press L : To Stop Bird" << endl << endl;

     cout << "Press M : For Night " << endl << endl;
    cout <<  "Press N : For Day" << endl << endl;

     cout << "Press S : To stop the Car and Train " << endl << endl;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("Natural View Of A Village");
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboard);
	glutTimerFunc(25, update, 0);
	init();
	glutMainLoop();
	return 0;
}
