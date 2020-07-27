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
 
int calc(int *a , int n , int time){
    int sum = 0;
    for(int i = 0 ; i< n ; i++){
        sum += time / a[i];
    }
 
    return sum;
}
 
int bin(int *a , int n , int t , int maxi){
    int l = 1 , h = maxi , m , ans = -1 ;
    while(l <= h){
        m = (l + h) / 2 ;
        int temp = calc(a , n , m);
        if(temp >= t){
            ans = m;
            h = m - 1;
        }else {
            l = m + 1;
        }
    }
    return ans;
}
 
void solve() {
    int n , t;
    cin>>n>>t;
    int a[n];
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        maxi = max(maxi , a[i]);
    }
    maxi = maxi * t;
    cout<<bin(a , n , t , maxi)<<endl;
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
