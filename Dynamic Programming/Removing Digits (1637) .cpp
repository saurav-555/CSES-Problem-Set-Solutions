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
#define MAX 1000005
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[MAX];
 
void solve() {
    int n;
    cin>>n;
    dp[0] = 0;
    for(int i = 1 ; i <= n; i++)
        dp[i] = LONG_LONG_MAX;
 
    for(int i = 1 ; i <= n ; i++){
        string digit = to_string(i);
        for(auto d : digit){
            if(d != '0' && dp[i - (d - '0')] != LONG_LONG_MAX){
                dp[i] = min(dp[i] , dp[i - (d - '0')] + 1);
            }
        }
    }
    cout<<dp[n] <<endl;
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
