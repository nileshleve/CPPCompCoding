#include <bits/stdc++.h>

using namespace std;
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
		sort(a, a + n);
		if(a[1] - a[0] != 1){
			cout<<a[0]<<endl;
		}
		else if(a[n-1] - a[n-2] != 1){
			cout<<a[n-1]<<endl;
		}
		else{
			for (int i = 0; i < n-1; ++i)
			{
				if(a[i] == a[i+1]){
					cout<<a[i]<<endl;
					break;
				}
			}
		}
		
	}
	return 0;
}