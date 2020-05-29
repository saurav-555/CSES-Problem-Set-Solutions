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
    int n , q;
    cin>>n>>q;
    vector<vector<int>> adj(n);
    vector<int> values(n);
 
    for(int i = 0 ; i< n ; i++)
        cin>>values[i];
 
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
    for(int i = 0 ; i < n ; i++){
        tour[tin[i] - 1] = i;
    }
    for(int j = 0 ; j < n ; j++){
        tour[tout[j] -1 ] = j;
    }
    vector<int> bit(2 * n , 0);
    for(int i = 0 ; i< 2 * n ; i++){
        update(bit , i ,  values[tour[i]]);
    }
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int s , x; cin>>s>>x; s--;
            update(bit , tin[s] -1 , -values[s]);
            update(bit , tout[s] - 1 , -values[s]);
            update(bit , tin[s] -1 , x);
            update(bit , tout[s] -1 , x);
            values[s] = x;
        }else{
            int s; cin>>s; s--;
            cout<<(query(bit , tout[s] -1 ) - query(bit , tin[s] - 1 - 1) ) / 2 <<endl;
        }
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
