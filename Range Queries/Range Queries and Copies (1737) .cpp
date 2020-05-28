#include<bits/stdc++.h>
 
using namespace std;
 
using u128 = __uint128_t;
#define version_count 200000
#define int long long
struct data{
    int value;
    data *left, *right;
    data(){
        value = 0, left = nullptr, right = nullptr;
    }
};
data **versions;
int *arr;
 
void build_seg_tree(data *root, int s, int e){
    if(s > e){
        return;
    }
    if(s==e){
        root->value = arr[s];
        return;
    }
    int mid = (s + e) /2;
    root->left = new data;
    root->right = new data;
    build_seg_tree(root->left , s, mid );
    build_seg_tree(root->right, mid+ 1, e);
    root->value = root->left->value + root->right->value;
}
int get_sum(data *root, int l, int r, int s, int e){
    if(l > r || s > e || l > e || r < s){
        return 0;
    }
    if(l <= s && e <= r){
        return root->value;
    }
    int mid = (s + e) /2;
    return get_sum(root->left, l, r, s, mid) + get_sum(root->right, l, r, mid+1, e);
}
void new_version_update(data *prev, data *curr, int in ,int value, int s, int e){
    if(s > e || in > e || in < s){
        return;
    }
    if(s == e){
        curr->value = value;
        return ;
    }
    int mid = (s + e) /2;
    if(in <= mid){
        curr->right = prev->right;
        curr->left = new data;
        new_version_update(prev->left, curr->left, in, value, s , mid);
    } else {
        curr->left = prev->left;
        curr->right = new data;
        new_version_update(prev->right, curr->right, in, value, mid+1, e);
    }
    curr->value = curr->left->value + curr->right ->value;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin>>n>>t;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    versions = new data*[version_count];
 
    data *root = new data;
    build_seg_tree(root, 0, n-1);
    versions[0] = root;
    int last_version = 0;
    while(t--){
        int o;
        cin>>o;
        if(o==1){
            int k, in, value;
            cin>>k>>in>>value;
            k--,in--;
            data *temp = new data;
            new_version_update(versions[k] , temp , in, value, 0, n-1);
            versions[k] = temp;
        } else if(o==2){
            int k, l, r;
            cin>>k>>l>>r;
            k--,l--,r--;
            cout<<get_sum(versions[k] , l, r, 0, n-1)<<endl;
        } else{
            int k;
            cin>>k;
            k--;
            last_version++;
            versions[last_version] = versions[k];
        }
    }
    return 0;
}
