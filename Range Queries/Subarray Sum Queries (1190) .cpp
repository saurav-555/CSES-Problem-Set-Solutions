#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
 
struct data{
    int pre;
    int suff;
    int sum;
    int ans;
    data(){
        pre = suff = sum = ans = 0;
    }
};
data *seg_tree;
int *arr;
data combine(const data &a,const data &b){
    data ans;
    ans.sum = a.sum + b.sum;
    ans.pre = max(a.pre , a.sum  + b.pre);
    ans.suff = max(b.suff, b.sum + a.suff );
    ans.ans = max(max(a.ans , b.ans ) , a.suff + b.pre);
    return ans;
}
void build_seg_tree(int index, int s, int e){
    if(s > e) return ;
    if(s == e) {
        seg_tree[index].sum = arr[s];
        seg_tree[index].pre = seg_tree[index].suff = seg_tree[index].ans = max((int)0, arr[s]);
        return;
    }
    int mid = (s + e) /2;
    build_seg_tree( 2*index + 1, s , mid);
    build_seg_tree(2*index + 2, mid + 1, e);
    seg_tree[index] = combine(seg_tree[2*index +1] , seg_tree[2*index + 2]);
}
void update_seg_tree(int in , int index, int s, int e){
    if( s > e || in > e || in < s){
        return;
    }
    if(s == e){
        seg_tree[index].sum = arr[s];
        seg_tree[index].pre = seg_tree[index].suff = seg_tree[index].ans = max((int)0, arr[s]);
        return;
    }
    int mid = (s + e)/2;
    if(in <= mid){
        update_seg_tree(in, 2*index + 1, s, mid);
    } else{
        update_seg_tree(in, 2*index + 2, mid + 1 , e);
    }
    seg_tree[index] = combine(seg_tree[2*index + 1], seg_tree[2*index +2]);
 
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , t;
    cin>>n >>t;
    arr = new int [n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int seg_size = 2 * (int)pow(2, ceil(log2(n))) -1;
    seg_tree = new data[seg_size];
    build_seg_tree( 0, 0, n-1);
    while(t--){
        int in, value;
        cin>>in>>value;
        in--;
        arr[in] = value;
        update_seg_tree(in, 0 , 0, n-1);
        cout<<seg_tree[0].ans<<endl;
    }
    return 0;
}
