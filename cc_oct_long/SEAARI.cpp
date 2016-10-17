#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n,k,d;
	cin>>n>>k>>d;
	long long int a[n];
	long long int b[n];
	map<long long int, long long int> m;
	set<int> s;
	for (long long int i = 0; i < n; ++i)
	{
		cin>>a[i];
		b[i] = a[i];
		m[a[i]] = i;
	}
	cout<<0<<" "<<1<<endl;
	sort(b, b + n);
	long long int temp = n-1;
	long long int temp1 = 0;
	long long int e;
	for (long long int i = 0; i < d; ++i)
	{
		if(b[temp] > abs(b[temp1]))
			e = b[temp--];
		else
			e = b[temp1++]; 
		if(s.find(e) == s.end()){
			cout<<2<<" "<<m[e]+1<<endl;
			a[m[e]] == INT_MIN;
			s.insert(e);
		}
		else{
			d--;
		}		
	}
	for (long long int i = 0; i < k; ++i)
	{
		e = b[temp--];
		//cout<<e<<endl;
		if(a[m[e]] != INT_MIN){
			a[m[e]] = INT_MIN;
			if(e > n-1){
				k--;
				continue;
			}
			else{
				if(a[e-1] != INT_MIN){
					cout<<1<<" "<<m[e]+1<<" "<<e<<endl;
				}
			}
		}

	}
	cout<<-1<<endl;
	return 0;
}