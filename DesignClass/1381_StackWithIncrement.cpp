class CustomStack {
private:
    vector<int>stack;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < maxSize)
            stack.emplace_back(x);
    }
    
    int pop() {
        if(stack.size() == 0) return -1;
        int back = stack.back();
        stack.pop_back();
        return back;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k and i < stack.size(); i++){
            //if(i >= stack.size()) break;
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
