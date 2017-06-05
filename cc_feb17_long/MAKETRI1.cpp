#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, l, r;
	cin>>n>>l>>r;
	int a[n];
	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		//s.insert(a[i]);
	}
	sort(a, a+n);
	int count = 0;
	int ub, lb;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			ub = a[i] + a[j];
			lb = abs(a[i] - a[j]);
			for (int k = lb+1; k < ub; ++k)
			{
				if(k >= l && k <= r && s.find(k) == s.end()){
					//cout<<a[i]<<" "<<a[j]<<" "<<k<<endl;
					count++;
					s.insert(k);
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}