 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <bits/stdc++.h>

using namespace std;
 
struct answers{
	int src;
	int dest;
	int latency;
};

struct answers ans[100000];
int ctr = 0;

bool structsort(struct answers a, struct answers b){
	if(a.latency > b.latency)
		return true;
	else
		return false;
}


struct Edge
{
    int src, dest, weight;
};
 
struct Graph
{
    int V, E;
 
    
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
struct subset
{
    int parent;
    int rank;
};
 

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 

int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];  
    int e = 0;  
    int i = 0;  
 
    
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    while (e < V - 1)
    {
        
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
 
    
    for (i = 0; i < e; ++i){
        ans[ctr].src = result[i].src;
        ans[ctr].dest = result[i].dest;
        ans[ctr++].latency = result[i].weight;
    }
    return;
}
 
int main()
{
    
 
 	int n,m;
    cin>>n;
    

    cin>>m;
    struct Graph* graph = createGraph(n, m);
    int i1,i2,i3;
    for(int i = 0; i < m; i++){
    	cin>>i1;
    	cin>>i2;
    	cin>>i3;
    	graph->edge[i].src = i1-1;
    	graph->edge[i].dest = i2-1;
    	graph->edge[i].weight = i3;
    }

 
    KruskalMST(graph);

    int q;
    cin>>q;
    int arr[q];
    for(int i = 0; i < q; i++){
    	cin>>arr[i];
    }
    sort(arr, arr + q);
    int cables = 0;
 	sort(ans, ans+ctr, structsort);
 	for (int i = 0; i < ctr && cables < (q - 1); ++i)
 	{
 		if(ans[i].latency > arr[cables]){
 			ans[i].latency = arr[cables++];
 		}
 	}
 	int finalans = 0;
 	for (int i = 0; i < ctr; ++i)
 	{
 		finalans += ans[i].latency;
 	}

 	cout<<finalans<<endl;
 
    return 0;
}
