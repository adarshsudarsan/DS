#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};struct node *tree,*root,*parent,*temp,*node,*c;
void inorder(struct node *tree);
void preorder(struct node *tree);
void postorder(struct node *tree);
struct node *insert(struct node *tree,int data);
struct node *minvalues(struct node *node);
struct node *delnode(struct node *tree,int data);
void main()
{
int n,ch,a;
do
{
printf("\t\t\tMENU\n1:insert\n2:delete\n3:inorder\n4:preorder\n5:postorder\n");
printf("enter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:printf("\nenter the element:");
       scanf("%d",&n);
       root=insert(root,n);
       break;
case 2:printf("\nenter the element:");
       scanf("%d",&n);
       root=delnode(root,n);
       break;
case 3:printf("\nTree:");
       inorder(root);
       break;
case 4:printf("\nTree:");
       preorder(root);
       break;
case 5:printf("\nTree:");
       postorder(root);
       break;
default:printf("\nInvalid entery");
}
printf("\nExit(1/0):");
scanf("%d",&a);
}while(a!=0);
}
struct node *minvalues(struct node *node)
{
struct node *c=node;
while(c->left!=NULL)
{
c=c->left;
return c;
}
}
struct node *delnode(struct node *tree,int data)
{
if(tree==NULL)
{
return tree;
}
else if(data<tree->data)
{
tree->left=delnode(tree->left,data);
}
else if(data>tree->data)
{
tree->right=delnode(tree->right,data);
}
else
{
if(tree->left==NULL)
{
struct node *temp=tree->right;
free(tree);
return temp;
}
else if(tree->right==NULL)
{
struct node *temp=tree->left;
free(tree);
return temp;
}
struct node *temp=minvalues(tree->right);
tree->data=temp->data;
tree->right=delnode(tree->right,tree->data);
}
return tree;
}
//inorder
void inorder(struct node *tree)
{
if(tree!=NULL)
{
inorder(tree->left);
printf("%d\t",tree->data);
inorder(tree->right);
}
}
//pretorder
void preorder(struct node *tree)
{
if(tree!=NULL)
{
printf("%d\t",tree->data);
preorder(tree->left);
preorder(tree->right);
}
}
//postorder
void postorder(struct node *tree)
{
if(tree!=NULL)
{
postorder(tree->left);
postorder(tree->right);
printf("%d\t",tree->data);
}
}
struct node *insert(struct node *tree,int data)
{
if(tree==NULL)
{
tree=(struct node *)malloc(sizeof(struct node));
tree->data=data;
tree->right=NULL;
tree->left=NULL;
return tree;
}
else if(tree->data>data)
{
tree->left=insert(tree->left,data);
return tree;
}
else if(tree->data<data)
{
tree->right=insert(tree->right,data);
return tree;
}
}
