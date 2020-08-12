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
    for(int i = 0 ; i < n; i++){
        for(int j = 1 ; j <= x ; j++){
            if(j >= c[i] && dp[j - c[i]] != 0){
                dp[j] += dp[j - c[i]];
                dp[j] %= MOD;
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
