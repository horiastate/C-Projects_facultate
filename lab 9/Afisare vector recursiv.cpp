#include <iostream>

using namespace std;

int vector[20];
int i=1;

int afisare(int vector[], int n, int i){
    if( i > n )
        return 0;
    else{
        cout<<vector[i]<<" ";
         return afisare(vector, n , i+1);
    }
}

int main(){

    int n;
    int i;
    cout<<"Lungimea vectorului este de: ";
    cin>>n;

    for( i = 1; i <= n ; i++ )
        cin>>vector[i];
    
    afisare(vector, n, 1);    

}