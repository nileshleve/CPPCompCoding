#include <bits/stdc++.h>

using namespace std;

int min(int x, int y){
	return x < y ? x : y;
}

int main(){
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n], b[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>b[i];
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i = i + 2)
		{
			sum1 += a[i];
		}
		for (int i = 1; i < n; i = i + 2)
		{
			sum1 += b[i];
		}
		for (int i = 0; i < n; i = i + 2)
		{
			sum2 += b[i];
		}
		for (int i = 1; i < n; i = i + 2)
		{
			sum2 += a[i];
		}
		cout<<min(sum1, sum2)<<endl;
	}
	return 0;
}