#include <stdio.h>

int smallest(int k,int n, int arr[])
{
    int j,min=arr[k],posOfMin=k;
    for(j=k+1;j<n;j++)
    {
        if(arr[j]<min)
        {
            min=arr[j];
            posOfMin=j;
        }

    }
    return posOfMin;
}

void selectionSort(int arr[], int n)
{
    int temp,i,j,minIndex;

    for(i=0;i<n;i++)
    {
        minIndex=smallest(i,n,arr);
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }

    printf("\nSorted array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
    int i,arr[10],n;

    printf("Enter the size:\n");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,n);

    return 0;
}
