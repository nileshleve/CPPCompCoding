#include <bits/stdc++.h>
#include <string>


using namespace std;

void printSets(int a[], int k, int n,int prev, string s);
int check =0;

set<string> ansset;

int main(){
	
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		
		
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		
		// for(int i= 0;i<n;i++)
		// 	cout<<a[i]<<"\t";
		sort(a,a+n);
		int k;
		cin>>k;
		string s;
		check = 0;
		ansset.clear();
		set<string>::iterator itset;
		printSets(a, k, n, 0, s);
		if(check == 0)
			cout<<"Empty";
		else{
			for(itset = ansset.begin(); itset!=ansset.end(); itset++){
				cout<<*itset;
			}

		}
		cout<<endl;


	}
	return 0;
}	


void printSets(int a[], int k, int n, int prev, string s){

	if(k < 0){
		return;
	}
	if(k == 0){
		string ans = "(";
		
		//s.erase(0, s.find_first_not_of(' ')); 
		//s.erase(s.find_last_not_of(' ')+ 1);
		s.erase(0,1);
		ans+=s;
		ans+=")";
		
		if(ansset.find(ans) == ansset.end()){
			ansset.insert(ans);
		}

		check++;
	}
	for(int i = prev; i < n; i++){
		stringstream sstm;
		sstm << "" << a[i];
		string result = sstm.str();
		printSets(a, k-a[i], n, i+1, s+" "+result);
	}
}
