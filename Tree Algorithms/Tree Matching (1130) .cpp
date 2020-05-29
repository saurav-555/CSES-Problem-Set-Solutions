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
 
void dfs(int v , int p , vector<vector<int>> &adj , int *match, int &match_counter){
    for(auto to : adj[v]){
        if(to != p){
            dfs(to , v , adj , match , match_counter);
        }
    }
    if(p != -1 && match[v] == 0 && match[p] == 0){
        match[p] = match[v] = ++match_counter;
    }
}
 
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i = 0 ; i< n - 1 ; i++){
        int from, to;
        cin>>from>>to;
        from--, to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int match[n];
    memset(match , 0 , sizeof(match));
    int match_counter = 0;
    dfs(0 , -1 , adj ,  match , match_counter);
    cout<<match_counter<<endl;
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
