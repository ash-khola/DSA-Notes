class NumArray {
private:
    vector<int> segTree;
    int n;

    void buildTree(vector<int> &nums, int left, int right, int node) {
        if(left == right) {
            segTree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        buildTree(nums, left, mid, 2 * node + 1);
        buildTree(nums, mid + 1, right, 2 * node + 2);

        segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
    }

    int sumRange(int left, int right, int ss, int se, int node) {
        if(se < left or ss > right) return 0;
        if(ss <= left and se >= right) return segTree[node];

        int mid = left + (right - left) / 2;

        int leftSum = sumRange(left, mid, ss, se, 2 * node + 1);
        int rightSum = sumRange(mid + 1, right, ss, se, 2 * node + 2);

        return leftSum + rightSum;
    }

    void update(int left, int right, int ind, int val, int node) {
        if(ind < left or ind > right) return;
        if(left == right) {
            segTree[node] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        update(left, mid, ind, val, 2 * node + 1);
        update(mid + 1, right, ind, val, 2 * node  + 2);

        segTree[node] = segTree[2 * node  + 1] + segTree[2 * node + 2];
    }
    
public: 

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildTree(nums, 0, n - 1, 0);
    }
    
    void update(int index, int val) {
        update(0, n - 1, index, val, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0, n - 1, left, right, 0);
    }
};