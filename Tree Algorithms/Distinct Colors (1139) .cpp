#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int long long
#define index_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIndex find_by_order
#define indexOf order_of_key
#define MOD 1000000007
#define MAX 200005
 
int dp[MAX];
 
struct Query{
    int l , r;
    int idx;
};
 
bool compare(const Query &x , const Query &y){
    return x.r < y.r;
}
void dfs(int v , int p , vector<vector<int>> &adj , vector<int > &tin , vector<int> &tout , int &timer){
    tin[v] = ++timer;
    for(auto to : adj[v]){
        if(to != p){
            dfs(to , v , adj , tin, tout , timer);
        }
    }
    tout[v] = ++timer;
}
 
int query(vector<int> &bit , int idx){
    int result  = 0;
    for( ; idx >= 0 ; idx = (idx & (idx + 1)) - 1){
        result += bit[idx];
    }
    return result;
}
 
void update(vector<int> &bit , int idx , int value){
    int n = bit.size();
    for( ; idx < n ; idx = idx | (idx + 1))
        bit[idx] += value;
}
 
 
void solve() {
    int n ;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> colors(n);
 
    for(int i = 0 ; i< n ; i++)
        cin>>colors[i];
 
    index_set compressor;
    for(int i = 0 ; i< n ; i++)
        compressor.insert(colors[i]);
    for(int i = 0 ; i < n ; i++)
        colors[i] = compressor.indexOf(colors[i]);
 
    for(int i = 0 ; i < n -1 ; i++){
        int from , to ;
        cin>>from>>to;
        from--, to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
 
    vector<int> tin(n) , tout(n);
    vector<int> tour(2 * n);
    int timer = 0;
    dfs(0 , 0 , adj , tin , tout , timer);
 
    for(int i = 0 ; i< n ; i++)
        tour[tin[i] -1] = colors[i];
    for(int i = 0 ; i< n ; i++)
        tour[tout[i] -1] = colors[i];
 
 
 
    Query q[n];
    for(int i = 0 ; i< n ; i++){
        q[i].l = tin[i] -1;
        q[i].r = tout[i] -1;
        q[i].idx = i;
    }
    sort(q , q + n , compare);
    int last_visited[compressor.size()];
    memset(last_visited , -1 , sizeof(last_visited));
 
    vector<int> bit(2 * n , 0);
 
    int ans[n];
    int query_counter = 0;
 
    for(int i = 0 ; i < 2 * n ; i++){
        if(last_visited[tour[i]] != -1){
            update(bit , last_visited[tour[i]] , -1);
        }
        last_visited[tour[i]] = i;
        update(bit , i , 1);
 
        while(query_counter < n && q[query_counter].r == i){
            ans[q[query_counter].idx] = query(bit , q[query_counter].r) - query(bit , q[query_counter].l -1);
            query_counter++;
        }
    }
    for(int i = 0 ; i< n; i++){
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
