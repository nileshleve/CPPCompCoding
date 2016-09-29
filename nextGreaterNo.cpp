#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {2, 5, 4, 3, 7, 9, 8, 10};
	stack<int> s;
	s.push(a[0]);
	map<int, int> m;
	//int ans[sizeof(a)/sizeof(a[0])];
	for(int i = 1; i < 8; i++){
		while(!s.empty() && a[i] > s.top()){
			m[s.top()] = a[i];
			s.pop();
		} 
		s.push(a[i]);
	}

	map<int, int>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		cout<<it->first<<"==>"<<it->second<<endl;
	}

	return 0;
}