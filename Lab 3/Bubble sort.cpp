#include <iostream>

using namespace std;

int main( )
{
    int a[101];
    int n , i;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for(i = 1; i < n; i++)
         for(int j =i + 1; j <= n; j++)
        if (a[i] > a[j])
            swap (a[i] , a[j]);
     for(i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
}