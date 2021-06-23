#include <bits/stdc++.h>
using namespace std;

// Stupid compiler - GFG

https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

// maxEndingHere stores the positive products of the previous index.
// minEndingHere stores the negative products of the previous index.
// maxTillNow stores the maximum product till now.

// maxEndingHere will be the maximum of: only current value OR minEndingHere * current value (if both current value and previous index are negative) OR maxEndingHere * current value (if both previous product and current value are positive).
// minEndingHere will be the minimum of: only current vaue OR minimiumEndingHere * current Value (if current value is positive and last value is negative) OR maxEndingHere * currentValue (if previous value is positive but current value is negative).
// since maxEndingHere is getting updated, we are storing its previous value in temp.

// store the value of max of maxEndingHere and previous max value.


long long maxProduct(int *arr, int n) {
    long long maxEndingHere = arr[0], minEndingHere = arr[0], maxTillNow = arr[0];

    for(int i = 1; i < n; i++) {
        long long temp = maxEndingHere;
        maxEndingHere = max(max(maxEndingHere * arr[i], arr[i]), minEndingHere * arr[i]);
        minEndingHere = min(minEndingHere * arr[i], min(arr[i], temp * arr[i]));

        maxTillNow = max(maxTillNow, maxEndingHere);
    }

    return maxTillNow;
}



// Code that actually works -

long long maxProduct(int *A, int N ) {

    long long maxP , minP , res ;

    maxP = minP = res = 1 ;

    for( int i = 0 ; i < N ; i++ )
    {
        long long  x = A[i];

        if( x < 0 ) swap( maxP , minP );

        maxP = max( x , x*maxP );
        minP = min( x , x*minP );

        res = max( res , maxP );
    }


    return res ;

}
