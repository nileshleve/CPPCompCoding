
#include <bits/stdc++.h>
using namespace std;

bool isGood(string a, int src, int visited[], int countVisited){
	if(src < 0 || src > a.size() - 1)
		return false;
	//cout<<src<<endl;

	if(src == a.size() - 1){
		for (int i = 0; i < a.size() - 1; ++i)
		{
			if(visited[i] == 0)
				return false;
		}
		return true;
	}
	if((a[src] - 48) == 1 && visited[src] != 1){
		visited[src] = 1;
		countVisited++;
		if(isGood(a, src + 1, visited, countVisited) || isGood(a, src - 1, visited, countVisited)){
			return true;
		}
		else{
			visited[src] = 0;
			countVisited--;
			return false;
		}
	}
	else if((a[src] - 48) == 2 && visited[src] != 1){
		visited[src] = 1;
		countVisited++;
		if(isGood(a, src + 2, visited, countVisited) || isGood(a, src - 2, visited, countVisited)){
			return true;
		}
		else{
			visited[src] = 0;
			countVisited--;
			return false;
		}
	}
	else{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- >0){
		string a;
		cin>>a;
		int visited[a.size()];

		int countVisited = 0;
		for (int i = 0; i < a.size(); ++i)
		{
			visited[i] = 0;
		}
		
		bool ans = isGood(a, 0, visited, countVisited);
		cout<<ans;
		//cout<<a.size();
	}
	return 0;
}