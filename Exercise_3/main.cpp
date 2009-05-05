// system includes
#include <iostream>
#include <vector>
#include <string>

// global namespace declaration
using namespace std;

// forward declaration 
void			EndOfExecPause();
// void			PrintVector(const vector< int >& inVec);

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
	
	//cout << "dimensione: " << vecIn.size()
	//	  << "\n";
	
	//PrintVector( vecIn );
	vector< int >::iterator myIter;
	for( myIter=vecIn.begin() ; myIter < (vecIn.end() - 1) ; ++ myIter)
	{
		if ( *myIter > *(myIter + 1))
			cout << *myIter;
	}

	EndOfExecPause();

	return 0;
}

// --------------------------------------------------------------------------
//		PrintVector
// --------------------------------------------------------------------------
//void
//PrintVector(const vector< int >& inVec)
//{
//	cout << "[ " ;
//	for ( int i=0; i<inVec.size(); ++i)
//		cout << inVec[i] << " ";
//	cout << "]\n";
//	return;
//}

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

