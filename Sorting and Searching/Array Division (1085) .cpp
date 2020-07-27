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
 
int how_many_section(int *a, int n, int len) {
    int count = 0;
    for(int i = 0 , l = 0 ; i < n ; i++){
        if(l + a[i] > len){
            count ++;
            l = 0;
        }
        l += a[i];
    }
    count++;
    return count;
}
 
int bin(int *a, int n, int k, int low, int high) {
    int mid , sections , ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        sections = how_many_section(a , n , mid);
        if(sections > k){
            low = mid + 1;
        }else  {
            ans = mid;
            high = mid -1;
        }
    }
    return ans;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    int a[n], mini = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mini = max(mini, a[i]);
        maxi = maxi + a[i];
    }
    cout << bin(a, n, k, mini, maxi);
 
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
