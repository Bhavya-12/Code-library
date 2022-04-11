#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*void swap(int *a ,int *b)
{
    int temp= *a;
    *a = *b;
    *b=temp;
}*/
struct students
{
    int marks;
    char *name;
    float average;
};
void display4(struct students array[],int n)
{
    for(int i =0;i<n;i++)
    {
        printf("%d %s %f \n",array[i].marks,array[i].name,array[i].average);
    }
    printf("/n");
}
void selection( struct students array[],int n)
{
    for(int step=0;step < n-1;step++)
    { 
         int min=step;
         for( int j=step+1 ;j <n ;j++)
         {
             if(strcmp(array[j].name,array[min].name)<0)
                min=j;
         }
         // swap(&array[min], &array[step]);
           struct students temp = array[min];
           array[min]=array[step];
           array[step]=temp;
    }
       //  printf("------------------step %d : ------------------\n swapped %d %d  After swapping : " ,t++,array[min],array[step]);
          //  display4(array,n);
}
int main()
{
    int n, marks;
    char name[10];
    float average;
      printf("enter the size\n");
    scanf("%d",&n);
    struct students s[n];
  //  int array[n];
    printf("enter the array elements\n");
    for(int i=0;i<n;i++)
    {
scanf("%d%s%f",&marks,name,&average);
s[i].marks=marks;
s[i].name=strdup(name);
s[i].average=average;
    }
   //  printf("tracing.. : \n");
    selection(s ,n);
    display4(s,n);
}