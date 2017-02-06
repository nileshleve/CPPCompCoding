#include <bits/stdc++.h>
 
using namespace std;

typedef struct node{
  int from[200000];
  int to[200000];
}fans;


// A class that represents an undirected graph
class Graph
{
  int V;    // No. of vertices
  list<int> *adj;    // A dynamic array of adjacency lists
public:
  fans answer;
  int answerctr = 0;
    // Constructor and destructor
  Graph(int V)  { this->V = V;  adj = new list<int>[V];  }
  ~Graph()      { delete [] adj;  }
 
  // functions to add and remove edge
  void addEdge(int u, int v) {  adj[u].push_back(v); adj[v].push_back(u); }
  void rmvEdge(int u, int v);
  fans getAnswer(){
    return answer;
  }
 
  // Methods to print Eulerian tour
  void printEulerTour();
  void printEulerUtil(int s);
  int isEulerian();
  bool isConnected();
  void DFSUtil(int v, bool visited[]);
 
  // This function returns count of vertices reachable from v. It does DFS
  int DFSCount(int v, bool visited[]);
 
  // Utility function to check if edge u-v is a valid next edge in
  // Eulerian trail or circuit
  bool isValidNextEdge(int u, int v);
};


void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool Graph::isConnected()
{
    // Mark all the vertices as not visited
    bool visited[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;
 
    // Find a vertex with non-zero degree
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;
 
    // If there are no edges in the graph, return true
    if (i == V)
        return true;
 
    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);
 
    // Check if all non-zero degree vertices are visited
    for (i = 0; i < V; i++)
       if (visited[i] == false && adj[i].size() > 0)
            return false;
 
    return true;
}

/* The function returns one of the following values
   0 --> If grpah is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;
 
    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;
 
    // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;
 
    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)? 1 : 2;
}


// Function to run test cases
int test(Graph &g)
{
    int res = g.isEulerian();
    return res;
    // if (res == 0){
    //     cout << "graph is not Eulerian\n";
    //     return 0;
    //   }
    // else if (res == 1){
    //     cout << "graph has a Euler path\n";
    //     return 1;
    //   }

    // else{
    //     //cout << "graph has a Euler cycle\n";
    //   return 2;
    //   }
}

 
/* The main function that print Eulerian Trail. It first finds an odd
   degree vertex (if there is any) and then calls printEulerUtil()
   to print the path */
void Graph::printEulerTour()
{
  // Find a vertex with odd degree
  int u = 0;
  for (int i = 0; i < V; i++)
      if (adj[i].size() & 1)
        {   u = i; break;  }
 
  // Print tour starting from oddv
  printEulerUtil(u);
  cout << endl;
}
 
// Print Euler tour starting from vertex u
void Graph::printEulerUtil(int u)
{
  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
  {
      int v = *i;
 
      // If edge u-v is not removed and it's a a valid next edge
      if (v != -1 && isValidNextEdge(u, v))
      {
          //cout << u+1 << " " << v+1 << "\n";
          answer.from[answerctr] = u+1;
          answer.to[answerctr++] = v+1;
          rmvEdge(u, v);
          printEulerUtil(v);
      }
  }
}
 
// The function to check if edge u-v can be considered as next edge in
// Euler Tout
bool Graph::isValidNextEdge(int u, int v)
{
  // The edge u-v is valid in one of the following two cases:
 
  // 1) If v is the only adjacent vertex of u
  int count = 0;  // To store count of adjacent vertices
  list<int>::iterator i;
  for (i = adj[u].begin(); i != adj[u].end(); ++i)
     if (*i != -1)
        count++;
  if (count == 1)
    return true;
 
 
  // 2) If there are multiple adjacents, then u-v is not a bridge
  // Do following steps to check if u-v is a bridge
 
  // 2.a) count of vertices reachable from u
  bool visited[V];
  memset(visited, false, V);
  int count1 = DFSCount(u, visited);
 
  // 2.b) Remove edge (u, v) and after removing the edge, count
  // vertices reachable from u
  rmvEdge(u, v);
  memset(visited, false, V);
  int count2 = DFSCount(u, visited);
 
  // 2.c) Add the edge back to the graph
  addEdge(u, v);
 
  // 2.d) If count1 is greater, then edge (u, v) is a bridge
  return (count1 > count2)? false: true;
}
 
// This function removes edge u-v from graph.  It removes the edge by
// replacing adjcent vertex value with -1.
void Graph::rmvEdge(int u, int v)
{
  // Find v in adjacency list of u and replace it with -1
  list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
  *iv = -1;
 
  // Find u in adjacency list of v and replace it with -1
  list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
  *iu = -1;
}
 
// A DFS based function to count reachable vertices from v
int Graph::DFSCount(int v, bool visited[])
{
  // Mark the current node as visited
  visited[v] = true;
  int count = 1;
 
  // Recur for all vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (*i != -1 && !visited[*i])
          count += DFSCount(*i, visited);
 
  return count;
}
 
int main(int argc, char const *argv[])
{
	int n, e;
	cin>>n>>e;
	int a, b;
	Graph g1(n);
    int from[e];
    int to[e];
	for (int i = 0; i < e; ++i)
	{
		cin>>a;
		cin>>b;
        from[i] = a;
        to[i]  = b;
		g1.addEdge(a-1, b-1);
	}
  int finalans = test(g1);
  if(finalans != 2)
    cout<<"NO"<<endl;
  else{
    cout<<"YES";
    g1.printEulerTour();
    fans answer = g1.getAnswer();
    int checker = 0;
    for (int i = 0; i < e; ++i)
    {
      for (int j = 0; j < e; ++j)
      {
        if(from[i] == answer.from[j] && to[i] == answer.to[j]){
          cout<<from[i]<<" "<<to[i]<<endl;
          answer.from[j] = answer.to[j] = INT_MIN;
          checker = 1;
          break;
        }
      }
      if(checker != 1){
        for (int j = 0; j < e; ++j)
        {
          if(from[i] == answer.to[j] && to[i] == answer.from[j]){
            cout<<to[i]<<" "<<from[i]<<endl;
            answer.from[j] = answer.to[j] = INT_MIN;
            checker = 1;
            break;
          }
        }
      }
      checker = 0;

    }
  }
	return 0;
} 