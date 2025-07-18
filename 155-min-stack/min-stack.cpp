class MinStack {
private:
    stack<int> s1;     // Actual stack
    stack<int> mins;   // Min-tracking stack

public:
    MinStack() {
        // No need to declare stacks here again
    }

    void push(int val) {
        s1.push(val);
        // Push to mins if it's empty or val <= current min
        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        }
    }

    void pop() {
        if (s1.empty()) return;
        int topVal = s1.top();
        s1.pop();
        if (topVal == mins.top()) {
            mins.pop();
        }
    }

    int top() {
        if (s1.empty()) return -1;
        return s1.top();  // Return top of the actual stack
    }

    int getMin() {
        if (mins.empty()) return -1;
        return mins.top();  // Return current minimum
    }
};
