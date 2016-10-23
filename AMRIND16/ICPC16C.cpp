#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-- > 0){
		int d;
		cin>>d;
		int count = 0;
		while(d > 9){
			d = d - 9;
			count++;
		}
		int last = d;
		if(last == 9)
			cout<<1<<endl;
		else
			cout<<last+1<<endl;
	}
	return 0;
}