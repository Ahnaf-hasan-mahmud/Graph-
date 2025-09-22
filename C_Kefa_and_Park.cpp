#include<bits/stdc++.h>
using namespace std;

typedef long long              ll;
#define endl                   '\n'
#define pb                     push_back
#define F                      first
#define S                      second
#define sz                     size()
#define yes                    cout << "Yes\n";
#define no                     cout << "No\n";
#define all(a)                 a.begin(), a.end()
#define rall(a)                a.rbegin(), a.rend()

long double pi=acos(-1);

ll const val=sqrtl(1e15);

vector<bool> primes(val+1,true);
//vector<ll>spf(1e7+1,0);
vector<ll>pr;
void seive() {
    primes[0]=primes[1]=false;
    for(ll i=2; i*i<=(val+1); i++) {
        if(primes[i]) {
            for(ll j=i*i; j<=(val+1); j+=i) {
                primes[j]=false;
                
            }
        }

    }
    for(ll i=1; i<=(val+1); i++) {
        if(primes[i]) {
            pr.pb(i);
        }
    }
}


ll mod=1e9+7;
const ll N=1e5; // number of vertice
vector<ll> adj[N]; // graph represented as an adjacency list

vector<bool> visited(N);
ll ans=0;
vector<ll>a(N);
ll m;

void dfs(ll u,ll p,ll mxcnt,ll cnt) {
    //Take action on vertex after entering the vertex
    
    if(a[u]==1){
        cnt++;
    }
    else{
        cnt=0;
    }
    mxcnt=max(mxcnt,cnt);

    ll ch=0;

    for (auto v : adj[u]) {
       //take action on child before entering the child
        if (v!=p){
            dfs(v,u,mxcnt,cnt);
            ch++;
        }
       //take action  on child after exiting the child
    }
   // take action on vertex before exiting the vertex

   if(ch==0 && mxcnt<=m){
    ans++;
   }

}


void solve() {
    ll n,d1,d2,k,q,mx=LLONG_MIN,mn=LLONG_MAX;
    cin>>n>>m;
  
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u); 
    }
    dfs(1,-1,0,0);
    cout<<ans<<endl;

    






}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
   // seive();
    // chk();
     // cin>>t;
    ll cs=0;
    while(t--) {        //cout<<"Case "<<++cs<<": ";
        solve();
    }
}