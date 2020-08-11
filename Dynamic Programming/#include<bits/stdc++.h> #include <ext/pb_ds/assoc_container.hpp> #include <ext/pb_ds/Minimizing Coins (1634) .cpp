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
#define MAX 1000001
 
int dp[MAX];
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n , k;
    cin>>n >>k;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a , a + n);
    for(int i = 0 ; i <= k ; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int i = 1 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++){
            if(a[j] <= i){
                if(dp[i - a[j]] != INT_MAX){
                    if(dp[i-a[j]] + 1 <=dp[i]){
                        dp[i] = dp[i-a[j]] + 1;
                    }
                }
            }else break;
        }
    }
    if(dp[k] != INT_MAX){
        cout<<dp[k]<<endl;
    }else cout<<-1<<endl;
    return 0;
}
