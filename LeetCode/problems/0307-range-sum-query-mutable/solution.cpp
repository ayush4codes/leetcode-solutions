class SegmentTree {
    public:
    int n;
    vector<int> tree;
    SegmentTree(vector<int> nums) {
        this->n = nums.size();
        tree.resize(4*n,0);
        build(1,0,n-1,nums);
    }
    void build(int node,int start,int end,vector<int>& nums) {
        if (start == end) {
            tree[node]  = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid, nums);
        build(2*node + 1,mid + 1,end, nums);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
    void update(int node,int start,int end,int idx,int value) {
        if (start == end) {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2*node,start,mid,idx,value);
        } else {
            update(2*node+1,mid+1,end,idx,value);
        }
        tree[node] = tree[2*node] + tree[2*node +1]; 
    }
    int query(int node,int start,int end,int L,int R) {
        if (end<L || start>R) return 0;
        if (start>=L && end <= R) return tree[node];
        int mid = (start+end) / 2;
        int l = query(2*node,start,mid,L,R);
        int r = query(2*node+1,mid+1,end,L,R);
        return l+r; 
    }
    int query(int L,int R) {
        return query(1,0,n-1,L,R);
    }
    void update(int idx,int value) {
        update(1,0,n-1,idx,value);
    }
};
class NumArray {
    SegmentTree* st;
public:
    NumArray(vector<int>& nums) {
        st = new SegmentTree(nums);
    }
    
    void update(int index, int val) {
        st->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return st->query(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */