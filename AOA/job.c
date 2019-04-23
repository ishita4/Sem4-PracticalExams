#include<conio.h>
#include<stdio.h>
int n,i,j,k,t;
int check(int s[],int p)
{
    int ptr=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==p) //if there is job having same deadline as some previously allocated job, increase ptr and decline
               ptr++;
    }

    if(ptr==0)
        return 1;   //can be allocated
    else
        return 0;   //cannot
}

int main()
{
     printf("enter the no of jobs      : ");
     scanf("%d",&n);

     int slot[n],profit,p[n],d[n];

     for(i=0;i<n;i++)
       {
            printf("\n enter the profit of job #%d      :",i+1);
            scanf("%d",&p[i]);
            printf("\n enter the deadline of job #%d    :",i+1);
            scanf("%d",&d[i]);
       }

     for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
         if(p[i]<p[j])
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
                t=d[i];
                d[i]=d[j];
                d[j]=t;
            }

       for(i=0;i<n;i++)
           slot[i]=0;

     for(i=0;i<n;i++)
         for(j=d[i];j>0;j--) //Suppose deadline of process one is 2
             {
                if(check(slot,j)==1)    //if slot can be allocated
                {
                    slot[i]=j;  //slot one becomes 2
                    break;
                }
             }

     printf("\n\n INDEX   PROFIT  DEADLINE  SLOT ALLOTTED ");
     for(i=0;i<n;i++)
     {
         if(slot[i]>0)
            printf("\n\n   %d       %d        %d        [%d - %d]", i+1,p[i],d[i],(slot[i]-1),slot[i]);
        else
            printf("\n\n   %d       %d        %d        REJECTED", i+1,p[i],d[i]);
     }

       getch();
}
