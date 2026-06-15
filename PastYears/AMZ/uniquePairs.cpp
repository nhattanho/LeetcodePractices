int unique(vector<int> arr, int target){
    unordered_map <int, int> fre; // key, frequency
    int len = arr.size();
    int count = 0;
    for(auto x: arr) fre[x]++;
    
    for(auto x: arr){
        int remain = target - x;
        if(fre[remain] != 0 && fre[x] != 0) {
            count++;
            fre[remain] = 0;
            fre[x] = 0;
        }
    }
    return count;
}

int unique(vector<int> arr, int target){
    unordered_map <int, int> fre; // key, frequency
    int len = arr.size();
    int count = 0;
    set<pair<int, int>> visited;
    
    for(auto x: arr){
        int remain = target - x;
        if(fre.count(remain) == 0) fre.insert({x, 0});
        else {
            visited.insert({min(remain, x), max(remain, x)});
        }
    }
    return visited.size();
}

int unique(vector<int> arr, int target){
    unordered_map <int, int> fre; // key, frequency
    int len = arr.size();
    int count = 0;
    unordered_map<int, int> visited;
    
    for(auto x: arr){
        int remain = target - x;
        if(fre.count(remain) == 0) fre.insert({x, 0});
        else {
            visited.insert({min(remain, x), max(remain, x)});
        }
    }
    return visited.size();
}
