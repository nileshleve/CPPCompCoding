// C program to show segment tree operations like construction, query
// and update
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
 
// A utility function to get the middle index from corner indexes.
long long int getMid(long long int s, long long int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range */
long long int getSumUtil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 1;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) *    
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes which have the given 
   index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is 
             in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(long long int *st, long long int ss, long long int se, long long int i, long long int diff, long long int si,long long int old_value)
{
    // Base Case: If the input index lies outside the range of 
    // this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update 
    // the value of the node and its children
    st[si] = (st[si]/old_value) * diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1, old_value);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2, old_value);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(long long int arr[], long long int *st, long long int n, long long int i, long long int new_val, long long int old_value)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    long long int diff = new_val;
    
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0, old_value);
}
 
// Return sum of elements in range from index qs (quey start)
// to qe (query end).  It mainly uses getSumUtil()
long long int getSum(long long int *st, long long int n, long long int qs, long long int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
long long int constructSTUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) *
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
long long int *constructST(long long int arr[], long long int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    long long int x = (long long int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    long long int max_size = 2*(long long int)pow(2, x) - 1; 
 
    // Allocate memory
    long long int *st = new long long int[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
 
long long int zeroes(long long int n)
{
    long long int count = 0;
    while(n != 0)
    {
        if(n % 10 == 0){
            ++count;    
            n /= 10;
        }
        else
            break;
    }
 
    return count;
}
 
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    long long int n, m;
    while(t-- > 0){
        cin>>n>>m;
        long long int ans = 0;
        long long int a, b, c, d;
        long long int arr[n];
        for (long long int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        // Build segment tree from given array
        long long int *st = constructST(arr, n);
 
        for (long long int i = 0; i < m; ++i)
        {
            cin>>a;
            if(a == 1){
                cin>>b>>c>>d;
                b--;
                c--;
                for (long long int j = b; j <= c; ++j)
                {
                    updateValue(arr, st, n, j, arr[j]*d, arr[j]);
                }
                // cout<<endl;
                // for (int i = 0; i < n; ++i)
                // {
                //     cout<<arr[i]<<" ";
                // }
                // cout<<endl;
            }
            else if(a == 2){
                cin>>b>>c>>d;
                b--;
                c--;
                for (long long int j = b; j <= c; ++j)
                {
                    updateValue(arr, st, n, j, d*(j-b+1), arr[j]);
                }
                // cout<<endl;
                // for (int i = 0; i < n; ++i)
                // {
                //     cout<<arr[i]<<" ";
                // }
                // cout<<endl;
            }
            else{
                cin>>b>>c;
                b--;
                c--;
                ans += zeroes(getSum(st, n, b, c));
 
                // ans = getSum(st, n, b, c);
                // cout<<ans;
            }
        }
 
        cout<<ans<<endl;
    }
    return 0;
} 