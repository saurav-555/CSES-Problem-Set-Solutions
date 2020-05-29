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
vector<int> subSize;
 
int dfs(int s , int p , vector<vector<int>> &adj){
    int sub = 0;
    for(auto to : adj[s]){
        if(to != p){
            sub += dfs(to , s , adj);
        }
    }
    subSize[s] = sub;
    return 1 + sub;
}
 
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i = 1 ; i < n ; i++){
        int parent; cin>>parent; parent--;
        adj[i].push_back(parent);
        adj[parent].push_back(i);
    }
    subSize.resize(n , 0);
    dfs(0 , 0 , adj);
    for(int i = 0 ; i < n ; i++){
        cout<<subSize[i]<<" ";
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
