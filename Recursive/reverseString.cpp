#include<iostream>
#include<cstring>
using namespace std;

string reverse(string& str, int l)
{
    if(l==0)
    {
        return "";   
    }
    else{
        return str[l-1]+reverse(str, l-1);
    }

}

int main()
{
    string str="LANA ANVAR";
    size_t len=str.size();

    string reversed=reverse(str, len);

    cout<<reversed;

    return 0;
}