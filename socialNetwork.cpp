#include <bits/stdc++.h>
using namespace std;

typedef struct graph
{
	int V;
	int E;
	int **adj; 
} graph;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int temp;
		graph *G = (struct graph*)malloc(sizeof(struct graph));
		cin>>G->V;
		G->adj = malloc(sizeof((G->V) * (G->V)));
		for (int i = 0; i < G->V; ++i)
		{
			for (int j = 0; j < G->V; ++j)
			{
				G->adj[i][j] = 0;
			}
		}
		
		for(int i = 1; i < G->V; i++){
			cin>>temp;
			G->adj[i][temp] = 1;
		}

		
	}
	return 0;
}