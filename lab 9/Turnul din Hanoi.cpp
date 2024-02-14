#include <iostream>

using namespace std;

char source, dest , aux;
int n;
void han (int n, char a, char b, char c)
{
    if (n==1) cout<<a<<b<<endl;
    else
    {
        han(n-1,a,c,b);
        cout<<a<<b<<endl;
        han(n-1,c,b,a);
    }
}
int main (void )
{
    cout<<"n= ";
    cin>>n;
    source='a';
    dest='b';
    aux='c';
    han(n,source,dest,aux);
}