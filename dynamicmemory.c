 #include<stdio.h>
#include<stdlib.h>
struct student
{
    int rno;
    char name[20];
    float avg;
};
void read(struct student *sptr, int n);
void display(struct student *sptr, int n);
void mean(struct student *sptr, int n);
int main()
{
    struct student *sptr;
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    sptr=(struct student*)malloc(n*sizeof(struct student));
    if(sptr==NULL)
    {
        printf("Could not allocate memory");
        exit(0);
    }
    read(sptr,n);
    display(sptr,n);
     mean(sptr,n);
    free(sptr);
    return 0;
}
void read(struct student *sptr, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter rno, name, average\n");
        scanf("%d%s%f",&sptr->rno,sptr->name,&sptr->avg);
        sptr++;
    }
}
void display(struct student *sptr, int n)
{
     int i;
      printf("R.no.\tName:\tAverage:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%f\n",(sptr+i)->rno,(sptr+i)->name,(sptr+i)->avg);
    }
}
void mean(struct student *sptr, int n)
{
    int i,sum=0;
    float res;
    for(i=0;i<n;i++)
    {
        sum=sum+(sptr+i)->avg;
    }
    res=(float)sum/n;
    printf("Mean=%f",res);
}
