#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int long long
#define index_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIndex find_by_order
#define indexOf order_of_key
#define MOD 1000000007
#define MAX 200005
 
 
vector<vector<int>> adj , up;
vector<int> tin, tout , ans;
int l , timer = 0;
 
void dfs(int v , int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for(int i = 1 ; i <= l ; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto to : adj[v]){
        if(to != p){
            dfs(to , v);
        }
    }
    tout[v] = ++timer;
}
 
 
bool is_ancestor(int u , int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
 
void lca(int u , int  v){
    if(is_ancestor(u , v)){
        ans[v] += 1;
        if(u != 0){
            ans[up[u][0]] -= 1;
        }
        return ;
    }
    if(is_ancestor(v , u)){
        ans[u] += 1;
        if(v != 0){
            ans[up[v][0]] -=1;
        }
        return ;
    }
    ans[u] += 1;
    ans[v] += 1;
    for(int i = l ; i >= 0 ; i--){
        if(!is_ancestor(up[u][i] , v)){
            u = up[u][i];
        }
    }
 
 
    int lca = up[u][0];
    ans[lca] -= 1;
    if(lca != 0){
        ans[up[lca][0]] -= 1;
    }
 
}
int dfs2(int v , int p){
    for(auto to : adj[v]){
        if(to != p){
            ans[v] += dfs2(to , v);
        }
    }
    return ans[v];
}
 
void solve() {
    int n , q;
    cin>>n>>q;
    adj.assign(n , vector<int>(0));
    for(int i = 0 ; i < n -1 ; i++){
        int from , to;
        cin>>from>>to;
        from--,to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    l = ceil(log2(n));
    tin.assign(n , 0) , tout.assign(n , 0);
    up.assign(n , vector<int>(l + 1));
    dfs(0 ,0 );
    ans.assign(n , 0);
 
 
    while(q--){
        int u , v;
        cin>>u>>v;
        u--, v--;
        lca(u , v);
 
    }
 
    dfs2(0 , 0);
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}
