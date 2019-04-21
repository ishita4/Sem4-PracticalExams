#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#define MAX 10000
int stack[MAX],top=-1;

void push(int x, int y)
{
    if(top==MAX-2)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=x;
        top++;
        stack[top]=y;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
    {
        int val= stack[top];
        top--;
        return val;
    }
}


void boundaryFill(int x, int y, int fillColour, int boundaryColour)
{
    push(x,y);
    while(top!=-1)
    {
        y=pop();
        x=pop();

        putpixel(x,y,fillColour);

        if(getpixel(x+1,y)!=boundaryColour && getpixel(x+1,y)!=fillColour)
            push(x+1,y);
        if(getpixel(x-1,y)!=boundaryColour && getpixel(x-1,y)!=fillColour)
            push(x-1,y);
        if(getpixel(x,y+1)!=boundaryColour && getpixel(x,y+1)!=fillColour)
            push(x,y+1);
        if(getpixel(x,y-1)!=boundaryColour && getpixel(x,y-1)!=fillColour)
            push(x,y-1);

    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"TurboC3\\BGI");
    int x,y,r;

    circle(100,100,50);
    boundaryFill(100,100,RED,WHITE);

    getch();
    closegraph();

    return 0;
}
