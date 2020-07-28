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
 
int binarySearch(int a, int b) {
    int l = 0, h = a;
    int m;
    while (l <= h) {
        m = (l + h) / 2;
        int aRemain = a - m;
        int bRemain = b - 2 * m;
        if (aRemain == bRemain)
            return m;
        else if (bRemain < aRemain)
            h = m - 1;
        else l = m + 1;
    }
    return -1;
}
 
void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    int is = binarySearch(a, b);
    if (is == -1)
        cout << "NO" << endl;
    else {
        a = a - is;
        b = b - is * 2;
 
        if (a % 3 == 0) {
            cout << "YES" << endl;
        }else cout<<"NO"<<endl;
    }
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
