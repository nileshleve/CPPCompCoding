#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 
int leastPrimeDivisor(int p);
int nextPrime(int number);
 
map<int, int> m1;
map<int, int> m2;
 

int simpleSieve(int limit, vector<int> &prime)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
 
    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
 	int temp = 1;
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            m2[temp] = p;
            temp = p;
            //cout << p << "  ";
        }
    }
    return temp;
}
 
// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;  
    int temp  = simpleSieve(limit, prime); 
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low  = limit;
    int high = 2*limit;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            /*  Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100]  marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range  */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 		
        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true){
            	m2[temp] = i;
            	temp = i;

                //cout << i << "  ";
            }
 
        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}

 
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

	while(prime <= sqrt(p)){
		//prime = nextPrime(prime);
		prime = m2[prime];
		if(p % prime == 0){
			return prime;
		}
	}
	return p;
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
 		
		m2[0] = 2;
		m2[1] = 3;
		m2[3] = 5;
		m2[5] = 7;
		m2[2] = 3;

		int hello;
		segmentedSieve(max);
	 
		for (int i = 0; i < m; i++)
		{
			if(x[i] == 0){
				type0(a, y[i]-1, z[i]-1);
			}
			else{
				type1(a, y[i]-1, z[i]-1);
			}
		}

		// int qwer;
		// hello = 1;
		// // for (int i = 0; i < 100; i)
		// // {	
		// // 	qwer = m2[hello];
		// // 	cout<<qwer<<" ";
		// // 	hello = qwer;
		// // }
 
	}

	return 0;
}  