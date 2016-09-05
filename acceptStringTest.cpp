#include <bits/stdc++.h>


using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		string s;
		//cin.ignore();
		cin>>ws;
		getline(cin, s);
		//int len = s.size();
		//char a[1000] = c_str(s);
		for (int i = 0; i < s.size(); i++)
		{
		
			if(s[i] != ' '){
				cout<<s[i];
				
			}
		}
		cout<<endl;
	}
	return 0;
}