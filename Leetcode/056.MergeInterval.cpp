/*
1. Idea
This is almost same as activity selection problem.
First, we need to sort intervals by start time. This takes O(nlogn).
Next we need to keep merging two intervals at a time.
We add temporary interval to the result array only when we cannot
merge any two intervals(when interval1.end < interval2.start).
This process takes O(n) time and O(n) space at maximum.

2. What I learned new
I learned how to write comparison operator inside and outside of
the object.
1) To declare inside of the object in ascending order:
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int a, int b) : start(a), end(b) {}
  bool operator<(const Interval& i) {
    return start < i.start;
  }
};

2) To declare outside of the object in ascending order:
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int a, int b) : start(a), end(b) {}
};
struct comparison {
  bool operator()(const Interval& a, const Interval& b) {
    return a.start < b.start;
  }
};
*/

#include <iostream>
#include <vector>
#include <algorithm>
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int a, int b) : start(a), end(b) {}
  bool operator<(const Interval& i) {
    return start < i.start;
  }
};
class Solution {
  std::vector<Interval> merge(std::vector<Interval>& intervals) {
    std::vector<Interval> result;
    if (intervals.empty()) return result;
    std::sort(intervals.begin(), intervals.end());
    Interval temp = intervals[0];
    for (int i = 1; i < intervals.size(); i++) {
      if (temp.end >= intervals[i].start) {
        temp.end = std::max(temp.end, intervals[i].end);
      }
      else {
        result.push_back(temp);
        temp = intervals[i];
      }
    }
    result.push_back(temp);
    return result;
  }
  
  std::vector<Interval> merge2(std::vector<Interval>& intervals) {
    std::vector<Interval> result;
    if (intervals.empty()) return result;
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return a.start < b.start;});
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start <= result.back().end) {
        result.back().end = std::max(result.back().end, intervals[i].end);
      }
      else {
        result.push_back(intervals[i]);
      }
    }
};