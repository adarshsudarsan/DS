#include<stdio.h>
int graph[10][10],visited[10],total;
void BFS(int start)
{
 int i;
 printf("%d",start);
 visited[start]=1;
 for(i=0;i<total;i++)
 {
  if(!visited[i]&&graph[start][i]==1)
  {
   BFS(i);
  }
 }
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
 printf("Breadth first traversal : ");
 BFS(0);
 return 0;
}  
