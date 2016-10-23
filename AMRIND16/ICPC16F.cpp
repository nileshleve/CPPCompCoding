#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-- > 0){
		int n, m, d, D;
		cin>>n>>m>>d>>D;
		
		if(n * d > m || m > n * D){
			cout<<-1<<endl;
			continue;
		}

		int count = 0;
		set<int> s[n];
		int loop = 0;
		int i = 0;
		int arr1[n];
		int arr2[n];
		int nedges = 0;
		for (int i = 0; i < n; ++i)
		{
			arr1[i] = 0;
			arr2[i] = 0;
		}
		while(loop < d){	
			for (i = 0; i < n - loop; ++i)
			{
				s[i].insert(i+loop);
				cout<<i+1<<" "<<i+loop+1<<endl;
				arr1[i]++;
				arr2[i+loop]++;
			}
			if(loop > 0){
				int secondstart = 0;
				int firststart = i;
				while(firststart < n){
					s[firststart].insert(secondstart);
					cout<<firststart+1<<" "<<secondstart+1<<endl;
					arr1[firststart]++;
					arr2[secondstart]++;
					firststart++;
					secondstart++;
				}
			}
			loop++;
		}
		nedges = n * d;
		int check = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(arr1[i] < D && arr2[j] < D && s[i].find(j) == s[i].end() && nedges < m){
					s[i].insert(j);
					cout<<i+1<<" "<<j+1<<endl;
					arr1[i]++;
					arr2[j]++;
					nedges++;
				}
				if(nedges == m){
					check = 1;
					break;
				}
			}
			if(check == 1)
				break;
		}

		
		
	}
	return 0;
}