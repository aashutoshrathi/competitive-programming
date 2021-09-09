#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
 */

// @lc code=start
#include <deque>

class FrontMiddleBackQueue {
 public:
  deque<int> x, y;
  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    if (x.size() > y.size()) {
      y.push_front(x.back());
      x.pop_back();
    }
    x.push_front(val);
  }

  void pushMiddle(int val) {
    if (x.size() > y.size()) {
      y.push_front(x.back());
      x.pop_back();
    }
    x.push_back(val);
  }

  void pushBack(int val) {
    if (y.size() > x.size()) {
      x.push_back(y.front());
      y.pop_front();
    }
    y.push_back(val);
  }

  int popFront() {
    int val = -1;
    if (!x.size() && !y.size()) {
      return val;
    }
    if (!x.size()) {
      val = y.front();
      y.pop_front();
    } else {
      if (x.size() < y.size()) {
        x.push_back(y.front());
        y.pop_front();
      }
      val = x.front();
      x.pop_front();
    }

    return val;
  }

  int popMiddle() {
    int val = -1;
    if (!x.size() && !y.size()) {
      return val;
    }

    if (y.size() > x.size()) {
      val = y.front();
      y.pop_front();
    } else {
      val = x.back();
      x.pop_back();
    }
    return val;
  }

  int popBack() {
    int val = -1;
    if (!x.size() && !y.size()) {
      return val;
    }
    if (!y.size()) {
      val = x.back();
      x.pop_back();
    } else {
      if (x.size() > y.size()) {
        y.push_front(x.back());
        x.pop_back();
      }
      val = y.back();
      y.pop_back();
    }

    return val;
  }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end
