class Logger {
private:
    unordered_map<string, int>m;
    vector<bool>res;
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(timestamp < m[message])
            return false;
        m[message] = timestamp + 10;
        return true;
        // if(m.count(message)){
        //     if(timestamp >= m[message]) {
        //         m[message] = timestamp+10;
        //         return true;
        //     }
        //     else return false;
        // }else {
        //     m[message] = timestamp+10;
        //     return true;
        // }
    }
};
