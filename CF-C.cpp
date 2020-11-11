#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    #ifndef ONLINE_JUDGE    
    //for getting input from input.txt
    freopen("inputA.txt","r",stdin);
    //for getting output from output.txt
    freopen("outputA.txt","w",stdout);
#endif
  ll n,x,pos; cin>>n>>x>>pos;
  ll s=x-1,b=n-x,l=0,r=n,m,out=1,mod=long(1e9+7);
  while(l<r)
  {
    m=(l+r)/2;
    if(m<pos)l=m+1,out*=s--,out%=mod;
    else if(m==pos)l=m+1;
    else r=m,out*=b--,out%=mod;
  }
  for(ll i=1;i<=s+b;i++)out*=i,out%=mod;
  cout<<out;
}