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
    int n , x;
    cin>>n>>x;
    int c[n];
    for(int i = 0 ; i < n; i++)
        cin>>c[i];
    dp[0] = 1;
    for(int i = 1 ; i <= x; i++){
        dp[i] = 0;
        for(int j = 0 ; j < n; j++){
            if(i >= c[j] && dp[i - c[j]] != 0){
                dp[i] += dp[i - c[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
 
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
