#include <iostream>
using namespace std;
#define ROWS 4
#define COLS 5
main()
{
int table[ROWS][COLS]=
{ {13,15,17,19,21},
{20,22,24,26,28},
{31,33,35,37,39},
{40,42,44,46,48} };
int konst=10;
int j,k;
for(j=0;j<ROWS;j++)
for(k=0;k<COLS;k++){
cout<<table[j][k]<<"->";
table[j][k]=*(*(table+j)+k)+konst;
cout<<*(*(table+j)+k)<<" ";
if (k==COLS-1) cout<<"\n";
}
}
