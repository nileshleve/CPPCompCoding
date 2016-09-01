#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int n;
	cin>>n;
	long long int a[n];
	map<long long int, long long int> m;
	for (long long int i = 0; i < n; i++)
	{
		cin>>a[i];
		m[i] = a[i];

	}
	long long int s,e;
	cin>>s>>e;
	s--;
	while(true){
		if(m.find(a[s]) != m.end()){
			if(a[s] == e){
				cout<<"Yes"<<endl;
				break;
			}
			else{
				s = a[s] - 1;
				//cout<<s+1<<"--->"<<a[s];
			}

		}
		else{
			cout<<"No"<<endl;
			break;
		}
	}
	return 0;
}