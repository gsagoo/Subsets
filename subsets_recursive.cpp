// Give a set of {1, 2 .., n} integers,  this code
// works out all the possible subsets of size k.

// RECURSIVE METHOD

// Compile with: g++ subsets_recursive.cpp -o subsets_rx -lm -O
// on Linux or Unix run with command ./subsets_rx

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include<limits>

using namespace std;

long counter = 0;
int child = 0;

void subset_recurse(long nk, long kk, long* &S, long k); 

int main (void)
{
    long n = 0, k = 5;
    while ( true )
    {
        cout << "This program works out the subsets of size k of (1,2, ..., n)\n";
        cout << "Enter a value for n: "; cin >> n;
        cout << "Enter a value for k: "; cin >> k;
        if( isnan(n) || isnan(k) || k  > n)
        {
            cout << "Input error!\nHit Enter to continue ...";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
            break;
    }
            
    long *pS = new long[k];
    subset_recurse( n, k, pS, k);
    cout << "\nThe number of subsets are: " << counter << endl;
    cout << n << " Choose " << k << " is " << counter << endl;   
    delete[] pS; 
    return(0);
}

void subset_recurse(long nk, long kk, long* &S, long k)
{ 
    if( kk == 1) //Must print out all the subsets
        {
            for( ; nk > 0 ; nk-- )
            {
                cout  << " {" << (S[0] = nk) ;
                for( int j = 1; j < k ; j++ )
                    cout << ", " << S[j];
                cout << "}" << "  subset number=" << setw(3) << ++counter << endl;
            }         
        }
    else
        for( ; nk > kk - 1; nk -- ) //Recursive call
            {
                S[kk-1] = nk;
                subset_recurse(nk -1, kk - 1, S, k);
            }
}
