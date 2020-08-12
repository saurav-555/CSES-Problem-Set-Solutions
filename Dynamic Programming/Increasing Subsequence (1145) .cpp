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
#define MAX 200005
 
int dp[MAX];
 
int binarySearch(int *a , vector<int> &record , int value , int ith){
    int l = 1 , h = ith , mid;
    if(a[record[0]] == value){
        return 0;
    }
    while(l <= h){
        mid = (l + h ) / 2;
        if(a[record[mid -1]] < value && value <= a[record[mid]]){
            return mid;
        }else if(a[record[mid]] < value){
            l = mid + 1;
        }else h = mid - 1;
    }
}
 
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i< n; i++)
        cin>>a[i];
    int res[n];
    memset(res , -1 , sizeof(res));
    vector<int> record;
    record.push_back(0);
    int ith = 0; // gives the last index of record
 
    for(int i = 1 ; i< n ; i++){
        // case 1 : greater than all
        if(a[record[ith]] < a[i]){
            record.push_back(i);
            res[i] = record[ith];
            ith++;
        }else if(a[record[0]] > a[i]){  // case 2 : smaller than all
            record[0] = i;
            res[i] = -1;
        }else { // case 3 : when intermediate
            int idx = binarySearch(a , record, a[i] , ith);
            record[idx] = i;
            if(idx != 0){
                res[i] = record[idx -1];
            }else res[i] = -1;
        }
 
    }
    cout<<ith + 1<<endl;
//    vector<int> ans;
//    int i ;
//    for( i = record[ith] ; res[i] != -1 ; i = res[i]){
//        ans.push_back(i);
//    }
//    ans.push_back(i);
//    reverse(ans.begin(), ans.end());
//    for(auto ii : ans){
//        cout<<a[ii]<<" ";
//    }
//    cout<<endl;
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
