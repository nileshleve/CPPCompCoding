#include <bits/stdc++.h>

using namespace std;


/*		//Wrong logic

int main(){
	int t;
	cin>>t;
	while(t-- >0){
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;
		int count = 0;
		if(s1.size() < s2.size()){
			cout<<"0";
			continue;
		}
		int len1 = s1.size();
		int len2 = s2.size();
		int lptr1 = 0;
		int rptr1 = len1-1;
		int lptr2 = 0;
		int rptr2 = len2-1;
		for(int i = 0; i < len1; i++){
			lptr1 = 0;
			lptr2 = 0;
			rptr1 = s1.size()-1;
			rptr2 = s2.size()-1;
			for(int j = 0; j < len2; j++){
				if(s1[lptr1] == s2[lptr2]){
					lptr1++;
					lptr2++;
					//cout<<lptr1<<"  ";
				}
				else{
					break;

				}

			}
			for (int i = s1.size()-1; i > lptr1; i--)
			{
				if(s1[i] == s2[rptr2--]){
					//cout<<"ha";
				}
				else{
					break;
				}
			}
			if(rptr2+1 == lptr2){
				if(s1[lptr1] == s2[lptr2-1]){
					s1.erase(lptr1, 1);
					s2.erase(lptr2-1, 1);
					// cout<<s1;
					// cout<<"    "<<s2<<endl;
					count++;
				}
				
			}
		}
		cout<<count+1<<endl;


	}
	return 0;
}*/