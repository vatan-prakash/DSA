class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        if (empty()) {
            q1.push(x);  // You can pick either q1 or q2 when both are empty
        } else {
            if (!q1.empty()) {
                q1.push(x);
            } else {
                q2.push(x);
            }
        }
    }

    int pop() {
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int val = q1.front();
            q1.pop();
            return val;
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int val = q2.front();
            q2.pop();
            return val;
        }
    }

    int top() {
        int val;
        if (!q1.empty()) {
            while (!q1.empty()) {
                val = q1.front();
                q2.push(val);
                q1.pop();
            }
        } else {
            while (!q2.empty()) {
                val = q2.front();
                q1.push(val);
                q2.pop();
            }
        }
        return val;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};
