class LRUCache {
private:
    int capacity;
    unordered_map<int, int>m;
    unordered_map<int, list<int>::iterator>pos;
    //begining of the list: most recently used
    //end of the list: least recently used
    list<int>l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        
        l.erase(pos[key]);
        l.insert(l.begin(), key);
        pos[key] = l.begin();
        return it->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) {
            m[key] = value;
            l.erase(pos[key]);
        }
        else {
            if(m.size()<capacity){
                // add the new
                m.insert({key, value});
            }else{
                //delete the least recently key
                //that is the last element of the list
                int key_delete = l.back();
                l.pop_back();
                m.erase(key_delete);
                m.insert({key,value});
            }
        }
        
        // begining of list is the most recently used
        l.insert(l.begin(), key);
        pos[key] = l.begin();
    }
