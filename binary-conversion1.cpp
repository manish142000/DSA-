    /*this code returns positive if a smaller binary number can be converted to a larger binary number 
            number containing same or more count of set bits else negetive by adding some number */

/*https://codeforces.com/problemset/problem/1491/D*/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define MX 1000000007
const int p = 1e6+ 1 ;
const ll inf = 1e18 ;
const ll mod = 998244353 ;
using namespace std ;


int main()
{
    int a[] = {1,0,1,1,0,0,0,1} ;
    int b[] = {0,0,0,1,0,1,1,1} ;
    
    //b is smaller than a can b be converted into a by adding some number
    bool flag = true ;
    for( int i = 0 ; i < 8 ; i ++ )
    {
        if(a[i]!=b[i])
        {
            if(b[i]){ flag  = false  ; }
            
            int temp = i+1 ;
            
            while(a[temp])
            {
                temp ++ ;
            }
            a[temp] = 1;
        }
    }
    if( flag ){ cout <<"YES" ;}    else cout<<"NO" ;
    return 0 ;
}
