#include<stdio.h>
int main()
{
    int i,j;
    char input,alphabet = 'A';
    printf("enter the uppercase charter in the last row\n");
    scanf("%c",&input);
    for(i=1;i<=(input-'A'+1);i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c " , alphabet);

        }
        alphabet++;
        printf("\n");
    }

}
