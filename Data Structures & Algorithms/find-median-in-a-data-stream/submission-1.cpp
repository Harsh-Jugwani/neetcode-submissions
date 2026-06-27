class MedianFinder {
/*You can write it in just 3 concise points:

Use two heaps: a max heap to store the smaller half of the numbers and a min heap to store the larger half.
On each insertion: add the number to the appropriate heap based on the max heap's top, then rebalance so the max heap has either the same number of elements as the min heap or one extra.
Find the median: if both heaps are the same size, return the average of their top elements; otherwise, return the top of the max heap.
*/
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 2 <= 5
        if(maxheap.empty() || num <= maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }

        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }


    }
    
    double findMedian() {
        int n = minheap.size() + maxheap.size();
        if(n%2 == 0){
            return (minheap.top() + maxheap.top())/2.0;
        }
        return maxheap.top();
    }
};
