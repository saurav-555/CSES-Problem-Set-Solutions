#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
#define MOD 1000000007
#define MAX 100005
 
int arr[MAX];
int  *seg_tree;
void buildSeg(const int *a , int in , int s, int e){
    if(s == e){
        seg_tree[in] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    buildSeg(a, 2*in + 1, s, mid);
    buildSeg(a, 2*in + 2, mid + 1, e);
    seg_tree[in] = max(seg_tree[2*in + 1] , seg_tree[2*in + 2]);
}
int solveSeg(int *a, int in , int s, int e, int value){
    if(s == e){
        a[s] = a[s] - value;
        seg_tree[in] = a[s];
        return s + 1;
    }
    int mid = (s + e) / 2;
    int k;
    if(seg_tree[2*in + 1] >= value){
        k = solveSeg(a, 2*in + 1, s, mid, value);
    }else {
        k = solveSeg(a, 2*in + 2, mid + 1 , e , value);
    }
    seg_tree[in] = max(seg_tree[2*in + 1] , seg_tree[2*in + 2]);
    return k;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin>>n>>t;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int seg_size = 2 * (int)pow(2, ceil(log2(n))) - 1;
    seg_tree = new int[seg_size];
    for (int j = 0; j < seg_size; ++j) {
        seg_tree[j] = LONG_LONG_MIN;
    }
    buildSeg(a, 0 , 0 , n-1);
    while(t--){
        int value;
        cin>>value;
        if(seg_tree[0] < value){
            cout<<0<<" ";
        }else {
            cout<<solveSeg(a, 0 , 0 , n-1, value)<<" ";
        }
    }
    return 0;
}
