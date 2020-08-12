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
#define MAX 100001
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[2][MAX];
 
void solve() {
    int n , x;
    cin>>n>>x;
 
    int price[n] , pages[n];
    for(int i = 0 ; i < n; i++)
        cin>>price[i];
    for(int i = 0 ; i < n; i++)
        cin>>pages[i];
 
    for(int i = 0 ; i <= x; i++)
        dp[0][i] = 0;
 
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= x ; j++){
            if(j >= price[i]){
                dp[1][j] = max(dp[0][j] , dp[0][j - price[i]] + pages[i]);
            }
        }
        for(int j = 0 ; j <= x ; j++){
            dp[0][j] = dp[1][j];
        }
    }
    cout<<dp[0][x]<<endl;
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
