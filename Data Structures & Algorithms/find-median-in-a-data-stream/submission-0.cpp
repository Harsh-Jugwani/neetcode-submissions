class MedianFinder {
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
