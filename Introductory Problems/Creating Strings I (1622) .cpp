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
    string x;
    cin>>x;
    int a[26] = {0};
    for(auto i : x){
        a[i-'a']++;
    }
    dp[0] = 1;
    for(int i = 1 ; i<= 10 ; i++){
        dp[i] = dp[i-1] * i;
    }
    int c = dp[x.size()];
    x.clear();
    for(int i = 0 ; i < 26 ; i++){
        c /= dp[a[i]];
        while(a[i] != 0){
            x.push_back(i + 'a');
            a[i]--;
        }
    }
    cout<<c<<endl;
    do{
        cout<<x<<endl;
    }while(next_permutation(x.begin() , x.end()));
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
