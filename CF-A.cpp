#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define pp pair<int,int>
const int p = 1e6 + 1 ;
void solve() ;
ll mergesort( ll a[] , ll temp[] , ll , ll ) ;
ll merge( ll a[] , ll temp[] , ll , ll , ll ) ;
ll merge( ll a[] , ll temp[] , ll l , ll mid , ll r)
{
    ll i = l , j = mid + 1 , k = l ;
    ll y = 0 ;
    while( ( i <= mid ) && ( j <= r ))
    {
        if( a[i] <= a[j] )
        {
            temp[k++] = a[i++] ;
        }
        else{
            temp[k++] = a[j++] ;
            y += ( mid - i  + 1 ) ;
        }
    }
    while( i <= mid ){ temp[k++] = a[i++] ; }

    while( j <= r){ temp[k++] = a[j++] ; }

    for( int i = l ; i <= r ; i ++ )
        { a[i] = temp[i] ; }
    return y ;
}
ll mergesort( ll a[] , ll temp[] , ll l , ll r )
{
    ll count_inv = 0 , mid ;
    if( l < r )
    {
        mid = ( l + r )/2 ;
        count_inv += mergesort( a , temp , l , mid ) ;
        count_inv += mergesort( a , temp , mid + 1 , r ) ;
        count_inv += merge( a , temp , l , mid  , r ) ;
    }
    return count_inv ;
} 
void solve()
{
    ll n ; cin >> n ; 
    ll a[n] ; for( ll i = 0 ; i < n ; i ++ ){ cin >> a[i] ; }
    ll temp[n] ;
    cout << mergesort(a,temp,0,n-1) ;
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
        // cin >> t ; 
        t = 1 ;
        
        while( t-- )
        {
            
            
            solve() ;
            //cout<<"\n" ;
        }
 
    return 0 ;
}
