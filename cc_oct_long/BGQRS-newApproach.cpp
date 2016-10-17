#include <bits/stdc++.h>

using namespace std;

typedef struct ele{
	long long int fives;
	long long int twos;
	//long long int val;
}ele;


long long int countFives(long long int x){
	long long int count5 = 0, count2 = 0;
	long long int oldx = x;
	while(x > 1){
		 
		if((x % 5) == 0){
			count5++;
			x = x / 5;	
		}
		
		if((x % 2) == 0){
			count2++;
			x = x / 2;
		}
		if(oldx == x)
			break;
		else
			oldx = x;
	}
	return count5;
}
long long int countTwos(long long int x){
	long long int count5 = 0, count2 = 0;
	long long int oldx = x;
	while(x > 1){
		 
		if((x % 5) == 0){
			count5++;
			x = x / 5;	
		}
		
		if((x % 2) == 0){
			count2++;
			x = x / 2;	
		}
		if(oldx == x)
			break;
		else
			oldx = x;
			
	}
	return count2;
}
long long int min(long long int x, long long int y){
	return (x < y) ? x : y;
}
ele arr[100000];	
int main()
{
	long long int t;
	cin>>t;
	while(t-- > 0){
		long long int n,m;
		cin>>n>>m;
		//ele arr[n];
		long long int a, b, c, d;
		long long int sum2 = 0, sum5 = 0; 
		long long int ans = 0;
		for (long long int i = 0; i < n; ++i)
		{
			arr[i].fives = 0;
			arr[i].twos = 0;
			//arr[i].val = 0;
		}
		long long int temp;
		for (long long int i = 0; i < n; ++i)
		{
			cin>>temp;
			arr[i].fives = countFives(temp);
			arr[i].twos = countTwos(temp);
            //cout<<"FROM0 "<<arr[i].fives<<" "<<arr[i].twos<<endl;

			//arr[i].val = temp;
		}
		// for (long long int i = 0; i < n; ++i)
		// {
		// 	cout<<arr[i].fives<<" "<<arr[i].twos<<endl;
		// }
		for (long long int i = 0; i < m; ++i)
        {
            cin>>a;
            if(a == 1){
                cin>>b>>c>>d;
                b--;
                c--;
                for (long long int j = b; j <= c; ++j)
                {
                    //updateValue(arr, st, n, j, arr[j]*d, arr[j]);
                    arr[j].fives += countFives(d);
                    arr[j].twos += countTwos(d);
                    //cout<<"FROM1 "<<arr[j].fives<<" "<<arr[j].twos<<endl;
                	// arr[j].fives = countFives(arr[j].val * d);
                	// arr[j].twos = countTwos(arr[j].val * d);
                	// arr[j].val = arr[j].val * d;
                }
                //cout<<endl;
                // for (long long int i = 0; i < n; ++i)
                // {
                //     cout<<arr[i]<<" ";
                // }
                // cout<<endl;
            }
            else if(a == 2){
                cin>>b>>c>>d;
                b--;
                c--;
                for (long long int j = b; j <= c; ++j)
                {
                    //updateValue(arr, st, n, j, d*(j-b+1), arr[j]);
                    arr[j].fives = countFives(d*(j-b+1));
                	arr[j].twos = countTwos(d*(j-b+1));
                	//arr[j].val = (d*(j-b+1));
                	//cout<<"FROM2"<<arr[j].fives<<" "<<arr[j].twos<<endl;
                }
                // cout<<endl;
                // for (long long int i = 0; i < n; ++i)
                // {
                //     cout<<arr[i]<<" ";
                // }
                // cout<<endl;
            }
            else{
                cin>>b>>c;
                b--;
                c--;
                sum5 = 0;
                sum2 = 0;
                for (long long int j = b; j <= c; ++j)
                {
                    sum5 += arr[j].fives;
                	sum2 += arr[j].twos;
                }
                //cout<<sum5<<" "<<sum2<<endl;
                //cout<<min(sum5, sum2)<<endl;
                ans += min(sum5, sum2); 
            }
        }
 		cout<<ans<<endl;
	}
	return 0;
}