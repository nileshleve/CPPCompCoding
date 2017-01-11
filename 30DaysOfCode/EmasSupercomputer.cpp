#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;
	string str[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>str[i];
	}
	int ans[15][15] = {0};
	int max = 0;
	
	for (int i = 0; i < n; ++i)
	{	
		for (int j = 0; j < m; ++j)
		{
			if(str[i][j] == 'G'){
				
				int c = 1;
				while(true){
					if(i-c >= 0 && i+c <= n-1 && j-c >= 0 && j+c <= m-1 && str[i-c][j] == 'G' && str[i][j+c] == 'G' && str[i+c][j] == 'G' && str[i][j-c] == 'G'){
						ans[i][j] += 4;
						c++;
					}
					else{
						ans[i][j] += 1;
						break;
					}
				}
			}
		}
	}
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout<<ans[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	int temp = 0;
	int given[n][m];
	int given1[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			given[i][j] = 0;
			given1[i][j] = 0;
		}
	}
	int note = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(ans[i][j] >= 1){
				for (int a = 0; a < n; ++a)
				{
					for (int b = 0; b < m; ++b)
					{
						given[a][b] = 0;
					}
				}
				int c = 1;
				given[i][j] = 1;
				while(ans[i][j] >= c){
					int l = (c - 1)/4; 
					if(c > 1)
						given[i-l][j] = given[i+l][j] = given[i][j+l] = given[i][j-l] = 1;
					for (int x = 0; x < n; ++x)
					{
						for (int y = 0; y < m; ++y)
						{
							if(ans[x][y] >= 1){
								for (int an = 0; an < n; ++an)
								{
									for (int bn = 0; bn < m; ++bn)
									{
										given1[an][bn] = 0;
									}
								}
								int cn = 1;
								given1[x][y] = 1;
								while(ans[x][y] >= cn){
									int ln = (cn - 1)/4; 
									if(cn > 1)
										given1[x-ln][y] = given1[x+ln][y] = given1[x][y+ln] = given1[x][y-ln] = 1;	
									for (int e = 0; e < n; ++e)
									{
										for (int f = 0; f < m; ++f)
										{
											if(given[e][f] == 1 && given1[e][f] == 1){
												note = 1;
												break;
											}
											if(note == 1)
												break;
										}
									}
									if(note != 1){
										temp = c * cn;
										if(max < temp)
											max = temp;
										//cout<<"haha";
									}
									note = 0;
									cn += 4;
								}
							}
						}
					}
					c += 4; 
				}
			}
		}
	}
	cout<<max<<endl;
	return 0;
}



