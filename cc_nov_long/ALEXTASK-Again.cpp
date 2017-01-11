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
			set<long long int> s;
			vector<long long int> vec;
			for (long long int i = 0; i < n; ++i)
			{
				cin>>a[i];
				if(s.find(a[i]) == s.end()){
					s.insert(a[i]);
				}
				else{
					s.insert(a[i]);
					vec.push_back(a[i]);
				}
			}
			sort(a, a+n);
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
			long long int ans = 0;
			vector<long long int>::iterator it;
			for (it = vec.begin(); it != vec.end(); ++it)
			{
				if(min > *it){
					min = *it;
				}
			}
			ans = min;
			if(ans == INT_MAX || ans == 0){
				ans = lcm(a[0], a[1]);
			}
			long long int i = 0;
			long long int temp = ans;
			long long int lt = ans;
			while(a[i] < lt && i < n - 1){
				temp = lcm(a[i], a[i+1]);
				if(temp < ans)
					ans = temp;
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