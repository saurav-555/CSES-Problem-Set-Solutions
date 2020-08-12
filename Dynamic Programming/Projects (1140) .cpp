#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using u128 = __uint128_t;
 
#define int long long
#define index_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIndex find_by_order
#define indexOf order_of_key
#define MOD 1000000007
#define MAX 200001
 
int dp[MAX];
 
int maxProfit(int ith , vector<pair<pair<int,int> , int>> &orders , vector<int> &start , int n){
    if(ith == n){
        return 0;
    }
    if(dp[ith] != -1) return dp[ith];
    int selected = orders[ith].second;
    auto it = upper_bound(start.begin() , start.end() , orders[ith].first.second);
    int next = it - start.begin();
 
    selected += maxProfit(next , orders, start, n);
 
    int notSelected = maxProfit(ith + 1 , orders , start , n);
 
    return dp[ith] = max(selected , notSelected);
 
}
 
 
bool compare(const pair<pair<int,int>, int> &x , const pair<pair<int,int> , int> &y){
    return x.first.first < y.first.first;
}
 
void solve() {
    int n;
    cin>>n;
    vector<pair<pair<int , int> , int> > orders(n);
    for(int i = 0 ; i< n ; i++){
        cin>>orders[i].first.first>>orders[i].first.second>>orders[i].second;
    }
    sort(orders.begin() , orders.end() , compare);
    vector<int> start;
    for(int i = 0 ; i< n ; i++){
        start.push_back(orders[i].first.first);
    }
    memset(dp , -1 , sizeof(dp));
    cout<<maxProfit(0 , orders, start , n)<<endl;
 
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
//    cin>>t;
    while (t--)
        solve();
    return 0;
}
