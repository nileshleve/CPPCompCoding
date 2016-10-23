#include <bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		int count = 0;
		int check = 0;
		int cminus = 0;
		int cones = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			if(a[i] == 0){

			}
			else if(a[i] == 1){
				cones++;
			}
			else if(a[i] == -1){
				cminus++;
			}
			else{
				count++;
			}
			if(count > 1){
				check = 1;
				break;

			}
		}
		if((cminus % 2 != 0) && cones == 0)
			check = 1;
		if(check == 1)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}