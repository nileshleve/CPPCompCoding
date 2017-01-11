#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int k;
		cin>>k;
		int a[k][5];
		int ans[5][5];
		if(k == 1)
			cout<<1<<endl;
		else if(k==3){
			cout<<3<<" "<<2<<" "<<1<<endl;
			cout<<1<<" "<<3<<" "<<2<<endl;
			cout<<2<<" "<<1<<" "<<3<<endl;
		}
		else{
			cout<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<endl;
			cout<<2<<" "<<1<<" "<<4<<" "<<5<<" "<<3<<endl;
			cout<<3<<" "<<4<<" "<<5<<" "<<2<<" "<<1<<endl;
			cout<<5<<" "<<3<<" "<<2<<" "<<1<<" "<<4<<endl;
			cout<<4<<" "<<5<<" "<<1<<" "<<3<<" "<<2<<endl;
		}
		
	}
	return 0;
}