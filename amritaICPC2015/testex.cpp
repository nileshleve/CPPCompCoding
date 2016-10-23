#include <bits/stdc++.h>
#define s(n) scanf("%d", &n)
 
using namespace std;
 
void solve(int st, int n, int k)
{
    if(k == 0)
    {
        int i;
        for(i=st; i < n+st-1; i++)
            printf("%d ", i);
        printf("%d ", i);
    }
    else
    {
        if(n < 2*k)
        {
            printf("-1");
        }
        else
        {
            if(n<4*k)
            {
                int i;
                if(n <= 3*k)
                {
                    for(i=k+st; i<=st+n-1; i++)
                        printf("%d ", i);
                    for(i=st; i<k+st-1; i++)
                        printf("%d ", i);
                    printf("%d ", i);
                }
                else
                {
                    int r = n-3*k;
                    for(i=k+st; i<=st+2*k-1; i++)
                        printf("%d ", i);
                    for(i=st; i<=st+n-3*k-1; i++)
                        printf("%d ", i);
                    for(i=r+1+2*k+st-1; i<=st+n-1; i++)
                        printf("%d ", i);
                    for(i=r+1+st-1; i<=k+st-1; i++)
                        printf("%d ", i);
                    for(i=2*k+1+st-1; i<=2*k+r+st-1; i++)
                        printf("%d ", i);
                }
            }
            else
            {
                solve(st, 2*k, k);
                solve(st+2*k, n-2*k, k);
            }
        }
    }
}
 
int main()
{
    int T;
    s(T);
    while(T--)
    {
        int N, K;
        s(N);
        s(K);
        solve(1, N, K);
        printf("\n");
    }
    return 0;
}
 
//Comments 
