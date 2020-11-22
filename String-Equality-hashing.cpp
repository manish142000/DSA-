                            /* https://codeforces.com/contest/1451/problem/C */

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

void solve() ;

void solve() 
{
        
    int n , k ; cin >> n >> k ;
    string a , b ; cin >> a >> b ;

    int a_map[26], b_map[26] ; 

    for( int i = 0 ; i < 26 ; i ++ ){ a_map[i] = 0 ; b_map[i] = 0 ; }

    for( int i = 0 ; i < n ; i ++ ){  a_map[a[i]-'a'] ++ ;   b_map[b[i]-'a'] ++ ;  }

    bool flag = false ;      
    for( int i = 0 ; i < 26 ; i ++ )
    {
        if( b_map[i] > a_map[i]   || ( ( a_map[i] -= b_map[i] ) % k ) )
        {
            flag = true ;
        }

        a_map[i+1] +=  a_map[i]  ; 
    }    

    cout << ( flag ? "NO" : "YES" ) <<"\n" ;
       
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
       
       

        int t  ; cin >> t ;


        while( t-- )
        {
            
            solve() ;

            

            
        }
 
    return 0 ;
}
