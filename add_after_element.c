#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE create_node();
NODE insert_begin(NODE);
NODE del_position(NODE,int);
void display(NODE);
void main()
{
    int n,pos;
    NODE first=NULL;
    printf("Enter the number of values\n");
    scanf("%d",&n);
    printf("Enter the position\n");
    scanf("%d",&pos);
    for(int i=0;i<n;i++)
    {
        first=insert_begin(first);
    }
    display(first);
    first=del_position(first,pos);
    display(first);
}
NODE create_node()
{
    NODE temp;
    temp=(NODE*)malloc(sizeof(NODE));
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
NODE insert_begin(NODE first)
{
    NODE temp;
    temp=create_node();
    temp->next=first;
    return temp;
}
void display(NODE first)
{
    while(first!=NULL)
    {
        printf("%d\t",first->data);
        first=first->next;
    }
}
NODE del_position(NODE first,int val)
{
    NODE c,prev,temp;
    int pos=1,i=1;
    c=first;
    while(c->next!=NULL)
    {
        if(c->data==val)
        {
            break;
        }
        c=c->next;
        pos++;
    }
    c=first;
    while(c->next!=NULL&&i!=pos+1)
    {
        prev=c;
        c=c->next;
        i++;
    }
    c=c->next;
    prev->next=c;
    return first;
}

