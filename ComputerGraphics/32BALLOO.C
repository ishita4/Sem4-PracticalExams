#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

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

void drawballoons(int x, int y)
{
       //FirstBalloon
       circle(x,y,40);
       setfillstyle(SOLID_FILL,RED);
       floodfill(x,y,RED,WHITE);
       arc(x,y+70,90,270,30);
       arc(x,y+130,300,90,30);

       //SecondBalloon
       circle(x+100,y,40);
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(x+100,y,WHITE);
       arc(x+100,y+70,90,270,30);
       arc(x+100,y+130,300,90,30);

       //ThirdBalloon
       circle(x-100,y,40);
       setfillstyle(SOLID_FILL,BLUE);
       floodfill(x-100,y,WHITE);
       arc(x-100,y+70,90,270,30);
       arc(x-100,y+130,300,90,30);

       delay(100);

       cleardevice();

}
int main()
{
    int gd=DETECT,gm,x,y,n;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    n=1;
    while(n==1)
    {
	for(y=getmaxy();y>100;y=y-5)
	{
	    drawballoons(320,y);
	}
    }
    getch();
    closegraph();
    return 0;
}