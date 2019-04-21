#include <stdio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>
int points[10][3],n=5;
float s[3][3];


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
    /*printf("Multiplication:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",mult[i][j]);
        printf("\n");
    }*/

    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
            points[i][j]=mult[i][j];
    }
}

void drawPyramid()
{
    points[0][0]=320;
    points[0][1]=50;
    points[1][0]=320;
    points[1][1]=150;
    points[2][0]=250;
    points[2][1]=170;
    points[3][0]=320;
    points[3][1]=190;
    points[4][0]=390;
    points[4][1]=170;
    points[4][2]=1;

    for(int i=0;i<4;i++)
    {
        line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
        points[i][2]=1;
    }
    line(points[4][0],points[4][1],points[0][0],points[0][1]);
    line(points[4][0],points[4][1],points[1][0],points[1][1]);
    line(points[0][0],points[0][1],points[2][0],points[2][1]);
}

void drawTranslatedPyramid()
{
    for(int i=0;i<4;i++)
    {
        line(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
        points[i][2]=1;
    }
    line(points[4][0],points[4][1],points[0][0],points[0][1]);
    line(points[4][0],points[4][1],points[1][0],points[1][1]);
    line(points[0][0],points[0][1],points[2][0],points[2][1]);
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

int main()
{
    int gd=DETECT, gm;
    float th;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int tx, ty;

    drawPyramid();
    printf("Translation Factor?:\n");
    scanf("%d%d",&tx,&ty);

    translate(tx,ty);

    drawTranslatedPyramid();

    getch();
    closegraph();

    return 0;
}
