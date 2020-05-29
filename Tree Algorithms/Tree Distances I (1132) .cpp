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
 
int dfs(int v , int p , vector<vector<int>> &adj , vector<int> &in){
    int maxi = 0;
    for(auto to : adj[v]){
        if(to != p){
            maxi = max(maxi , 1 +  dfs(to , v , adj , in));
        }
    }
    return in[v] = maxi;
}
void dfs2(int v , int p , vector<vector<int>> &adj , vector<int> &in , vector<int> &out){
    int maxi[2] = {-1 , -1};
    for(auto to : adj[v]){
        if(to != p){
            if(in[to] > maxi[0]){
                maxi[1] = maxi[0];
                maxi[0] = in[to];
            }else if(in[to] > maxi[1]){
                maxi[1] = in[to];
            }
        }
    }
    int maximum;
    for(auto to : adj[v]){
        if(to != p){
            maximum = maxi[0];
            if(in[to] == maxi[0])
                maximum = maxi[1];
            out[to] = max(maximum + 2 , out[v] + 1);
            dfs2(to , v , adj , in , out);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> in(n , 0) , out(n);
    for(int i = 0 ; i < n -1 ; i++){
        int from , to ;
        cin>>from >> to;
        from-- , to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dfs(0 , 0 , adj , in);
    out[0] = 0;
    dfs2(0 , 0 , adj , in , out);
 
    for(int i = 0 ; i < n ; i++){
        cout<<max(in[i] , out[i])<<" ";
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
