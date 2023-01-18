// Union by size 

class DSU {
    private:
    vector<int> parent, size, rank;
    public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i, size[i] = 1;
    }
    
    int findParent(int a) {
        if(parent[a] == a) return a;
        return parent[a] = findParent(parent[a]);
    }
    
    void Union(int a, int b) {
        int a1 = findParent(a);
        int b1 = findParent(b);
        if(a1 != b1) {
            if(size[a1] < size[b1]) {
            swap(a1, b1);
            }
            parent[b1] = parent[a1];
            size[a1] += size[b1];
        }
    }
};