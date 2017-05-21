#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int x,y;
	cin>>x>>y;
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int t;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		t = a[i];
		while(a[i] > 0){
			a[i] = a[i] - x;
			ans++;
			if(a[i] <= 0)
				break;
			else
				a[i] = a[i] + y;
		}
	}
	cout<<ans;
	return 0;
}