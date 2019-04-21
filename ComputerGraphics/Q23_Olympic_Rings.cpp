#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
/******Implement using midpoint circle*******/
void drawRings(int n)
{
    int a,b;
    b=n/2;
    a=n-b;
    printf("%d %d",a,b);
    int start1=100,start2=170;
    while(a)
    {
        circle(start1,150,65);
        start1=start1+140;
        a--;
    }
    while(b)
    {
        circle(start2,230,65);
        start2=start2+140;
        b--;
    }
}

int main()
{
    int gd=DETECT, gm,n;
    initgraph(&gd,&gm,"TurboC3\\BGI");

    printf("Enter the number of rings:\n");
    scanf("%d",&n);
    drawRings(n);

    getch();
    closegraph();
    return 0;
}

