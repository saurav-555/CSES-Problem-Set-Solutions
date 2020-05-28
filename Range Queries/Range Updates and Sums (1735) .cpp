#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
 
#define int long long
struct lazy{
    char type;
    int value;
    lazy(){
        type = 'n';
        value = 0;
    }
};
 
lazy *lazy_tree;
int *seg_tree , *arr;
 
void set_seg_tree(int index, int s, int e){
    if(s > e){
        return;
    }
    if(s==e){
        seg_tree[index] = arr[s];
        return;
    }
    int mid = (s + e) /2;
    set_seg_tree(2*index + 1, s , mid);
    set_seg_tree(2*index + 2, mid + 1, e);
    seg_tree[index] = seg_tree[2*index + 1] + seg_tree[2*index + 2];
}
void update_seg(bool type, int value, int l, int r, int index, int s, int e){
 
    if(lazy_tree[index].type =='i'){
        seg_tree[index] += (e - s + 1) * lazy_tree[index].value;
        if(s != e){
            if(lazy_tree[2*index + 1].type !='n'){
                lazy_tree[2*index+1].value += lazy_tree[index].value;
            }else{
                lazy_tree[2*index + 1].value = lazy_tree[index].value;
                lazy_tree[2*index + 1].type = 'i';
            }
            if(lazy_tree[2*index + 2].type !='n'){
                lazy_tree[2*index+2].value += lazy_tree[index].value;
            }else{
                lazy_tree[2*index + 2].value = lazy_tree[index].value;
                lazy_tree[2*index + 2].type = 'i';
            }
        }
        lazy_tree[index].type = 'n';
        lazy_tree[index].value = 0;
    }
    if(lazy_tree[index].type =='s'){
        seg_tree[index] = (e - s + 1) * lazy_tree[index].value;
        if(s != e){
            lazy_tree[2 * index + 1].value = lazy_tree[index].value;
            lazy_tree[2 * index + 1].type = 's';
 
            lazy_tree[2 * index + 2].value = lazy_tree[index].value;
            lazy_tree[2 * index + 2].type = 's';
        }
        lazy_tree[index].type = 'n';
        lazy_tree[index].value = 0;
    }
    if(l > r || s > e || l > e || r < s){
        return;
    }
    if(l <= s && e <= r){
        if(type){
            seg_tree[index] += (e - s + 1) * value;
            if(s!=e){
                if(lazy_tree[2*index + 1].type !='n'){
                    lazy_tree[2*index+1].value += value;
                }else{
                    lazy_tree[2*index + 1].value = value;
                    lazy_tree[2*index + 1].type = 'i';
                }
                if(lazy_tree[2*index + 2].type !='n'){
                    lazy_tree[2*index+2].value += value;
                }else{
                    lazy_tree[2*index + 2].value = value;
                    lazy_tree[2*index + 2].type = 'i';
                }
            }
        } else{
            seg_tree[index] = (e - s + 1) * value;
            if(s != e){
                lazy_tree[2 * index + 1].value = value;
                lazy_tree[2 * index + 1].type = 's';
 
                lazy_tree[2 * index + 2].value = value;
                lazy_tree[2 * index + 2].type = 's';
            }
        }
        return;
    }
    int mid = (s + e) /2;
    update_seg(type, value, l, r, 2*index +1, s, mid);
    update_seg(type, value, l, r, 2*index +2 , mid+1, e);
    seg_tree[index] = seg_tree[2*index + 1] + seg_tree[2*index +2];
 
}
int seg_sum(int l, int r, int index, int s, int e){
    if(s > e || l > r || l > e || r <s ){
        return 0;
    }
    if(lazy_tree[index].type =='i'){
        seg_tree[index] += (e - s + 1) * lazy_tree[index].value;
        if(s != e){
            if(lazy_tree[2*index + 1].type !='n'){
                lazy_tree[2*index+1].value += lazy_tree[index].value;
            }else{
                lazy_tree[2*index + 1].value = lazy_tree[index].value;
                lazy_tree[2*index + 1].type = 'i';
            }
            if(lazy_tree[2*index + 2].type !='n'){
                lazy_tree[2*index+2].value += lazy_tree[index].value;
            }else{
                lazy_tree[2*index + 2].value = lazy_tree[index].value;
                lazy_tree[2*index + 2].type = 'i';
            }
        }
        lazy_tree[index].type = 'n';
        lazy_tree[index].value = 0;
    }
    if(lazy_tree[index].type =='s'){
        seg_tree[index] = (e - s + 1) * lazy_tree[index].value;
        if(s != e){
            lazy_tree[2 * index + 1].value = lazy_tree[index].value;
            lazy_tree[2 * index + 1].type = 's';
 
            lazy_tree[2 * index + 2].value = lazy_tree[index].value;
            lazy_tree[2 * index + 2].type = 's';
        }
        lazy_tree[index].type = 'n';
        lazy_tree[index].value = 0;
    }
    if(l <= s && e <= r){
        return seg_tree[index];
    }
    int mid = (s + e) /2;
    return seg_sum(l, r, 2*index + 1, s, mid) + seg_sum(l, r, 2*index + 2, mid + 1, e);
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t;
    cin>>n>>t;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int seg_size = 2 * (int)pow(2, ceil(log2(n))) -1;
 
    seg_tree = new int[seg_size];
    lazy_tree = new lazy[seg_size];
 
    set_seg_tree(0, 0, n-1);
 
    while(t--){
        int o,l,r,value;
        cin>>o>>l>>r;
        l--,r--;
        if(o ==1){
            cin>>value;
            update_seg(true, value, l, r, 0, 0 , n-1);
        } else if(o==2){
            cin>>value;
            update_seg(false, value, l, r, 0, 0, n-1);
        } else {
            cout<<seg_sum(l,r, 0, 0, n-1)<<endl;
        }
    }
    return 0;
 
}
