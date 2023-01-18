// *************************** Hash Set ***************************
class MyHashSet {
private:
    int size;
    vector<list<int>> myHash;
public:
    MyHashSet() {
        size = 100;
        myHash.resize(size);
    }

    int index(int key) {
        return key % size;
    }

    list<int> :: iterator search(int key) {
        int i = index(key);
        return find(myHash[i].begin(), myHash[i].end(), key);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = index(key);
        myHash[i].push_back((key));
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = index(key);
        myHash[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = index(key);
        if(search(key) == myHash[i].end()) return false;
        else return true;
    }
};




// *************************** Hash Map ***************************

class MyHashMap {
private:
    int size;
    vector<list<pair<int, int>>> myMap;
public:
    MyHashMap() {
        size = 100;
        myMap.resize(100);
    }

    int index(int key) {
        return key % size;
    }

    list<pair<int, int>> :: iterator search(int key) {
        int i = index(key);
        auto it = myMap[i].begin();
        while((*it)first != key and it != myMap[i].end()) it++;
        return it;
    }
    
    void put(int key, int value) {
        int i = index(key);
        auto it = search(key);
        if(it == myMap[i].end()) myMap[i].push_back({key, value});
        else it->second = value;
    }
    
    int get(int key) {
        auto it = search(key);
        int i = index(key);
        if(it != myMap[i].end()) return it->second;
        else return -1;
    }
    
    void remove(int key) {
        auto it = search(key);
        int i = index(key);
        if(it != myMap[i].end()) myMap[i].erase(it);
    }
};
