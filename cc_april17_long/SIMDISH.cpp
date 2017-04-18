#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int t;
	cin>>t;
	while(t-- > 0){

		string str1;
		string str2;
    	cin >> ws;
		getline(cin, str1);
		
		getline(cin, str2);
		//cin>>str1;
		//cin>>str2;
		//cout<<" str1 ====> "<<str1<<endl;
		//cout<<" str2 ====> "<<str2<<endl;
		string buff;
		stringstream ss1(str1);
		stringstream ss2(str2);
		string str2arr[1000000];
		set<string> s;
		while(ss1 >> buff){			
			s.insert(buff);
		}
		int ctr = 0;
		int len = 0;
		while(ss2 >> buff){
			len++;
			if(s.find(buff) != s.end()){
				ctr++;
			}
		}
		
		//int len = sizeof(str2arr) / sizeof(str2arr[0]);
		
		if((float)ctr >= (float)(len/2))
			cout<<"similar\n";
		else
			cout<<"dissimilar\n";
		}
	return 0;
}