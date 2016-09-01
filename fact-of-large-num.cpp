#include <bits/stdc++.h>
using namespace std;

int factorial(long long int n, long long int fact[]){
	long long int i;
    fact[0] = 1;
    if(n == 1)
        return 1;
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i; 
    }
    return fact[--i]; 
}

int main() {
	int t;
	cin>>t;
	long long int n;
	long long int ans;
	while(t-- > 0){
	    cin>>n;
	    long long int fact[n];
	    ans = factorial(n, fact);
	    cout<<ans<<endl;
	    
	}
	return 0;
}