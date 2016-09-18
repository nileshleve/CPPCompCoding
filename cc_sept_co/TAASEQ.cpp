#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		map<int, long long int > m;
		map<int, long long int >::iterator it;
		long long int a[n];
		cin>>a[0];
		set<long long int> s;
		long long int last = a[0];
		for (int i = 1; i < n; i++)
		{
			cin>>a[i];
			m[i] = a[i] - last;
			s.insert(a[i] - last);
			last = a[i];
		}
		

		if(s.size() == 1){

			cout<<a[0]<<endl;
			continue;
		}


		
        int length;
        length = lenghtOfLongestAP(a, n);
        if(length == 2 && n > 3){
        	cout<<"-1"<<endl;
        	continue;
        }

        long long int mind = INT_MAX;
		int loc;
		for(it = m.begin(); it != m.end(); it++){
			if(mind > it->second){
				mind = it->second;
				loc = it->first;
			}
		}
		cout<<a[loc]<<endl;
		
	}
	return 0;
}