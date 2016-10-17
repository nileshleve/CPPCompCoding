#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int n;
	cin>>n;
	long long int ans[1000][1000] = {0};
	long long int x[1000] = {0}, y[1000] = {0};
	long long int i = 0;
	
	long long int temp;
	long long int max = INT_MIN;
	if(n >= 1){
		cin>>x[i]>>y[i];
		cout<<0<<endl;
		i++;
	}

	while(i < n){
		cin>>x[i]>>y[i];
		for(long long int j = 0; j < i; j++){
			temp = (((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])));
			ans[i][j] = temp;
		}
		for (long long int k = 0; k < n; ++k)
		{
			for (long long int j = 0; j < i; ++j)
			{
				if(ans[i][j] > max)
					max = ans[i][j];
			}
		}
		i++;
		cout<<max<<endl;;
	}
	return 0;
}