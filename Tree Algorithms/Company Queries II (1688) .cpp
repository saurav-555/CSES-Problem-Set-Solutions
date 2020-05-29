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
 
void dfs(int v , int p , vector<vector<int>> &adj , vector<vector<int>> &up , int l , vector<int> &in , vector<int> &out){
    up[v][0] = p;
    for(int i = 1 ; i <= l ; i++)
        up[v][i] = up[up[v][i-1]][i-1];
 
    in[v] = ++timer;
    for(auto to : adj[v]){
        if(to != p){
            dfs(to , v , adj , up , l , in , out);
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
    for(int i = 1 ; i < n; i++){
        int boss;
        cin>>boss;
        boss--;
        adj[i].push_back(boss);
        adj[boss].push_back(i);
    }
    int l = ceil(log2(n));
    vector<vector<int>> up(n , vector<int>(l + 1));
    vector<int> in(n) , out(n);
    dfs(0 , 0 , adj , up , l , in , out);
 
    while(q--){
        int u , v;
        cin>>u>>v;
        u-- , v--;
        cout<<lca(u , v , in , out , up , l) + 1 <<endl;
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
