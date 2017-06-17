
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 ; 

long long int a,b,c,d;

void fast_fib(long long int n,long long int ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}




// To store segment tree
int *st;
 
// Function to find gcd of 2 numbers.
long long int gcd(long long int a, long long int b)
{
    if (a < b)
        swap(a, b);
    if (b==0)
        return a;
    return gcd(b, a%b);
}
 

long long int findGcd(long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
    if (ss>qe || se < qs)
        return 0;
    if (qs<=ss && qe>=se)
        return st[si];
    long long int mid = ss+(se-ss)/2;
    return gcd(findGcd(ss, mid, qs, qe, si*2+1),
               findGcd(mid+1, se, qs, qe, si*2+2));
}
 

long long int findRangeGcd(long long int ss, long long int se, long long int arr[], long long int n)
{
    
    return findGcd(0, n-1, ss, se, 0);
}
 

long long int constructST(long long int arr[], long long int ss, long long int se, long long int si)
{
    if (ss==se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    long long int mid = ss+(se-ss)/2;
    st[si] = gcd(constructST(arr, ss, mid, si*2+1),
                 constructST(arr, mid+1, se, si*2+2));
    return st[si];
}
 

int *constructSegmentTree(long long int arr[], long long int n)
{
   long long int height = (long long int)(ceil(log2(n)));
   long long int size = 2*(long long int)pow(2, height)-1;
   st = new int[size];
   constructST(arr, 0, n-1, 0);
   return st;
}
 

int main()
{
    long long int n, q;
    cin>>n>>q;
    long long int arr[n];
    long long int a[n];
    for (long long int i = 0; i < n; ++i)
    {
    	cin>>arr[i];
    	long long int ans[2] = {0};
    	fast_fib(arr[i], ans);
    	a[i] = (int)ans[0];	
    }
    
    constructSegmentTree(a, n);
 
    long long int l, r;
    for (long long int i = 0; i < q; ++i)
    {
    	cin>>l>>r;
    	cout << ((findRangeGcd(l-1, r-1, a, n)) % 1000000007 ) << "\n";
    }
 
    return 0;
}