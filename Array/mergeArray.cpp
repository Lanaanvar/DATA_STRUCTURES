#include<iostream>
#include<algorithm>
using namespace std;

void merge_array(int arr1[], int arr2[], int arr3[], int n)
{
    sort(arr1, arr1+n);

    for(int a=0; a<n; a++)
    {
        cout<< arr1[a]<<", ";
    }

    cout<<"\n";

    sort(arr2, arr2+n);

    for(int a=0; a<n; a++)
    {
        cout<< arr2[a]<<", ";
    }

    cout<<"\n";


    int n3=0;
    for (int i=0; i<n; i++)
    {
        arr3[n3]=arr1[i];
        n3++;

    }

    for(int j=0; j<n; j++)
    {
        arr3[n3]=arr2[j];
        n3++;
    }


    sort(arr3, arr3+n3);
    reverse(arr3, arr3+n3);

    for(int k=0; k<n3; k++)
    {
        cout<< arr3[k]<<", ";
    }

    
}

int main()
{
    int arr1[5]={34, 10, 589,3,0};



    int arr2[5]={45,22,9000,4,224};

    

    int arr3[10];

    // int merged_array=merge_array(arr1, arr2, arr3, 5, 5);

    merge_array(arr1, arr2, arr3, 5);

    return 0;
}