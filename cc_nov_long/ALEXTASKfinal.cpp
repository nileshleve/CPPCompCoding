#include <bits/stdc++.h>

using namespace std;
long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}


long long int lcm(long long int a, long long int b)
{
  return (a*b)/gcd(a,b);
}

int main()
{
	long long int t;
	cin>>t;
	while(t-- > 0){
		long long int n;
		cin>>n;
		long long int a[n];
		for (long long int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		sort(a, a+n);
		long long int ans = 0;
		long long int br = 0;
		vector<long long int> vec;
		for (long long int i = 0; i < n; ++i)
		{
			for (long long int j = i+1; j < n; ++j)
			{
				if(a[j] % a[i] == 0){
					vec.push_back(a[j]);
				}
			}
		}
		long long int min = INT_MAX;
		vector<long long int>::iterator it;
		for (it = vec.begin(); it != vec.end(); ++it)
		{
			if(min > *it){
				min = *it;
				ans = min;
			}
		}
		if(ans == 0 && n >= 2){
			ans = lcm(a[0], a[1]);
		}
		else if(ans == 0 && n < 2){
			ans = a[0];
		}
		int i = 0;
		while(a[i+1] < ans && i+1 < n){
			if(a[i] == a[i+1]){
				ans = a[i];
				break;
			}
			i++;			
		}

		cout<<ans<<endl;
	}
	return 0;
}
//Following test case fails
//1
//4
//97 98 99 100