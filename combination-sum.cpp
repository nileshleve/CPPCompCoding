#include <bits/stdc++.h>
#include <string>


using namespace std;

void printSets(int a[], int k, int n,int prev, string s);
int check =0;

int main(){
	
	int t;
	cin>>t;
	while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		set<int> temp;
		int temp1;
		int t = 0;
		for(int i = 0 ; i < n ; i++){
			cin>>temp1;
			if(temp.find(temp1) == temp.end()){
				temp.insert(temp1);
				a[t++] = temp1;
			}
		}
		n = t;
		// for(int i= 0;i<n;i++)
		// 	cout<<a[i]<<"\t";
		sort(a,a+n);
		int k;
		cin>>k;
		string s;
		check = 0;
		printSets(a, k, n, 0, s);
		if(check == 0)
			cout<<"Empty";
		cout<<endl;


	}
	return 0;
}	


void printSets(int a[], int k, int n, int prev, string s){

	if(k < 0){
		return;
	}
	if(k == 0){
		cout<<"(";
		//s.erase(0, s.find_first_not_of(' ')); 
		//s.erase(s.find_last_not_of(' ')+ 1);
		s.erase(0,1);
		cout<<s;
		check++;
		cout<<")";
	}
	for(int i = prev ; i < n; i++){
		stringstream sstm;
		sstm << "" << a[i];
		string result = sstm.str();
		printSets(a, k-a[i], n, i, s+" "+result);
	}
}
