#include<stdio.h>
void heapify(int a[],int n,int i);
void heapsort(int a[],int n);
void display(int a[],int size);
void main()
{
 int a[10],size,i;
 printf("Enter the size : ");
 scanf("%d",&size);
 printf("Enter the elements : ");
 for(i=0;i<size;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Elements before sorting : ");
 display(a,size);
 heapsort(a,size);
 printf("\nElements after sorting : ");
 display(a,size);
}
void heapify(int a[],int n,int i)
{
 int largest=i;
 int left=2*i+1;
 int right=2*i+2;
 if(left<n && a[left]>a[largest])
 {
  largest=left;
 }
 if(right<n && a[right]>a[largest])
 {
  largest=right;
 }
 if(largest!=i)
 {
  int temp=a[i];
  a[i]=a[largest];
  a[largest]=temp;
  heapify(a,n,largest);
 }
}
void display(int a[],int size)
{
 int i;
 for(i=0;i<size;i++)
 {
  printf("%d ",a[i]);
 }
}
void heapsort(int a[],int n)
{
 int i;
 for(i=(n/2)-1;i>=0;i--)
 {
  heapify(a,n,i);
 }
 for(i=n-1;i>=0;i--)
 {
  int temp=a[0];
  a[0]=a[i];
  a[i]=temp;
  heapify(a,i,0);
 }
}
