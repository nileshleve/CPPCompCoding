#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

bool isGood(string a, int src, int visited[], int countVisited){
	if(src < 0 || src > a.size() - 1)
		return false;
	//cout<<src<<endl;

	if(src == a.size() - 1){
		for (int i = 0; i < a.size() - 1; ++i)
		{
			if(visited[i] == 0)
				return false;
		}
		return true;
	}

	if(visited[src] == 1)
		return false;
	visited[src] = 1;
	countVisited++;
	if((a[src] - 48) == 1){
		
		if(isGood(a, src + 1, visited, countVisited) || isGood(a, src - 1, visited, countVisited)){
			return true;
		}
		else{
			visited[src] = 0;
			countVisited--;
			return false;
		}
	}
	else{
		if(isGood(a, src + 2, visited, countVisited) || isGood(a, src - 2, visited, countVisited)){
			return true;
		}
		else{
			visited[src] = 0;
			countVisited--;
			return false;
		}
	}
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

// 1221122111
// 1112211211