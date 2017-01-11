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
		long long int min = LONG_MAX;
		for (long long int i = 0; i < n; ++i)
		{
			for (long long int j = i+1; j < n; ++j)
			{
				long long int temp = lcm(a[i], a[j]);
				if(temp < min)
					min = temp;
			}
		}
		cout<<min<<endl;
	}
	return 0;
}