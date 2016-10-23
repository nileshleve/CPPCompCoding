#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		if(arr[i] % 2 == 0){
			count++;
		}
	}
	if(count > (n - count))
		cout<<"READY FOR BATTLE"<<endl;
	else
		cout<<"NOT READY"<<endl;

	return 0;
}