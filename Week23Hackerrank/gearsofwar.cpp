#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		if(temp %2 == 0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}

	return 0;
}