#include<iostream>
using namespace std;

int duplicate_count(char arr[], int n)
{
    int freq[256]={0};
    int count=0;
    for (int i=0; i<n; i++)
    {
        freq[arr[i]]++;
    }

    for(int j=0; j<256; j++)
    {
        if(freq[j]>1)
        {
            count++;
        }
        else{
            count=count;
        }
    }

    return count;
}

int main()
{
    char arr[7]={'f','d','r','c','d','c','r'};

    int count=duplicate_count(arr,7);

    cout<<count;

    return 0;
}