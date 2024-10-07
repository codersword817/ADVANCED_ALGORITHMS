// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Node{
    public:
    vector<int> bit;
    int sz;
    Node(int n){
        bit.resize(n+1, 0);
        sz=n;
    }
    void insert(int ele, int idx){
        while(idx<=sz){
            bit[idx]+=ele;
            idx+=(idx & -idx);
        }
    }
    int query(int idx){
        int res=0;
        while(idx>0){
            res+=bit[idx];
            idx-=(idx&-idx);
        }
        return res;
    }
};



class Solution {
public:

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> vpp;
        int n=nums.size();
        if(n==1) return {0};
        for(int i=0;i<n;i++){
            vpp.push_back({nums[i], i});
        }
        sort(vpp.begin(), vpp.end());
        vector<int> res(n, 0);
        Node* node=new Node(n);
        for(auto i:vpp){
            int ele=i.first;
            int idx=i.second+1;
            res[idx-1]=(node->query(n)-node->query(idx));
            node->insert(1, idx);
        }
        return res;
    }
};
