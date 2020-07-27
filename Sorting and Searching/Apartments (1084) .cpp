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
    int n , m , k;
    cin>>n>>m>>k;
    int a[n] , b[m];
    for(int i = 0 ; i < n ; i++)
        cin>>a[i];
    for (int j = 0; j < m; ++j) {
        cin>>b[j];
    }
    sort(a , a + n);
    sort(b , b + m);
    int i = 0 , j = 0 , c = 0;
    while(i < n && j < m){
        if(b[j] < a[i] - k)
            j++;
        else if(a[i] + k < b[j])
            i++;
        else {
            i++ , j++ , c++;
        }
    }
    cout<<c<<endl;
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
