#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a[] = {100, 80, 60, 70, 60, 75, 85};
	//int a[] = {6,3,4,5,2};
	
	stack<int> s;
	int span[sizeof(a)/sizeof(a[0])] = {0};
	int P;
	int x;

	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
		while(!(s.empty()) && a[i] > a[s.top()]){
			
			s.pop();
			
		}
		if(s.empty()){
			P = -1;
		}
		else{
			P = s.top();
		}
		span[i] = i - P;
		s.push(i);
		
	}

	for(int  i =0; i < sizeof(a)/sizeof(a[0]); i++){
		cout<<span[i]<<"\t";
	}

	return 0;
}