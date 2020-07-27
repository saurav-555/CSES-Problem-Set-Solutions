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
 
bool compare(const p(ii , int) &x , const p(ii , int ) &y){
    if(x.first.first < y.first.first){
        return true;
    }    else if(x.first.first > y.first.first){
        return false;
    }else {
        return x.first.second <= y.first.second;
    }
}
struct compare2{
    bool operator() (const ii &x , const ii &y) const{
        if(x.first > y.first)
            return true;
        else if(x.first < y.first)
            return false;
        else return x.second > y.second;
    }
};
void solve() {
    int n;
    cin>>n;
    v(p(ii , int)) data(n);
    for(int i = 0 ; i< n ; i++){
        cin>>data[i].first.first;
        cin>>data[i].first.second;
        data[i].second = i;
    }
    sort(data.begin() , data.end() , compare);
    int reqRooms = 0 , room;
    set<int> have;
    vi ans(n);
    priority_queue<ii , vii , compare2> q;
    for(int i = 0 ; i < n ; i++){
        while(!q.empty() && q.top().first < data[i].first.first){
            have.insert(q.top().second);
            q.pop();
        }
        if(have.empty()){
            room = ++reqRooms;
        }else {
            room = *have.begin();
            have.erase(have.begin());
        }
        ans[data[i].second] = room;
        q.push({data[i].first.second , room});
    }
    cout<<reqRooms<<endl;
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
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
