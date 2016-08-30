#include<bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin>>t;
	while(t-->0){
		string str;
		cin>>str;
		int k;
		cin>>k;
		if(k > str.size()){
			cout<<"0"<<endl;
			continue;
		}
		map<char, int> m;
		map<char, int>::iterator it;
		for(int i=0;i<str.size();i++){
			m[str[i]]++;
		}

		// for(it=m.begin();it!=m.end();it++){
		// 	cout<<it->first<<" "<<it->second<<endl;
		// }

		map<char, int>:: iterator it1;
		int max;
		while(k-->0){
			max = INT_MIN;
			for(it = m.begin(); it != m.end(); it++){
				if(it->second > max){
					max = it->second;
					it1 = it;
				}

			}
			it1->second--;
		}

		int minsum = 0;
		for(it = m.begin(); it != m.end(); it++){
			minsum += pow(it->second, 2);
		}
		cout<<minsum<<endl;

	}


	return 0;
}