#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int long long
#define idxSet tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIdx find_by_order
#define idxOf order_of_key
#define MOD 1000000007
#define MAX 501
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[501][501];
 
int minWays(int n , int m ){
    if(n == m ) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    int mini = LONG_LONG_MAX;
    // horizontally
    for(int i = 1 ; i <= n/2; i++){
        mini = min(mini , 1 + minWays(i , m) + minWays(n - i , m));
    }
    for(int j = 1 ; j <= m /2 ; j++){
        mini = min(mini , 1 + minWays(n , j) + minWays(n , m - j));
    }
    return dp[n][m] = mini;
}
 
void solve() {
    memset(dp , -1 , sizeof(dp));
    int n , m;
    cin>>n>>m;
    cout<<minWays(n , m)<<endl;
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
