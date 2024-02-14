
#include <iostream>
using namespace std;
int main()
{
  unsigned a,b,c;
  int ok=1;
  cout<<"Lungimea laturii AB este ";
  cin>>a;
  cout<<"Lungimea laturii BC este ";
  cin>>b;
  cout<<"Lungimea laturii CA este ";
  cin>>c;
   if(a<b+c && b<a+c && c<a+b)
   {
       if(a==b && b==c)
           cout<<"triunghi echilateral";
       else
           if(a==b)
               cout<<"triunghi isoscel cu laturile congruente AB si BC si baza AC";
           else
               if(b==c)
                   cout<<"triunghi isoscel cu laturile congruente BC si CA si baza AB";
               else
                   if(a==c)
                       cout<<"triunghi isoscel cu laturile congruente AB si CA si baza BC";
                   else
                       cout<<"triunghi oarecare";
   }
   else
       cout<<"Triunghiul nu poate fi format deoarece valorile sunt gresite";
   return 0;
} 
