#include <deque>

class MovingAverage {
public:
    deque<int> q;
    int max;
    double output;
    MovingAverage(int size) {
        max = size;
        output = 0;
    }
    
    double next(int val) {
        if(q.size()==max){
            output -= q.back();
            q.pop_back();
        } 

        q.push_front(val);
        output += val;
        return output/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */