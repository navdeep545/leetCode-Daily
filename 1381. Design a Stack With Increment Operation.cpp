class CustomStack {
    int *data ;
    int nextIndex ;
    int capacity ;
public:
    CustomStack(int maxSize) {
        data = new int[maxSize] ;
        nextIndex = 0 ;
        capacity = maxSize ;
    }
    
    void push(int x) {
        if(nextIndex == capacity) return ;
            data[nextIndex] = x ;
            nextIndex++ ;
    }
    
    int pop() {
        if(!nextIndex) return -1 ;
        nextIndex-- ;
        return data[nextIndex] ;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<nextIndex;i++){
            data[i] += val ;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */