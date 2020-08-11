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
#define MAX 1000005
 
int dp[MAX];
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1 ; i <= 1000000 ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(j <= i){
                dp[i] += dp[i-j] ;
                dp[i] %= MOD;
            } else break;
        }
    }
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
    return 0;
}
