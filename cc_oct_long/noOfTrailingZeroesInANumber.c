#include <stdio.h>
int main()
{
    long long n;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%lld", &n);

    while(n != 0)
    {
        if(n % 10 == 0){
            ++count;    
            n /= 10;
        }
        else
            break;
    }

    printf("Number of digits: %d", count);
}