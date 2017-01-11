#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int t;
	cin>>t;
	while(t-- > 0){
		long long int n, l, r;
		cin>>n;
		cin>>l;
		long long int count = 0;
		cin>>r;
		long long int pno[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
		for (long long int i = l; i <= r; ++i)
		{
			for (long long int j = 0; j < 15; ++j)
			{
				if(i % pno[j] == 0 && pno[j] <= n){
					count++;
					break;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}