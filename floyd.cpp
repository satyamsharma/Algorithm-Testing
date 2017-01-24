

// C Program for Floyd Warshall Algorithm
#include<stdio.h>
 
// Number of vertices in the graph
#define V 3     // 4
 
/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 99999
 
// A function to print the solution matrix
void printSolution(int dist[][V]);
 
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall (int graph[][V])
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    int dist[V][V], i, j, k;
 
    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
    printSolution(dist);
}
 
/* A utility function to print solution */
void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
/*    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
*/
                      
    int myGraph[V][V] = { {  0,   3,   1},
                          {INF,  0, INF},
                          {INF,  1,  0}
    };
 
    // Print the solution
    floydWarshall(myGraph);
    return 0;
}





/*
#include <stdio.h>
#include <algorithm>

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

void floyd(int n, const int W[][n], int D[][n])
{
    int i, j, k;
    D = W;
    
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                D[i][j] = minimum(D[i][j], D[i][k] + D[k][j]);
}

void floyd2(int n, const int W[n][n], int D[n][n], int P[n][n])
{
    int i, j, k;
    
    for(i = 0; i < n; i++)
        for(j = 1; j <= n; j++)
            P[i][j] = 0;
        
    D = W;
    
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                D[i][j] = minimum(D[i][j], D[i][k] + D[k][j]);
}

void path (int q, int r)
{
    if(P[q][r] != 0)
    {
        path(q, path[q][r]);
        cout << "v" << P[q][r];
        path(q, path[q][r]);
                                                                                                                                                                                                                                                                                                                                        ][])
    }
}
*/