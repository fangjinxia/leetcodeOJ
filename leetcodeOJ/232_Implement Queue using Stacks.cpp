class MyQueue {
public:
    stack<int> s;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        genPush(x);
    }
    void genPush(int x){
        if(s.size() == 0){
            s.push(x);
            return ;
        }
        int data = s.top();
        s.pop();
        genPush(x);
        s.push(data);
        return ;
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int data = s.top();
        s.pop();
        return data;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */