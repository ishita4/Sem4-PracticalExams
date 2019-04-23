#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("\t\tRABIN KARP ALGORITHM\n");
    char a[50];
    printf("ENTER THE STRING : ");
    gets(a);
    char b[50];
    printf("ENTER THE PATTERN TO BE SEARCHEd : ");
    gets(b);
    int n = strlen(a);
    int m = strlen(b);
    int p=0,t=0,h=1,i,j;

    for(i=0;i<m-1;i++)
        h=(10*h)%11;

    for(i=0;i<m;i++)
    {
         p = (10*p + b[i])%11;
         t = (10*t + a[i])%11;
    }

    for(i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==m)
                printf("PATTERN FOUND AT : %d \n",i+1);
        }

        if(i<n-m)
        {
            t = (10*(t - a[i]*h) + a[i+m])%11;
            if(t < 0)
                t = (t + 11);
        }
    }

    return 0;
}
