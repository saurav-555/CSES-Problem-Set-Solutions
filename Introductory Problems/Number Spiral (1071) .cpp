#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int unsigned long long
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
    int r , c;
    cin>>r>>c;
    int ith = max(r , c) -1;
    ith = ith * ith;
    int have = 1 + 2 * (max(r , c) -1);
    if(max(r , c) % 2 == 0){
        if(r >= c){
            c--;
            ith += have - c;
        }else{
            ith += r;
        }
    }else{
        if(c >= r){
            r--;
            ith += have - r;
        }else {
            ith += c;
        }
    }
    cout<<ith<<endl;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
