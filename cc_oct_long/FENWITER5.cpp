#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t-- > 0){
        string str1, str2, str3;
        int n;
        int count = 0;
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        cin>>str1>>str2>>str3;
        cin>>n;
        int temp = 0;
        int carry = 1;
        int arr[str3.size()];

        for (int i = 0; i < str1.size(); ++i)
        {
            temp = (int)str1[i] - 48;
            if(temp == 1)
                c1++;
        }
        for (int i = 0; i < str2.size(); ++i)
        {
            temp = (int)str2[i] - 48;
            if(temp == 1)
                c2++;
        }
        for (int i = 0; i < str3.size(); ++i)
        {
            arr[i] = (int)str3[i] - 48;
            if(arr[i] == 1)
                c3++;
        }
        int ans = 0;
        if(c3 == str3.size()){
            ans = c1 + (c2*n);
        }
        else{
            for (int i = str3.size()-1; i >= 0; i--)
            {
                if(carry == 0)
                    break;
                else if(arr[i] + carry == 2){
                    arr[i] = 0;
                    c3--;
                    carry = 1;
                }
                else if(arr[i] == 0 && carry == 1){
                    arr[i] = 1;
                    c3++;
                    carry = 0;
                }
            }  
            ans = c1 + (c2*n) + c3;
        }
        cout<<ans<<endl;
    }
    return 0;
} 