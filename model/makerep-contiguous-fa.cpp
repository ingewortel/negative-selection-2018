#include <iostream>
#include <vector>
#include <cstdlib> 

#include "dfa.hpp"
#include "aminoacids.hpp"

using namespace std;

inline int c2i( int c ){
	return aa_goedel[c-'A'];
}

DFA<N_AMINOACIDS+1> branch( int n ){
	DFA<N_AMINOACIDS+1> R;
	map<long,long> Vcode;

	if( n == 0 ){ 
		R.addState( 0, Vcode );
		R.setAccepting( 0, Vcode );
		return R; 
	};

	int i, l;
	int acc = n;
	R.addState( 0, Vcode );
	for( l = 0 ; l < n ; l ++ ){
		R.addState( l+1, Vcode );
		for( int k = 0 ; k < N_AMINOACIDS ; k ++ ){
			R.addEdge( l, l+1, c2i(aminoacids[k]), Vcode );
		}
	}

	R.setAccepting( acc, Vcode );

	return R;
}

int main( int argc, char * argv[] )
{
	if( argc < 2 ){
		cerr << "Usage : " << argv[0] << " [n] " << endl;
		exit(1);
	}
	int n = atoi( argv[1] ); 
	DFA<N_AMINOACIDS+1> A = branch( n );
	A = A.minimize();
	A.print();
}
