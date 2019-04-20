#include <stdio.h>
#define SIZE 50
int arr[SIZE];

int merge(int start,int mid,int end)
{
    int i=start,j=mid+1,temp[SIZE],k=0,index=0;

    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            temp[index]=arr[i];
            index++;
            i++;
        }
        else
        {
            temp[index]=arr[j];
            index++;
            j++;
        }
    }

    if(i>mid)
    {
        while(j<=end)
        {
            temp[index]=arr[j];
            index++;
            j++;
        }

    }
    else
    {
        while(i<=mid)
        {
            temp[index]=arr[i];
            index++;
            i++;
        }
    }

    for(k=start;k<index;k++)
    {
        arr[k]=temp[k];
    }
}

void mergeSort(int beg, int end)
{
    int mid;

    if(beg<end)
    {
        mid=(beg+end)/2;
        mergeSort(0,mid);
        mergeSort(mid+1,end);
        merge(beg,mid,end);
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

    mergeSort(0,n-1);

    printf("\nSorted array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}
