        /*  https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/the-parking-slot-9fac40d6/description/?layout=old */
        
     
        
 #include<bits/stdc++.h>
#define pb push_back
#define ll long long int
#define ff first
#define ss second
#define vi vector
#define MAX 1000000007 
using namespace std;
const int p = 1e5 + 1 ;
const ll inf = 1e18 ; 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vi <ll> ans ;

    int  n , m ;
    ll f ;
    cin >> n >> m >> f ;
    vi <pair<ll,ll>> ed[n+1] ;
    ll cap[n+1] ;
    for( ll i = 1 ; i <= n ; i ++ ){ cin >> cap[i] ; }

    bool vis[n+1] ;

    ll dist[n+1] ;

    for( int i = 0 ; i <= n ; i ++)
    {
        vis[i] = false ;
        dist[i] = inf ; 
    }

    while( m-- )
    {
        ll x , y , cost ; 

        cin >> x >> y >> cost ;

        ed[x].pb({y,cost}) ;

        ed[y].pb({x,cost}) ;

    }
    

    ll k ; 

    cin >> k ;
    dist[1] = 0 ;
    multiset<pair<ll,ll>> s ;

    s.insert({0,1}) ;
    ll temp = k ;
    while( !s.empty() )
    {
        pair<ll,ll> q = *s.begin() ;

        s.erase(s.begin()) ;

        ll x = q.ss ;
        if( vis[x] ){ continue ; }

        vis[x] = true ;
        for(int j = 0 ; j < cap[x] ; j ++ ){ ans.pb(dist[x]) ; k -- ; if( k < 0 ){ break ;} }
        if( k < 0 ){ break ;}
        
        
        for( int i = 0 ; i < ed[x].size() ; i ++ )
        {
            ll a = ed[x][i].ff , b = ed[x][i].ss ;

            if( b + dist[x] < dist[a] )
            {
                dist[a] = b + dist[x] ;

                s.insert({dist[a],a}) ;

                
            }
            
        }
        
    }

     for(ll i=0;i<temp;i++){
        if(i<ans.size()){  cout<<ans[i]+f<<" "; }
       
        else {cout<<-1<<" ";}
    }
    
    return 0 ;
}
