#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        for(int i =0;i<(sizeof(a)/sizeof(a[0]));i++)
        {
        
            for(int j =i;j<(sizeof(a)/sizeof(a[0]));j++){
                if(a[j]>a[i]){
                    cout<<a[j]<<" ";
                    break;
                }
                else if(j == n-1){
                    cout<<"-1 ";
                    break;
                }
                else
                    continue;
                
            }
        }
        cout<<endl;
        
        
        
    }


	return 0;
}