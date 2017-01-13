#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}

int findnos(int a[], int n, int src, int last, int ans){
	if(src >= n){
		return ans;
	}
	if(gcd(last, a[src]) > 1){
		int u = findnos(a, n, src+1, a[src], ans+1);
		int v = findnos(a, n, src+1, last, ans);
		return u > v ? u : v;
	}
	else{
		return findnos(a, n, src+1, last, ans);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		int ans = findnos(a, n, 0, a[0], 0);
		//int ans2 = findnos(a, n, 1, a[0], 0);
		cout<<ans<<endl;
	}
	return 0;
}