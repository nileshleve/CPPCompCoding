#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-- > 0){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		if(x2 == x1){
			if(y1 < y2){
				cout<<"up"<<endl;
				continue;

			}
			else{
				cout<<"down"<<endl;
				continue;
			}	
		}
		else if(y2 == y1){
			if(x1 < x2){
				cout<<"right"<<endl;
				continue;

			}
			else{
				cout<<"left"<<endl;
				continue;
			}	
		}
		else{
			cout<<"sad"<<endl;
		}

	}


	return 0;
}