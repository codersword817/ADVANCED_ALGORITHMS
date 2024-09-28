#include<bits/stdc++.h>
using namespace std;

// one - based indexing 
// inserting N elements takes O(NLogN) time, Querying q queries takes O(qLogN) time
// Space - O(N) for bit array 

vector<int> bit;
int size;
void update(int idx, int value){ // populate the value accross from top to bottom logN times
    while(idx<=size){
        bit[idx]+=value;
        idx+=(idx & -idx);
    }
}

int query(int id){
    int ans=0;
    while(id>0){
        ans+=bit[id];
        id-=(id & -id); // removing the Least significant Set Bit (Removing right most set bit)
    }
    return ans;
}
// query(r) means sum(1, r)

// if you want Ar-Al = query(r) - query(l-1);

int main(){
    
    int n;
    cin>>n;
    size=n;
    vector<int> arr(n+1, 0);
    bit.resize(n+1, 0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i, arr[i]);
    }

    int q;
    cin>>q;
    while(q--){
        int r;
        cin>>r;
        cout<<query(r)<<endl;
    }

    return 0;
}