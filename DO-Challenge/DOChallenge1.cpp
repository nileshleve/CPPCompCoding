#include <bits/stdc++.h>

using namespace std;
long long int a[100000];
long long int b[500000];

long long int min(long long int a, long long int b){
	return a < b ? a : b;
}

long long int findMin(long long int n, long long int m){
	if(n < 0 && m < 0){
		return 0;
	}
	long long int i = n-1;
	long long int j = m-1;
	long long int sum1 = 0;
	long long int sum2 = 0;

	while(i >= 0 || j >= 0){
		if(i >= 0 && j >= 0 && a[i] > b[j]){
			sum1 += a[i];
			i--;
		}
		else if(i >= 0 && j >= 0 && a[i] < b[j]){
			sum2 += b[j];
			j--;	
		}
		else if(i >= 0 && j >= 0 && a[i] == b[j]){
			sum1 += a[i];
			sum2 += b[j];
			if(i == 0 && j == 0){
				return min(sum1, sum2);
			}
			long long int minValue = findMin(i, j);
			return min(sum1 + minValue, sum2 + minValue);
		}
		else if(i > j){
			sum1 += a[i];
			i--;
		}
		else{
			sum2 += b[j--];
		}
	}
	return min(sum1, sum2);	
}


int main()
{
	long long int t;
	cin>>t;
	while(t-- > 0){
		long long int n, m;
		cin>>n;
		for (long long int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		cin>>m;
		for (long long int i = 0; i < m; ++i)
		{
			cin>>b[i];
		}
		long long int ans = findMin(n, m);
		cout<<ans<<endl;	
	}
	return 0;
}