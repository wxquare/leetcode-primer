class StockSpanner {
public: 
    stack<pair<int,int>> st;
    int index;
    StockSpanner() {
        index = 0;
    }
    int next(int price) {
        while(!st.empty() && price >= st.top().first){
            st.pop();
        }
        if(st.empty()){
            index++;
            st.push({price,index});
            return index;
        }else{
            index++;
            int ans = index - st.top().second;
            st.push({price,index});
            return ans;
        }
    }
};