#include <iostream>

using namespace std;
int a[101], n, rezerva[101];
void sort (int st, int dr)
{
    if (st > dr)
        return ;
    else
    {
        int mij= (st+dr)/2;
        sort(st, mij);
        sort(mij+1, dr);
        int ind1 = st, ind2 = mij + 1, ind = 0;
        while(ind1 <= mij && ind2 <= dr)
        {
            if(a[ind1] <= a[ind2])
                rezerva[++ind]=a[ind1++];
            else
                rezerva[++ind]=a[ind2++];
        }
        while(ind1 <= mij)
            rezerva[++ind] = a[ind1++];
        while(ind2 <= dr)
            rezerva[++ind] = a[ind2++];
        for (int i = st; i <= dr; ++i )
            a[i]=rezerva[i - st + 1];
    }

}

int main ()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(1,n);
    for(int i = 1; i <= n; i++)
        cout<< a[i] << " ";

}