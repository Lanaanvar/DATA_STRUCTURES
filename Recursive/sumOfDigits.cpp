#include <iostream>
using namespace std;

int sum_dig(int n)
{
    int r, sum;

    if (n == 0)
    {
        sum = 0;
    }
    else
    {
        r = n % 10;
        sum = r + sum_dig(n / 10);
    }

    return sum;
}

int main()
{
    int x = sum_dig(5467);
    cout << x;

    return 0;
}