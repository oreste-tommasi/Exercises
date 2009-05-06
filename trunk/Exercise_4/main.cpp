// system includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// global namespace declaration
using namespace std;

// forward declaration 
void			EndOfExecPause();
void			PrintVector(const vector< int >& inVec);

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

	cout << "Before sorting: ";
	PrintVector(vecIn);
	
	sort( vecIn.begin(), vecIn.end() );
	cout << "After sorting: ";
	PrintVector(vecIn);

	reverse ( vecIn.begin(), vecIn.end() );
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

