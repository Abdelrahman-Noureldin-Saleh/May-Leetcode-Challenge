class StockSpanner {
public:
    stack<pair<int, int>>* span;
    StockSpanner() {
        span = new stack<pair<int, int>>();
    }
    
    int next(int price) {
        int currentSpan = 1;
        while (!span->empty() && span->top().first <= price){
            currentSpan += span->top().second;
            span->pop();
        }
        span->push(make_pair(price, currentSpan));
        return currentSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */