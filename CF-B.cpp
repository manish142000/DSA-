#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define MX 1000000007
const int p = 100005 ;
using namespace std ;
int spf[p] ;
void solve() ;
void sieve() ;
vi <int> get_primes(int x) ;
void sieve()
{
    spf[1] = 1 ;

    for( int i = 2 ; i < p ; i ++ ){ spf[i] = i ; }

    for( int i = 4 ; i < p ; i += 2 ){ spf[i] = 2 ; }
    
    for( int i = 3 ; i*i < p ; i ++ )
    {
        if( spf[i] == i )
        {
            for( int j = i*i ; j < p ; j += i )
            {
                spf[j] = i ; 
            }
        }
    }    
}
vi <int> get_primes(int x) 
{
    vi <int> temp ;
    while( x != 1 )
    {
        temp.pb(spf[x]) ;
        x /= spf[x] ;
    }
    return temp ;
}
void solve() 
{
   
    int n ;

    cin >> n ;

    int a[n+1] ;

    map <int,int> f , l ;


    for( int i = 1 ; i <= n ; i ++ ){ 

        cin >> a[i] ; 

        vi <int> pf = get_primes(a[i]) ;

        for( auto k : pf )
        {
            if( f[k] == 0 ){ f[k] = i ; }

            l[k] = i ;
        }
    }

    vi <int> cover(n+1,0) ;


    for( auto k : f ){ cover[k.ss]++ ; }

    

    for( auto k : l ){ cover[k.ss]-- ; }

    for( int i = 1 ; i <= n ; i ++ )
    {
        cover[i] += cover[i-1] ;
        if( cover[i] == 0 ){ cout <<i ; return ; }
       // cout << cover[i]<<" " ;
    }    

    

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
       
        sieve() ;

        int t  ; cin >> t ;


        while( t-- )
        {
            
            solve() ;

            cout <<"\n" ;

            
        }
 
    return 0 ;
}
