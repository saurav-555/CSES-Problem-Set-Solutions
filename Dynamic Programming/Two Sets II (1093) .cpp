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
#define MAX 501
 
int dp[MAX][(MAX * (MAX + 1)) / 2];
 
int countWays(int ith , int n , int sum ){
    if(ith == n + 1){
        if(4 * sum == n * (n + 1))
            return 1;
        else return 0;
    }
    if(dp[ith][sum ] != -1)
        return dp[ith][sum] % MOD;
 
    return dp[ith][sum] = (countWays(ith + 1 , n , sum + ith ) + countWays(ith + 1 , n , sum)) % MOD;
}
 
int exp(int base, int e , int mod){
    int result = 1;
    base %= mod;
    while(e){
        if(e & 1 )
        result =  result  * base % mod;
 
            base = base * base % mod;
            e >>=1 ;
    }
    return result;
}
void solve() {
    memset(dp , -1 , sizeof(dp));
    int n;
    cin>>n;
    cout<<countWays(1 , n , 0) * exp(2 , MOD -2 , MOD) % MOD;
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
