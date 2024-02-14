#include <iostream>

using namespace std;


int main()
{
    int n, i, s=0, nr1, nr2;
    cout<<"Primele cate numere al sirului Fibonacci se vor afisa?: ";
    cin>>n;
    nr1=0;
    nr2=1;
    cout<<nr1<<" , "<<nr2;
    for( i = 1; i <= n; i++ )
        {
            s=nr1 + nr2;
            nr1 = nr2;
            nr2 = s;

            cout<<" , "<<s;
        }
    cout<<"."<<"\n";
    
}
