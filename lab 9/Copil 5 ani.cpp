#include <iostream>

using namespace std;

int inmultire ( int n, int i ){

    if ( i > 10 )
        return 0;

    else{
        cout<<n<< " * " << i << " = "<< n*i<<"\n";
        inmultire(n,i+1);
    }

}


int main(){
    int n ;
    int i=1;
    cout<<"Numarul cu care se realizeaza inmultirea pana la 10: ";
    cin>>n;
    inmultire(n , i);


}