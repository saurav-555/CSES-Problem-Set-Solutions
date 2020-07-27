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
    int n;
    cin>>n;
    int a[n] , d[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i]>>d[i];
    }
    sort(a , a + n);
    sort(d , d + n);
    int i = 0  , j = 0 , c = 0 , maxi = 0;
    while(i < n || j < n){
        if(i < n && j < n){
            if(a[i] < d[j]){
                i++; c++;
                maxi = max(c , maxi);
            }else {
                j++ , c--;
                maxi = max(c , maxi);
            }
        }else if(i < n ){
            i++ , c++;
            maxi = max(c , maxi);
        }else {
            j++ , c--;
            maxi = max(c , maxi);
        }
    }
    cout<<maxi<<endl;
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
