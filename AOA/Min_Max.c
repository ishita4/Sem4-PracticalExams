#include <stdio.h>
#define SIZE 50
int arr[SIZE];
int min=0, max=0;

void minMax(int beg, int end)
{
    int max1=0,min1=0,mid=0;
    if(beg==end) //Single element exists
    {
        max=arr[beg];
        min=arr[beg];
    }
    else if(beg == end-1) //Two elements exist
    {
        if(arr[beg]>arr[end])
        {
            max=arr[beg];
            min=arr[end];
        }
        else
        {
            min=arr[beg];
            max=arr[end];
        }
    }
    else
    {
        mid=(beg+end)/2;
        minMax(beg,mid);
        max1=max;
        min1=min;
        minMax(mid+1,end);

        if(max1>max)
            max=max1;
        else if(min1<min)
            min=min1;
    }
}

int main()
{
    int i,n;

    printf("Enter the size:\n");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    minMax(0,n-1);

    printf("Minimum in the array is: %d\n",min);
    printf("Maximum in the array is: %d\n",max);

    return 0;
}
