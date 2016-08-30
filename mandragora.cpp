#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	long long int t;
	cin>>t;
	long long int n;
	while(t-- >0){
		cin>>n;
		long long int man[n];
		long long int sum = 0;
		for (long long int i = 0; i < n; i++)
		{
			cin>>man[i];
			sum += man[i];
		}
		sort(man, man+n);
		long long int x = 1;
		long long int y = 0;
		long long int max = sum;

		for (long long int i = 0; i < n; i++)
		{
			x++;
			sum -= man[i];
			y = x * sum;
			if(y > max)
				max = y;
		}
		cout<<max<<endl;
	}
	return 0;
}