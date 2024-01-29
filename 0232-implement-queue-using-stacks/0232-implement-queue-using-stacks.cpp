class MyQueue {
stack<int> container1, container2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        container1.push(x);
    }
    
    int pop() {
        int retVal;
        while(container1.empty() == false)
        {
            container2.push(container1.top());
            container1.pop();
        }
        retVal = container2.top();
        container2.pop();
        while(container2.empty() == false)
        {
            container1.push(container2.top());
            container2.pop();
        }
        return retVal;
    }
    
    int peek() {
        int retVal;
        while(container1.empty() == false)
        {
            container2.push(container1.top());
            container1.pop();
        }
        retVal = container2.top();
        while(container2.empty() == false)
        {
            container1.push(container2.top());
            container2.pop();
        }
        return retVal;
    }
    
    bool empty() {
        return container1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */