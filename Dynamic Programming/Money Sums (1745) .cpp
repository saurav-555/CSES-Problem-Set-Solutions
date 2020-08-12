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
#define MAX 100005
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
bool dp[2][MAX];
 
void solve() {
    int n ;
    cin>>n;
    int c[n];
    for(int i = 0 ; i < n ; i++)
        cin>>c[i];
    sort(c , c + n);
    int maxi = n * 1000;
    memset(dp , false , sizeof(dp));
    dp[0][0] = true;
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= maxi ; j++ ){
            if(j >= c[i] && dp[0][j - c[i]]){
                dp[1][j] = true;
            }
        }
        for(int j = 1 ; j <= maxi ; j++){
            dp[0][j] = dp[1][j];
        }
    }
    vi ans;
    for(int i = 1 ; i <= maxi ; i++){
        if(dp[0][i])
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto i : ans){
        cout<<i<<" ";
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
