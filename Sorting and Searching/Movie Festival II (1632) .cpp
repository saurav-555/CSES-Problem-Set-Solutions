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
 
bool compare(const ii &x , const ii &y){
    return x.second < y.second;
}
 
void solve() {
    int n , k;
    cin>>n>>k;
    vii adj(n);
    for(int i = 0 ; i< n ; i++)
        cin>>adj[i].first >>adj[i].second;
    sort(adj.begin() , adj.end() , compare);
    multiset<int> persons;
    for(int i = 0 ; i < k ; i++)
        persons.insert(0);
    int ans = 0;
    for(int i = 0 ; i< n ; i++){
        auto it = persons.lower_bound(-adj[i].first);
        if(it == persons.end()) continue;
        ans++;
        persons.erase(it);
        persons.insert(-adj[i].second);
    }
    cout<<ans<<endl;
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
