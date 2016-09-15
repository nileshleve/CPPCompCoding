#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0 ){
		string s;
		cin>>s;
		int len = s.size();
		int ctr = 0;
		
		for(int i = 0; i < (len/2); i++){
			if(s[i] == s[len-i-1] && s[i] != '.'){
				continue;
			}
			else if(s[i] == '.' && s[len-i-1] == '.'){
				s[i] = s[len - i - 1] = 'a';
			}
			else if(s[i] == '.' ){
				s[i] = s[len - i - 1];
			}
			else if(s[len - i - 1] == '.' ){
				s[len - i - 1] = s[i];
			}
			else{
				cout<<"-1"<<endl;
				ctr = 1;
				break;
				
			}
		}
		if(ctr == 1){
			continue;
			ctr = 0;
		}
		if(len % 2 != 0){
			if(s[(len/2)] == '.'){
				s[(len/2)] = 'a';
			}
		}

		cout<<s<<endl;
	}
	return 0;
}