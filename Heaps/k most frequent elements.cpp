class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> map;
        for(auto it:nums){
            map[it]++;
        }
        for(auto it:map){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        nums.clear();
        while(!pq.empty()){
            nums.push_back(pq.top().second);
            pq.pop();
        }
        return nums;
    }
};
