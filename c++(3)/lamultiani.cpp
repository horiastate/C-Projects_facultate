#include <iostream>
#include <fstream>

using namespace std;
ifstream mesaje;
int main()
{
    char vector[11];
    mesaje.open("mesaj2.dat",ios::binary);
    for(int i=1;i<=11;i++)
        {
            mesaje.read((char*)&vector[i],sizeof(char));
            cout<<vector[i]<<" ";
        }
}
