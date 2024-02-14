#include <iostream>
using namespace std;

int main() {
	int an;
	cin>>an;
	if(an % 400 == 0) cout<<"An Bisect";
	else if(an % 100 == 0) cout<<"Nu este an Bisect";
	else if(an % 4 == 0) cout<<"DA";
	else cout<<"NU";
}
