#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left;
struct node*right;
};
struct node*createNode(int value)
{
struct node*newNode;
newNode=(struct node*)malloc(sizeof(struct node));
newNode->data=value;
newNode->left=NULL;
newNode->right=NULL;
return newNode;
}
struct node*insert(struct node*root,int value)
{
if(root==NULl)
return createNode(value);
if(value<root->data)
root->right=insert(root->left,value);
else if(value>root->data)
root->right=insert(root->right,value);
else
printf("Duplicate elements are not allowed.\n");
return root;
}
void inorder(struct node*root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d",root->right);
void preorder(struct node*root)
{
if(root!=NULL)
{
printf("%d",root->data);
preorder(root->left);
preorder(root->right);
}
}
void postorder(struct node*root)
{
if(root!=NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d",rooot->data);
}
}
struct node*findMin(struct node*root,int value)
{
struct node*temp;
if(root==NULL)
{
printf("Element not found!\n");
return NULL;
}
if(value<root->data)
root->left=deleteNode(root->left,value);
else if(value>root->data)
root->right=deleteNode(root->right,value);
else
{
if(root->left==NULL&&root->right==NULL)
{
free(root);
return NULL;
}
else if(root->left==NULL)
{
temp=root->right;
free(root);
}
else
{
temp=findMin(root->right);
root->data=temp->data;
root->right=deleteNode(root->right,temp->data);
}
}
return root;
}
int main()
{ struct node*root=NULL;
int choice,value;
do
{
printf("\n------BINARY SEARCH TREE---------\n");
printf("1.insert\n");
printf("2.inorder Traversal\n");
printf("3.preorder Traversal\n");
printf("4.postorder Traversal\n");
printf("5.Delete a Node\n");
printf("6.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Eneter value to insert:");
scanf("%d",&value);
root=insert(root,value);
break;
case 2:
printf("inorder Traversal:");
inorder(root);
printf("\n");
break;
case 3:
printf("preorder Traversal:");
preorder(root);
printf("\n");
break;
case 4:
printf("postorder Traversal:");
postorder(root);
printf("\n");
break;
case 5:
printf("Enter value to delete:");
scanf("%d",&value);
root=deleteNode(root,value);
break;
case 6:
printf("Exiting program......\n");
break;
default:
printf("invalid chooice!\n");
}
}
while(choice!=6)
return 0;
}




