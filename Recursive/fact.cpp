#include <iostream>
using namespace std;

int factorial(int x)
{
    int fact;
    if (x == 0)
    {
        fact = 1;
    }
    else
    {
        fact= x*factorial(x-1);
    }

    return fact;
}

int main()
{
    int n;

    cout<<"ENTER NUMBER : ";
    cin>>n;

    cout<<"\n";

    cout<<"FACTORIAL OF "<<n<<" : "<<factorial(n);

    cout<<"\n\n";

    return 0;
}