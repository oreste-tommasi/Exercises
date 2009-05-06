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
		vecIn.push_back( userIn );
	}
	
	PrintVector( vecIn );

	vector< int >::iterator myIter;

	int valueFind;

	cin.clear();

	string a;
	cin >> a;
	
	// Ricerca e swap

	cin >> valueFind;

	myIter=find( vecIn.begin(), vecIn.end(), valueFind ); 
	if ( myIter != vecIn.end() )
		swap( *myIter, *vecIn.begin() );


	// Inserimento

	cin >> temp;
	
	for( myIter=vecIn.begin() ; myIter < vecIn.end() ; ++ myIter)
	{
		if ( temp > *myIter )
		{
			vecIn.insert((myIter+1),temp);
			break;
		}
			
	}

	PrintVector(vecIn);

	
	// Cancellazione

	cin >> temp;

	for( myIter=vecIn.begin() ; myIter < vecIn.end() ; ++ myIter)
	{
		if ( temp < *myIter )
		{
			vecIn.erase(myIter);
			break;
		}
			
	}

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

