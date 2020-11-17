                /**** This is the code to find the " Least Common Ancestor " in a rooted tree *********/
                /**time complexicity - Olog(N) **/
                /** space complexicity - Nlog(N) **/
                /** application - find the length between two nodes in a rooted tree , finding kth ancestor **/
//** this code calculate the kth ancestor of any node . for sample we took n = 1e6 + 1 .
#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
#define pb push_back
#define pf push_front
#define vi vector 
#define ff first
#define ss second
#define pp pair<int,int>
 
const int p = 5e5 + 1 ;
 
vi <int> edges[ p ] ; // adjacency list .
 
int node_level[ p ] ; 
 
 
int node_parent[ p ][ 20 ] ; // keeps a track os the node at the 2^(i) the parent . 
 
void solve() ;
 
int kth_parent( int x , int k  ) ;
 
void dfs(int, int) ;
 
void intialise_binary_matrix() ;
 
int kth_parent( int x , int k  )
{
    int i = 0 ; bool flag = false ;
     // intialising with 1 jump  
    
    while( i < 20 ) // suppose our k is 11001 so we first make 1 jump then 8 jump then 16 jump in order to reach kth ancestor
    {
        if( (k >> i) & (1) )
        {
 
            x = node_parent[x][i] ;
        }
        i ++ ;
    }
   
 
        return x ;
    
}
 
void intialise_binary_matrix() 
{
 
    for( int i = 0 ; i < p ; i ++ )
    {
        for( int j = 0 ; j < 19 ; j ++ )
        {
            node_parent[i][j] = -1 ;
        }
    }
}
 
 
void dfs( int x , int p)
{
    node_parent[x][0] = p ;
    node_level[x] = node_level[p] + 1 ;
    for( auto k : edges[x] )
    {
        if( k != p )
        {
            
             
            dfs( k , x ) ;
        }
    }
}
 
void solve()
{
    int n , q ; cin >> n >> q ;
    
    int c = n ;
 
    c-- ;
 
    intialise_binary_matrix() ;
 
    while( c -- )
    {
        int x , y ; cin >> x >> y ; edges[x].pb(y) ; edges[y].pb(x) ;
    }
 
    node_level[1] = 0 ; // starting node level is marked as zer0
 
    dfs(1,-1) ;
 
    for( int j = 1 ; j < 19 ; j ++ )// since log2(1e6 + 5 ) is 20 , max ancestor length we can get is 20 
    {
        for( int i = 1 ; i <= n ; i ++ ) 
        {
            int temp =  node_parent[i][j-1] ; // in order to jump to 2^k th ancestor we  look at the 2*( 2^(k-1) ) or the 2nd parent from 2^(k-1) ancestor of i.
            
 
            // if there exists 2^(k-1) parent of i then proceed .
 
            if( temp != -1 ) 
            {
                node_parent[i][j] = node_parent[ temp ][ j-1 ] ; // this step is basically dynamic programming .
            }
        }
    }
 
    
    // these queries find the kth ancestor of the x .
    while( q-- )
    {
        int x , k ; cin >> x >> k ;
 
        if( node_level[x] < k  ) { cout <<"-1\n" ; continue ; }
 
 
 
        cout << kth_parent( x , k ) <<"\n" ;
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
