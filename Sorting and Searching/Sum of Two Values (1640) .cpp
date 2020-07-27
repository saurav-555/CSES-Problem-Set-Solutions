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
    int n , x;
    cin>>n>>x;
    map<int,pair<int,int>> d;
    for(int i = 0 ; i < n ; i++){
        int a ; cin>>a;
        if(d.count(a) == 0){
            d[a] = {i + 1 , -1};
        }else if(d[a].second == -1){
            d[a].second = i + 1;
        }
    }
    bool is = false;
    for(auto i : d){
        int f = i.first;
        int s = x - i.first;
        if(f != s && d.count(s) != 0){
            cout<<i.second.first<<" "<<d[s].first<<endl;
            is = true;
            break;
        }else if(f == s && d[s].second != -1){
            cout<<i.second.first<<" "<<i.second.second<<endl;
            is = true;
            break;
        }
    }
    if(!is){
        cout<<"IMPOSSIBLE"<<endl;
    }
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
