/* Using one more space to save the min value of current stack*/
class MinStack {
    vector<int> min;
    vector<int> stack;
    public:
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min.empty() || x <= min.back())
            min.push_back(x);
    }
    
    void pop() {
        if(stack.back() == min.back())
            min.pop_back();
        stack.pop_back();
    }
    
    int top() {
        if(!stack.empty())
            return stack.back();
        
        return -1;
    }
    
    int getMin() {
        if(!min.empty())
            return min.back();
        return -1;
    }
};

/* Another approach to save space by saving the value and it's min value
 * in the same stack. We want to save the value and the current minimum
 * in the same time, so each time we push the value into stack, we have
 * to compare immediately this value with the current minimum to update
 * for it, so if we arrange the minimum above the value in the stack, it
 * would be easier to compare between the minimum with the next value of
 * the next push. For example: -2 0 -1 3 -3 6 
 * ------
 * | -3 |---------->min
 * |  6 |->value
 * |----|
 * | -3 |---------->min
 * | -3 |->value
 * |----|
 * | -2 |---------->min
 * |  3 |->value
 * |----|
 * | -2 |---------->min
 * | -1 |->value
 * |----|
 * | -2 |---------->min
 * |  0 |->value
 * |----|
 * | -2 |---------->min
 * | -2 |->value
 * ------
 * */
class MinStack {
    public:
    vector<int> data;
    MinStack(){}

    void push(int x) {
        if(data.empty()){
            data.push_back(x);//value
            data.push_back(x); //min value
        }
        else{
            int min = (x > data.back())?data.back():x;
            data.push_back(x);
            data.push_back(min);
        }
    }

    void pop() {
        if(!data.empty()){
            data.pop_back();//remove value
            data.pop_back();//remove min value
        }
    }

    int top() {
        if(!data.empty()){
            int min = data.back();
            data.pop_back();
            int value = data.back();
            data.push_back(min);
            return value;
        }
        return -1;
    }

    int getMin() {
        if(!data.empty()) return data.back();
        return -1;
    }
};
