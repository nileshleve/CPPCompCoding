#include <iostream>
#include <vector>
using namespace std; 
int main()
{
    int t;
    cin>>t;
    while(t-- > 0){
        string str1, str2, str3;
        int n;
        cin>>str1>>str2>>str3;
        cin>>n;
        int size1 = str1.size();
        int size2 = str2.size();
        int size3 = str3.size();
        int c1ones = 0;
        int c2ones = 0;
        int c3ones = 0;
        int cones = 0;
        int lastunset = -1;
        int temp = 0;
        for(int i = size3 - 1; i >= 0; i--)
        {
            temp = (int)str3[i] - 48;
            if(temp == 1)
                c3ones++;
            else if(lastunset == -1)
                lastunset = (size1 + (n * size2) + (i));
        }

        for(int i = size2 - 1; i >= 0; i--)
        {
            temp = (int)str2[i] - 48;
            if(temp == 1)
                c2ones++;
            else if(lastunset == -1){
                lastunset = (size1 + ((n-1) * size2) + i);
            }
        }
        
        for(int i = size1 - 1; i >= 0; i--)
        {
            temp = (int)str1[i] - 48;
            if(temp == 1)
                c1ones++;
            else if(lastunset == -1){
                lastunset = i;
            }
        }
        
        cones = c1ones + (c2ones * n) + c3ones;
        if(cones == size1 + (n * size2) + size3){
            cout<<1<<endl;
            continue;
        }
        cones += lastunset - (size1 + (n * size2) + size3) + 2;
        cout<<cones<<endl;
    }
    return 0;
} 