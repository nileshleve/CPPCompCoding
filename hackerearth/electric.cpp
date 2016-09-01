#include <bits/stdc++.h>
//#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
	long long int n;
	cin>>n;
	long long int a[n];
	set<long long int> s;
	long long int distinct = 0;
	for (long long int i = 0; i < n; i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}	
	distinct = s.size();
	long long int ans = 0;
	long long int count = 0;
	set<long long int> notin;
	for(long long int i = 0; i < n; i++){
		set<long long int> newset;
		if(notin.find(a[i]) == notin.end()){
			for(long long int j = i+1; j < n; j++){
			
				newset.insert(a[j]);
			}
			ans += newset.size();
			notin.insert(a[i]);
		}
		
		
	}
	cout<<ans<<endl;

	return 0;
}