#include <bits/stdc++.h>
using namespace std;

int checkSides(char arr[1000][1000], int x, int y, int n, int m){
	if(arr[x][y] == 'W'){
		if (y-1 < 0 || y+1 >= m)
			return 0;
		else if(arr[x][y-1] == 'A' || arr[x][y+1] == 'A')
			return 0;
		if(x-1 >= 0 && (arr[x-1][y] == 'B'))
			return 0;
		if(x+1 < n && arr[x+1][y] == 'A')
			return 0;
		// if(x+1 >= n)
		// 	return 0;
	}
	else if(arr[x][y] == 'A'){
		if(y-1 >= 0 && arr[x][y-1] == 'W')
			return 0;
		if(y+1 < m && arr[x][y+1] == 'W')
			return 0;
		if(x-1 >= 0 && (arr[x-1][y] == 'W' || arr[x-1][y] == 'B'))
			return 0;
	}
	else{
		if(x+1 < n && (arr[x+1][y] == 'W' || arr[x+1][y] == 'A'))
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n, m;
		cin>>n>>m;
		char arr[1000][1000];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>arr[i][j];
			}
		}
		int ans = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				ans = checkSides(arr, i, j, n, m);
				if(ans)
					continue;
				else{
					break;
				}

			}
			if(ans == 0){
				break;
			}
		}
		if(ans == 0)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;

	}
	return 0;
}