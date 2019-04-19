#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx,dy,steps,i,P;
    int s1,s2,temp,flag=0;
    int x=x1, y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    P = 2*dy- dx;

    if(x2-x1 > 0)
        s1=1;
    else if(x2-x1<0)
        s1=-1;
    else
        s1=0;

    if(y2-y1 > 0)
        s2=1;
    else if(y2-y1<0)
        s2=-1;
    else
        s2=0;

    if(dy>dx)  //SLOPE>1
    {
        temp=dy;
        dy=dx;
        dx=temp;
        flag=1;
    }

    putpixel(x,y,GREEN);
    for(int i=0;i<dx;i++)
    {
        if(P<0)
        {
            if(flag == 1)
            {
                y=y+s2;
                if(i%4 == 0)
                    putpixel(x,y,GREEN);
            }
            else
            {
                x=x+s1;
                if(i%4 == 0)
                    putpixel(x,y,GREEN);
            }
            P=P+2*dy;
        }
        else
        {
            x=x+s1;
            y=y+s2;
            P=P+2*dy-2*dx;
            if(i%4 == 0)
                putpixel(x,y,GREEN);
        }
        delay(20);
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

    //line(x1,y1,x2,y2);
    drawLine(x1,y1,x2,y2);

    getch();
    closegraph();

    return 0;
}
