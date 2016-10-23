#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int arr[n];
		int check = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n - 1; ++i)
		{
			if(abs(arr[i] - arr[i+1]) > 1){
				cout<<"NO"<<endl;
				check = 1;
				break;
			}

		}
		if(check != 1)
			cout<<"YES"<<endl;
	}
	return 0;
}