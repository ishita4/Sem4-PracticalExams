#include <stdio.h>
#define SIZE 50
int arr[SIZE];

int partition(int start,int end)
{
    int left=start,loc=start,right=end,flag=0,temp;

    while(flag!=1)
    {
        while((arr[loc]<=arr[right]) && (loc!=right))
        {
            right--;
        }
        if(loc == right)
            flag=1;
        else if(arr[loc]>arr[right])
        {
            temp=arr[loc];
            arr[loc]=arr[right];
            arr[right]=temp;
            loc=right;
        }

        if(flag!=1)
        {
            while((arr[loc]>=arr[left]) && (loc!=left))
            {
                left++;
            }
            if(loc == left)
                flag=1;
            else if(arr[loc]<arr[left])
            {
                temp=arr[loc];
                arr[loc]=arr[left];
                arr[left]=temp;
                loc=left;
            }
        }
        return loc;
    }
}

void quickSort(int beg, int end)
{
    int loc;
    if(beg<end)
    {
        loc=partition(beg,end);
        quickSort(beg,loc-1);
        quickSort(loc+1,end);
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

    quickSort(0,n-1);

    printf("\nSorted array is: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}
