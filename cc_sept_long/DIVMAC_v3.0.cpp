#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 
int leastPrimeDivisor(int p);
int nextPrime(int number);
 
map<int, int> m1;
map<int, int> m2;
 
 
int max(int x, int y){
	if(x < y)
		return y;
	else
		return x;
}
 
 
void type0(int a[], int y, int z){
	int temp;
	for (int i = y; i <= z; i++)
	{
		if(a[i] != 1){
			if(m1.find(a[i]) == m1.end()){
				temp = leastPrimeDivisor(a[i]);
				m1[a[i]] = temp;
 
			}
			
			a[i] = a[i]/m1[a[i]];
		}
	}
}
 
void type1(int a[], int y, int z){
	int result = 1;
	int temp;
	for (int i = y; i <= z; i++)
	{
		if(a[i] != 1){
			if(m1.find(a[i]) == m1.end()){
				temp = leastPrimeDivisor(a[i]);
				m1[a[i]] = temp;
			}
				
			result = max(result, m1[a[i]]);
		}
	}
	cout<<result<<" ";
}
 
int leastPrimeDivisor(int p){
	int prime = 1;
 
	if(p % 2 == 0)
		return 2;
 
	while(prime <= sqrt(p)){
		prime = nextPrime(prime);
		if(p % prime == 0){
			return prime;
		}
	}
	return p;
}
 
int nextPrime(int no){
	int number = no;
	if(m2.find(no) != m2.end())
		return m2[no];
	int count = 0;
	number = number + 2;
	for (int i = 2; i < number; i++)
	{
		if(number % i == 0){
			count++;
			break;
		}
	}
	if(count == 0){
		m2[no] = number;
		return number;
	}
	else{
		int temp = nextPrime(number);
		m2[no] = temp;
		return temp;
	}
}
 
 
 
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t-- >0){
		int n,m;
		cin>>n>>m;
		int a[n];
		int x[m];
		int y[m];
		int z[m];
	
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
 
 
		for (int i = 0; i < m; i++)
		{
			cin>>x[i]>>y[i]>>z[i];
		}
 		



 
		for (int i = 0; i < m; i++)
		{
			if(x[i] == 0){
				type0(a, y[i]-1, z[i]-1);
			}
			else{
				type1(a, y[i]-1, z[i]-1);
			}
		}
 
 
	}
	return 0;
}  