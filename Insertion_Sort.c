#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int temp,i,j;

    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=arr[i];

        while(j>=0 && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;
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

    insertionSort(arr,n);

    return 0;
}
