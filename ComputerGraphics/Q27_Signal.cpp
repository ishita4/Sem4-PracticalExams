#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

void drawSignal()
{
    line(300,100,200,200);
    line(300,100,400,200);
    line(400,200,300,300);
    line(200,200,300,300);

    circle(300,150,22);
    circle(300,200,22);
    circle(300,250,22);

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(230,200,WHITE);

}
void colour()
{
    while(1)
    {
        drawSignal();
        setfillstyle(SOLID_FILL,RED);
        floodfill(300,150,WHITE);
        delay(1000);
        cleardevice();
        drawSignal();

        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(300,200,WHITE);
        delay(1000);
        cleardevice();
        drawSignal();

        setfillstyle(SOLID_FILL,GREEN);
        floodfill(300,250,WHITE);
        delay(1000);
        cleardevice();
        drawSignal();
    }
}


int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

    colour();

    getch();
    closegraph();

    return 0;
}
