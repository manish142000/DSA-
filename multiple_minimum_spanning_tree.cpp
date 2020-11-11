/*https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/to-buy-or-not-to-buy-6/description/?layout=old  */                                                              

#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define ff first
#define ss second
#define vi vector
#define MAX 1000000007 
using namespace std;

vi< pair<int,pair<int,int>>>  road ;

int parent[1001] ;
ll mc ;
int gcd(int,int) ;
int gcd(int a ,int b)
{
    if( b == 0 ){ return a ; }

    return gcd(b,a%b) ; 
}
void solve() ;
void min_cost() ;
int root( int x ) ;
void union_set( int x ,int y ) ;
void initialise_parent(int) ;
 
void initialise_parent(int n )
{
    for( int i = 0 ; i <= n ; i ++ )
    {
        parent[i] = i ;
    }
}
int root( int x )
{
    while( parent[x] != x )
    {
        parent[x] = parent[parent[x]] ;

        x = parent[x] ;
    }

    return x ;
}

void union_set( int x ,int y )
{
    int p = root(x) ;
    int q = root(y) ;

    parent[p] = parent[q] ;
}

void min_cost()
{
    int m = road.size() ;
    mc = 0 ;
    for( int i = 0 ; i < m ; i ++ )
    {
        int x = road[i].ss.ff , y = road[i].ss.ss ;
        //cout << x <<" "<<y <<" "<<road[i].ff<<"\n" ;
        if( root(x) != root(y) )
        {

            mc += road[i].first ;
            union_set(x,y) ;
        }
    }

    //cout << ct ;
}
void solve(int n , int k ) 
{
    initialise_parent(n) ;
    
    while( k-- )
    {
        int x , y , cost ;
        cin >> x >> y >> cost ;
        road.pb({cost,{x,y}}) ;
    }

    sort(road.begin(),road.end()) ;


    min_cost() ;

    int m ;
    cin >> m ;
    int temp = m ;
    int a = 0 ; 
    while( m-- )
    {
        int p ,q ;
        cin >> p >> q ;
        ll as = 0 ;
        initialise_parent(n) ;

        union_set(p,q) ;

        for( auto y : road )
        {
            if( ( y.ss.ff == p && y.ss.ss == q ) || ( y.ss.ff == q  && y.ss.ss == p) ){ as += y.ff ; }

            else{
                    if( root(y.ss.ff) != root(y.ss.ss) )
                    {
                        as += y.ff ;
                        union_set(y.ss.ff,y.ss.ss) ;
                    }
            }
        }

        if( as == mc ){ a ++ ; }
    }
   
    int hcf = gcd(a,temp) ;

    a /= hcf ;
    temp /= hcf ;

    cout << a <<"/" << temp <<"\n" ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
        int n , k ;

        cin >> n >> k ;

        solve(n,k) ;

        road.clear() ;

    
    }    
    
    

    return 0 ;
}
