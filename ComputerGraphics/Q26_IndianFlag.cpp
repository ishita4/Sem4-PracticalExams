#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
void drawFlag();
void bezier();

/*
TEST INPUT
200 200
300 100
400 100
500 200
*/

int fact(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}

int combination(int n, int r)
{
    return fact(n)/(fact(n-r)*fact(r));
}

void bezier(int X[],int Y[],int n)
{
    float u;
    float x,y;
   // drawFlag();

    for(u=0.001;u<1;u=u+0.001)
    {
        x=0;
        y=0;
        for(int k=0;k<n;k++)
        {
            x= x + (combination(n-1,k)*X[k]*pow(u,k)*pow(1-u,n-k-1));
            y= y + (combination(n-1,k)*Y[k]*pow(u,k)*pow(1-u,n-k-1));
        }
        putpixel(int(x),int(y),WHITE);
    }


}

void drawFlag()
{
    int X1[4],Y1[4],X2[4],Y2[4],X3[4],Y3[4],X4[4],Y4[4];

   /* line(0,380,getmaxx(),380);
            //Stand
            line(280,360,360,360);
            line(300,340,340,340);
            line(280,360,280,380);
            line(360,360,360,380);
            line(300,340,300,360);
            line(340,340,340,360);
            setfillstyle(SOLID_FILL,BROWN);
            floodfill(320,350,WHITE);
            floodfill(320,370,WHITE);

            //Pole
            line(315,140,315,340);
            line(325,140,325,340);
            line(315,140,325,140);
            floodfill(320,330,WHITE);


            //Flag
            line(475,140,475,230);

          // putpixel(400,160,WHITE);
            //setfillstyle(SOLID_FILL,WHITE);
            //floodfill(330,180,WHITE);
            //setfillstyle(SOLID_FILL,GREEN);
            //floodfill(330,210,WHITE);
            X1[0]=325;
            X1[1]=375;
            X1[2]=425;
            X1[3]=475;

            Y1[0]=140;
            Y1[1]=100;
            Y1[2]=180;
            Y1[3]=140;

            X2[0]=325;
            X2[1]=375;
            X2[2]=425;
            X2[3]=475;

            Y2[0]=170;
            Y2[1]=130;
            Y2[2]=210;
            Y2[3]=170;

            X3[0]=325;
            X3[1]=375;
            X3[2]=425;
            X3[3]=475;

            Y3[0]=200;
            Y3[1]=160;
            Y3[2]=240;
            Y3[3]=200;

            X4[0]=325;
            X4[1]=375;
            X4[2]=425;
            X4[3]=475;

            Y4[0]=230;
            Y4[1]=190;
            Y4[2]=270;
            Y4[3]=230;

            bezier(X1,Y1,4);
            bezier(X2,Y2,4);
            bezier(X3,Y3,4);
            bezier(X4,Y4,4);

            setfillstyle(SOLID_FILL,RED);
            floodfill(400,160,WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(330,180,WHITE);
            floodfill(470,180,WHITE);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(330,210,WHITE);

            //Chakra
            setcolor(BLUE);
            circle(400,185,15);
            line(400,170,400,200);
            line(385,185,415,185);
            line(410,177,393,195);
            line(392,174,407,195);
            setcolor(WHITE);*/



    while(1)
    {
        for(int i=0;i<80;i=i+5)
        {

            line(0,380,getmaxx(),380);
            //Stand
            line(280,360,360,360);
            line(300,340,340,340);
            line(280,360,280,380);
            line(360,360,360,380);
            line(300,340,300,360);
            line(340,340,340,360);
            setfillstyle(SOLID_FILL,BROWN);
            floodfill(320,350,WHITE);
            floodfill(320,370,WHITE);

            //Pole
            line(315,140,315,340);
            line(325,140,325,340);
            line(315,140,325,140);
            floodfill(320,330,WHITE);

            //Chakra
            circle(400,185,15);

            //Flag
            line(475,140,475,230);

          // putpixel(400,160,WHITE);
            //setfillstyle(SOLID_FILL,WHITE);
            //floodfill(330,180,WHITE);
            //setfillstyle(SOLID_FILL,GREEN);
            //floodfill(330,210,WHITE);
            X1[0]=325;
            X1[1]=375;
            X1[2]=425;
            X1[3]=475;

            Y1[0]=140;
            Y1[1]=100;
            Y1[2]=180;
            Y1[3]=140;

            X2[0]=325;
            X2[1]=375;
            X2[2]=425;
            X2[3]=475;

            Y2[0]=170;
            Y2[1]=130;
            Y2[2]=210;
            Y2[3]=170;

            X3[0]=325;
            X3[1]=375;
            X3[2]=425;
            X3[3]=475;

            Y3[0]=200;
            Y3[1]=160;
            Y3[2]=240;
            Y3[3]=200;

            X4[0]=325;
            X4[1]=375;
            X4[2]=425;
            X4[3]=475;

            Y4[0]=230;
            Y4[1]=190;
            Y4[2]=270;
            Y4[3]=230;



            Y1[1]=100+i;
            Y1[2]=180-i;

            Y2[1]=130+i;
            Y2[2]=210-i;

            Y3[1]=160+i;
            Y3[2]=240-i;

            Y4[1]=190+i;
            Y4[2]=270-i;
            bezier(X1,Y1,4);
            bezier(X2,Y2,4);
            bezier(X3,Y3,4);
            bezier(X4,Y4,4);

            setfillstyle(SOLID_FILL,RED);
            floodfill(400,160,WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            floodfill(330,180,WHITE);
            floodfill(470,180,WHITE);
            floodfill(400,185,WHITE);
            setfillstyle(SOLID_FILL,GREEN);
            floodfill(330,210,WHITE);

            //Chakra
            setcolor(BLUE);
            circle(400,185,15);
            line(400,170,400,200);
            line(385,185,415,185);
            line(410,177,393,195);
            line(392,174,407,195);
            setcolor(WHITE);

            delay(100);
            cleardevice();


        }
    }



}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"TurboC3\\BGI");

    drawFlag();

    getch();
    closegraph();
    return 0;
}

