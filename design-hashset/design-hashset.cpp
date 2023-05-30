class MyHashSet {
public:
    vector<list<int>> arr;
    int size;

    MyHashSet() {
        size = 100;
        arr.resize(size);    
    }
    
    int hash(int key){
        return key%size;
    }

    list<int>::iterator search(int key){
        int i = hash(key);
        return find(arr[i].begin(), arr[i].end(), key);
    }

    void add(int key) {
        if(contains(key)) return;
        int i = hash(key);
        arr[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hash(key);
        arr[i].erase(search(key));
    }
    
    bool contains(int key) {
        int id = hash(key);
        if(search(key) != arr[id].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */