#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0 , rear = -1;

void bfs(int start,int vertex)
{
    visited[start] = 1;
    rear ++;
    queue [rear] = start;
    printf("BFS Traversal : ");
    
    while(front <= rear)
    {
        int Currentvertex = queue[front];
        front++;
        printf("%d ",Currentvertex);
        for(int i =0;i<vertex;i++)
        {
            if(adjMatrix[Currentvertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                rear++;
                queue[rear] = i;
            }
        }
    }
    printf("\n");
}

void main()
{
    int ver,edges,start,end,startVertex;
    printf("Enter the number of vertices : ");
    scanf("%d",&ver);
    printf("Enter the number of edges : ");
    scanf("%d",&edges);
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
    
    printf("Enter the edges(start end) : ");
    for(int i = 0; i < edges ; i++)
    {
        scanf("%d%d",&start,&end);
        adjMatrix[start][end] = 1;
    }
    
    printf("Enter the starting vertex for traversal :");
    scanf("%d",&startVertex);
    bfs(startVertex,ver);
}