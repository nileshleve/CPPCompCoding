// #include<iostream>
// #include<algorithm>
// #include<cstdio>
// #include<map>
#include<bits/stdc++.h>

using namespace std;

typedef struct element{
	int ele;
	int count;
	int first;
}element;


bool mycomp(struct element a, struct element b){
	if(a.count != b.count)
		return (a.count > b.count);
	else
		return (a.first < b.first);
}

int main(){	
	int a[] = {2, 5, 2, 8, 5, 6, 8, 8};
	int index[100];
	
	

	for(int i = 0; i < sizeof(index)/sizeof(index[0]); i++){
		index[i]=-10;	
	}


	map <int, int> m1;
	for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
		if(m1.find(a[i]) == m1.end())
			index[a[i]] = i;
		m1[a[i]]++;
	} 

	element elements[sizeof(a)/sizeof(a[0])];
	int k=0;

	for(int i = 0; i < sizeof(index)/sizeof(index[0]); i++){
		if(index[i]>-1){
			elements[k].ele = i;
			elements[k].count = m1[i];
			elements[k++].first = index[i];
		}	
	}

		
	stable_sort(elements, elements+k, mycomp);

	for(int i = 0; i < k; i++){
		for(int j = elements[i].count; j > 0 ;j--)
			cout<<elements[i].ele<<"  ";
	}
	cout<<endl;

	for(int i =0; i< k;i++){
		cout<<elements[i].ele<<" "<<elements[i].count<<" "<<elements[i].first<<"\n";
	}

	return 0;
}