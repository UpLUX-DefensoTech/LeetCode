class MyHashSet {
private:
    vector<bool> table;  // boolean array to track presence

public:
    MyHashSet() {
        table.resize(1000001, false);  // keys range from 0 to 1e6
    }
    
    void add(int key) {
        table[key] = true;
    }
    
    void remove(int key) {
        table[key] = false;
    }
    
    bool contains(int key) {
        return table[key];
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */