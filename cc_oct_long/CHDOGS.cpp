#include <bits/stdc++.h>

using namespace  std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		long long int s,v;
		cin>>s>>v;
		double d = (double)(2*s)/(3*v);
		cout<<fixed<<setprecision(6)<<d<<"\n";
	}
	return 0;
}