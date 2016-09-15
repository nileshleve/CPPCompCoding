#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int leastPrimeDivisor(int p);
int nextPrime(int number);

int pno[1000000];

int max(int x, int y){
	if(x < y)
		return y;
	else
		return x;
}


void type0(int a[], int y, int z){
	for (int i = y; i <= z; i++)
	{
		if(a[i] != 1){
			a[i] = a[i]/leastPrimeDivisor(a[i]);
		}
	}
}

void type1(int a[], int y, int z){
	int result = 1;
	for (int i = y; i <= z; i++)
	{
		if(a[i] != 1)
			result = max(result, leastPrimeDivisor(a[i]));
	}
	cout<<result<<" ";
}

int leastPrimeDivisor(int p){
	int prime = pno[0];
	int i = 0;
	while(prime <= p){
		prime = pno[i++];
		if(p % prime == 0){
			return prime;
		}
	}
}

int nextPrime(int number){
	int count = 0;
	number = number + 2;
	for (int i = 2; i < number; i++)
	{
		if(number % i == 0){
			count++;
			break;
		}
	}
	if(count == 0)
		return number;
	else
		return (nextPrime(number));
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
		int max = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
			if(max < a[i])
				max = a[i];
		}


		for (int i = 0; i < m; i++)
		{
			cin>>x[i]>>y[i]>>z[i];
		}

		pno[0] = 2;
		pno[1] = 3;
		int test = (max/log(max))+100;
		for (int i = 2; i < test; i++)
		{
			pno[i] = nextPrime(pno[i-1]);
			//cout<<pno[i]<<" ";
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

		cout<<endl;
	}
	return 0;
}