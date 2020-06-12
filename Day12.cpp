//problem link;-https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3358/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    private:
    vector<int>arr;
    unordered_map<int,int>mp;
    public:
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        arr.emplace_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int last=arr.back();
        mp[last]=mp[val];
        arr[mp[val]]=last;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r=rand()%arr.size();
        return arr[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
