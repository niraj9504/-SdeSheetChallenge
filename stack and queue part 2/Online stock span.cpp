//m1 TLE
class StockSpanner {
public:
    stack<int> st,temp;//val,span
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        while(!st.empty() && st.top()<=price){
            ans++;
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        st.push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
//m2
class StockSpanner {
public:
    stack<pair<int,int>> st;//val,span
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;;
        while(!st.empty() && st.top().first<=price){
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};
//codestudio
#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    stack<pair<int,int>> st;
    int n=price.size();
    for(int i=0;i<n;i++){
        int cnt=1;
        while(!st.empty() && st.top().first<=price[i]){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price[i],cnt});
        price[i]=cnt;
    }
    return price;
}
