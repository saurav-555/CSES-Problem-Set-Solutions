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
#define MAX 200005
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[100001][101];
 
void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                if (j >= 2) dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] += dp[i - 1][j];
                if (j <= m - 1) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        } else {
            if (a[i] >= 2) dp[i][a[i]] += dp[i - 1][a[i] - 1];
            dp[i][a[i]] += dp[i - 1][a[i]];
            if (a[i] <= m - 1) dp[i][a[i]] += dp[i - 1][a[i] + 1];
            dp[i][a[i]] %= MOD;
        }
    }
    int sum = 0;
    for(int j = 1 ; j <= m ; j++){
        sum += dp[n-1][j];
    }
    sum %= MOD;
    cout<<sum<<endl;
 
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
