#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	string res;

	while(t-- > 0){
		int one = 0;
		int zero = 0;
		cin>>res;
		// stringstream ss;
		// ss<<n;
		// string res = ss.str();
		//cout<<res;
		for(int i = 0; i<res.size();i++){
			if(res[i] == '1'){
				one++;
			}
			else{
				zero++;
			}

		}
		if((zero == 1 && one == res.size()-1) || (zero == res.size() - 1 && one == 1)){
			cout<<"Yes"<<endl;
		} 
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
	
}