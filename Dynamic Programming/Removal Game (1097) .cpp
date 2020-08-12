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
#define MAX 5001
#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[MAX][MAX];
 
 
int maxScore(int ith , int jth , int *a ){
    if(ith == jth){
        return dp[ith][jth] = a[ith];
    }
    if(dp[ith][jth] != -1)
        return dp[ith][jth];
    // it's select first element
    return dp[ith][jth] = max(a[ith] - maxScore(ith+ 1 , jth , a) , a[jth] - maxScore(ith , jth -1 ,a));
 
}
 
void solve() {
    int n; cin>>n;
    int a[n] , sum = 0;
    for(int i = 0 ; i< n; i++){
        cin>>a[i] ;
        sum+= a[i];
    }
    memset(dp , -1 ,sizeof(dp));
    cout<<(maxScore(0 , n-1 , a) + sum) / 2<<endl;
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
