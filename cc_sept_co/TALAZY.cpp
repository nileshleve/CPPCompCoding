#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int t;
	cin>>t;
	while(t-- > 0){
		long long int n;
		cin>>n;
		long long int b;
		cin>>b;
		long long int m;
		cin>>m;
		long long int sum = 0;
		while(n > 0){
			if(n % 2 == 0){
				sum += ((n/2)*m);
				n= n/2;
			}
			else{
				sum += (((n+1)/2)*m);
				n -= ((n+1)/2);
			}
			m = m*2;
			sum += b;
		}
		cout<<sum - b<<endl;
	}
	return 0;
}