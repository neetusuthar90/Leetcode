class SmallestInfiniteSet {
public:
    int num = 1000;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;
    SmallestInfiniteSet() {
        for (int i = 1; i <= num; i++){
            pq.push(i);
            mp[i]++;
        }

    }
    
    int popSmallest() {
        int a = pq.top();
        pq.pop();
        mp.erase(a);
        return a;
    }
    
    void addBack(int num) {
        if(mp[num]==0){
            pq.push(num);
            mp[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */