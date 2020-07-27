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
//#define endl '\n'
 
#define v(type) vector<type>
#define p(type1, type2) pair<type1 , type2>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
int dp[MAX];
 
void make_equal(multiset<int> &l, multiset<int> &r, int k) {
    while (l.size() - r.size() != k % 2) {
        if ((int)(l.size() - r.size()) > k % 2) {
            auto it = l.end(); it--;
            r.insert(*it);
            l.erase(it);
        } else {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
    }
}
 
void modify(multiset<int> &l, multiset<int> &r, int k, int add, int remove) {
    // removing element
    auto it = l.lower_bound(remove);
    if (*it == remove) {
        l.erase(it);
    } else {
        it = r.lower_bound(remove);
        r.erase(it);
    }
    // adding element
    if (l.empty() && r.empty()) {
        l.insert(add);
    } else if (l.empty()) {
        if (add <= *r.begin())
            l.insert(add);
        else r.insert(add);
    } else if (r.empty()) {
        auto it2 = l.end();
        it2--;
        if (add <= *it2)
            l.insert(add);
        else r.insert(add);
    } else {
        if (add <= *r.begin()) {
            l.insert(add);
        } else r.insert(add);
    }
    make_equal(l, r, k);
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> l, r;
    for (int i = 0; i < k; i++) {
        l.insert(a[i]);
    }
    make_equal(l, r, k);
    auto it = l.end();
    it--;
    cout << *it << " ";
    for (int i = k; i < n; i++) {
        modify(l, r, k, a[i], a[i - k]);
        it = l.end();
        it--;
        cout << *it << " ";
    }
    cout << endl;
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
