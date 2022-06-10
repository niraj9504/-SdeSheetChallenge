//m1(memory limit exceed)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return n; 
        int m=*min_element(nums.begin(),nums.end());
        int M=*max_element(nums.begin(),nums.end());
        
        vector<int> v(M-m+1,0);//for space optimisation eg. 50,51,52,53,200 as 0,1,2,3,150 
        for(auto it:nums){     //(new value lies b/w 0 to 150 i.e. 0 to M-m+1)
            //cout<<it-m<<" ";
            v[it-m]=1;
        }
        int cnt=1,best=1;
        for(int i=1;i<M-m+1;i++){
            if(v[i]==1 && v[i-1]==1)cnt++;
            else{
                cnt=1;
            }
            best=max(best,cnt);
        }
        return best;
    }
};
//m2(slow using set , TLE)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        if(s.size()==0 || s.size()==1)return s.size();
        int count=1,best=1;
        auto it=s.begin();
        int prev=*it;
        it++;
        for(it;it!=s.end();it++){
            int curr=(*it);
            if((curr-1)==prev){
                count++;
                best=max(best,count);
            }
            else{
                count=1;
            }
            prev=curr;
        }
        
        return best;
    }
};
//m3 (Radix sort) not applicable because nums[i] may be negative also and radix sort for positive only
class Solution {
public:
    void countSort(vector<int> &nums,int n,int place){
        vector<int> count(10,0);//digits b/w 0 to 9
        for(int i=0;i<n;i++)count[(nums[i]/place)%10]++;
        for(int i=1;i<10;i++)count[i]+=count[i-1];
        //output array
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            res[--(count[(nums[i]/place)%10])]=nums[i];
        }
        for(int i=0;i<n;i++)nums[i]=res[i];
    }
    int longestConsecutive(vector<int>& nums) {
        //Radix Sort
        int n=nums.size();
        if(n<=1)return n;
        int m=*max_element(nums.begin(),nums.end());
        //cout<<m;
        for(int place=1;(m/place)>0;place*=10){
            countSort(nums,n,place);
        }
        int cnt=1,best=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)cnt++;
            else cnt=1;
            best=max(best,cnt);
        }
        return best;
    }
};
//m4 O(n) time 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return n;
        unordered_set<int> st(nums.begin(),nums.end());
        int best=0;
        for(auto it:st){
            if(st.count(it-1)==0){
                int cnt=1;
                int curr=it;
                while(st.count(curr+1)){
                    curr++;cnt++;
                }
                best=max(best,cnt);
            }
        }
        return best;
    }
};
//m5 (best) try with union find(disjoint set) :- see leetcode discussion

