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
 
 
void dfs(int v, int p , vector<vector<int>> &adj , vector<pair<int, int>> &in){
    in[v] = {0 , 1};
    for(auto to : adj[v]){
        if(to != p){
            dfs(to , v , adj , in);
        }
    }
    for(auto to : adj[v]){
        if(to != p){
            in[v].first += in[to].first + in[to].second;
            in[v].second += in[to].second;
        }
    }
}
 
void dfs2(int v , int p , vector<vector<int>> &adj , vector<pair<int,int>> &in , vector<pair<int,int>> &out){
    for(auto to : adj[v]){
        if(to != p){
            pair<int, int> temp;
            temp.first = in[v].first - in[to].first - in[to].second;
            temp.second = in[v].second - in[to].second;
            out[to].first = temp.first + out[v].first + out[v].second;
            out[to].second = temp.second + out[v].second;
            dfs2(to , v , adj , in , out);
        }
    }
}
 
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> in(n) , out(n);
    for(int i = 0 ; i < n-1 ; i++){
        int from , to;
        cin>>from>>to;
        from--, to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    dfs(0 , 0 , adj , in);
    out[0] = {0 , 0};
    dfs2(0 , 0 , adj , in , out);
//    for(auto i : in){
//        cout<<i.first<<ends<<i.second<<endl;
//    }
//    cout<<endl;
//    for(auto i : out){
//        cout<<i.first<<ends<<i.second<<endl;
//    }
//    cout<<endl;
    for(int i = 0 ; i< n ; i++){
        cout<<in[i].first + out[i].first + out[i].second<<" ";
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
