class MedianFinder {
    priority_queue<long> maxheap, minheap;
public:

    void addNum(int num) {
        maxheap.push(num);
        minheap.push(-maxheap.top());
       maxheap.pop();
        if (maxheap.size() < minheap.size()) {
            maxheap.push(-minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        return (maxheap.size() > minheap.size())
               ? maxheap.top()
               : (maxheap.top() - minheap.top()) / 2.0;
    }
};