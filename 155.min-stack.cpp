/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
// class MinStack {
// public:
// 	/** initialize your data structure here. */
// 	MinStack() : min(INT_MAX), s(){
// 	}

// 	void push(int x) {
// 		if (x < min) {
// 			min = x;
// 		}
// 		s.push_back(x);
// 	}

// 	void pop() {
// 		if (s.empty()) {
// 			return;
// 		}
// 		if (min == s.back()) {
// 			s.erase(s.end() - 1);
// 			min = INT_MAX;
// 			for (auto a : s) {
// 				if (a < min) {
// 					min = a;
// 				}
// 			}
// 		}
// 		else {
// 			s.erase(s.end() - 1);
// 		}
// 	}

// 	int top() {
// 		if (s.empty()) {
// 			return INT_MAX;
// 		}
// 		return s.back();
// 	}

// 	int getMin() {
// 		if (s.empty()) {
// 			return INT_MAX;
// 		}
// 		return min;
// 	}
// private:
// 	int min;
// 	int lastMin;
// 	vector<int> s;
// };

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() : min(INT_MAX), s() {
	}

	void push(int x) {
		if (x < min) {
			min = x;
		}
		s.push_back(x);
		s.push_back(min);
	}

	void pop() {
		if (s.empty()) {
			return;
		}
		s.erase(s.end() - 1);
		s.erase(s.end() - 1);
		min = s.back();
	}

	int top() {
		if (s.empty()) {
			return INT_MAX;
		}
		return *(s.end() - 2);
	}

	int getMin() {
		if (s.empty()) {
			return INT_MAX;
		}
		return min;
	}
private:
	int min;
	vector<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

