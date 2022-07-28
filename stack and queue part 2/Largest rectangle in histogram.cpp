//prereq. next ggreater/smaller element array
//M1(gives TLE)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int minH=INT_MAX;
            for(int j=i;j<n;j++){
                minH=min(minH,h[j]);
                ans=max(ans,minH*(j-i+1));
            }
        }
        return ans;
    }
};

//M2
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> lse(n),rse(n);//left smaller element, right smaller element
        stack<int> st;
        //lse
        for(int i=0;i<n;i++){
            while(!st.empty() && h[i]<=h[st.top()])st.pop();
            
            if(st.empty())lse[i]=0;
            else{
                lse[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        int ans=0;
        
        //rse
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[i]<=h[st.top()])st.pop();
            
            if(st.empty())rse[i]=n-1;
            else{
                rse[i]=st.top()-1;
            }
            ans=max(ans,h[i]*(rse[i]-lse[i]+1));
            st.push(i);
        }
        return ans;
    }
};

//M3 (more optimised)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || h[i]<=h[st.top()])){
                int height=h[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else{
                    width=i-st.top()-1;
                }
                maxArea=max(maxArea,height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
