#include <bits/stdc++.h>
using namespace std;
// long long int lcm(long long int a, long long int b){
	
// 	long long int m, n;
// 	m = a;
//     n = b;
//     while(m != n)
//     {
// 		if(m < n)
// 		{
// 			m = m + a;
// 		}
// 		else
// 		{
// 	    	n = n + b;
// 	    }
//     }
//     return m;
//     //cout<<"\nL.C.M of "<<a<<" and "<<b<<" is "<<m;
// }

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}


long long int lcm(long long int a, long long int b)
{
  return (a*b)/gcd(a,b);
}


// long long int lcm(long long int a, long long int b){
// 	long long int n1, n2, i, gcd, lcm;

//     n1 = a;
//     n2 = b;

//     for(i=1; i <= n1 && i <= n2; ++i)
//     {
//         // Checks if i is factor of both integers
//         if(n1%i==0 && n2%i==0)
//             gcd = i;
//     }

//     lcm = (n1*n2)/gcd;
//     //printf("The LCM of two numbers %d and %d is %d.", n1, n2, lcm);
//     return lcm;
// }


int main()
{
	long long int t;
	cin>>t;
	while(t-- > 0){
		long long int n;
		cin>>n;
		set<long long int> s;
		vector<long long int> vec;
		long long int a[n];
		for (long long int i = 0; i < n; ++i)
		{
			cin>>a[i];
			if(s.find(a[i]) == s.end()){
				s.insert(a[i]);
			}
		}
		sort(a, a+n);
		
		for (int i = 1; i < n; ++i)
		{
			if(a[i-1] == a[i])
				vec.push_back(a[i]);
		}
		

		set<long long int> s1;
		long long int temp = a[0];
		for (long long int i = 1; i < n; ++i)
		{
			temp = lcm(a[i], temp);
			if(s.find(temp) != s.end()){
				vec.push_back(temp);
				break;
			}
			else{
				vec.push_back(temp);
			}
		}
		long long int min = INT_MAX;
		vector<long long int>::iterator it;
		for (it = vec.begin(); it != vec.end(); ++it)
		{
			if(min > *it)
				min = *it;
		}
		int i = 1;
		int br = 0;
		while(a[i] < min){
			for (int j = 0; j < i; ++j)
			{
				if(a[i] % a[j] == 0){
					min = a[i];
					br = 1;
					break;
				}
			}
			i++;
			if(br == 1)
				break;
		}
		cout<<min<<endl;;
	}
	return 0;
}