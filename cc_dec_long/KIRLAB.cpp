#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		int cones = 0;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			if(a[i] == 1)
				cones++;
		}
		// if(n == 1 || cones == n){
		// 	cout<<1<<endl;
		// 	continue;
		// }
		int var = 0;
		int max = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			int last = a[i];
			count = 0;
			for (int j = i; j < n - 1; ++j)
			{
				if(gcd(last, a[j+1]) > 1){
					count++;
					last = a[j+1];
					var = 1;
				}
			}
			if(var == 1){
				var = 0;
				count++;
			}
			if(count > max){
				max = count;
			}
		}
		cout<<max<<endl;
			
	}
	return 0;
}