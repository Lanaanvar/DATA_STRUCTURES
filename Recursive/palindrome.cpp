#include<iostream>
#include<cstring>
using namespace std;

void palindrome(const string& str, int start, int end)
{
    if(start>=end)
    {
        cout<<"THE STRING IS PALINDROME ";
    }
    else if(str[start]==str[end])
    {
        palindrome(str, start+1, end-1);
    }
    else
    {
        cout<<"NOT PALINDROME";
    }
}

int main()
{
    string str="malayalam";
    int start=0;
    int end=str.length()-1;
    palindrome(str, start, end);

    return 0;
}