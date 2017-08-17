class MyStack {
public:
    queue<int> myStack;
    
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myStack.push(x);
        for (int i = 1; i < myStack.size(); ++i) {
            myStack.push(top());
            myStack.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = top();
        myStack.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return myStack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myStack.empty();
    }
};