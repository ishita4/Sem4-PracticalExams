#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
/*
TEST INPUT:
200 200
400 200
3
*/

void kochCurve(int x1, int y1, int x2, int y2, int it)
{
    float angle=60*M_PI/180;

    int x3=(2*x1 + x2)/3;
    int y3= (2*y1 + y2)/3;
    int x4=(x1 + 2*x2)/3;
    int y4=(y1 + 2*y2)/3;

    int x= x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
    int y= y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
   // int x= x3 - (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
   // int y= y3 + (x4-x3)*sin(angle) + (y4-y3)*cos(angle);

    if(it>0)
    {
        kochCurve(x1,y1,x3,y3, it-1);
        kochCurve(x3,y3,x,y, it-1);
        kochCurve(x,y,x4,y4, it-1);
        kochCurve(x4,y4,x2,y2, it-1);
    }
    else
    {
        line(x1,y1,x3,y3);
        line(x3,y3,x,y);
        line(x,y,x4,y4);
        line(x4,y4,x2,y2);
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"TurboC3\\BGI");
    int x1,y1,x2,y2,it;


    //Single line
    /*printf("Enter x1 and y1\n");
    scanf("%d %d",&x1, &y1);

    printf("Enter x2 and y2\n");
    scanf("%d %d",&x2, &y2);

    printf("Enter the number of iterations:\n");
    scanf("%d",&it);

    //kochCurve(x1,y1,x2,y2,it);*/


    //Snowflake
    kochCurve(100,100,400,100,3);
    kochCurve(400,100,250,400,3);
    kochCurve(250,400,100,100,3);


    getch();
    closegraph();
    return 0;
}
