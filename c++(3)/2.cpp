#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main()
{
    char b[101];
    cin>>b;
    for (int i=0;i<=strlen(b);i++)
    cout<<char(toupper(b[i]));
    return 0;
    
}
