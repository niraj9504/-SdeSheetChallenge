#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
        int buy=prices[0],profit=0;
        for(int i=1;i<prices.size();i++){
            buy=min(prices[i],buy);
            profit=max(profit,(int)(prices[i]-buy));
        }
        return profit;
}
