#include <stdio.h>
#include <dos.h>
#include <graphics.h>

void floodFill(int x, int y,int fillColour, int bgColour)
{
    if(getpixel(x,y)== bgColour)
    {
        floodFill(x+1, y,fillColour, bgColour);
        floodFill(x-1, y,fillColour, bgColour);
        floodFill(x, y+1,fillColour, bgColour);
        floodFill(x, y-1,fillColour, bgColour);
    }
}

void drawCar(int x, int y)
{
    line(0,380,getmaxx(),380);

    //Wheels
    circle(x,y,40);
    circle(x+160,y,40);
    arc(x,y,0,180,50);
    arc(x+160,y,0,180,50);
    line(x+50,y,x+110,y);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(x,y,WHITE);
    floodfill(x+160,y,WHITE);

    //Body
    line(x-50,y,x-70,y);
    line(x-70,y,x-70,y-80);
    line(x-70,y-80,x,y-80);
    line(x,y-80,x+20,y-180);
    line(x+20,y-180,x+20+120,y-180);
    line(x+20+120,y-180,x+20+120+20,y-80);
    line(x+20+120,y-180,x+20+120+20,y-80);
    line(x+160,y-80,x+260,y-80);
    line(x+260,y-80,x+260,y);
    line(x+260,y,x+160+50,y);
    //floodFill(x+70,y-50,BLUE,BLACK);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(x+70,y-50,WHITE);

    //Window
    line(x+10,y-80,x+30,y-170);
    line(x+30,y-170,x+30+100,y-170);
    line(x+30+100,y-170,x+30+100+20,y-80);
    line(x+10,y-80,x+30+100+20,y-80);
    line(x+30+50,y-170,x+30+50,y-80);
    setfillstyle(SOLID_FILL,RED);
    floodfill(x+20,y-100,WHITE);
    floodfill(x+30+90,y-100,WHITE);

    //Headlight
    line(x+230,y-80,x+230,y-60);
    line(x+230,y-60,x+260,y-60);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(x+240,y-70,WHITE);

    delay(100);
    cleardevice();


}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int x,y,r;
   // print("En")

    while(true)
    {
        for(x=0;x<getmaxx();x=x+10)
        {
            drawCar(x,340);
        }
    }


  //  drawCar(80,340);
    getch();
    closegraph();

    return 0;
}
