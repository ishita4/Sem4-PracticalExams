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

void matrix_mult(int points[10][3])
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

void plot_output(int colour,int points[10][3])
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
    matrix_mult(points);
}

void reflect_x()
{
    printf("reflext x\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==0 and j==0)
                s[i][j]=1;
            else if(i==j)
                s[i][j]=-1;
            else
                s[i][j]=0;
        }
    }
    matrix_mult(points);
}

void reflect_y()
{
    printf("reflext y\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==1 and j==1)
                s[i][j]=1;
            else if(i==j)
                s[i][j]=-1;
            else
                s[i][j]=0;
        }
    }
    matrix_mult(points);
}

void reflect_origin()
{
    printf("reflext origin\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==2 and j==2)
                s[i][j]=1;
            else if(i==j)
                s[i][j]=-1;
            else
                s[i][j]=0;
        }
    }
    matrix_mult(points);
}

void shear_x(int shx)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                s[i][j]=1;
            else if(i==1 && j==0)
                s[i][j]=shx;
            else
                s[i][j]=0;
        }
    }
    matrix_mult(points);
}

void shear_y(int shy)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                s[i][j]=1;
            else if(i==0 && j==1)
                s[i][j]=shy;
            else
                s[i][j]=0;
        }
    }
    matrix_mult(points);
}

int main()
{
    int gd=DETECT, gm;
    float th;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
    int tx, ty,shx,shy, choice;

    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    //Taking input
    input_points();
    plot_output(WHITE,points);
    tx=points[0][0];
    ty=points[0][1];

    printf("Enter choice:\n1.Reflect X\n2.Reflect Y\n3.Reflect about Origin\n4.X Shear\n5.Y Shear\n");
    scanf("%d",&choice);

    if(choice == 1)
    {
        //Reflect about X-axis
        reflect_x();
        plot_output(WHITE,points);
    }
    else if(choice == 2)
    {
        reflect_y();
        plot_output(WHITE,points);
    }
    else if(choice == 3)
    {
        reflect_origin();
        plot_output(WHITE,points);
    }
    else if(choice == 4)
    {
        //Translating to origin
        translate((-tx),(-ty));
        plot_output(GREEN,points); //Can comment out the two polygons at origin if not required
        //Shearing at x
        printf("Shearing factors shx?:\n");
        scanf("%d",&shx);
        shear_x(shx);
        plot_output(GREEN,points);

        //Translating back to original co-ordinates and displaying
        translate(tx,ty);
        plot_output(WHITE,points);
    }
    else if(choice == 5)
    {
        //Translating to origin
        translate((-tx),(-ty));
        plot_output(GREEN,points); //Can comment out the two polygons at origin if not required
        //Shearing at y
        printf("Shearing factors shy?:\n");
        scanf("%d",&shy);
        shear_y(shy);
        plot_output(GREEN,points);

        //Translating back to original co-ordinates and displaying
        translate(tx,ty);
        plot_output(WHITE,points);
    }

    getch();
    closegraph();

    return 0;
}
