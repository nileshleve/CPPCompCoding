#include <bits/stdc++.h>

using namespace std;

bool dfs(int n, vector<int> adj[], int u, int visited[]){
	if(visited[u] == 1){
		return 1;
	}
	visited[u] = 1;
	vector<int>:: iterator it;
	for (it = adj[u].begin(); it != adj[u].end() ; ++it)
	{
		return dfs(n,s adj, *it, visited);
	}
	return 0;

}

bool isCyclicUtil(int n, int m, vector<int> adj[], int i){
	int visited[n];
	int j;
	for (j = 0; j < n; ++j)
	{
		visited[j] = 0;
	}
	bool val = dfs(n, adj, i, visited);
	if(val)
		return true;
	else
		return false;
}

int main(){
	int t;
	cin>>t;
	while(t-- > 0){
		int n, m;
		cin>>n>>m;
		vector<int> adj[n];
		int src[m], dest[m];
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin>>a>>b;
			adj[a-1].push_back(b-1);
			src[i] = a-1;
			dest[i] = b-1;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			bool check = isCyclicUtil(n, m, adj, i);
			if(check == true){
				for (int j = 0; j < m; ++j)
				{
					if(dest[j] == i){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
