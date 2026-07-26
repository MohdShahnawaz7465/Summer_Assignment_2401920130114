class MinStack {
public:
    MinStack() {

    }

    void push(int value) {
        st.push(value);
        if (minSt.empty() || value <= minSt.top()) {
            minSt.push(value);
        } else {
            minSt.push(minSt.top());
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;
};
