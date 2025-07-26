class MyQueue {
public:
    
    stack<int>s1;
    stack<int>s2;
    

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(empty()) return 0;
        else{
            if(!s2.empty()){
                int e=s2.top();
                s2.pop();
                 return e;
            }
            else{
                while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
                }
                int e=s2.top();
                s2.pop();
                 return e;
        
            }
          
        }
         
    }
    
    int peek() {
        if(empty()) return -1;
        else{
            if(!s2.empty()){
                int e=s2.top();
                return e;
            }

            else{
                while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
                }
                 int e=s2.top();
                
                return e;
            }
        }
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
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