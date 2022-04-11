#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node *nlink,*plink;
};
typedef struct node Node;
Node* create_node();
Node* insert_front(Node *head);
Node* insert_end(Node *head);
void display(Node *head);
Node* delete_front(Node *head);
Node* delete_end(Node *head);
void revdisplay(Node *head);
int count(Node *head);
Node* insert_position(Node *head);
Node* delete_position(Node *head);
void average(Node *head);
void search(Node *head);
void highest(Node *head);
void lowest(Node *head);
//Node *delete_key(Node *head);
int main()
{
    Node *head=NULL;
    int choice,cnt;
    while(1)
    {
        printf("Enter choice\n");
        printf("1.Insert front\n2.Insert position\n3.Insert end\n4.Delete front\n5.Delete position\n6.Delete end\n7.Display\n");
        printf("8.Average\n9.Count\n10.Exit\n12.Display reverse\n14.Search\n15.Highest\n16.Lowest\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=insert_front(head);
            break;
            case 2:head=insert_position(head);
            break;
            case 3:head=insert_end(head);
            break;
            case 4:head=delete_front(head);
            break;
            case 5:head=delete_position(head);
            break;
            case 6:head=delete_end(head);
            break;
            case 7:display(head);
            break;
            case 8:average(head);
            break;
            case 9:cnt=count(head);
            printf("Count=%d\n",cnt);
            break;
            case 10:printf("Thank you");
            exit(0);
            case 12:revdisplay(head);
            break;
            case 14:search(head);
            break;
            case 15:highest(head);
            break;
            case 16:lowest(head);
            break;
            //case 17:head=delete_key(head);
            //break;
            default:printf("Invalid input\n");
            break;
        }
    }
    return 0;
}
Node* create_node()
{
    Node *n1;
    n1=(Node*)malloc(sizeof(Node));
    if(n1==NULL)
    {
        printf("Could not allocate memory\n");
        exit(0);
    }
    printf("Enter the number:");
    scanf("%d",&n1->data);
    n1->nlink=NULL;
    n1->plink=NULL;
    return n1;
}
Node* insert_front(Node *head)
{
    Node *temp;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->nlink=head;
        head->plink=temp;
        head=temp;
    }
    return head;
}
Node* delete_front(Node *head)
{
    Node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else if(temp->nlink==NULL)
    {
        head=NULL;
        printf("Deleted %d\n",temp->data);
        free(temp);
    }
    else
        {
           head=temp->nlink;
           printf("Deleted %d\n",temp->data);
           temp->nlink=NULL;
           head->plink=NULL;
           free(temp);
        }
    return head;
}
void display(Node *head)
{
    Node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->nlink;
        }
        printf("\n");
    }
}
void revdisplay(Node *head)
{
     Node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp->nlink!=NULL)
        {
            temp=temp->nlink;
        }
            while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->plink;
            }
        printf("\n");
    }
}
int count(Node *head)
{
    Node *temp;
    int cnt=0;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->nlink;
        }
    }
    return cnt;
}

Node *insert_position(Node *head)
{
    Node *temp,*p;
    int pos,cnt,i=1;
    temp=create_node();
    printf("Enter position:");
    scanf("%d",&pos);
    if(head==NULL && pos==1)
    {
        head=temp;
    }
    else if(pos==1)
    {
        temp->nlink=head;
        head->plink=temp;
        head=temp;
    }
    else
    {
        cnt=count(head);
        if(pos>=cnt+2 || pos<=0)
        {
            printf("Invalid input\n");
        }
        else
        {
            p=head;
            while(i<pos-1)
            {
                p=p->nlink;
                i++;
            }
            if(p->nlink==NULL)
            {
                p->nlink=temp;
                temp->plink=p;
            }
            else
            {
                temp->nlink=p->nlink;
                p->nlink->plink=temp;
                p->nlink=temp;
                temp->plink=p;
            }
        }
    }
    return head;
}
Node* delete_position(Node *head)
{
    Node *temp,*p;
    int pos,cnt,i=1;
    temp=head;
    printf("Enter position:");
    scanf("%d",&pos);
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else if(pos==1)
    {
       head=temp->nlink;
       if(head!=NULL)
       {
           head->plink=NULL;
       }
       temp->nlink=NULL;
       printf("Deleted %d\n",temp->data);
       free(temp);
    }
    else
    {
        cnt=count(head);
        if(pos>cnt || pos<=0)
        {
            printf("Invalid input\n");
        }
        else
        {
            p=head;
            while(i<pos-1)
            {
                p=p->nlink;
                i++;
            }
            temp=p->nlink;
            if(pos==cnt)
            {
                p->nlink=temp->plink=NULL;
                 printf("Deleted %d\n",temp->data);
                 free(temp);
            }
            else
            {
                temp->nlink->plink=p;
                p->nlink=temp->nlink;
                temp->nlink=temp->plink=NULL;
                 printf("Deleted %d\n",temp->data);
                 free(temp);
            }
        }
    }
    return head;
}
Node* insert_end(Node *head)
{
    Node *temp,*p;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        p=head;
        while(p->nlink!=NULL)
        {
            p=p->nlink;
        }
        p->nlink=temp;
        temp->plink=p;
        temp->nlink=NULL;
    }
    return head;
}
Node* delete_end(Node *head)
{
    Node *temp,*p;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else if(temp->nlink==NULL)
    {
        head=NULL;
        printf("Deleted %d\n",temp->data);
        free(temp);
    }
    else
    {
        while(temp->nlink!=NULL)
        {
            p=temp;
            temp=temp->nlink;
        }
        p->nlink=NULL;
        temp->plink=NULL;
        printf("Deleted %d\n",temp->data);
        free(temp);
    }
    return head;
}
void search(Node *head)
{
     Node *temp;
    int flag=0,key,i=0;
    temp=head;
    printf("Enter the key to be searched:");
    scanf("%d",&key);
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
       while(temp!=NULL)
        {
            if(temp->data==key)
            {
                printf("Item found at location %d\n",i+1);
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            temp=temp->nlink;
        }
        if(flag==0)
        {
            printf("Item not found\n");
        }
    }
}
void highest(Node *head)
{
    Node *temp,*test;

    int h;
    temp=head;
    h=INT_MIN;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data>h)
             {
                 h=temp->data;
                 test=temp;
             }
        temp=temp->nlink;
        }
        printf("Highest data:%d\n",test->data);
    }
}
void lowest(Node *head)
{
    Node *temp,*test;
    int l;
    temp=head;
    l=INT_MAX;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data<l)
             {
                 l=temp->data;
                 test=temp;
             }
        temp=temp->nlink;
        }
        printf("Lowest data:%d\n",test->data);
    }
}
void average(Node *head)
{
    Node *temp;
    temp=head;
    float avg;
    int sum=0,cnt;
    cnt=count(head);
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            sum=sum+temp->data;
            temp=temp->nlink;
        }
         avg=(float)sum/cnt;
         printf("Average=%f\n",avg);
    }
}
