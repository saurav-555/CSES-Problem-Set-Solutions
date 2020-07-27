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
    int x , n;
    cin>>x>>n;
    map<int,int> size;
    size[x - 0]++;
    set<int> pts;
    pts.insert(0);
    pts.insert(x);
    for(int i = 0 ; i < n ; i++){
        int a; cin>>a;
        auto it = pts.upper_bound(a);
        int r = *it;
        it--;
        int l = *it;
        size[r - l]--;
        if(size[r - l] == 0){
            size.erase(r - l);
        }
        size[a - l]++;
        size[r - a]++;
        pts.insert(a);
        auto it2 = size.end();
        it2--;
        cout<<it2->first<<" ";
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
