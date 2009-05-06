// system includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// global namespace declaration
using namespace std;

// forward declaration 
void	EndOfExecPause();
void	PrintVector( const vector< int >& inVec);
bool	IsOdd ( int );


// --------------------------------------------------------------------------
//		main
// --------------------------------------------------------------------------
int main ()
{
	int userIn;
	vector< int > vecIn;

	while ( cin >> userIn )
	{
		vecIn.push_back( userIn );
	}
	
	PrintVector( vecIn );

	vector< int >::iterator myIter;
	
	myIter = remove_if( vecIn.begin() , vecIn.end() , IsOdd );

	cout << "\n\n";

	//vecIn.resize( myIter - vecIn.begin() );
	vecIn.erase( myIter, vecIn.end());

	PrintVector( vecIn );

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

// --------------------------------------------------------------------------
//		IsOdd
// --------------------------------------------------------------------------
bool
IsOdd (int i) 
{ 
	return i & 0x01; // ((i%2)==1); 
}


