#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
typedef struct node Node;
Node* create_node();
Node* insert_front(Node *head);
Node* insert_end(Node *head);
void display(Node *head);
Node* delete_front(Node *head);
Node* delete_end(Node *head);
int main()
{
    Node *head=NULL;
    int choice,cnt;
    while(1)
    {
        printf("Enter choice\n");
        printf(" 1.Insert front\n 2.Insert end\n 3.Delete front\n 4.Delete end\n 5.Display\n 6.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=insert_front(head);
            break;
            case 2:head=insert_end(head);
            break;
            case 3:head=delete_front(head);
            break;
            case 4:head=delete_end(head);
            break;
            case 5:display(head);
            break;
            case 6:printf("Thank you");
            exit(0);
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
    n1->link=NULL;
    return n1;
}
Node* insert_front(Node *head)
{
    Node *temp,*p;
    temp=create_node();
    if(head==NULL)
    {
        head=temp;
        temp->link=temp;
    }
    else
    {
        p=head;
        while(p->link!=head)
        {
            p=p->link;
        }
        p->link=temp;
        temp->link=head;
        head=temp;
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
       while(temp->link!=head)
       {
           printf(" %d ",temp->data);
           temp=temp->link;
       }
       printf(" %d ",temp->data);
       printf("\n");
    }
}
Node* delete_front(Node *head)
{
    Node *temp,*p;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else if(temp->link==head)
    {
        head=NULL;
        printf("Deleted %d",temp->data);
        temp->link=NULL;
        free(temp);
    }
    else
        {
            p=head;
            while(p->link!=head)
            {
                p=p->link;
            }
           head=p->link=temp->link;
           printf("Deleted %d\n",temp->data);
           temp->link=NULL;
           free(temp);
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
        temp->link=head;
    }
    else
        {
            p=head;
            while(p->link!=head)
            {
                p=p->link;
            }
            p->link=temp;
            temp->link=head;
        }
    return head;
}
Node* delete_end(Node *head)
{
    Node *temp,*p;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty");
    }
    else if(temp->link==head)
    {
        head=NULL;
        printf("Deleted %d\n",temp->data);
        temp->link=NULL;
        free(temp);
    }
    else
    {
        while(temp->link!=head)
        {
            p=temp;
            temp=temp->link;
        }
        p->link=head;
        temp->link=NULL;
        printf("Deleted %d\n",temp->data);
        free(temp);
    }
    return head;
}

