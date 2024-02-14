#include <iostream>
#include <math.h>
using namespace std;

void citire(int a[],int b[]){
    for (int i=1;i<=10;i++)cin>>a[i];
    for (int i=1;i<=10;i++)cin>>b[i];
    int dist=sqrt((a[10]-a[1])*(a[10]-a[1])+(b[10]-b[1])*(b[10]-b[1]));
    cout<<"Distanta de la primul la ultimul punct este: "<<dist<<". \n";
}

void distanta(int a[],int b[]){
    int m,n,distmed=0,k=0,dist;
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++){
            int m=(a[j]-a[i])*(a[j]-a[i]);
            int n=(b[j]-b[i])*(b[j]-b[i]);
            dist=sqrt(m+n);
            k++; distmed+=dist;
        }
    distmed/=k;
    cout<<"Distanta medie intre doua puncte este: "<<distmed<<". \n";
}
 int main(){
    int x[11],y[11];
    citire(x,y);
    distanta(x,y);
    return 0;
}
