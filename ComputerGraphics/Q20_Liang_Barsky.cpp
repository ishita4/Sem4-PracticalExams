#include <stdio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>
/*
TEST INPUT:
100 100
400 400
100 50
300 300
*/
void liangBarsky()
{
    int x1,x2,y1,y2,xwMin,xwMax,ywMin, ywMax;
    int dx,dy,p[4],q[4];
    float t1=0, t2=1,m,t[4];

    printf("Enter lower coordinates\n");
    scanf("%d %d",&xwMin, &ywMin);

    printf("Enter upper coordinates:\n");
    scanf("%d %d",&xwMax, &ywMax);

    rectangle(xwMin,ywMin,xwMax, ywMax);

    printf("Enter x1 and y1\n");
    scanf("%d %d",&x1, &y1);

    printf("Enter x2 and y2\n");
    scanf("%d %d",&x2, &y2);

    setcolor(RED);
    line(x1,y1,x2,y2);

    dx=x2-x1;
    dy=y2-y1;

    p[0]=-dx;
    p[1]=dx;
    p[2]=-dy;
    p[3]=dy;

    q[0]=x1-xwMin;
    q[1]=xwMax-x1;
    q[2]=y1-ywMin;
    q[3]=ywMax-y1;

    for(int i=0;i<4;i++)
	{
		if(p[i]==0)
		{
			printf("line is parallel to one of the clipping boundary");
			if (q[i]<0) //COMPLETELY OUTTSIDE DISCARD LINE
            {
                printf("Completely outside\n");
                cleardevice();
                rectangle(xwMin,ywMin,xwMax, ywMax);
            }
			else if(q[i]>=0)
			{
				if(i<2)
				{
					if(y1<ywMin) //Y1 outside ymin but y2 inside (Partially inside)
					{
						y1=ywMin;
					}

					if(y2>ywMax)
					{
						y2=ywMax;
					}

					line(x1,y1,x2,y2);
				}

				if(i>1)
				{
					if(x1<xwMin)
					{
						x1=xwMin;
					}

					if(x2>xwMax)
					{
						x2=xwMax;
					}

					line(x1,y1,x2,y2);
				}
			}
		}
	}

    for(int i=0;i<4;i++)
	{
		float temp=(float)q[i]/p[i];

		if(p[i]<0)
		{
			if(t1<=temp)
				t1=temp;
		}
		else
		{
			if(t2>temp)
				t2=temp;
		}
	}

    if(t1<t2)
    {
        int xx1=x1 + t1*dx;
        int yy1=y1 + t1*dy;
        int xx2=x1 + t2*dx;
        int yy2=y1 + t2*dy;
        setcolor(WHITE);
        line(xx1,yy1,xx2,yy2);
    }
    else
    {
        printf("Line is completely outside");
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"TurboC3\\BGI");

    liangBarsky();

    getch();
    closegraph();
    return 0;
}
