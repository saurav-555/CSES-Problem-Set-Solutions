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
#define MAX 1005
#define MAX_FACT 20
 
int dp[MAX][MAX];
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp , 0 , sizeof(dp));
    int n;
    cin>>n;
    char matrix[n][n + 1];
    for (int i = 0; i < n; ++i) {
        cin>>matrix[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(matrix[0][i] == '*'){
            break;
        }else dp[0][i] = 1;
    }
    for(int i = 0 ; i < n ; i++){
        if(matrix[i][0] == '*'){
            break;
        }else dp[i][0] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < n; j++) {
            if (matrix[i][j] != '*') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
 
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}
