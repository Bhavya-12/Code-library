#include<stdio.h>
int main ()
{
    int i , space, rows;
    int k=0;
    printf("enter the number of rows\n");
    scanf("%d",&rows);
       for(i=1;i <=rows;i++,k=0)
    {
       // k=0;
        for(space=1;space <= rows-i;space++)
        {
            printf("  ");
        }
        while(k!=2*i-1)
        {
            printf("* ");
            k++;
        }
        printf("\n");
    }
    return 0;
}
