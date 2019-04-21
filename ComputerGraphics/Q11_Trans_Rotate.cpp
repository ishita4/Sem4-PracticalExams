#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>
int points[10][3],n;
float s[3][3];

/*
TEST INPUT:
50 50
100 100
150 50

50 50
50 100
100 100
100 50

Translate about point - 50 50
Rotate by - 30
*/

void matrix_mult()
{
    int mult[n][3];
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            mult[i][j]=0;
            for(k=0;k<3;k++)
            {
                mult[i][j] += points[i][k]*s[k][j];

            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
            points[i][j]=mult[i][j];
    }
}

void input_points()
{
    int i,j;
    printf("How many points?:\n");
    scanf("%d",&n);

    printf("Enter the points:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&points[i][0],&points[i][1]);
        points[i][2]=1;

    }
}

void plot_output(int colour)
{
    int i,j;
    setcolor(colour);
    for(i=0;i<n-1;i++)
    {
        line(320+points[i][0],240-points[i][1],320+points[i+1][0],240-points[i+1][1]);
    }
    line(320+points[n-1][0],240-points[n-1][1],320+points[0][0],240-points[0][1]);

}

void translate(int tx, int ty)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
            s[i][j]=1;
            else if(i==2 and j==0)
                s[i][j]=tx;
            else if(i==2 and j==1)
                s[i][j]=ty;
            else
                s[i][j]=0;
        }

    }
    matrix_mult();
}

void rotate(float th)
{
    th=th*M_PI/180;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==2 && j==2)
                s[i][j]=1;
            else if(i==j)
                s[i][j]=cos(th);
            else if(i==0 and j==1)
                s[i][j]=sin(th);
            else if(i==1 and j==0)
                s[i][j]=-sin(th);
            else
                s[i][j]=0;
        }
    }
    matrix_mult();
}



/************ In order to transform a polygon, translate to the origin, apply specified transformations and tranlate back***/
int main()
{
    int gd=DETECT, gm;
    float th;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int tx, ty;

    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    input_points();
    plot_output(WHITE);

    printf("Point about which to translate?:\n");
    scanf("%d%d",&tx,&ty);

    translate((-tx),(-ty));

    plot_output(GREEN);

    printf("Angle by which to rotate?:\n");
    scanf("%f",&th);

    rotate(th);
    plot_output(GREEN);

    translate(tx,ty);
    plot_output(WHITE);

    getch();
    closegraph();

    return 0;
}
