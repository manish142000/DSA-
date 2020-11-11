
#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define pp pair<int,int>

void solve(  ) ;
 
void solve(  )
{
     int n ; 
     cin >> n ;
     int a[n] , temp[50] = {0} ;
     for( int i = 0 ; i < n ; i ++ )
     {
        cin >> a[i] ;
        int f = log2(a[i]) ;
        temp[f] ++ ;
     }
     ll ans = 0 ; 
     for( int i = 0 ; i < 50 ; i ++ )
     {
        ans +=  ( ( temp[i] *(temp[i] - 1) )/2 );
     }
     cout << ans ;

}


int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL); 
    cout.tie(NULL) ;
 
#ifndef ONLINE_JUDGE    
    //for getting input from input.txt
    freopen("inputA.txt","r",stdin);
    //for getting output from output.txt
    freopen("outputA.txt","w",stdout);
#endif

        int t ;
        cin >> t ;
        while( t-- )
        {
            solve() ;
            cout <<"\n" ;
        }
    
 
    return 0 ;
    
}
