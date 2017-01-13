#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int div = n / 8;
		int mod = n % 8;
		int ans;
		string anssuffix = "";
		switch(mod){
			case 1: 
				ans = mod + 3;
				anssuffix = "LB";
				break;
			case 2:
				ans = mod + 3;
				anssuffix = "MB";
				break;
			case 3: 
				ans = mod + 3;
				anssuffix = "UB";
				break;
			case 4: 
				ans = mod - 3;
				anssuffix = "LB";
				break;
			case 5: 
				ans = mod - 3;
				anssuffix = "MB";
				break;
			case 6: 
				ans = mod - 3;
				anssuffix = "UB";
				break;
			case 7: 
				ans = mod + 1;
				anssuffix = "SU";
				break;
			case 0:
				ans = mod - 1;
				anssuffix = "SL";	
		}
		cout<<ans+(div*8)<<anssuffix<<endl;
	}
	return 0;
}