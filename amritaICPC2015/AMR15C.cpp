#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int k;
		cin>>k;
		int arr[n];
		int ansarr[n];
		for (int i = 0; i < n; ++i)
		{
			arr[i] = i;
		}
		int start = 0;
		int count = 0;
		while(true){
			if(start - k >= 0 && ans[start - k] != INT_MIN){
				ansarr[start] = start - k; 
				ans[start - k] = INT_MIN;
				count++;
			}
			else{
				ansarr[start] = start + k;
				ans[start + k] = INT_MIN;
				count++;
			}
			start++;
		}



	}
	return 0;
}