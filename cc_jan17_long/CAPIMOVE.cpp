#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int p[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>p[i];
		}
		int from[n-1];
		int to[n-1];
		for (int i = 0; i < n-1; i++)
		{
			cin>>from[i];
			cin>>to[i];
		}
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				arr[j] = 0;
			}
			arr[i] = 1;
			for (int j = 0; j < n-1; ++j)
			{
				if(from[j] == i+1)
					arr[to[j] - 1] = 1;
				if(to[j] == i+1)
					arr[from[j] - 1] = 1;
			}
			int max = INT_MIN;
			int ans = 0;
			for (int j = 0; j < n; ++j)
			{
				if(arr[j] != 1){
					if(p[j] > max){
						max = p[j];
						ans = j+1;
					}
				}
			}
			cout<<ans<<" ";
		}
	}
	return 0;
}