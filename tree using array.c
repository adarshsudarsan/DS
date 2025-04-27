#include<stdio.h>
#define size 100
void create(int[],int,int);
void inorder(int[],int);
void preorder(int[],int);
void postorder(int[],int);
void main()
{
 int no[size];
 int i,data,a,index;
 for(i=1;i<size;i++)
 {
  no[i]=-1;
 }
 do
  {
  printf("\n Enter the value");
  scanf("%d",&data);
  create(no,data,1);
  printf("\n continue?(1/0)");
  scanf("%d",&a);
  }
  while(a==1);
  printf("\n inorder: ");inorder(no,1);
  printf("\n preorder: ");preorder(no,1);
  printf("\n postorder: ");postorder(no,1);
}
void create(int no[],int data,int index)
{
 if(index==size)
 printf("\nSpace not availabe");
 else if(no[index]==-1)
 no[index]=data;
 else if(data<no[index])
 create(no,data,index*2);
 else
 create(no,data,(index*2)+1);
}
void inorder(int no[],int index)
 {
 if(no[index]!=-1)
  {
  inorder(no,index*2);
  printf("%d\t",no[index]);
  inorder(no,(index*2)+1);
  }
 }   
void preorder(int no[],int index)
 {
 if(no[index]!=-1)
  {
  printf("%d\t",no[index]);
  preorder(no,index*2);
  preorder(no,(index*2)+1);
  }
 }
void postorder(int no[],int index)
 {
 if(no[index]!=-1)
  {
  postorder(no,index*2);
  postorder(no,(index*2)+1);
  printf("%d\t",no[index]);
  }
 }
