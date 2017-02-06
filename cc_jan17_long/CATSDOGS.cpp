#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		long long int c,d,l;
		cin>>c;
		cin>>d;
		cin>>l;
		long long int max = 4*(c+d);
		long long int min = 0;
		if(l%4 != 0){
			cout<<"no"<<endl;
			continue;
		}
		if(c <= 2*d)
			min = 4*d;
		else
			min = 4*d + ((c - (2*d))*4);
		if(l >= min && l <= max)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;

	}
	return 0;
}