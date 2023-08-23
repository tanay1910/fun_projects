#include <stdio.h>
#include<stdlib.h>
int largestInArray(int arr[3],int m, int n)
{
    int largest = arr[0];
    for(int i = 0; i<n; i++)
    {
        if(arr[i]>largest)
        {
            largest=i;
        }
    }

    return(largest);
}

int smallestInArray(int arr[3],int m, int n)
{
    int smallest = arr[0];
    for(int i = 0; i<n; i++)
    {
        if(arr[i]<smallest)
        {
            smallest=i;
        }
    }

    return(smallest);
}

  

// int maxProfit(int profitTable[][])
// {
  
//     for(int i = 0; i<5;i++)
//     {
//         int smallest = i;
//         int largest = i+1;
//         for(int j = i; j<5;j++)
//         {
//             if(arr[i][j]>largest)
//             {
//                 largest=[j];
//             }

//             if(arr[i][j]<smallest)
//             {

//             }

//         }
//     }
// }
  
int main()
{
    int profitTable [3][3];
    int i,j,m=3,n=3;
    printf("enter the prices: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&profitTable[i][j]);
        }
    }

    printf("Entered values: \n");
    for(int i =0 ; i<m;i++)
    {
        for(int j = 0; j<n;j++)
        {
            printf("%d ",profitTable[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<m;i++)
    {
        int largest = largestInArray(profitTable[i],m,n);
        int smallest = smallestInArray(profitTable[i],m,n);


        printf("(%d , %d)",largest,smallest);
    }



}