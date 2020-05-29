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
 
int dp[MAX];
 
int DIAMETER = 0;
 
int dfs(int v , int p , vector<vector<int>> &adj , vector<int> &depth){
    int maxi = 0;
    for(auto to : adj[v]){
        if(to != p){
            maxi = max(1 + dfs(to , v , adj , depth)  , maxi);
        }
    }
    return depth[v] = maxi;
}
void dfs2(int v , int p , vector<vector<int>> &adj , vector<int> &depth){
    int maxi[2] = {-1 , -1};
    for(auto to : adj[v]){
        if(to != p){
            if(depth[to] > maxi[0]){
                maxi[1] = maxi[0];
                maxi[0] = depth[to];
            }else if(depth[to] > maxi[1]){
                maxi[1] = depth[to];
            }
        }
    }
    DIAMETER = max(DIAMETER , maxi[0] + maxi[1] + 2);
    for(auto to : adj[v]){
        if(to != p){
            dfs2(to , v , adj , depth);
        }
    }
}
 
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i = 0 ; i< n -1 ; i++){
        int from , to;
        cin>>from>>to;
        from--, to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vector<int> depth(n , 0);
    dfs(0 , 0 , adj , depth);
    dfs2(0 , 0 , adj , depth);
    cout<<DIAMETER<<endl;
 
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
