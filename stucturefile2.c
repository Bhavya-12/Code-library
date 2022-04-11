#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rno;
    char name[20];
    float avg;

};
int main()
{
    struct student s;
    FILE*fp;
    int i,n;
    fp=fopen("record.txt","w");
    if(fp==NULL)
    {
        printf("file cannot be opened\n");
        exit(0);
    }
    printf("enter nos of students\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter rno,name and avg\n");
        scanf("%d%s%f",&s.rno,s.name,&s.avg);
        fprintf(fp,"%d %s %f\n",s.rno,s.name,s.avg);
    }
    fclose(fp);
     fp=fopen("record.txt","r");
     char lcnt;
     char ch;
     if(fp==NULL)
     {
         printf("file cannot be opened\n");
         exit(0);
     }
     while((ch=fgetc(fp))!=EOF)
     {
         if(ch=='\n')
            lcnt++;
     }
     printf("nos of lines %d\n",lcnt);
     fclose(fp);
     return 0;
}
