/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

class RandomizedSet {
public:
    // we will use a map to keep track of where elements are stored in an array
    // and we will use an vector array for inserting elements into array in O(1)
    // for random value retreival we will use rand function..
    unordered_map<int, int>mp; // element and index
    vector<int>a;
    RandomizedSet() {
        // yo
    }
    
    bool insert(int val) {
        // insert elements into array only if it is not present in map
        if(mp.find(val) != mp.end()) return false;// element already present
        // else if not present put it into vector
        a.push_back(val);
        mp[val] = a.size()-1; // whatever the current size is
        return true;

    }
    
    bool remove(int val) {
        // to remove check if it exists or not
        if(mp.find(val) == mp.end()) return false;
        // else remove the element and put the last element in its place
        int idx = mp[val];
        int lastEle = a.back();
        a[idx] = lastEle;
        mp[lastEle] = idx;
        a.pop_back();
        return true;

    }
    
    int getRandom() {
        // get a random value from array with equal probability
        int random = rand()%a.size();
        return a[random];
    }
};