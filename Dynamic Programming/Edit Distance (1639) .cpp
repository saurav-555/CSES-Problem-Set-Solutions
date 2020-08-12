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
#define MAX 5001
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[MAX][MAX];
 
int n , m;
string x , y;
 
int countWays(int ith , int jth){
    if(dp[ith][jth] != -1) return dp[ith][jth];
    if(ith == n && jth == m)
        return dp[ith][jth] = 0;
    if(ith == n){
        // deleting y's end element
        return dp[ith][jth] = 1 + countWays(ith , jth + 1);
    }
    if(jth == m){
        // adding to x
        return dp[ith][jth] = 1 + countWays(ith + 1 , jth);
    }
    if(x[ith] == y[jth])
        return dp[ith][jth] = countWays(ith + 1 , jth+1);
 
    int mini = LONG_LONG_MAX;
    // adding to x
    mini = min(mini , 1 + countWays(ith , jth+1));
    // replacing in x
    mini = min(mini , 1 + countWays(ith +1 , jth + 1));
    // removing in x
    mini = min(mini , 1 + countWays(ith+1 , jth));
    return dp[ith][jth] = mini;
}
 
void solve() {
    cin>>x>>y;
    n = x.size() , m = y.size();
    memset(dp , -1 , sizeof(dp));
    cout<<countWays(0 , 0)<<endl;
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
