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
ll sum[200001] ;
ll a[200001] ;
ll fact[16] ;

void solve() ;
void modify(ll , ll , ll ) ;

void modify(ll p, ll n , ll max_ind)
{
    
    vi <ll> v ;

    for( ll i = 0 ; i < max_ind ; i ++ )
    {
        v.pb( n- max_ind + i + 1 ) ;
    }
    
    for( ll i = max_ind - 1 ; i >= 1 ; i --  )
    {
        ll temp = p/fact[i] ;
        a[n-i] = v[temp] ;
        sum[n-i] = a[n-i] + sum[n-i-1] ;
        v.erase(v.begin() + temp ) ;
        p %= fact[i] ;

    }

   
 
}

void solve() 
{
    ll n , q ;
    cin >> n >> q ;
    
    sum[0] = 0 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
    a[i] = i ; sum[i] = sum[i-1] + a[i] ; }
        
    
    fact[0] = 1 ;
    for( ll i = 1 ; i <= 15 ; i ++  ){ fact[i] = fact[i-1]*i ; }
    ll max_ind =  min(n,(ll)14) ;    
    ll p  = 0 ;
    
    
    while( q-- )
    {
        int x ;
        cin >> x ;
        if( x == 2 )
        {
            int temp ;
            cin >> temp ;
            p += temp ;
            modify(p,n,max_ind) ;
          
        }
        else{
                ll l ,r ;
                cin >> l >> r ;
                cout << sum[r] - sum[l-1] <<"\n" ;


              }
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
       
        

        int t = 1 ;

        while( t-- )
        {
            
            solve() ;

          // cout <<"\n" ;
            
        }
 
    return 0 ;
}
