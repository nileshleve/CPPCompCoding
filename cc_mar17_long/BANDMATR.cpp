#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n][n];
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>a[i][j];
				if(a[i][j] == 0){
					count++;
				}
			}
		}
		float num;
		int num1;
		int i;
		for (i = count; i >= 0; --i)
		{
			num = (float)((sqrt(4*i+1) - 1)/2);
			num1 = (int)num;
			if(num1 == num){
				break;
			}
		}
		cout<<n-1-num1<<endl;
		
	}
	return 0;
}