#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
bool isGood(string a, int src, int visited[], int countVisited){
			
	if(a.size() == 1)
		return true;

	for (int i = 0; i < a.size() - 2; ++i){

		if(a[i] - 48 == 1)
			continue;
		if((a[i] - 48) == 2 && (a[i + 1] - 48) == 2 && (a[i + 2] - 48) == 1)
			i = i + 2;
		else
			return false;
	}
	if(a.size() >= 2){
		if((a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 2)
			return false;
	}
	
	if(a.size() >= 3){
		if((a[a.size() - 3] - 48) == 1 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 2)
			return false;
		if((a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 1)
			return false;
		if((a[a.size() - 3] - 48) == 1 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 1)
			return false;
	}
	if(a.size() >= 4){
		if((a[a.size() - 4] - 48) == 2 && (a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 1 && (a[a.size() - 1] - 48) == 2)
			return true;
	} 
	if(a.size() >= 3){
		if((a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 1 && (a[a.size() - 1] - 48) == 2)
			return false;
	}


	return true;
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- > 0){
		string a, b;
		cin>>a>>b;
		long long int count = 0;
		int set_size = a.size();

		string temp = a, temp1 = b;
		char t;
		int visited[set_size];
		int visited1[set_size];
		int countVisited = 0;
		int countVisited1 = 0;

		unsigned int pow_set_size = pow(2, set_size);
	    int counter, j;
	    for(counter = 0; counter < pow_set_size; counter++)
	    {
	      for(j = 0; j < set_size; j++)
	       {
	        	if(counter & (1<<j)){
		          	//printf("%d", j);
		          	t = temp[j];
		          	temp[j] = temp1[j];
		          	temp1[j] = t;
				}
	        }
	        countVisited = 0;
			countVisited1 = 0;
			for (int i = 0; i < set_size; ++i)
			{
				visited[i] = 0;
				visited1[i] = 0;
			}
	        //cout<<"\t\t"<<temp<<"\t\t"<<temp1<<"    ";
			if(isGood(temp, 0, visited, countVisited) && isGood(temp1, 0, visited1, countVisited1)){
				count++;
				//cout<<"\t\t"<<temp<<"\t\t"<<temp1<<"    ";
				//cout<<count<<endl;
			}
			//cout<<endl;
			temp = a;
		    temp1 = b;
	       //printf("\n");
	    }
	    cout<<((count + MOD) % MOD)<<endl;	
	}
	return 0;
}