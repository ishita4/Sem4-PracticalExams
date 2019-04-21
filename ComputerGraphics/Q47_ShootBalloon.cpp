#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

void drawBalloon()
{
    ellipse(550,200,0,360,40,60);
    line(550,260,540,getmaxy());
    line(550,260,540,getmaxy());
    setfillstyle(SOLID_FILL,RED);
    floodfill(550,200,WHITE);
}

void drawBowandArrow(int x, int y)
{

    arc(30,200,270,90,30);
    arc(30,260,270,90,30);
    ellipse(30,200,270,90,45,30);
    ellipse(30,260,270,90,45,30);

    line(x,y,x+50,y);
    line(x+50,y,x+40,y-10);
    line(x+50,y,x+40,y+10);

    delay(30);
    cleardevice();

}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

    drawBalloon();

    for(int x=30;x<getmaxx();x=x+5)
    {
        if(x<=480)
        {
            drawBalloon();
            drawBowandArrow(x,230);
        }
        else
            drawBowandArrow(x,230);
    }


    getch();
    closegraph();

    return 0;
}
