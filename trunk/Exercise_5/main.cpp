// system includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// global namespace declaration
using namespace std;

// forward declaration 

void			PrintVector(const vector< int >& inVec);
void			EndOfExecPause();

// --------------------------------------------------------------------------
//		main
// --------------------------------------------------------------------------
int main ()
{
	int userIn;
	vector< int > vecIn;

	while ( cin >> userIn )
	{
		vecIn.push_back(userIn);
	}
	
	cout << "size: " << vecIn.size()
		<< "\n capacity: " << vecIn.capacity() << "\n";

	vecIn.resize(0);
	
	cout << "size: " << vecIn.size()
		<< "\n capacity: " << vecIn.capacity() << "\n";

	vecIn.reserve(2*vecIn.capacity());

	cout << "size: " << vecIn.size()
		<< "\n capacity: " << vecIn.capacity() << "\n";

	EndOfExecPause();

	return 0;
}

// --------------------------------------------------------------------------
//		PrintVector
// --------------------------------------------------------------------------
void
PrintVector(const vector< int >& inVec)
{
	cout << "[ " ;
	for ( int i=0; i<inVec.size(); ++i)
		cout << inVec[i] << " ";
	cout << "]\n";
	return;
}

// --------------------------------------------------------------------------
//		EndOfExecPause
// --------------------------------------------------------------------------
void 
EndOfExecPause()
{
	cin.clear();
	
	string a;
	cin >> a;
	cin >> a;
}

