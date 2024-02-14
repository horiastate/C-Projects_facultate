#include <fstream>
#include <iostream>
using namespace std;

int main() {
	
	ifstream file ("circuit.jpg", ios::binary);
	
	char byte;
	
	file.read(&byte, 1 );
	
	cout << (( byte >> 0 )&1 )<<endl;
	
	file.seekg( -1, ios::end );
		
	file.read( &byte ,1 );
	
	cout << (( byte >> 0 )&7);
	
	file.close();
	
	return 0;
	
}

