#include <iostream>
#include <queue>

using namespace std;


bool isBipartite(int G[][1000], int V, int source, int visited[])
{
    int arr[V];
    for (int i = 0; i < V; ++i)
        arr[i] = -1;
 
    arr[source] = 1;
 
    
    queue <int> Que;
    Que.push(source);
 
    while (!Que.empty())
    {
        int u = Que.front();
        visited[u] = 1;
        Que.pop();
 
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && arr[v] == -1)
            {
                arr[v] = 1 - arr[u];
                Que.push(v);
            }
 
            else if (G[u][v] && arr[v] == arr[u])
                return false;
        }
    }
 
    return true;
}
 
int main()
{
    int t;
    cin>>t;
    while(t-- > 0){
        int V = 0; 
        int E;
        int i,j;
        
        cin>>V>>E;
        
        int visited[V];
        int x, y;
        int G[1000][1000];

        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if(i != j)
                    G[i][j] = 1;
                else
                    G[i][j] = 0;

            }
        }


        for(i = 0; i < E; i++){
            cin>>x>>y;
            x--;
            y--;
            G[x][y] = 0;
            G[y][x] = 0;
        }

        int check = 0;
        for (int i = 0; i < V; ++i)
        {   
            if(visited[i] != 1){
                if(!isBipartite(G, V, i, visited)){
                    check = 1;
                }
            }
        }

        if(check == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}