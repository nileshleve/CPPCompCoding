
	#include <bits/stdc++.h>
	using namespace std;
	bool isGood(string a, int src, int visited[], int countVisited){
		
		// if((a[a.size() - 2] - 48) == 1 && (a[a.size() - 1] - 48) == 2)
		// 	return true;

		// for(int i=0;i<a.size();i++)
		// {
		// 	if(a[i]-48==2)
		// 	{
		// 		int count=0;
		// 		while(i<a.size() && a[i]-48!=1)
		// 		{
		// 			i++;
		// 			count++;
					
		// 		}
		// 		if(count == 2)
		// 			return true;
		// 		else{
		// 			return false;
		// 		}
		// 	}
		// }
		
		for (int i = 0; i < a.size() - 2; ++i)
		{
			if((a[i] - 48) == 1)
				continue;



			if((a[i] - 48) == 2){
				if((a[i + 1] - 48) == 2){
					if((a[i + 2] - 48) == 1){
						i = i + 2;
					}
					else{
						return false;
					}
				}
			}
			else
				return false;
		}
		if((a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 2)
			return false;
		if((a[a.size() - 3] - 48) == 1 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 2)
			return false;
		if((a[a.size() - 3] - 48) == 2 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 1)     // Very bad (Back to square ONE)
			return false;
		if((a[a.size() - 3] - 48) == 1 && (a[a.size() - 2] - 48) == 2 && (a[a.size() - 1] - 48) == 1)
			return false;
		
		return true;
	}




	int main(int argc, char const *argv[])
	{
		int t;
		cin>>t;
		while(t-- >0){
			string a, b;
			cin>>a>>b;
			int count = 0;
			int set_size = a.size();

			string temp = a, temp1 = b;
			char t;
			int visited[set_size];
			int visited1[set_size];
			int countVisited = 0;
			int countVisited1 = 0;

			unsigned int pow_set_size = pow(2, set_size);
		    int counter, j;
		    /*Run from counter 000..0 to 111..1*/
		    for(counter = 0; counter < pow_set_size; counter++)
		    {
		      for(j = 0; j < set_size; j++)
		       {
		          /* Check if jth bit in the counter is set
		             If set then pront jth element from set */
		        	if(counter & (1<<j)){
			          	// printf("%d", j);
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
				}
				for (int i = 0; i < set_size; ++i)
				{
					visited1[i] = 0;
				}
		        //cout<<temp<<"\t\t"<<temp1<<endl;
				if(isGood(temp, 0, visited, countVisited) && isGood(temp1, 0, visited1, countVisited1)){
					count++;
					//cout<<count<<endl;
				}
				temp = a;
			    temp1 = b;
		       //printf("\n");
		    }
		    cout<<count<<endl;	
		}
		return 0;
	}