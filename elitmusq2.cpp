#include <bits/stdc++.h>

using namespace std;

/*
Other soln is dp 
i.e.
dp[i] = dp[i-1] + dp[i - 3]

*/

long long int ans = 0;

int traverse(long long int src, long long int check, long long int dest, string str){
	if(src == dest){
		cout<<str<<endl;
		ans++;
		return 1;
	}
	else if(src > dest){
		return 0;
	}
	else{
		traverse(src+1, 0 , dest, str+"1");
		if(check == 0){
			traverse(src+2, 1, dest, str+"2");
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		long long int n;
		ans = 0;
		cin>>n;
		string str = "";
		traverse(0, 0, n, str);
		ans = ans % 1000000007;
		cout<<ans<<endl;
	}
	return 0;
}