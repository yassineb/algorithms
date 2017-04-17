#include <bits/stdc++.h>

using namespace std;

class LRUCache{    
public:    
    LRUCache(int capacity) {
        this->capacity = capacity;
        items_map.reserve(capacity);
    }
    
    int get(int key) {
        auto it = items_map.find(key);
        
        if (it != items_map.end())
        {
            // move the element to the front 
            items_list.splice(items_list.begin(), items_list, it->second);
            return it->second->second;
        }
        
        return -1;
    }

    
    void put(int key, int value) {
        auto it = items_map.find(key);
        
        if (it != items_map.end())
        {
            items_list.erase(it->second);
            items_map.erase(it);
        }
        
        items_list.push_front(key_value_pair_t(key, value));
        items_map[key] = items_list.begin();
        
        if (size() > capacity)
        {
            auto last = items_list.end();
            --last;
            
            items_map.erase(last->first);
            items_list.pop_back();
        }
    }
    
    const int size() {
        return items_map.size();
    }
    
private:
	typedef pair<int, int> key_value_pair_t;
    typedef list<key_value_pair_t>::iterator items_list_iterator_t;
    
    int capacity;
    list<key_value_pair_t> items_list;
    unordered_map<int, items_list_iterator_t> items_map;
};
