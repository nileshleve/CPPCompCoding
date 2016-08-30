#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t-->0){
	    int x;
	    cin>>x;
	    // if(x == 2){
	    // 	cout<<"2"<<endl;
	    // 	continue;
	    // }
	    long long int ans;
	    if(x%2 == 0){
	    	ans = pow(2, pow(3, (x/2)-1));
	    	cout<<ans<<endl;
	   
	    }
	    else{
	    	ans = pow(2, pow(2, (x/2)));
	    	cout<<ans<<endl;

	    }
    
	}
	return 0;
}