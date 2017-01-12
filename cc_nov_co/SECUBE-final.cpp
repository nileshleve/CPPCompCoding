#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		long long int k, c;
		cin>>k;
		cin>>c;
		long long int total = k*k*k;
		long long int a = total - c;
		long long int num = a*(a*a - 1);
		long long int den = total;
		cout<<num<<"   "<<den<<endl;
		if(num % den == 0)
		   cout<<"YES\n";
		else
		   cout<<"NO\n";
	}	
	return 0;
}