#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
using namespace std ;


void solve() ;


void solve() 
{
    ll n , k ;
    cin >> n >> k ;
    k -- ;
    int max_d = -1 , min_d = 10 ;

    while( k ){
        max_d = -1 ; min_d = 10 ;
        ll p = n ;
        while( p )
       {
        int temp = p % 10 ;
         max_d = max(temp,max_d) ; min_d=min(min_d,temp) ;
         p /= 10 ;
       }  if( min_d == 0 ){ break ; }
       n = n + max_d * min_d ;
       k-- ;
    } 
    cout << n ;
   
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
    freopen("outputB.txt","w",stdout);
#endif
       
        int t ;
         cin >> t ; 
       // t = 1 ;
         //sieve() ;
        while( t-- )
        {
            //for( int i = 0 ; i < p ; i ++ ){ is_stored[i] = false ; }
            solve() ;
            cout<<"\n" ;
        }
 
    return 0 ;
}
