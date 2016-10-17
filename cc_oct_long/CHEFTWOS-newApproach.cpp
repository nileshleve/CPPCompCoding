
#include <bits/stdc++.h>
using namespace std;
bool isGood(string a, int src, int visited[], int countVisited){
			
	if(a.size() == 1)
		return true;

	for (int i = 0; i < a.size() - 2; ++i){

		if(a[i] - 48 == 1)
			continue;
		if((a[i] - 48) == 2 && (a[i + 1] - 48) == 2 && (a[i + 2] - 48) == 1)
			i = i + 2;
		else
			return false;
	}
	if(a.size() >= 2){
		if((a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 2)
			return false;
	}
	
	if(a.size() >= 3){
		if((a[a.size() - 3] - 48) == 1 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 2)
			return false;
		if((a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 1)
			return false;
		if((a[a.size() - 3] - 48) == 1 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 1)
			return false;
	}
	if(a.size() >= 4){
		if((a[a.size() - 4] - 48) == 2 && (a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 1 && (a[a.size() - 1] - 48) == 2)
			return true;
	} 
	if(a.size() >= 3){
		if((a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 1 && (a[a.size() - 1] - 48) == 2)
			return false;
	}


	return true;
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