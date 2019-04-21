#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
/*
TEST INPUT:
4
100 100
400 100
400 300
100 300
*/
void scanLine()
{
    int i,j,n,arr[10][2],dx,dy,xi[100];
    float slope[10];
    printf("How many points?:\n");
    scanf("%d",&n);

    printf("Enter the points:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&arr[i][0],&arr[i][1]);
    }
    arr[n][0]=arr[0][0];
    arr[n][1]=arr[0][1];

    for(i=0;i<n;i++)
    {
        line(arr[i][0],arr[i][1],arr[i+1][0],arr[i+1][1]);
    }

    for(i=0;i<n;i++)
    {
        dy=arr[i+1][1] - arr[i][1];
        dx=arr[i+1][0] - arr[i][0];

        if(dx==0)
            slope[i]=0.0;
        if(dy==0)
            slope[i]=1.0;
        if(dx!=0 && dy!=0)
        {
            slope[i]=(float)dx/dy;
        }
    }
    int k;

    for(int y=0;y<480;y++)
    {
        k=0;
        for(i=0;i<n;i++)
        {
            if((arr[i][1]<=y && y<arr[i+1][1]) || (arr[i][1]>y && y>=arr[i+1][1]))
            {
                xi[k]=(int)(arr[i][0] + slope[i]*(y-arr[i][1]));
                k++;
            }
        }

        float temp;
        for(int j=0;j<k-1;j++)
        {
            for(int i=0;i<k-1;i++)
            {
                if(xi[i+1]<xi[i])
                {
                    temp=xi[i+1];
                    xi[i+1]=xi[i];
                    xi[i]=temp;
                }
            }
        }

        setcolor(RED);
        for(int i=0; i<k; i=i+2)
            line(xi[i]+1,y,xi[i+1]-1,y);

    }


}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"TurboC3\\BGI");

    scanLine();

    getch();
    closegraph();
    return 0;
}
