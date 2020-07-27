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
 
void make_equal(multiset<int> &l, multiset<int> &r, int k , int &leftSum , int &rightSum) {
    while (l.size() - r.size() != k % 2) {
        if ((int)(l.size() - r.size()) > k % 2) {
            auto it = l.end(); it--;
            rightSum += *it;
            r.insert(*it);
            leftSum -= *it;
            l.erase(it);
 
        } else {
            leftSum += *r.begin();
            l.insert(*r.begin());
            rightSum -= *r.begin();
            r.erase(r.begin());
        }
    }
}
 
void modify(multiset<int> &l, multiset<int> &r, int k, int add, int remove , int &leftSum , int &rightSum) {
    // removing element
    auto it = l.lower_bound(remove);
    if (*it == remove) {
        leftSum -= *it;
        l.erase(it);
    } else {
        it = r.lower_bound(remove);
        rightSum -= *it;
        r.erase(it);
    }
    // adding element
    if (l.empty() && r.empty()) {
        leftSum += add;
        l.insert(add);
    } else if (l.empty()) {
        if (add <= *r.begin())
            l.insert(add) , leftSum += add;
        else r.insert(add) , rightSum += add;
    } else if (r.empty()) {
        auto it2 = l.end();
        it2--;
        if (add <= *it2)
            l.insert(add) , leftSum += add;
        else r.insert(add) , rightSum += add;
    } else {
        if (add <= *r.begin()) {
            l.insert(add) , leftSum += add;
        } else r.insert(add) , rightSum += add;
    }
    make_equal(l, r, k , leftSum , rightSum);
}

int printCost(multiset<int> &l , multiset<int> &r , int k , int &leftSum , int &rightSum){
    int median  , cost ;
    if(k % 2 == 0){
        auto it = l.end(); it--;
        median  = *it + *r.begin();
        median /= 2;
    }else {
        auto it = l.end() ; it--;
        median = *it;
    }
    cost = median * l.size() - leftSum + rightSum - median * r.size();
    return cost;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n] , leftSum = 0 , rightSum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> l, r;
    for (int i = 0; i < k; i++) {
        l.insert(a[i]);
        leftSum += a[i];
    }
    make_equal(l, r, k , leftSum , rightSum);
    cout<<printCost(l , r , k , leftSum , rightSum)<<" ";
    for (int i = k; i < n; i++) {
        modify(l, r, k, a[i], a[i - k] , leftSum , rightSum);
        cout<<printCost(l , r , k , leftSum , rightSum)<<" ";
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
 
