/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() : active(true) {
		
	}

	/** Push element x onto stack. */
	void push(int x) {
		if (active) {
			q1.push(x);
		}
		else {
			q2.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (active) {
			while (q1.size() != 1) {
				q2.push(q1.front());
				q1.pop();
			}
			active = false;
			int ret = q1.front();
			q1.pop();
			return ret;
		}
		else {
			while (q2.size() != 1) {
				q1.push(q2.front());
				q2.pop();
				active = true;
			}
			active = true;
			int ret = q2.front();
			q2.pop();
			return ret;
		}
	}

	/** Get the top element. */
	int top() {
		int ret = 0;
		if (active) {
			while (!q1.empty()) {
				ret = q1.front();
				q2.push(ret);
				q1.pop();
			}
			active = false;
			return ret;
		}
		else {
			while (!q2.empty()) {
				ret = q2.front();
				q1.push(ret);
				q2.pop();
			}
			active = true;
			return ret;
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
	// active = true <=>  q1 is active
	// active = false <=>  q2 is active
	bool active;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

