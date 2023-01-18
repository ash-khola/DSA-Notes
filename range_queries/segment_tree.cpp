// implement segment tree 

#include<bits/stdc++.h>
using namespace std;

int arr[10000], seg[4 * 1000];

void build(int idx, int low, int high) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }

    int mid = low + (high - low) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r) {
    if (low >= l and high <= r) return seg[idx];

    if (low > r or high < l) return INT_MIN;
    int mid = low + (high - low) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);

    return max(left, right);
}

int main() {
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}

// This is for max element in the given range if min element is asked than while buolding tree store the minimum of left and right 
// If instead of max element we are asked to find the sum for the given range than instead of storing the max of left and right child we will store the sum of the left and right child