#include<iostream>
using namespace std;

int SecLargest(int arr[], int n)
{
    int l=1;
    int sl=0;

    for(int i=0; i<n; i++)
    {
        if (arr[i]>l)
        {
            sl=l;
            l=arr[i];
        }
        else if(arr[i]<l && arr[i]>sl)
        {
            sl=arr[i];
            l=l;
        }
    }

    return sl;
}

int main()
{
    int arr[7]={45,4,100,56,39,34,100};

    int secondLargest= SecLargest(arr, 7);

    cout<<secondLargest;

    return 0;
}