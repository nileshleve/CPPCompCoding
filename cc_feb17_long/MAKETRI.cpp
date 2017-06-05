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
		s.insert(a[i]);
	}
	sort(a, a+n);
	int count = 0;
	int check = 0;
	int lb, ub;
	for (int i = l; i <= r; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ub = i + a[j];
			lb = abs(i - a[j]);
			s.erase(a[j]);
			for (int k = lb+1; k < ub; ++k)
			{
				if(s.find(k) != s.end()){
					count++;
					//cout<<i<<" "<<a[j]<<" "<<k<<endl;
					check = 1;
					break;
				}
			}
			s.insert(a[j]);
			if(check == 1){
				check = 0;
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}