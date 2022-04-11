#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
};
void insertatbegining(struct Node ** head,int new_data)
{
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data= new_data ;
new_node->next = (*head);
(*head) = new_node;

}
void insertatend(struct Node **head,int new_data)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    new_node->data= new_data;
    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
}
void deleteNode(struct Node **head,int key)
{
    struct Node *temp = *head,*prev;
    if(temp!=NULL && temp->data == key )
    {
        *head=temp->next;
        free(temp);
        return ;
    }
    while(temp!=NULL && temp->data !=key)
    {
        prev =temp ;
        temp= temp->next;
    }
    if(temp==NULL)
    {
        return ;
    }
    prev->next=temp->next;
    free(temp);
}
bool searchnode(struct Node** head,int key)
{
    struct Node* current = *head;
    while(current !=NULL)
    {
        if(current->data == key)return true;
        current=current->next;
    }
    return false;
}
void sortLinkedList(struct Node **head)
{
    struct Node *current =*head, *index =NULL;
    int temp;
    if(head==NULL)
    {
        return;
    }
    else {
    while(current!=NULL)
    {
        index=current->next;
        while(index!=NULL)
        {
            if(current->data > index->data)
            {
                temp=current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
       current = current->next;
    }
}
}
void printlist(struct Node *node)
{
    while(node!=NULL)
    {
      cout<<node->data<<" ";
      node=node->next;
    }
}
int main()
{
    struct Node* head =NULL;
    insertatend(&head,5);
    insertatbegining(&head,6);
      insertatbegining(&head,8);
     insertatbegining(&head,3);
    insertatend(&head,7);
    cout << "Linked list: ";
  printlist(head);

  cout << "\nAfter deleting an element: ";
  deleteNode(&head, 3);
  printlist(head);
  int item_to_find = 3;
  if (searchnode(&head, item_to_find)) {
  cout << endl << item_to_find << " is found";
  } else {
  cout << endl << item_to_find << " is not found";
  }

  sortLinkedList(&head);
  cout << "\nSorted List: ";
  printlist(head);

}
