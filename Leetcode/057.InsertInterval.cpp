/*
Problem:
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
*/
#include <iostream>
#include <vector>
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
  std::vector<Interval> result;
  int i = 0;
  for (; i < intervals.size(); i++) {
    if (newInterval.end < intervals[i].start) {
      break;
    }
    else if (newInterval.start > intervals[i].end) {
      result.push_back(intervals[i]);
    }
    else {
      newInterval.end = std::max(newInterval.end, intervals[i].end);
      newInterval.start = std::min(newInterval.start, intervals[i].start);
    }
  }
  result.push_back(newInterval);
  for (; i < intervals.size(); i++) {
    result.push_back(intervals[i]);
  }
  return result;
}