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
    vii data(n);
    for (int i = 0; i < n; ++i) {
        cin>>data[i].first;
        data[i].second = i + 1;
    }
    sort(data.begin() , data.end());
    bool exist = false;
    for(int i = 2 ; i< n ; i++){
        int l = 0 , r = i - 1 , req = x - data[i].first;
        while(l < r){
            if(data[l].first + data[r].first > req){
                r--;
            }else if(data[l].first + data[r].first < req){
                l++;
            }else {
                exist = true;
                cout<<data[i].second<<" "<<data[l].second<<" "<<data[r].second<<endl;
                goto fuck;
            }
        }
    }
    fuck:;
    if(!exist){
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
