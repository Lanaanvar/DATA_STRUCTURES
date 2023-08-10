#include <iostream>
using namespace std;

void bubble_sort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
         
        }
        
    }
    for(int k=0; k<n; k++)
    {
        cout<<arr[k]<<" ";
    }
    
}

int main()
{
    int n;
    cout<<"Enter length of array : ";
    cin>>n;

    double array[n];
    cout<<"Enter "<<n<<" array elements :";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }
    cout<<"\nGiven array : ";
    for(int k=0; k<n; k++)
    {
        cout<<array[k]<<" ";
    }

    cout<<"\n\n";
    cout<<"After sorting : ";
    bubble_sort(array, n);

    return 0;
}