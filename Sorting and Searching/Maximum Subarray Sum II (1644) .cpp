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
 
void solve() {
    int n , a , b;
    cin>>n>>a>>b;
    int v[n+1];
    v[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin>>v[i];
        v[i] += v[i-1];
    }
    set<ii> s;
    int ans = LONG_LONG_MIN;
    for(int i = 0 ; i<= n ;i++){
        if(i >= a){
            s.insert({v[i-a] , i - a});
        }
        if(s.size()){
            ans = max( v[i] - s.begin()->first , ans);
        }
        if(i >= b){
            s.erase({v[i-b] , i - b });
        }
    }
    cout<<ans<<endl;
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
