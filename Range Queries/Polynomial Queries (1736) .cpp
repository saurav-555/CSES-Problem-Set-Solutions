#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
 
struct lazy{
    int n , sum;
    lazy(){
        n = 0 , sum = 0;
    }
};
lazy *lazy_tree;
int *arr , *seg_tree;
void set_seg_tree(int index, int s, int e){
    if(s > e){
        return ;
    }
    if(s == e){
        seg_tree[index] = arr[s];
        return ;
    }
    int mid = (s + e) /2;
    set_seg_tree(2*index +1, s, mid);
    set_seg_tree(2*index + 2 , mid + 1, e);
    seg_tree[index] = seg_tree[2*index + 1] + seg_tree[2*index + 2];
}
 
void update_seg(int l, int r , int index, int s, int e){
 
     if(lazy_tree[index].n != 0){
         int add_term = (lazy_tree[index]. n * ((e+1) * (e + 2) - s * (s + 1)) / 2) - lazy_tree[index].sum * (e - s + 1);
         seg_tree[index] += add_term;
         if(s != e){
             lazy_tree[2*index +1].n += lazy_tree[index].n;
             lazy_tree[2*index + 1].sum += lazy_tree[index].sum;
             lazy_tree[2*index +2].n += lazy_tree[index].n;
             lazy_tree[2*index + 2].sum += lazy_tree[index].sum;
         }
         lazy_tree[index].n = 0;
         lazy_tree[index].sum = 0;
     }
 
    if( l > r || s > e || l > e || r < s){
        return;
    }
     if(l <= s && e <= r){
         int add_term = (((e+1) * (e + 2) - s * (s + 1)) / 2) - l * (e - s + 1);
         seg_tree[index] += add_term;
         if( s != e){
             lazy_tree[2*index + 1].n +=1;
             lazy_tree[2*index + 1].sum +=l;
             lazy_tree[2*index + 2].n +=1;
             lazy_tree[2*index + 2].sum +=l;
         }
         return;
     }
     int mid = (s + e) /2;
     update_seg(l,r, 2*index + 1, s, mid);
     update_seg(l,r, 2*index + 2, mid+ 1, e);
     seg_tree[index] = seg_tree[2*index + 1] + seg_tree[2*index + 2];
 
}
int sum_in_seg(int l , int r, int index, int s, int e){
    if(l > r || s > e || l > e || r < s){
        return 0;
    }
    if(lazy_tree[index].n != 0){
        int add_term = (lazy_tree[index]. n * ((e +1) * (e + 2) - s * (s + 1)) / 2) - lazy_tree[index].sum * (e - s + 1);
        seg_tree[index] += add_term;
        if(s != e){
            lazy_tree[2*index +1].n += lazy_tree[index].n;
            lazy_tree[2*index + 1].sum += lazy_tree[index].sum;
            lazy_tree[2*index +2].n += lazy_tree[index].n;
            lazy_tree[2*index + 2].sum += lazy_tree[index].sum;
        }
        lazy_tree[index].n = 0;
        lazy_tree[index].sum = 0;
    }
    if(l <= s && e <= r){
        return seg_tree[index];
    }
    int mid = (s + e) / 2;
    return sum_in_seg(l, r, 2*index + 1, s, mid) + sum_in_seg(l, r, 2*index + 2, mid+1, e);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , t;
    cin>>n >>t;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int seg_size = 2 * (int) pow(2, ceil(log2(n))) -1;
    seg_tree = new int [seg_size];
    lazy_tree = new lazy [seg_size];
    set_seg_tree(0 , 0 , n-1);
    while(t--){
        int o,l,r;
        cin>>o;
        if(o==1){
            cin>>l>>r;
            l--,r--;
            update_seg(l,r,0,0,n-1);
        }else{
            cin>>l>>r;
            l--,r--;
            cout<<sum_in_seg(l,r,0,0,n-1)<<endl;
        }
    }
    return 0;
}
