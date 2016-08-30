#include <bits/stdc++.h>
using namespace std;


int countUniqueBSTs(int n, int table[]){
	if(n == 0) return 1;
	if(table[n] != 1){
		return table[n];
	}
	table[n] = 0;
	for(int i = 1 ; i <= n; i++){
		table[n] += countUniqueBSTs(i - 1, table) * countUniqueBSTs(n - i, table);
	}
	return table[n];
}


int main(){
	int t;
	cin>>t;
	int n;
	int ans;
	while(t-- >0){
		cin>>n;
		int table[1024];
		for(int i = 0;i<1024;i++)
			table[i] = 1;
		ans = countUniqueBSTs(n, table);
		cout<<ans<<endl;
	}

	return 0;
}