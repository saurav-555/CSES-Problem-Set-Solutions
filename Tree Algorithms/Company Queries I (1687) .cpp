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
 
void dfs(int v , int p , vector<vector<int>> &adj , vector<vector<int>> &up , int l){
    up[v][0] = p;
    for(int i = 1 ; i <= l ; i++)
        if(up[v][i-1] != -1)
            up[v][i] = up[up[v][i-1]][i-1];
        else up[v][i] = -1;
 
    for(auto to : adj[v]){
        if(to != p){
            dfs(to , v , adj , up , l);
        }
    }
}
int find_nth_above(int of , int level , vector<vector<int>> &up , int l){
 
    for(int i = l ; i >= 0 ; i--){
        if(dp[i] > level){
            continue;
        }else if(dp[i] < level){
            of = up[of][i];
            level -= dp[i];
            if(of == -1)
                return -1;
        }else{
            return up[of][i];
        }
    }
    return of;
 
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
    dfs(0 , -1 , adj , up , l);
 
    dp[0] = 1;
    for(int i = 1 ; i <= 20 ; i++){
        dp[i] = dp[i-1] * 2;
    }
 
    while(q--){
        int of , level;
        cin>>of>>level;
        of--;
        int ans = find_nth_above(of , level , up , l);
        if(ans == -1)
            cout<<-1<<endl;
        else
            cout<<ans + 1 <<endl;
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
