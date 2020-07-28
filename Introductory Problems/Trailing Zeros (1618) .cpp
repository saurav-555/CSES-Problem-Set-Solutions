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
 
int dp[MAX];
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
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 5 ; i <= n ; i*=5){
           sum += n / i;
    }
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
