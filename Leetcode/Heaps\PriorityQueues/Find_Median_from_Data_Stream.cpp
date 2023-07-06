class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int> left;
    int count;
    MedianFinder() {
        count=0;
    }
    
    void addNum(int num) {
        if((count&1)==0)
        {
            right.push(num);
        }
        else
        {
            left.push(num);
        }
        if(left.size() && right.top()<left.top())
        {
            int a = right.top();right.pop();
            int b = left.top();left.pop();
            left.push(a); right.push(b);
        }
        count++;
    }
    
    double findMedian() {
        if((count&1)==0)return (double)(left.top()+right.top())/2;
        return (double)right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
