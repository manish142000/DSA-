#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define MX 1000000007

using namespace std ;

ll inf = 1e18 ;
void solve() ;
int make_mask(string) ;
int make_mask(string s )
{
    int temp = 0 ;
    for( int i = 0 ; i < 3 ; i ++ )
    {
        char c = 'C' - i ;

        for( int j = 0 ; j < s.length() ; j ++ )
        {
            if( s[j] == c )
            {
                temp += (1<<i) ;
                break ;
            }
        } 
    }

    return temp ;
}

void solve() 
{
    int n ;

    cin >> n ;

    ll dp[n+1][8] ;

    for( int i = 0 ; i <= n ; i ++ )
    {
        for( int j = 0 ; j <= 7 ; j ++ ){ dp[i][j] = inf  ; }
    }
    dp[0][0] = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        ll cost ; string s ; cin >> cost >> s ;
    
        int s_mask = make_mask(s) ; 

        for( int mask = 0 ; mask < 8 ; mask ++ )
        {
            dp[i+1][mask] = min(dp[i+1][mask],dp[i][mask]) ;
            dp[i+1][mask|s_mask] = min(dp[i+1][mask|s_mask],cost+dp[i][mask]) ;
        }

    }
    if( dp[n][7] == inf ){ cout <<"-1" ; }
    else { cout << dp[n][7] ; }
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
       
        
        int t  ; //cin >> t ;

        t = 1 ;

        while( t-- )
        {
            
            solve() ;

            cout <<"\n" ;

            
        }
 
    return 0 ;
}
