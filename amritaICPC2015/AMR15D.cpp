#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int q;
	cin>>q;
	int k[q];
	for (int i = 0; i < q; ++i)
	{
		cin>>k[i];
	}
	sort(arr, arr + n);
	
	for (int j = 0; j < q; ++j)
	{
		int pay = 0;
		int start = 0;
		int end = n-1;
		while(start <= end){
			pay = pay + arr[start++];
			end = end - k[j];
		}
		cout<<pay<<endl;
	}
	
	return 0;
}