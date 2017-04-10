#include <bits/stdc++.h>

using namespace std;

set<int> vnum;

map<int, int> s1;
map<int, int> s2;

int min(int a, int b){
	return a < b ? a : b;
}

int findMin(int a[], int b[], int sum, int pos, int ch){
	
	if(ch == 1){
		
		if(pos >= 0){
			if(vnum.find(a[pos]) == vnum.end()){
				return findMin(a, b, sum + a[pos], pos-1, 1);
			}
			else{
				return min(findMin(a, b, sum + a[pos], pos - 1, 1), findMin(a, b, sum + a[pos], s2[a[pos]] - 1, 2)); 
			}
		}
		else{
			return sum;
		}	
	}
	else{
		if(pos >= 0){
			if(vnum.find(b[pos]) == vnum.end()){
				return findMin(a, b, sum + b[pos], pos-1, 2);
			}
			else{
				return min(findMin(a, b, sum + b[pos], s1[b[pos]] - 1, 1), findMin(a, b, sum + b[pos], pos - 1, 2)); 
			}
		}
		else{
			return sum;
		}	
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		vnum.clear();
		s1.clear();
		s2.clear();
		int n, m;
		cin>>n;
		int a[n];
		
		set<int> s;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			s1[a[i]] = i;
			s.insert(a[i]);
		}
		cin>>m;
		int b[m];
		for (int i = 0; i < m; ++i)
		{
			cin>>b[i];
			s2[b[i]] = i;
			if(s.find(b[i]) != s.end()){
				vnum.insert(b[i]);
			}
		}
		int ans1 = findMin(a, b, 0, n-1, 1);
		int ans2 = findMin(a, b, 0, m-1, 2);
		int ans = min(ans1, ans2);
		cout<<ans<<endl;


	}
	return 0;
}