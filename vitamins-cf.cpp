                                  /*  https://codeforces.com/problemset/problem/1042/B */ 

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
    int n ; // given n strings 

    cin >> n ;

    ll dp[n+1][8] ; // keeping a table to store the ans of ( inclding/not including ith juice with/without cost  ) basically contains the cost of including/not including ith juice

    for( int i = 0 ; i <= n ; i ++ )
    {
        for( int j = 0 ; j <= 7 ; j ++ ){ dp[i][j] = inf  ; } // if we dont get all the vitamins from n juices then we have infinty at the last cell
    }
    dp[0][0] = 0 ; // contains the cost of buying 0 jusice which is 0 // base case 
    for( int i = 0 ; i < n ; i ++ )
    {
        ll cost ; string s ; cin >> cost >> s ;
    
        int s_mask = make_mask(s) ; // bit masking . A has value 4 , B has value 2 and C has value 1 .

        // this code uses push dp ie pushing the cost of including or not including the string into the i+1th row  

        for( int mask = 0 ; mask < 8 ; mask ++ )
        {
            // if we do not include the ith juice then we dont consider its cost while pushing into i+1th row  
            dp[i+1][mask] = min(dp[i+1][mask],dp[i][mask]) ; 
            // if we do include then just add the cost and after considering vitamins present in ith string we place the cost in the cell containg all the vitams collected up until now
            dp[i+1][mask|s_mask] = min(dp[i+1][mask|s_mask],cost+dp[i][mask]) ;
        }

    }
    // after going throug all the cases we will have answer in the final cell .
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
