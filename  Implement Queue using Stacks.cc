class MyQueue {
public:
    stack<int> myQueue;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (empty()) {
            myQueue.push(x);
        } else {
            int val = peek();
            myQueue.pop();
            push(x);
            myQueue.push(val);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = myQueue.top();
        myQueue.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return myQueue.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return myQueue.empty();
    }
};