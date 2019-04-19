#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx,dy,steps,i;
    float x,y,xInr,yInr;
    dx=(x2-x1);
    dy=(y2-y1);

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);

    xInr= ((float)dx/steps);
    yInr= ((float)dy/steps);

    x=x1;
    y=y1;

    for(i=0;i<=steps;i++)
    {
        putpixel(round(x),round(y),WHITE);
        putpixel(round(x),round(y+1),WHITE);
        putpixel(round(x),round(y-1),WHITE);
        putpixel(round(x),round(y+2),WHITE);
        putpixel(round(x),round(y-2),WHITE);

        x += xInr;
        y += yInr;
        delay(50);

    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int x1,y1,x2,y2;

    x1=400;
    y1=400;
    x2=200;
    y2=200;

    drawLine(x1,y1,x2,y2);

    getch();
    closegraph();

    return 0;
}
