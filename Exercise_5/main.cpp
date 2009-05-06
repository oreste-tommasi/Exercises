// system includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// global namespace declaration
using namespace std;

// forward declaration 

void			PrintVector(const vector< int >& inVec);
void			ReadVector(vector< int >& inVec, bool inEmpty = true );
void			EndOfExecPause();

// --------------------------------------------------------------------------
//		main
// --------------------------------------------------------------------------
int main ()
{
	vector< int > vecIn;

	ReadVector( vecIn );
	PrintVector( vecIn );
		
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
ReadVector( vector< int >& inVec, bool inEmpty)
{
	int userIn;

	if ( inEmpty )
		inVec.resize(0);
	
	while ( cin >> userIn )
		inVec.push_back(userIn);
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

