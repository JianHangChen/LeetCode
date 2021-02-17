// sol1, from gy, O(1), O(1)
#include <list>
class LFUCache {
private:
    unordered_map<int, int> counter; //key2Freq
    unordered_map<int, list<vector<int>>::iterator> key2Pos;
    unordered_map<int, list<vector<int>>> freq2Keys;
    int CAP, minFreq;
public:
    LFUCache(int capacity) {
        CAP = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(key2Pos.count(key) == 0) return -1;
        auto position = key2Pos[key];
        int value = (*position)[1];
        freq2Keys[counter[key]].erase(position);
        if(freq2Keys[minFreq].size() == 0) minFreq++; // !!!important to check the minFreq list
        
        // update to counter
        counter[key]++;
        
        // update to most recently used
        freq2Keys[counter[key]].push_front({key,value});
        key2Pos[key] =  freq2Keys[counter[key]].begin();
        return value;
    }
 
    void put(int key, int value) {
        if(CAP == 0) return; //!! edge case, nothing to delete when key not exist
        if(get(key) != -1){ // key exist
            (*key2Pos[key])[1] = value;
        }
        else{ // key not exist
            if(key2Pos.size() >= CAP){ // full capacity
                int keyToDelete = freq2Keys[minFreq].back()[0];
                freq2Keys[minFreq].pop_back();
                key2Pos.erase(keyToDelete);
                counter.erase(keyToDelete);
            }
            // add key
            counter[key] = 1;
            minFreq = 1;
            freq2Keys[minFreq].push_front({key, value});
            key2Pos[key] = freq2Keys[minFreq].begin();
        }
    }
};
