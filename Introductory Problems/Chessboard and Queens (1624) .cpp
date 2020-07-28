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
char x[8][8];
int ways = 0;
 
void findWays(int ith , bool fSlash[] , bool bSlash[] , bool col[]){
    if(ith == 8){
        ways++;
        return;
    }
    for(int j = 0 ; j < 8 ; j++){
        if(x[ith][j] == '.'){
            if(!col[j] && !fSlash[j - ith + 7] && !bSlash[j+ith]){
                col[j] = fSlash[j - ith + 7] = bSlash[j+ith] = true;
                findWays(ith + 1 , fSlash , bSlash , col);
                col[j] = fSlash[j-ith + 7] = bSlash[j+ith] = false;
            }
        }
    }
}
 
void solve() {
    for(int i = 0 ; i < 8 ; i++){
        cin>>x[i];
    }
    bool fSlash[2 * 8 -1] = {false}, bSlash[2 * 8 - 1] = {false};
    bool col[8] = {false};
    findWays(0 , fSlash , bSlash , col);
    cout<<ways<<endl;
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
