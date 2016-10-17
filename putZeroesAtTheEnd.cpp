#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	int czero = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];

		if(a[i] == 0){
			czero++;
		}
		
	}
	int temp = n-1-czero;
	int swap;
	for (int i = n-1; i > n-czero-1; i--)
	{
		if(a[i] != 0){
			while(true){
				if(a[temp] == 0){
					a[temp] = a[i];
					a[i] = 0;
					break;
				}
				temp--;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<"  ";
	}
	return 0;
}