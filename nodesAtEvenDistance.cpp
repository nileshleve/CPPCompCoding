#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> a[], vector<int> &vis, int s, int flg, int &odd, int &even)
{
    vis[s] = 1;
    //cout<<"ha "<<s<<"ha  ";
    flg = 1 - flg;
    if(flg == 0) even++;
    else odd++;
    
    for(int i=0;i<a[s].size();i++)
    {
        if(!vis[a[s][i]])
        {
            dfs(a,vis,a[s][i],flg,odd,even);
        }
    }
}

int main()
{
     int t,n;
     cin>>t;
     for(int j=0;j<t;j++)
     {
        cin>>n;
        vector<int> a[n];
        //vector<int> temp(2*n-2,0);
         
        int p, count=0, x;
        for(int i = 0;i<2*n-2;i++) 
        {
            count++;
            if(count%2 == 0)
            {
                cin>>x;
                a[p-1].push_back(x-1);
                a[x-1].push_back(p-1);
            }
            else 
                cin>>p;
        }
        
        vector<int> vis(n,0);
        int flg=1, odd=0, even=0,s=0;
         
        dfs(a, vis,s,flg,odd,even);
        cout<<endl<<"  "<<odd<<"   "<<even; 
        int ans = (odd*(odd-1))/2 + (even*(even-1))/2;
        cout<<ans<<endl;
     }
     return 0;
}
