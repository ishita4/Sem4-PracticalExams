#include <stdio.h>
#include <math.h>
int n,x[10];
int position(int x[], int r)
{
    for(int i=0;i<r;i++)
    {
        if((x[i]==x[r]) || (abs(i-r)==abs(x[i]-x[r])))
            return 0;
    }
    return 1;
}

void printArray(int x[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",x[i]);
    printf("\n");
}

void Queen(int r,int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        x[r]=i;

        if(position(x,r))
        {
            if(r+1<n)
                Queen(r+1,n);
            else
                printArray(x,n);
        }
    }
}

int main()
{
    printf("Enter the number of Queens:\n");
    scanf("%d",&n);

    Queen(0,n);

    return 0;

}
