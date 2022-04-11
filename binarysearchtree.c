#include<stdio.h>
#include<stdlib.h>
struct node 
{
int key;
struct node *left,*right;
};
struct node *createnew(int item)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root,int key)
{
    if(root == NULL) return createnew(key);

    if(key < root->key)
        root->left = insert(root->left,key);
    else
    root->right = insert(root->right,key);
    return root;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
    }
}
struct node *minvalue(struct node *root)
{
    struct node *current=root;
    while(current && current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}
int search(struct node* root,int key)
{
    struct node *current=root;
    printf("path of the element");
    while(current->key !=key)
    {
        if(current!=NULL)
        {
            printf("%d-> ",current->key);
        
        if(key > current->key)
        {
            current=current->right;
        }
        else
        {
            current=current->left;
        }
        if(current == NULL)
        {
            return 0;
        }
      }
    }

    return 1;
}
struct node *delete(struct node *root,int key)
{
    if(root==NULL)
    return root;
    if(key>root->key)
    {
        root->right=delete(root->right,key);
    }
    else if(key < root->key)
    {
     root->left=delete(root->left,key); 
    }
    else
    {
    if(root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minvalue(root->right);
        root->key = temp->key;
        root->right = delete(root->right,temp->key);

    }
return root;
}
int main()
{
 struct node *root=NULL;
 int n, ch;
 while(1)
 {
     printf("\n enter\n1:insert\n2:delete \n3:search \n4:display inorder \n5:exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
    case 1:
         printf("enter element to be inserted :");
         scanf("%d",&n);
         root = insert(root,n);
         break;
    case 2:
         printf("enter the number to be deleted :");
         scanf("%d",&n);
         root=delete(root,n);
         break;
    case 3: 
         printf("enter number to be searched");
         scanf("%d",&n);
         if(search(root,n))
         printf("\nelement is found ");
         else
         printf("element not found");
         break;
    case 4:
         inorder(root);
         break;
    case 5:
         exit(1);
         break;
    default:
         printf("enter correct choice\n");
         break;

     }
 }

}





