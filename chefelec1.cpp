
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>





// Number of vertices in the graph
#define V 5
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int nvillage)
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < nvillage; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V],int nvillage)
{
   printf("Edge   Weight\n");
   for (int i = 1; i < nvillage; i++)
      
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V],int nvillage)
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < nvillage; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     printMST(parent, V, graph,nvillage);
}























// //#include <cmath.h>

// //using namespace std;
 

// struct Edge
// {
//     int src, dest, weight;
// };
 

// struct Graph
// {
    
//     int V, E;
 
    
//     struct Edge* edge;
// };
 

// struct Graph* createGraph(int V, int E)
// {
//     struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
//     graph->V = V;
//     graph->E = E;
 
//     graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
//     return graph;
// }
//  struct subset
// {
//     int parent;
//     int rank;
// };
 

// int find(struct subset subsets[], int i)
// {
    
//     if (subsets[i].parent != i)
//         subsets[i].parent = find(subsets, subsets[i].parent);
 
//     return subsets[i].parent;
// }
 

// void Union(struct subset subsets[], int x, int y)
// {
//     int xroot = find(subsets, x);
//     int yroot = find(subsets, y);
 
    
//     if (subsets[xroot].rank < subsets[yroot].rank)
//         subsets[xroot].parent = yroot;
//     else if (subsets[xroot].rank > subsets[yroot].rank)
//         subsets[yroot].parent = xroot;
 
    
//     else
//     {
//         subsets[yroot].parent = xroot;
//         subsets[xroot].rank++;
//     }
// }
 

// int myComp(const void* a, const void* b)
// {
//     struct Edge* a1 = (struct Edge*)a;
//     struct Edge* b1 = (struct Edge*)b;
//     return a1->weight > b1->weight;
// }
 

// void KruskalMST(struct Graph* graph)
// {
//     int ans = 0;
//     int V = graph->V;
//     struct Edge result[V];  // Tnis will store the resultant MST
//     int e = 0;  // An index variable, used for result[]
//     int i = 0;  // An index variable, used for sorted edges
 
    
//     qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    
//     struct subset *subsets =
//         (struct subset*) malloc( V * sizeof(struct subset) );
 
    
//     for (int v = 0; v < V; ++v)
//     {
//         subsets[v].parent = v;
//         subsets[v].rank = 0;
//     }
 
    
//     while (e < V - 1)
//     {
        
//         struct Edge next_edge = graph->edge[i++];
 
//         int x = find(subsets, next_edge.src);
//         int y = find(subsets, next_edge.dest);
 
        
//         if (x != y)
//         {
//             result[e++] = next_edge;
//             Union(subsets, x, y);
//         }
        
//     }
 
    
//     for (i = 0; i < e; ++i){
//         ans+=result[i].weight;
        
//     }
//     printf("%d\n",ans);
//     return;
// }





// Driver program to test above functions
int main()
{
    
    
   int t,nvillage,number;
   
   int i=0;
   int j=0;
   int k=0;
   int E,V;
    scanf("%d",&t);

    while(t--){
        
        int noofzeroes,count;
        int evillage[100000];
        int cvillage[100000];
        count=0;
        noofzeroes = 0;
        k=0;
        i=0;j=0;
        E=V=0;

        scanf("%d",&nvillage);
        i = nvillage;
        scanf("%d",&number);


        //i = nvillage;
            //number = Integer.parseInt(dis.readLine());
        while (number > 0 && i-- > 0) {
            evillage[i] = number % 10;
            number = number / 10;
        }


        // for(i=0;i<nvillage;i++){
        //     printf("%d \t",evillage[i]);
        // }



        //i = nvillage;
        for(i=0;i<nvillage;i++){
            if(evillage[i]==0){
                noofzeroes+=1;
            }
        }
        

        //printf("zeroes= %d \n",noofzeroes);

        for(i=0;i<nvillage-1;i++){
            if((evillage[i]==0 && evillage[i+1]==1) || (evillage[i]==1 && evillage[i+1]==0)){
                count+=1;
            }
        }

        for(i=0;i<nvillage-1;i++){
            
            if(evillage[i]==0){

                for(j=i+1;j<nvillage;j++){
                   
                    if(evillage[j]==0){
                        count++;
                    }
                    else{
                        i = j;
                        break;

                    }
                }    
            }
        }
                //printf("count after 0000 s = %d \n",count);


        // E = (count + (nvillage - noofzeroes - 1));
        // V = nvillage;
        // struct Graph* graph = createGraph(V, E);
     
        int matrix[nvillage][nvillage];
    
        i = 0;
        while(i < nvillage){
            scanf("%d",&cvillage[i++]);
        }


        for(i=0;i<nvillage-1;i+=0){             //for connecting all 1's
            if(evillage[i]==1){
                for(j=i+1;j<nvillage;j++){
                    if(evillage[j]==1){
                        graph->edge[k].src = i;
                        graph->edge[k].dest = j;
                        graph->edge[k].weight = 0;
                        i = j; 
                        k++;
                        break;
                    }
                }
            }
        }



        for(i=0;i<nvillage-1;i++){              //for connecting all 0's
            
            if(evillage[i]==0){

                for(j=i+1;j<nvillage;j++){
                   
                    if(evillage[j]==0){
                        graph->edge[k].src = i;
                        graph->edge[k].dest = j;
                        graph->edge[k++].weight = cvillage[j]-cvillage[i];
                        i = j;

                    }
                    else{
                        i = j;
                        break;

                    }
                }    
            }
        }


        for(i=0;i<nvillage-1;i++){
            if((evillage[i]==0 && evillage[i+1]==1) || (evillage[i]==1 && evillage[i+1]==0)){
                graph->edge[k].src = i;
                graph->edge[k].dest = i+1;
                graph->edge[k++].weight = cvillage[i+1]-cvillage[i];
                
            }
        }

       
        int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
        // Print the solution
        primMST(graph,nvillage);
 
    





        // KruskalMST(graph);
        
    
    }
   
    return 0;
}


