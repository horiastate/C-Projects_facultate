#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
    char S[100];
    int voc, cons, nr, sg;
    voc=cons=nr=sg=0;
    cout<<"Se introduce: ";
    cin.getline(S,99);
    char Vocale[]="aeiouAEIOU";
    char Numere[]="0123456789";
    for(int i=0; i<strlen(S); i++)
    { if(strchr(Vocale,S[i]) != NULL)
      {voc++;
        }
     else { cons++; }
        if(strchr(Numere, S[i]) != NULL) {
         nr++;
        }
        else if(S[i]==' ') {
            sg++;
        }
    }
    cout<<"vocale "<<voc<<endl;
    cout<<"consoane "<<cons<<endl;
    cout<<"cifre "<<nr<<endl;
    cout<<"spatii "<<sg<<endl;
}





