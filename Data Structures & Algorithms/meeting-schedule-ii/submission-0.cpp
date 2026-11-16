/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<intervals.size(); i++){
            int start = intervals[i].start;
            int end = intervals[i].end;

            // same room is available, remove the previous end time
            if(!minHeap.empty() && minHeap.top() <= start){
                minHeap.pop();
            }

            //push the new end time, in both cases if room is available or not
            minHeap.push(end);
        }

        return minHeap.size();
    }
};
