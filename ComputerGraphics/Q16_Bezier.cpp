#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>

/*
TEST INPUT
200 200
300 100
400 100
500 200
*/

int fact(int n)
{
    int f=1;
    for(int i=1;i<=n;i++)
        f=f*i;
    return f;
}

int combination(int n, int r)
{
    return fact(n)/(fact(n-r)*fact(r));
}

void bezier(int X[],int Y[],int n)
{
    float u;
    float x,y;

    for(u=0.001;u<1;u=u+0.001)
    {
        x=0;
        y=0;
        for(int k=0;k<n;k++)
        {
            x= x + (combination(n-1,k)*X[k]*pow(u,k)*pow(1-u,n-k-1));
            y= y + (combination(n-1,k)*Y[k]*pow(u,k)*pow(1-u,n-k-1));
        }
        putpixel(int(x),int(y),WHITE);
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"TurboC3\\BGI");
    int arr[50],n,x[20],y[20];

    printf("How many vertices?\n");
    scanf("%d",&n);

    printf("Enter the vertices of the polygon:\n");

    for(int i=0;i<2*n;i++)
    {
        scanf("%d",&arr[i]);
    }
 //   arr[2*n]=arr[0];
  //  arr[(2*n)+1]=arr[1];

    int i=0,j=1;
    for(int k=0;k<n;k++)
    {
        x[k]=arr[i];
        y[k]=arr[j];
        i=i+2;
        j=j+2;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\t",x[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\t",y[i]);
    }
    drawpoly(n,arr);
    bezier(x,y,n);

    getch();
    closegraph();
    return 0;
}
