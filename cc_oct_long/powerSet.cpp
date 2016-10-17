#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;
void printPowerSet(int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    int a[10] = {1,1,1,1,1,1,1,1,1,1};
    int temp[10] = {1,1,1,1,1,1,1,1,1,1};
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
            //printf("%d", j);
            temp[j] = 2;
       }
       //printf("\n");
       for (int i = 0; i < 10; ++i)
       {
         cout<<temp[i];
         temp[i] = a[i];
       }
       cout<<endl;
    }
}
 
/*Driver program to test printPowerSet*/
int main()
{
    printPowerSet(10);
 
    getchar();
    return 0;
}