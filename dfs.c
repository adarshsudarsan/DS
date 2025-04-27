#include<stdio.h>
#include<stdlib.h>
int graph[10][10],visited[10]={0},stack[20],total;
int k=0,count=0;
void DFS(int start)
{
 int i,flag=0;
 count++;
 printf("%d\t",start);
 visited[start]=1;
 for(i=0;i<total;i++)
 {
  if(!visited[i] && graph[start][i]==1)
  {
  stack[++k]=i;
  flag=1;
  }
 if(count==total)
 exit(0);
 }
 if(flag==1)
 DFS(stack[k]);
 else
 k--;
 DFS(stack[k]);
}
int main()
{
  int i,j;
 printf("Enter the total number of vertices in graph : ");
 scanf("%d",&total);
 printf("Enter the adjanency matrix :\n");
 for(i=0;i<total;i++)
 {
  for(j=0;j<total;j++)
  {
  scanf("%d",&graph[i][j]);
  }
 }
 printf("depth first traversal : ");
 DFS(0);
 return 0;
}  
