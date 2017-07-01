#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string str = argv[1];
	stringstream ss(str);
	string buff;
	stack<string> s;
	while(ss >> buff){
		s.push(buff);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}