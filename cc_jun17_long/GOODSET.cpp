#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int a[501] = {0};
	set<int> s;
	for (int i = 1; i <= 500; ++i)
	{
		a[i] = 1;
		s.insert(i);
		set<int>::iterator k;
		set<int>::iterator j;
		for (k = s.begin(); k != s.end(); ++k)
		{
			j = k;
			++j;
			for (; j != s.end(); ++j)
			{
				if(s.find(*k + *j) != s.end()){
					a[i] = 0;
					s.erase(i);
				}
			}
		}
	}
	while(t-- > 0){
		int n;
		cin>>n;
		int count = 0;
		for (int i = 1; i <= 500; ++i)
		{
			if(a[i] == 1 && count < n){
				cout<<i<<" ";
				count++;
			}
		}
		cout<<endl;
	}
	return 0;
}