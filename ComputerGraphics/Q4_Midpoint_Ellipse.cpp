#include <stdio.h>
#include <dos.h>
#include <graphics.h>

void drawEllipse(float xc, float yc, float rx, float ry)
{
   float P1,P2,x,y;
   x=0;
   y=ry;

   float rxSq=rx*rx, rySq=ry*ry, rxry=rx*ry;
    putpixel(xc,yc-ry,WHITE);
    putpixel(xc,yc+ry,WHITE);

   P1=rySq - rxSq*ry + 0.25*rxSq;

   while(2*rxSq*y>=2*rySq*x)
   {
       if(P1<0)
       {
           x=x+1;
           P1=P1 + 2*rySq*x + rySq;
       }
       else
       {
           x=x+1;
           y=y-1;
           P1=P1 + 2*rySq*x - 2*rxSq*y + rySq;
       }
       putpixel(xc+x,yc+y,WHITE);
       putpixel(xc-x,yc+y,WHITE);
       putpixel(xc+x,yc-y,WHITE);
       putpixel(xc-x,yc-y,WHITE);
   }

   P2= rySq*(x+0.5)*(x + 0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;

   while(y>=0)
   {
       if(P2<0)
       {
           x=x+1;
           y=y-1;
           P2=P2 + 2*rySq*x - 2*rxSq*y + rxSq;
       }
       else
       {
           y=y-1;
           P2=P2 - 2*rxSq*y + rxSq;
       }
       putpixel(xc+x,yc+y,WHITE);
       putpixel(xc-x,yc+y,WHITE);
       putpixel(xc+x,yc-y,WHITE);
       putpixel(xc-x,yc-y,WHITE);
   }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int x,y,rx,ry;

    x=200;
    y=200;
    rx=50;
    ry=30;

    drawEllipse(x,y,rx,ry);

    getch();
    closegraph();

    return 0;
}
