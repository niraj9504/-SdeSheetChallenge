//see striver solution
class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        unordered_map<int,int> map;
        int sum=0,best=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==0){
                best=max(best,i+1);
            }
            else if(!map.empty() && map.find(sum)!=map.end()){
                best=max(best,i-map[sum]);
            }
            else{
                map[sum]=i;
            }
        }
        return best;
    }
};
