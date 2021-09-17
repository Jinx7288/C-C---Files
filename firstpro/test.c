#include<stdio.h>
#include<math.h>
int isPrime(int n) {
    int k = sqrt(n);
    for (int i = 2; i < k+1; i++)
    {
        if (n%i ==0)
        {
            return 0;
        }
    }
    return 1;
}
int main() {
    printf("%d", isPrime(13));
}