#include <stdio.h>
#include <string.h>
char str1[20],str2[20],path[20];
char b[20][20];
int c[20][20];

/*
Test Input
ABCBDAB
BDCABA
 */

void lcs(int m, int n)
{
    int i,j,k;

    for(i=0;i<=m;i++)
    {
        c[i][0]=0;
        b[i][0]=0;
    }


    for(i=0;i<=n;i++)
    {
        c[0][i]=0;
        b[0][i]=0;
    }


    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    }
}

void printPath(int i, int j)
{
    if(i==0 || j==0)
        return;
    else if(b[i][j]=='d')
    {

        printPath(i-1,j-1);
        printf("%c",str1[i-1]);
    }
    else if(b[i][j]=='u')
        printPath(i-1,j);

    else if(b[i][j]=='l')
        printPath(i,j-1);

}

void printArray(int m, int n)
{
    int i,j;

    printf("\t\t");
    for(i=0;i<n;i++)
        printf("%c\t",str2[i]);

    printf("\n");
    for(i=0;i<=m;i++)
    {

        printf("%c\t",str1[i-1]);
        for(j=0;j<=n;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int m, n;
    printf("Enter the string:\n");
    gets(str1);

    printf("Enter the pattern:\n");
    gets(str2);

    m=strlen(str1);
    n=strlen(str2);

    lcs(m,n);
    printArray(m,n);

    printf("The longest common subsequence is:");
    printPath(m,n);

    return 0;
}
