#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int x, y;
		cin>>x>>y;
		long long int sum = x + y;
		long long int count  = 1;
		count = (sum * (sum + 1))/2;
		// while(sum-- > 0){
		// 	count += i;
		// 	i++;
		// }
		count = count + x + 1;
		cout<<count<<endl;
	}
	return 0;
}