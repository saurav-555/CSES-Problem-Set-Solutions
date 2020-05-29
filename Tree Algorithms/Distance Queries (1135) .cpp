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
#define endl '\n'
#define MAX 200005
 
int dp[MAX];
 
int timer = 0;
 
void dfs(int d , vector<int> &depth , int v , int p , vector<vector<int>> &adj , vector<vector<int>> &up , int l , vector<int> &in , vector<int> &out){
    depth[v] = d;
    up[v][0] = p;
    for(int i = 1 ; i <= l ; i++)
        up[v][i] = up[up[v][i-1]][i-1];
 
    in[v] = ++timer;
    for(auto to : adj[v]){
        if(to != p){
            dfs(d + 1 , depth , to , v , adj , up , l , in , out);
        }
    }
    out[v] = ++timer;
}
 
bool is_ancestor(int u , int v , vector<int> &in , vector<int>  &out){
    return in[u] <= in[v] && out[u] >= out[v];
}
 
int lca(int u , int v , vector<int> &in , vector<int> &out , vector<vector<int>> &up , int l){
    if(is_ancestor(u , v , in , out))
        return u;
    if(is_ancestor(v , u , in , out))
        return v;
    for(int i = l ; i >= 0 ; i--){
        if(!is_ancestor(up[u][i] , v , in , out))
            u = up[u][i];
    }
    return up[u][0];
}
 
 
 
void solve() {
    int n , q;
    cin>>n >>q;
    vector<vector<int>> adj(n);
    for(int i = 0 ;  i < n -1; i++){
        int from , to;
        cin>>from>>to;
        from--,to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int l = ceil(log2(n));
    vector<vector<int>> up(n , vector<int>(l + 1));
    vector<int> in(n) , out(n) , depth(n);
    dfs(0 , depth , 0 , 0 , adj , up , l , in , out);
 
    while(q--){
        int u , v;
        cin>>u>>v;
        u--, v--;
        int LCA = lca(u , v , in , out , up , l);
        cout<<depth[u] + depth[v] - 2 * depth[LCA]<<endl;
    }
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
