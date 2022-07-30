class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans="1";
        while(n>1){
            string curr="";
            for(int i=0;i<ans.size();i++){
                int cnt=1;
                while(i+1<ans.size() && ans[i]==ans[i+1]){
                    cnt++;i++;
                }
                curr+=to_string(cnt)+ans[i];
            }
            ans=curr;
            n--;
        }
        return ans;
    }
};
