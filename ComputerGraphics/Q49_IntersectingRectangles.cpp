#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>

void floodFill(int x, int y, int fillColour, int interiorColour)
{
     if(getpixel(x, y)==interiorColour)
     {
          putpixel(x, y, fillColour);
          floodFill(x-1, y, fillColour, interiorColour);
          floodFill(x, y-1, fillColour, interiorColour);
          floodFill(x+1, y-1, fillColour, interiorColour);
          floodFill(x, y+1, fillColour, interiorColour);
     }
}

void drawRect()
{
    rectangle(100,50,300,200);
    rectangle(200,100,450,250);
    floodFill(120,70,BLUE,BLACK);
    floodFill(430,120,RED,BLACK);
    floodFill(210,120,YELLOW,BLACK);
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

    drawRect();

    getch();
    closegraph();

    return 0;
}
