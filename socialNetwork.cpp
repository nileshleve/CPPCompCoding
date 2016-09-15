#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		int V;
		cin>>V;
		int edges[V];
		edges[0] = -1;
		int count;
		int temp = 0;
		int temp1;
		int temp2;
		stack<string> s;
		for (int i = 1; i < V; i++)
		{
			cin>>edges[i];
			edges[i]--;
		}
		for (int i = 1; i < V; i++)
		{
			temp1 = temp = i;
			temp2 = i;
			count = 1;
			while(edges[temp] != -1){
				temp = edges[temp1];
				stringstream ss;
				ss<<temp2+1<<" "<<temp+1<<" "<<count<<" ";
				string result = ss.str();
				s.push(result);
				temp1 = temp;
				count++;
			}
			while(!s.empty()){
				string str = s.top();
				s.pop();
				cout<<str;
			}
		}
		cout<<endl;
		
	}
	return 0;
}