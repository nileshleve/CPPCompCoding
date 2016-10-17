#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n,m,c;
		cin>>n>>m>>c;
		int count = 0;
		for (int i = 1; i <= n; ++i)
		{
			
			if((c%i == 0) && c/i <= m)
				count++;



			// for (int j = 1; j <= m; ++j)
			// {
			// 	if(i*j == c){
			// 		count++;
			// 		break;
			// 	}
			// }	
		}
		cout<<count<<endl;
	} 
	return 0;
}  