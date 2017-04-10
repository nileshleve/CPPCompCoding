#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n, m;
		unordered_set<int> s;
		unordered_set<int> vnum;
		int ans = 0;
		int sum1[10001] = {0};
		int sum2[10001] = {0};
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		cin>>m;
		int b[m];
		for (int i = 0; i < m; ++i)
		{
			cin>>b[i];
			if(s.find(b[i]) != s.end()){
				vnum.insert(b[i]);
			}
		}
		int sum = 0;
		int end1 = 0;
		int end2 = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			sum = sum + a[i];
			if(vnum.find(a[i]) != vnum.end()){
				sum1[a[i]] = sum; 
				sum = 0;
			}
		}
		sum += a[n-1];
		if(vnum.find(a[n - 1]) != vnum.end()){
			sum1[a[n - 1]] = sum; 
		}
		else{
			end1 = sum;
		}
		sum = 0;
		for (int i = 0; i < m - 1; ++i)
		{
			sum += b[i];
			if(vnum.find(b[i]) != vnum.end()){
				sum2[b[i]] = sum; 
				sum = 0;
			}
		}
		sum += b[m-1];
		if(vnum.find(b[m - 1]) != vnum.end()){
			sum2[b[m - 1]] = sum; 
		}
		else{
			end2 = sum;
		}
		for (int i = 0; i < 10001; ++i)
		{
			if(sum2[i] != 0){
				ans += min(sum1[i], sum2[i]);
			}
		}
		if(vnum.find(a[n - 1]) == vnum.end() && vnum.find(b[m - 1]) == vnum.end()){
			ans += min(end1, end2);
		}
		cout<<ans<<endl;
	}
	return 0;
}