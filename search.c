
#include <stdio.h>
int a[50],n,item;
void linearsearch();
void binarysearch();
void main()
{
    int choice,j;
    while(1)
    {
        printf("\t MENU\n1. Binary search\n2. Linear search\n3. exit\n");
        scanf("%d",&choice);
        if(choice==1 || choice==2)
        {
            printf("Enter the number of elements in the array\n");
            scanf("%d",&n);
            printf("Enter the elements\n");
            j=0;
            while(j<n)
                scanf("%d",&a[j++]);
            switch(choice)
            {
                case 1: printf("Enter the item to be searched\n");
                        scanf("%d",&item);
                        binarysearch();
                        break;

                case 2: printf("Enter the item to be searched\n");
                        scanf("%d",&item);
                        linearsearch();
                        break;
                case 3 : exit(0);
            }
        }
        else
            break;
    }
}

void linearsearch()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("%d found at position %d\n",item,i+1);
            break;
        }
    }
    if(i==n)
        printf("Element not found\n");
}
void binarysearch()
{
    int temp,first=0,last=n-1,middle=(first+last)/2;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted array is : ");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");

    while(first<=last)
    {
        if(a[middle]==item)
        {
            printf("%d found at position %d\n",item,middle+1);
            break;
        }
        else if(item>a[middle])
            first=middle+1;
        else
            last=middle-1;
        middle=(first+last)/2;
    }
    if(first>last)
        printf("Element not found\n");
}
