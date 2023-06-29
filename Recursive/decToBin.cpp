#include <iostream>
using namespace std;

void Binary(int n)
{

    if (n == 1)
    {
        cout << "1";
    }
    else
    {
        Binary(n / 2);
        cout << n % 2;
    }
}

int main()
{
    Binary(294);

    return 0;
}