#include <stdio.h>
#include <dos.h>
#include <graphics.h>

void drawCircle(float xc, float yc, int r)
{
    float P;
    float x,y;
    P=1-r;
    x=0;
    y=r;

    putpixel(int(xc+r),int(yc),WHITE);
    putpixel(int(xc-r),int(yc),WHITE);
    putpixel(int(xc),int(yc-r),WHITE);
    putpixel(int(xc),int(yc+r),WHITE);

    for(int i=0;y>=x;i++)
    {
        if(P<=0)
        {
            x=x+1;
            P=P+2*x+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            P=P+2*x-2*y+1;
        }
        putpixel(int(xc+x),int(yc+y),WHITE);
        putpixel(int(xc+y),int(yc+x),WHITE);
        putpixel(int(xc-y),int(yc+x),WHITE);
        putpixel(int(xc-x),int(yc+y),WHITE);
        putpixel(int(xc-x),int(yc-y),WHITE);
        putpixel(int(xc-y),int(yc-x),WHITE);
        putpixel(int(xc+y),int(yc-x),WHITE);
        putpixel(int(xc+x),int(yc-y),WHITE);
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int x,y,r;

    x=100;
    y=100;
    r=50;

    drawCircle(x,y,r);

    getch();
    closegraph();

    return 0;
}
